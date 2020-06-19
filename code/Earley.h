#ifndef __Ealey_Parcer__
#define __Ealey_Parcer__

#include "gramatica.h"
//#include "unordered_map"

//typedef std::unordered_map<size_t,Estado*> algo q no se usa;

bool es_mayuscula(char letra){return (letra>='A' && letra<='Z');}


struct Estado{
	size_t punPos;//marca que parte de la regla ya a sido parceada
	size_t origen;//en que etapa del algoritmo fue creado

	string izq;
	string der;

	char siguiente(){return der[punPos];}
	bool esta_completo(){return punPos==der.size()?true:false;}

	void mostrar(){
		cout<<"origen "<<origen<<": ";
		cout<<izq<<" -> ";
		for(size_t i=0;i<der.size();i++){
			if(i==punPos) cout<<".";
			cout<<der[i];
		}
		if(punPos==der.size()) cout<<".";
		cout<<"\n";

	}

	Estado(regla* _regla, size_t cual,size_t ppos,size_t ori){
		izq=_regla->izq;
		der=_regla->der[cual];
		punPos=ppos;
		origen=ori;
	}

	Estado(Estado* otro_estado,size_t pos){
		izq=otro_estado->izq;
		der=otro_estado->der;
		punPos=(otro_estado->punPos)+1;
		origen=pos;
	}

	bool es_igual_a(Estado* otro_estado){
		if(izq.compare(otro_estado->izq)!=0)return false;
		if(der.compare(otro_estado->der)!=0)return false;
		if(origen!=otro_estado->origen)return false;
		if(punPos!=otro_estado->punPos)return false;
		return true;
	}
};


class Earley{
	vector<vector<Estado*> > tabla;
	gramatica* _gramatica_;
	string _cadena_;

	void agregar_estado(regla*,size_t,size_t,size_t);//a partir de una regla
	void agregar_estado(Estado*,size_t,size_t);//a partir de otro estado;avanza el punto
	
	void predecir(Estado*,size_t);
	void escanear(Estado*,size_t);
	void completar(Estado*,size_t);

public:
	Earley(gramatica*,string);
	virtual ~Earley();

	bool reconocer();
};


#endif
