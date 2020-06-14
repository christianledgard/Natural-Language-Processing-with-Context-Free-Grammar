#include <iostream>
#include "gramatica.h"
#include "CYK.h"

int main() {

    gramatica g;
    g.crearRegla("S","RT");
    g.crearRegla("R","TR|a");
    g.crearRegla("T","TR|b");


    cout << g.queReglaDeriva("TR") << endl;

    g.print();

    CYK cyk(&g,'S',"baba");

    cout << cyk.solve();

    return 0;




}
