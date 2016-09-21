#include <iostream>
#include <cstdlib>
#include <stack>
#include <sstream>

using namespace std;

typedef struct {
	int *estados;
	int qtEstados;
}TRANSICOES;

typedef struct{
	TRANSICOES **transicoes;
	string alfabeto;
    string *estados;
    int qtEstados;
    int estadoInicial;
    int *estadosFinais;
    int qtEstFinais;
}AUTOMATO;

typedef struct PILHAAUTOMATO{
	AUTOMATO *automato;
    struct PILHAAUTOMATO *prox;
}PILHAAUTOMATO;

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
            string unirEstados(string estados1, string estados2);
    		//stack <AUTOMATO> pilha;
    	};

    	~Thompson();

    	string unirAlfabetos(string alfabeto1, string alfabeto2) {
    		string alfabeto;
    		alfabeto = alfabeto1;
    		for (int x = 0; x < alfabeto2.size(); x++) {
    			alfabeto += alfabeto2[x];
    		}
    		return alfabeto;
    	};

        // TRANSICOES *unirTransicoes(TRANSICOES *transicoes1, TRANSICOES *transicoes2){
        //     TRANSICOES *transicoes;
        //     PILHAAUTOMATO *topo = NULL;
        //     for(int x = 0; x < transicoes1.size(); x++){
        //         empilharTransicoes(&topo, &transicoes1[x]);
        //     }

        //     for(int x = 0; x < transicoes2.size(); x++){
        //         empilharTransicoes(&topo, &transicoes2[x]);
        //     }
        //     return transicoes;
        // };

        /*----------------------- FUNÇÃO EMPILHAR-----------------------------*/
        // void empilharTransicoes(PILHAAUTOMATO **topo, TRANSICOES *recebe){
        //     PILHAAUTOMATO *novo;
        //     novo = new PILHAAUTOMATO;
        //     if(novo == NULL)
        //         cout << "NÃO ALOCADO" << endl;
        //     else{
        //         novo->automato->transicoes = recebe;
        //         novo->prox = (*topo);
        //         (*topo) = novo;
        //     }
        // };

        /*----------------------- FUNÇÃO EMPILHAR-----------------------------*/
        // void empilharEstados(PILHAAUTOMATO **topo, string recebe){
        //     PILHAAUTOMATO *novo;
        //     novo = new PILHAAUTOMATO;
        //     if(novo == NULL)
        //         cout << "NÃO ALOCADO" << endl;
        //     else{
        //         novo->automato->estados = recebe;
        //         novo->prox = (*topo);
        //         (*topo) = novo;
        //     }
        // };

        // string unirEstados(string estados1, string estados2){
        //     string estados, armazena;
        //     PILHAAUTOMATO *topo = NULL;
        //     for(int x = 0; x < estados1.length(); x++){
        //         armazena = estados1[x];
        //         empilharEstados(&topo, armazena);
        //     }

        //     for(int x = 0; x < estados2.length(); x++){
        //         armazena = estados2[x];
        //         empilharEstados(&topo, estados2[x]);
        //     }
        //     return estados;
        // };


    	/*----------------------- FUNÇÃO EMPILHAR-----------------------------*/
        void empilhar(PILHAAUTOMATO **topo, AUTOMATO *recebe){
            PILHAAUTOMATO *novo;
            novo = new PILHAAUTOMATO;
            if(novo == NULL)
                cout << "NÃO ALOCADO" << endl;
            else{
                novo->automato = recebe;
                novo->prox = (*topo);
                (*topo) = novo;
            }
        };

        /*----------------------- FUNÇÃO DESEMPILHAR-----------------------------*/
        void desempilhar(PILHAAUTOMATO **topo){
            PILHAAUTOMATO *aux;
            if(aux == NULL)
                cout << "NÃO EXISTE NENHUM ELEMENTO NA PILHA" << endl;
            else{
                aux = (*topo);
                (*topo) = (*topo)->prox;
                delete aux;
            }
        };


        void listar(PILHAAUTOMATO *topo){
            PILHAAUTOMATO *aux;
            if(topo == NULL)
                cout << "PILHA VAZIA" << endl;
            else{
                aux = topo;
                while(aux != NULL){
                    cout << " ALFABETO: " << aux->automato->alfabeto << endl;
                    cout << " E. INCIAL: " << aux->automato->estadoInicial << endl;
                    cout << " ESTADOS: " << aux->automato->estados << endl;
                    cout << " Q. ESTADOS: " << aux->automato->qtEstados << endl;
                    cout << " Q. ESTADOS FINAIS: " << aux->automato->qtEstFinais<< endl;
                    aux = aux->prox;
                }
           }
        };

        /*----------------------- FUNÇÃO BASE - CONCLUÍDA-----------------------------*/
    	AUTOMATO *Base(string simbolo) {
            AUTOMATO *base = new AUTOMATO; // Criando objeto automato
            base->alfabeto = simbolo; // Alfabeto recebendo o simbolo
            //Código abaixo para criar os estados
            base->qtEstados = 2;
            base->estados = new string[base->qtEstados];
            base->estados[0] = "0";
            base->estados[1] = "1";
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

            //string *todosEstados;
            //Só para testes, depois remover
            cout << "-----------------------------------------------" << endl;
            cout << " ALFABETO: " << base->alfabeto << endl;
            cout << " ESTADO INICIAL: " << base->estadoInicial << endl;
            cout << " CONJUNTO DE ESTADOS: ";
            for(int x = 0; x < base->qtEstados; x++){
                cout << " " << base->estados[x];
            }
            cout << endl << " ESTADO FINAIS: ";
            for(int x = 0; x < base->qtEstFinais; x++){
                cout << " " << base->estadosFinais[x];
            }
            cout << endl << " QUANTIDADE ESTADOS: " << base->qtEstados << endl;
            cout << " QUANTIDADE ESTADOS FINAIS: " << base->qtEstFinais<< endl;
            cout << "-----------------------------------------------" << endl << endl;
            return base;
        };

        AUTOMATO *unirEstados(AUTOMATO estados1, AUTOMATO estados2){
            AUTOMATO *estados;
            for(int x = 0; x < 6; x++){
                cout << "Itens 1: " << estados->estados[x] << endl;
            }
        };

        AUTOMATO *Concatenacao(AUTOMATO *a, AUTOMATO *b) {
            stringstream conversao;
            AUTOMATO *novo = new AUTOMATO;
            novo->alfabeto = unirAlfabetos(a->alfabeto, b->alfabeto);
            novo->qtEstados = a->qtEstados+b->qtEstados;
            novo->estados = new string[novo->qtEstados+2];

            //Preencher os estados do novo autômatos com os estados de a e b
            //Preencher as transições do novo autômatos com as transições de a e b
            novo->estadoInicial = 0;
            novo->estadosFinais = new int[1];
            novo->estadosFinais[0] = novo->qtEstados+1;//Estado final
            novo->qtEstFinais = 1;

            //Unindo estados
            for(int x = 0; x < novo->qtEstados+2; x++){
                int y = x;
                conversao << y;
                novo->estados[x] = conversao.str();
                conversao.str("");
            }

            //Só para testes, depois remover
            cout << "-----------------------------------------------" << endl;
            cout << " ALFABETO: " << novo->alfabeto << endl;
            cout << " ESTADO INCIAL: " << novo->estadoInicial << endl;
            cout << " CONJUNTO DE ESTADOS: ";
            for(int x = 0; x < novo->qtEstados+2; x++){
                cout << " " << novo->estados[x];
            }
            cout << endl << " ESTADO FINAL: ";
            for(int x = 0; x < novo->qtEstFinais; x++){
                cout << " " << novo->estadosFinais[x];
            }
            cout << endl << " QUANTIDADE ESTADOS: " << novo->qtEstados << endl;
            cout << " QUANTIDADE ESTADOS FINAIS: " << novo->qtEstFinais<< endl;
            cout << "-----------------------------------------------" << endl << endl;

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
            cout << "-----------------------------------------------" << endl;
            cout << " ALFABETO: " << novo->alfabeto << endl;
            cout << " E. INCIAL: " << novo->estadoInicial << endl;
            cout << " Q. ESTADOS: " << novo->qtEstados << endl;
            cout << " Q. ESTADOS FINAIS: " << novo->qtEstFinais<< endl;
            //cout << " ALFABETO UNIDO: " << unirAlfabetos(a->alfabeto,"") << endl ;
            cout << "-----------------------------------------------" << endl << endl;
            return novo;
        };

        void montadorAutomato(string posTho){
           //stack <AUTOMATO> pilha;
           PILHAAUTOMATO *topo = NULL;

            AUTOMATO *recebe1, *recebe2, *automato;
            for(int x = 0; x < posTho.length(); x++){
                simbolo = posTho[x];

            	if(simbolo != "+" && simbolo != "." && simbolo != "*"){
                    //Chamando a base para gerar a expressão regular que tá nos simbolo o automato
                    empilhar(&topo, Base(simbolo));
                    cout << "Montou a Base" << endl << endl;
                    //listar(topo);
                }
                //Para operador unário Fecho de Kleene
                else if(simbolo == "*"){
                    recebe1 = topo->automato;
                    desempilhar(&topo);
                    cout << "-----------------------------------" << endl;
                    //listar(topo);
                    empilhar(&topo, FechoDeKleene(recebe1));
                    cout << "Entrou aqui Fecho de Kleene" << endl;
                    //listar(topo);
                }
                else if(simbolo == "+" || simbolo == "."){
                    recebe2 = topo->automato;
                    desempilhar(&topo);
                    if(topo != NULL){
                        recebe1 = topo->automato;
                        desempilhar(&topo);
                        if(simbolo == "+"){
                            empilhar(&topo, Concatenacao(recebe1, recebe2));//Chamando concatenação, falta tratar ainda tá incompleta
                            cout << "Entrou aqui Concatenação" << endl;
                        }
                        else if(simbolo == "."){
                            empilhar(&topo, Uniao(recebe1, recebe2));
                            cout << "Entrou aqui União" << endl;
                        }
                    }
                }
                //listar(topo);
            }
        };
};
