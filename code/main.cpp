#include <iostream>
#include "gramatica.h"

int main() {

    gramatica g;

    g.crearRegla("S","AB|BC");
    g.crearRegla("A","BC|AABC|AA");

    g.print();


    return 0;




}
