#ifndef C___GRAMATICA_H
#define C___GRAMATICA_H

#include "lib.h"
#include "aux.h"

struct regla{
    string izq;
    vector<vector<string>> der;
    regla(string izq, vector<string> der,char delim=' ') : izq(std::move(izq)){
       for(int i=0;i<der.size();i++){
        this->der.push_back(splitString(der[i],delim));
       }
    }
    string preattyStringOutput(char sep=' ');
};

class gramatica{
    vector<regla*> gram;

public:
    gramatica() = default;
    void crearRegla(string izq, const string& der,char delim=' ');
	regla* inicio();
	regla* get_regla(string);
    vector<regla*> get_gramatica(){return gram;}

    string queReglaDeriva(const string& x);

    void print();

    virtual ~gramatica();
};

#endif //C___GRAMATICA_H
