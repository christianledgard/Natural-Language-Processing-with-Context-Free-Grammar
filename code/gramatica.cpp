//
// Created by Christian Ledgard on 6/14/20.
//

#include "gramatica.h"

void gramatica::crearRegla(string izq, string der) {
    vector<string> vecDer;
    string temp = "";

    //SPLIT DER and STORE IN A VEC

    for(char i : der){
        if(i != '|'){
            temp += i;
        }else{
            vecDer.push_back(temp);
            temp = "";
        }
    }
    vecDer.push_back(temp);


    gram.push_back(new regla(izq, vecDer));
    vecDer.clear();
}

void gramatica::print() {
    for (const auto &x :  gram){
        cout << x->preattyStringOutput() << endl;
    }
}

gramatica::~gramatica() {
    for (auto p : gram)
        delete p;
}

string regla::preattyStringOutput() {
    string result;
    result += izq;
    result += " -> ";
    for(int i = 0; i < der.size(); ++i)
    {
        result += der[i];
        if(i < der.size()-1)
            result += " | ";
    }
    return result;
}
