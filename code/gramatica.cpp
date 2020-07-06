#include "gramatica.h"



void gramatica::crearRegla(string izq, const string& der,char delim) {
    vector<string> vecDer;
    string temp;

    //SPLIT DER and STORE IN A VEC

//    for(char i : der){
//        if(i != '|'){
//            temp += i;
//        }else{
//            vecDer.push_back(temp);
//            temp = "";
//        }
//    }
    vecDer= splitString(der,'|');

    gram.push_back(new regla(std::move(izq), vecDer,delim));
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
            for(const auto &k: j)
                if (k == x)
                    result = i->izq;
    return result;
}

string regla::preattyStringOutput(char sep) {
    string result;
    result += izq;
    result += " -> ";
    for(int i = 0; i < der.size(); ++i)
    {
        for(int j=0;j<der[i].size();j++){
            result += der[i][j];
            if(j < der.size()-1)
                result += sep;
        }
        if(i < der.size()-1)
            result += " | ";
    }
    return result;
}

regla* gramatica::inicio(){return gram.size()>0?gram[0]:nullptr;}

regla* gramatica::get_regla(string i){
	for(auto r:gram)
		if(!i.compare(r->izq)) return r;

	return nullptr;
}
