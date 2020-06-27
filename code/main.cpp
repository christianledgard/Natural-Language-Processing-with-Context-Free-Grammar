#include <iostream>
#include "gramatica.h"
#include "CYK.h"
#include "Earley.cpp"

int main() {
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
	
    return 0;
}
