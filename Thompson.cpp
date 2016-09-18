#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

typedef struct {
	int *estados;
	int qtEstados;
}TRANSICOES;

typedef struct no{
	TRANSICOES **transicoes;
	string alfabeto;
	string *estados;
	int qtEstados;
	int estadoInicial;
	int *estadosFinais;
	int qtEstFinais;
	struct no *prox;
}AUTOMATO;

class Thompson{
	public:
		string posTho, simbolo;
	public:
		Thompson(){
			AUTOMATO *Base(string simbolo);
			AUTOMATO *Concatenacao(AUTOMATO *a, AUTOMATO *b);
			AUTOMATO *Uniao(AUTOMATO *a, AUTOMATO *b);
			void montadorAutomato(string posTho);
			string uneAlfabetos(string a, string b);
			void montadorAutomato(string posTho);
			//void testandoExpressao(string posTho);
			stack <AUTOMATO> pilha;
		};

		~Thompson();

        string unirAlfabetos(string a, string b) {
        	string alfabeto;
            alfabeto = a;

			for (int x = 0; x < b.size(); x++) {
            	alfabeto.
            }
            return alfabeto;
		};

  //       TRANSICOES  *unirEstados(TRANSICOES *estado1, TRANSICOES *estado2){
  //       	TRANSICOES estados;
  //           for(int x = 0; x < estado1->length(); x++){
  //           	empilharEstados(&topo, estado1[x]);
  //           }
  //           for(int x = 0; x < estado2->length(); x++){
  //           	empilharEstados(&topo, estado2[x]);
  //           }
  //           return estados;
		// };

		// TRANSICOES *unirTransicoes(TRANSICOES *transicoes1, TRANSICOES *transicoes2){
		// 	TRANSICOES transicoes;
		// 	for(int x = 0; x < transicoes1.length(); x++){
		// 		empilharTransicoes(&topo, transicoes1[x]);
		// 	}
		// 	for(int x = 0; x < transicoes2.length(); x++){
		// 		empilharTransicoes(&topo, transicoes2[x]);
		// 	}
		// 	return transicoes;
		// };

		AUTOMATO *Base(string simbolo) {
			AUTOMATO *base = new AUTOMATO; // Criando objeto automato
			base->alfabeto = simbolo; // Alfabeto recebendo o simbolo
			//Código abaixo para criar os estados
			base->qtEstados = 2;
			base->estados = new string[base->qtEstados];
			base->estados[0] = '0';
			base->estados[1] = '1';
			base->estadoInicial = 0;//Correspondente ao estado inicial 
			base->qtEstFinais = 1;//Definindo a quantidade de estados finais, só 1
			base->estadosFinais = new int[1];//Criando objeto estados finais
			base->estadosFinais[0] = 1; // Dizendo que é o estado final
			//Código abaixo referente as transições do automato
            base->transicoes = new TRANSICOES*[2];
            base->transicoes[0] = new TRANSICOES[1];
			base->transicoes[0][0].qtEstados = 1;

			base->transicoes[0][0].estados = new int[1];
			base->transicoes[0][0].estados[0] = 1;
			base->transicoes[1] = new TRANSICOES[1];
			base->transicoes[1][0].qtEstados = 0;
			return base;
		};


		AUTOMATO *Concatenacao(AUTOMATO *a, AUTOMATO *b) {
			AUTOMATO *novo = new AUTOMATO;
			novo->alfabeto = unirAlfabetos(a->alfabeto, b->alfabeto);
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
			novo->alfabeto = unirAlfabetos(a->alfabeto,b->alfabeto);
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
            novo->alfabeto = unirAlfabetos(a->alfabeto,"");
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

		void montadorAutomato(string posTho){
			stack <AUTOMATO> pilha;
			for(int x = 0; x < posTho.length(); x++){
				simbolo = posTho[x];
				if(simbolo != "+" && simbolo != "." && simbolo != "*"){
					Base(simbolo);//Chamando a base para gerar da expressão regular que tá nos simbolo o automato
				}
				else if(simbolo == "+"){
					// a = posTho[x-2];
					// b = posTho[x-1];
					// &Concatenacao(a, b);//Chamando concatenação, falta tratar ainda tá incompleta
				}
				else if(simbolo == "."){
					//&Uniao(a, b);//Chamando concatenação, falta tratar ainda tá incompleta
				}
				else if(simbolo == "*"){
					//&FechoDeKleene(a);//Chamando concatenação, falta tratar ainda tá incompleta
				}
			}
		};

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
