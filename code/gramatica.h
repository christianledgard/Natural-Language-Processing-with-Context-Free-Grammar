//
// Created by Christian Ledgard on 6/14/20.
//

#ifndef C___GRAMATICA_H
#define C___GRAMATICA_H

#include <string>
#include <utility>
#include <vector>
#include <iostream>


using namespace std;


class regla{
    string izq;
    vector<string> der;
public:
    regla(string izq, vector<string> der) : izq(std::move(izq)), der(std::move(der)) {}
    string preattyStringOutput();
};

class gramatica{
    vector<regla*> gram;

public:
    gramatica() {}
    void crearRegla(string izq, string der);
    void print();

    virtual ~gramatica();
};





#endif //C___GRAMATICA_H
