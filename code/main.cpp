#include <iostream>
#include "gramatica.h"
#include "CYK.h"

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
    cout << cyk.solve();



    cout << endl << endl;




//    gramatica a;
//    a.crearRegla("S","RT");
//    a.crearRegla("R","TR|a");
//    a.crearRegla("T","TR|b");
//    a.print();
//
//    CYK cyk2(&a,'S',"baba");


    gramatica clase;
    clase.crearRegla("S","AB|BC");
    clase.crearRegla("A","BA|a");
    clase.crearRegla("B","CC|b");
    clase.crearRegla("C","AB|a");
    clase.print();

    CYK cyk3(&clase,'S',"baaba");
    cout << cyk3.solve() << endl;
    cyk3.printSolution();

    return 0;




}
