#include "CYK.h"

string ** CYK::solve()
{
    for (int i = 1; i < cadena.size()+1; ++i)
        matriz[i][i] = G->queReglaDeriva(getString(cadena[i - 1]));

    for (int l = 2; l <= cadena.size(); ++l)
    {
        for (int i = 1; i <= cadena.size() - l + 1; ++i)
        {
            string tempResultado;
            int j = i + l - 1;
            for (int k = i; k <= j-1; ++k){


                if(!matriz[i][k].empty() && !matriz[k + 1][j].empty())
                {
                    vector<string> posiblesCombinaciones = distributiva(matriz[i][k], matriz[k + 1][j]);

                    string respuesta;

                    for(const string& combinacion : posiblesCombinaciones)
                        respuesta += G->queReglaDeriva(combinacion);

                    tempResultado += respuesta;
                }
            }
            matriz[i][j] = eliminarDuplicados(tempResultado);
        }

    }


    return matriz;
}


vector<string> CYK::distributiva(const string& a, const string& b)
{
    vector<string> temp;
    for(char i : a) {
        for (char j : b) {
            temp.push_back(string(1,i)+j);
        }
    }
    return temp;
}

CYK::CYK(gramatica *g, char S, const string& cadena) : G(g),S(S),cadena(cadena) {
    CYK::arraySize = cadena.size()+1;
    matriz = new string*[arraySize];
    for(size_t i = 0; i < arraySize; ++i) {
        matriz[i] = new string[arraySize + 1];
    }
}

CYK::~CYK() {
    for(int i = 0; i < arraySize; ++i) {
        delete [] matriz[i];
        matriz[i]=nullptr;
    }
    delete [] matriz;
    matriz=nullptr;
}


string CYK::eliminarDuplicados(string x) {
	sort(x.begin(), x.end());
    auto res = unique(x.begin(), x.end());
    return string(x.begin(), res) ;
}

bool CYK::cadenaAceptada() {
    return (matriz[1][cadena.size()]).find(S) != std::string::npos;
}

ostream &operator<<(ostream &out, const CYK &cyk) {
    for (int i = 1; i < cyk.arraySize; ++i) {
        for (int j = 1; j < cyk.arraySize; ++j) {
            cout << setw(5)<< cyk.matriz[i][j] << setw(5)<< "|";
        }
        cout << endl;
    }
    return out;
}
