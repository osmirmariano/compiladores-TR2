#include <iostream>

using namespace std;

typedef struct {
	int *estados;
	int qtEstados;
}TRANSICOES;

typedef struct {
	string alfabeto;
	string *estados;
	int qtEstados;
	TRANSICOES **transicoes;
	int estadoInicial;
	int *estadosFinais;
	int qtEstFinais;
}AUTOMATO;

class Thompson{

	public:
		Thompson(){

		};
		~Thompson();
	
};