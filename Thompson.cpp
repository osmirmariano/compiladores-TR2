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
			stack <AUTOMATO> pilha;
		};

		~Thompson();

        string unirAlfabetos(string alfabeto1, string alfabeto2) {
        	string alfabeto;
            alfabeto = alfabeto1;
			for (int x = 0; x < alfabeto2.size(); x++) {
            	alfabeto.push(alfabeto2[x]);
            }
			return alfabeto;
        };

   //          AUTOMATO  *unirEstados(AUTOMATO *estado1, AUTOMATO *estado2){
   //          	AUTOMATO *estados;
   //              for(int x = 0; x < estado1->length(); x++){
   //              	estados->estados->push_back(estado1[x]);
   //              }
   //              for(int x = 0; x < estado2->length(); x++){
   //              	estados->estados->push_back(estado2[x]);
   //              }
   //              return estados;
			// };

		// TRANSICOES *unirTransicoes(TRANSICOES *transicoes1, TRANSICOES *transicoes2){
		// 	TRANSICOES transicoes;
		// 	for(int x = 0; x < transicoes1.length(); x++){
  //                           transicoes.empilharTransicoes(&topo, transicoes1[x]);
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

			//Para testes
            cout << "SIMBOLO: " << base->alfabeto << endl;
            cout << "Q. ESTADOS: " << base->qtEstados << endl;
            cout << "ESTADO INICIAL: " << base->estadoInicial << endl;
			cout << "ESTADO FINAL: " << base->estadosFinais[0] << endl;
			cout << "TRANSICAO: " << base->transicoes[0][0].estados[0] << endl << endl;
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
			AUTOMATO *recebe1, *recebe2;
			for(int x = 0; x < posTho.length(); x++){
				simbolo = posTho[x];
				if(simbolo != "+" && simbolo != "." && simbolo != "*"){
					Base(simbolo);//Chamando a base para gerar da expressão regular que tá nos simbolo o automato
					//Aqui empilha a Base
                    pilha.push(Base(simbolo));
					cout << "Montou a Base" << endl;
				}
				else if(simbolo == "+"){
					/*Primeiro Desempilha o primeiro que foi inserido
					Segundo Desempilha o segundo que foi desempilhado
					E passa ambos para concatenação (No lugar de A e B)*/
					//Concatenacao(a, b);//Chamando concatenação, falta tratar ainda tá incompleta
					cout << "Entrou aqui Concatenacao" << endl;
				}
				else if(simbolo == "."){
					/*Primeiro Desempilha o primeiro que foi inserido
					Segundo Desempilha o segundo que foi desempilhado
					E passa ambos para concatenação (No lugar de A e B)*/
					//Uniao(a, b);//Chamando concatenação, falta tratar ainda tá incompleta
				}
				else if(simbolo == "*"){
					/*Desempilha somente o que tá no topo, visto que * é um operador binário e
					passa para a função no lugar do A*/
					//FechoDeKleene(a);//Chamando concatenação, falta tratar ainda tá incompleta
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
