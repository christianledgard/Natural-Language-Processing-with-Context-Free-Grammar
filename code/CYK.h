//
// Created by Christian Ledgard on 6/14/20.
//

#ifndef C___CYK_H
#define C___CYK_H

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <ctype.h>


#include "gramatica.h"

using namespace std;


class CYK{
private:
    gramatica* G;
    string cadena;
    char S;

    string table[100][100];

    string getString(char x){ string s(1, x); return s; }
    vector<string> distributiva(string a, string b);

public:
    CYK(gramatica *g,char S, string cadena) : G(g),S(S) {CYK::cadena = cadena;}
    bool solve();

};

#endif //C___CYK_H
