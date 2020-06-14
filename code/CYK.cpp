//
// Created by Christian Ledgard on 6/14/20.
//

#include "CYK.h"


bool CYK::solve()
{
    for (int i = 1; i < cadena.size()+1; ++i)
        table[i][i] = G->queReglaDeriva(getString(cadena[i-1]));

    for (int l = 2; l <= cadena.size(); ++l)
        for (int i = 1; i <= cadena.size() - l + 1; ++i)
        {
            int j = i + l - 1;
            for (int k = i; k <= j-1; ++k)
                if(!table[i][k].empty() && !table[k+1][j].empty())
                {
                    vector<string> posiblesCombinaciones = distributiva(table[i][k],table[k+1][j]);

                    string respuesta;

                    for(const string& combinacion : posiblesCombinaciones)
                        respuesta += G->queReglaDeriva(combinacion);

                    table[i][j] += respuesta;
                }
        }

    return (table[1][cadena.size()]).find(S) != std::string::npos;
}


vector<string> CYK::distributiva(string a, string b)
{
    vector<string> temp;
    for(char i : a) {
        for (char j : b) {
            temp.push_back(string(1,i)+j);
        }
    }
    return temp;
}
