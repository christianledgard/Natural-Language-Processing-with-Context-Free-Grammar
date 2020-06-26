#include "gramatica.h"

#include <utility>

void gramatica::crearRegla(string izq, const string& der) {
    vector<string> vecDer;
    string temp;

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


    gram.push_back(new regla(std::move(izq), vecDer));
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

string gramatica::queReglaDeriva(const string& x) {

    string result;
    for (const auto &i : gram)
        for (const auto &j : i->der)
            if (j == x)
                result += i->izq;
    return result;
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

regla* gramatica::inicio(){return gram.size()>0?gram[0]:nullptr;}

regla* gramatica::get_regla(char i){
	for(auto r:gram)
		if(i==(r->izq)[0]) return r;

	return nullptr;
}