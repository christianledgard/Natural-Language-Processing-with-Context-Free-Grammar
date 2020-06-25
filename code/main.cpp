#include <iostream>
#include "gramatica.h"
#include "CYK.h"
#include "Earley.cpp"

int main() {
	gramatica suma;
	suma.crearRegla("S","N+S|N*S|(S)|N");
	suma.crearRegla("N","1|2|3|4|5|6|7|8|9");

	Earley sumas(&suma,"1+2+(3*4)");
	cout<<sumas.reconocer()<<endl<<endl;
    cout <<"|-----------------------------------------------------------------------|\n";

    gramatica g;
    g.crearRegla("S","AB");
    g.crearRegla("A","CD|CF");
    g.crearRegla("B","c|EB");
    g.crearRegla("C","a");
    g.crearRegla("D","b");
    g.crearRegla("E","c");
    g.crearRegla("F","AD");
    g.print();

    CYK cyk(&g,'S',"aaabbbcc");
    cyk.solve();
    cout << cyk.cadenaAceptada()<< endl;
    cout << cyk;

    cout <<"|-----------------------------------------------------------------------|\n";

	Earley gram1(&g,"aaabbbcc");
	cout<<gram1.reconocer()<<endl<<endl;


    gramatica a;
    a.crearRegla("S","RT");
    a.crearRegla("R","TR|a");
    a.crearRegla("T","TR|b");
    a.print();

    CYK cyk2(&a,'S',"baba");



    cout <<"|-----------------------------------------------------------------------|\n";
    gramatica clase;
    clase.crearRegla("S","AB|BC");
    clase.crearRegla("A","BA|a");
    clase.crearRegla("B","CC|b");
    clase.crearRegla("C","AB|a");
    clase.print();

    CYK cyk3(&clase,'S',"baaba");
    cyk3.solve();
    cout << cyk3.cadenaAceptada()<< endl;
    cout << cyk3;

    cout <<"|-----------------------------------------------------------------------|\n";
	
	Earley gram2(&clase,"baaba");
	cout<<gram2.reconocer()<<endl<<endl;
    Earley e(&clase,"baaba");
    cout << e.reconocer() << endl;

    return 0;
}
