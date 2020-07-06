#ifndef __Ealey_Parcer__
#define __Ealey_Parcer__

#include "lib.h"
#include "gramatica.h"

struct Estado{
	size_t punPos;//marca que parte de la regla ya a sido parceada
	size_t origen;//en que etapa del algoritmo fue creado

	string izq;
	vector<string> der;

	string siguiente(){return der[punPos];}
	bool esta_completo(){return punPos==der.size();}

	void mostrar();

	Estado(regla* _regla, size_t cual,size_t ppos,size_t ori);

	Estado(Estado* otro_estado,size_t pos);

	bool es_igual_a(Estado* otro_estado);
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

    bool es_variable(string var);

public:
	Earley(gramatica*,string);
	bool reconocer();
    virtual ~Earley();
};

//bool es_mayuscula(char letra){return (letra>='A' && letra<='Z');}

#endif
