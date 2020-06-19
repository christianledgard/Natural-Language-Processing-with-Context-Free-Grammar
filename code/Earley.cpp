#include "Earley.h"

Earley::Earley(gramatica* gram,string cadena):_gramatica_(gram),_cadena_(cadena){
	tabla.reserve(_cadena_.size()+1);
}

void Earley::agregar_estado(regla* _regla,size_t cual,size_t punPos,size_t pos){
	Estado* nuevo_estado=new Estado(_regla,cual,punPos,pos);

	for(size_t i=0;i<tabla[pos].size();i++)
		if(tabla[pos][i]->es_igual_a(nuevo_estado)){
			delete nuevo_estado;
			return;
		}

	tabla[pos].push_back(nuevo_estado);
	tabla[pos][tabla[pos].size()-1]->mostrar();
}

void Earley::agregar_estado(Estado* est,size_t opos,size_t tpos){
	Estado* nuevo_estado=new Estado(est,opos);

	for(size_t i=0;i<tabla[tpos].size();i++)
		if(tabla[tpos][i]->es_igual_a(nuevo_estado)){
			delete nuevo_estado;
			return;
		}

	tabla[tpos].push_back(nuevo_estado);
	tabla[tpos][tabla[tpos].size()-1]->mostrar();
}

void Earley::predecir(Estado* est,size_t k){//para variables
	regla* sigue_variable=_gramatica_->get_regla(est->siguiente());
	if(sigue_variable==nullptr) return;
	for(size_t i=0;i<sigue_variable->der.size();i++)
		agregar_estado(sigue_variable,i,0,k);
}

void Earley::escanear(Estado* est,size_t k){//para literales
	if(est->siguiente()==_cadena_[k])
		agregar_estado(est,est->origen,k+1);
}

void Earley::completar(Estado* est,size_t k){//para estados ya parceados
	for(size_t i=0;i<tabla[est->origen].size();i++)
		if(tabla[est->origen][i]->siguiente()==est->izq[0])
			agregar_estado(tabla[est->origen][i],tabla[est->origen][i]->origen,k);
}

bool Earley::reconocer(){
	regla* regla_inicial=_gramatica_->inicio();
	for(size_t i=0;i<regla_inicial->der.size();i++)
		agregar_estado(_gramatica_->inicio(),i,0,0);

	for(size_t k=0;k<=_cadena_.size();k++){
		if(k<_cadena_.size())
		cout<<"caracter: \""<<_cadena_[k]<<"\"\n";
		for(size_t i=0;i<tabla[k].size();i++){//se puede expandir
			if(tabla[k][i]->esta_completo()){//ya fue parceado
				completar(tabla[k][i],k);
//				cout<<"completado\n\n";
				}
			else if(es_mayuscula(tabla[k][i]->siguiente())){//el siguiente termino es una variable
				predecir(tabla[k][i],k);
//				cout<<"predicho\n\n";
				}
			else{
				escanear(tabla[k][i],k);//el siguiente termino es un literal
//				cout<<"escaneado\n\n";
				}
		}
	}//
	Estado* algun_estado=nullptr;
	for(size_t i=0;i<tabla[_cadena_.size()].size();i++){
		algun_estado=tabla[_cadena_.size()][i];
		if(algun_estado->esta_completo())
			if(algun_estado->origen==0)
				if(algun_estado->izq==regla_inicial->izq)
					return true;
	}

	return false;
}

Earley::~Earley(){
	for(auto vec:tabla)
		for(auto est:vec)
			delete est;
}
