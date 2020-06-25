//
// Created by Christian Ledgard on 6/14/20.
//

#ifndef C___CYK_H
#define C___CYK_H

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <iomanip>
#include <unordered_map>

#include "gramatica.h"

using namespace std;


class CYK{
private:
    gramatica* G;
    string cadena;
    char S;

    string **matriz;
    size_t arraySize;

    static string getString(char x){ string s(1, x); return s; }
    static vector<string> distributiva(const string& a, const string& b);
    string eliminarDuplicados(string x);

public:
    CYK(gramatica *g,char S, const string& cadena);

    string **solve();
    bool cadenaAceptada();
    friend ostream & operator<< (ostream &out, const CYK &cyk);


    virtual ~CYK();

};

#endif //C___CYK_H
