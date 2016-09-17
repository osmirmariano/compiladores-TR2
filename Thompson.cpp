#include <iostream>
#include <cstdlib>
//#include "Posfixa.cpp"

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
		string posTho, simbolo;
	public:
		Thompson(){
			AUTOMATO *Base(string simbolo);
			AUTOMATO *Concatenacao(AUTOMATO *a, AUTOMATO *b);
			AUTOMATO *Uniao(AUTOMATO *a, AUTOMATO *b);
			//void testandoExpressao(string posTho);

		};
		~Thompson();

		AUTOMATO *uneAlfabetos(string a, string b){

		};

		AUTOMATO *Base(string simbolo) {
			AUTOMATO *base = new AUTOMATO;
			base->alfabeto = simbolo;
			base->qtEstados = 2;
			base->estados = new string[base->qtEstados];
			base->estados[0] = '0';
			base->estados[1] = '1';
			base->transicoes = new transicoes*[2];
			base->transicoes[0] = new transicoes[1];
			base->transicoes[0][0].qtEstados = 1;
			base->transicoes[0][0].estados = new int[1];
			base->transicoes[0][0].estados[0] = 1;
			base->transicoes[1] = new transicoes[1];
			base->transicoes[1][0].qtEstados = 0;
			base->estadoInicial = 0;
			base->qtEstFinais = 1;
			base->estadosFinais = new int[1];
			base->estadosFinais[0] = 1;
			return base;
		};


		AUTOMATO *Concatenacao(AUTOMATO *a, AUTOMATO *b) {
			AUTOMATO *novo = new AUTOMATO;
			novo->alfabeto = uneAlfabetos(a->alfabeto,b->alfabeto);
			novo->qtEstados = a->qtEstados+b->qtEstados;
			novo->estados = new string[novo->qtEstados];
			//Preencher os estados do novo autômatos com os estados de a e b
			//Preencher as transições do novo autômatos com as transições de a e b
			novo->estadoInicial = 0;
			novo->estadosFinais = new int[1];
			novo->estadosFinais[0] = novo->qtEstados-1;
			novo->qtEstFinais = 1;
			return novo;
		};

		AUTOMATO *Uniao(AUTOMATO *a, AUTOMATO *b) {
			AUTOMATO *novo = new AUTOMATO;
			novo->alfabeto = uneAlfabetos(a->alfabeto,b->alfabeto);
			novo->qtEstados = a->qtEstados+b->qtEstados+2;
			novo->estados = new string[novo->qtEstados];
			//Preencher os estados do novo autômatos com os estados de a e b
			//Preencher as transições do novo autômatos com as transições de a e b
			novo->estadoInicial = 0;
			novo->estadosFinais = new int[1];
			novo->estadosFinais[0] = novo->qtEstados-1;
			novo->qtEstFinais = 1;
			return novo;
		};


		AUTOMATO *FechoDeKleene(AUTOMATO *a) {
			AUTOMATO *novo = new AUTOMATO;
			novo->alfabeto = uneAlfabetos(a->alfabeto,"");
			novo->qtEstados = a->qtEstados+2;
			novo->estados = new string[novo->qtEstados];
			//Preencher os estados do novo autômatos com os estados de a
			//Preencher as transições do novo autômatos com as transições de a
			novo->estadoInicial = 0;
			novo->estadosFinais = new int[1];
			novo->estadosFinais[0] = novo->qtEstados-1;
			novo->qtEstFinais = 1;
			return novo;
		};

		// void montadorAutomato(string posTho){

		// 	for(int x = 0; x < posTho.length(); x++){
		// 		simbolo = posTho[x];
		// 		if(simbolo != "+" && simbolo != "." && simbolo != "*"){
		// 			&Base(simbolo);//Chamando a base para gerar da expressão regular que tá nos simbolo o automato
		// 		}
		// 		else if(simbolo == "+"){
		// 			&Concatenacao(a, b);//Chamando concatenação, falta tratar ainda tá incompleta
		// 		}
		// 		else if(simbolo == "."){
		// 			&Uniao(a, b);//Chamando concatenação, falta tratar ainda tá incompleta
		// 		}
		// 		else if(simbolo == "*"){
		// 			&FechoDeKleene(a);//Chamando concatenação, falta tratar ainda tá incompleta
		// 		}
		// 	}
		// };

		/*void verifcaAutomato(){
			while
		}
		enquanto (não terminar a entrada) {
			simbolo = próximo caractere de entrada;
			se (simbolo é um operando)
			push(pilha, Base(simbolo));
			senão {
			se (simbolo é operador unário) {
			op1 = pop(pilha);
			push(pilha, FechoDeKleene(op1));
			}
			senão se (simbolo é operador binário) {
			op2 = pop(pilha);
			se (top(pilha) != null) {
			op1 = pop(pilha);
			 se (operador é concatenação)
			 push(pilha, Concatenacao(op1,op2));
			 senão se (operador é união)
			 push(pilha, União(op1,op2));
			 }
			 }
			 }
			}
			afd= pop(pilha);
			se (se a pilha estiver vazia)
			 imprimir(afd);*/


};
