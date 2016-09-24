#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <cctype>

#include "Automato.cpp"
#include "Transicao.cpp"


using namespace std;

class Thompson{
	public:
		string posTho;
	public:
		Thompson(){
			Automato constroiAutomato(string);
			bool temVazio(string);
			string moveVazio(string);
			bool operando(string);
			bool operando(char);
			bool operadorUnario(string);
			bool operadorBinario(string);
			bool operadorConcatenacao(string);
			bool operadorUniao(string);

			Automato base(char);
			Automato concatenacao(Automato, Automato);
			Automato uniao(Automato, Automato);
			Automato fechoDeKleene(Automato);

			char retiraAspas(string);

			vector<Transicao> uneTransicoes(vector<Transicao>, vector<Transicao>);
			vector<string> uneEstados(vector<string>, vector<string>);
			string uneAlfabetos(string, string);
			bool contemLetra(string, char);

			Automato renomeiaConcatenacaoB(Automato, string);
			Automato renomeiaUniaoA(Automato);
			Automato renomeiaUniaoB(Automato);
			Automato renomeiaUniao(Automato);
			Automato renomeiaFechoA(Automato);
			Automato renomeiaFecho(Automato);
		};


		Automato montadorAutomato(string posTho) {
			stack<Automato> pilha;

			Automato automato, op1, op2;
			string simbolo;

			for (int i = 0; i < posTho.size(); i++) {
				simbolo = posTho[i];

				if (operando(simbolo)){
					pilha.push(base(retiraAspas(simbolo)));
				}
				else if (operadorUnario(simbolo)) {
					op1 = pilha.top();
					pilha.pop();
					pilha.push(fechoDeKleene(op1));
				} else if (operadorBinario(simbolo)) {
					op2 = pilha.top();
					pilha.pop();
					if (!pilha.empty()) {
						op1 = pilha.top();
						pilha.pop();
						if (operadorConcatenacao(simbolo)){
							pilha.push(concatenacao(op1, op2));
						}
						else if (operadorUniao(simbolo))
							pilha.push(uniao(op1, op2));
					}
				}
			}

			automato = pilha.top();
			pilha.pop();

			if (temVazio(posTho))
				automato.setAlfabeto(moveVazio(automato.getAlfabeto()));
			else
				automato.setAlfabeto(automato.getAlfabeto() + "&");

			if (pilha.empty()){
				mostrarAutomato(automato);
				return automato;
			}
		};

		void mostrarAutomato(Automato automato){
			vector<Transicao> transicoes = automato.getTransicoes();
			string origem, texto, simbolo, teste, armazena;
			string aux;


			

			/*aux = automato.getAlfabeto();
			cout << endl << "---------------------------------------------" << endl;
			cout << " ESTADOS" ;
			for (int i = 0; i < aux.size(); i++){
				cout << "   |   " << aux[i];
			}
			cout << endl << "---------------------------------------------" << endl;
			for (int x = 0; x < automato.getNumeroEstados(); x++) {
				if (automato.getEstado(x) == automato.getEstadoInicial()){
					cout << "  ->" << automato.getEstado(x) << "   ";
					cout << "---------------------------------------------" << endl;
				}
				else if (automato.getEstado(x) == automato.getEstadoFinal()){
					cout << "   *" << automato.getEstado(x);
					cout << "---------------------------------------------" << endl;
				}
				else{
                	cout << "    " << automato.getEstado(x);
                	cout << "---------------------------------------------" << endl;
                }
                teste.clear();

				for (int k = 0; k < transicoes.size(); k++) {
                    armazena = automato.getAlfabeto();
					//simbolo = transicoes[k].getSimbolo();
                    if(armazena[x] == transicoes[k].getSimbolo()){
                      	//texto = armazena[k];
						if (transicoes[k].getOrigem() == origem && simbolo == texto){
							teste += transicoes[k].getDestino() + " ";
							cout << " " << transicoes[k].getSimbolo();
	                        //k = transicoes.size()+1;
	                    }
                    }
                }
                if (teste.empty())
					cout << "{ }";
				else
                    cout << "  {" + teste + "}" << endl;
			}
			cout << endl << "---------------------------------------------" << endl;*/


			aux = automato.getAlfabeto();
			cout << endl << "---------------------------------------------" << endl;
			cout << " ESTADOS" ;
			for (int i = 0; i < aux.size(); i++){
				cout << "   |   " << aux[i];
			}
			cout << endl << "---------------------------------------------" << endl;
			for (int x = 0; x < automato.getNumeroTransicoes(); x++) {
				origem = automato.getEstado(x);
				if (automato.getEstado(x) == automato.getEstadoInicial()){
					cout << "  ->" << origem << "    |";
				}
				else if (automato.getEstado(x) == automato.getEstadoFinal()){
					cout << "   *" << origem << "    |";
				}
				else{
                	cout << "    " << origem << "    |";
                }
				
				for (int  j = 0; j < automato.getTamanhoAlfabeto(); j++) {
					teste.clear();

					for (int k = 0; k < transicoes.size(); k++) {
                        armazena = automato.getAlfabeto();
						//simbolo = transicoes[k].getSimbolo();
                        if(armazena[j] == transicoes[k].getSimbolo()){
                        	//texto = armazena[k];
							if (transicoes[k].getOrigem() == origem && simbolo == texto){
								teste += transicoes[k].getDestino() + " ";
								//cout << " " << transicoes[k].getSimbolo();
	                            //k = transicoes.size()+1;
	                        }
                        }
                        /*texto = armazena[k];
						simbolo = transicoes[k].getSimbolo();
						cout << "--------------------------------" << endl;
						cout << "  TEXTO: " << armazena[k];
						cout << "  SIMBOLO: " << simbolo << endl;
						cout << "--------------------------------" << endl;
						if (transicoes[k].getOrigem() == origem && simbolo == texto){
							teste += transicoes[k].getDestino() + " ";
							cout << " ENTRA < " << simbolo << " > ";
                            //k = transicoes.size()+1;
                        }*/

					}
					//cout << "SIMBOLO: " << simbolo << endl << endl;

					if (teste.empty()){
						cout << "  { }  | ";
					}

					else{
                        cout << "  {" + teste + "}" << endl;
					}
                    
                    //teste.clear();
				}
				cout << "---------------------------------------------" << endl;

			}
			cout << endl;
		};




		bool temVazio(string posTho) {
			for (int i = 0; i < posTho.size(); i++)
				if (posTho[i] == '&')
					return true;
			return false;
		}

		string moveVazio(string alfabeto) {
			string aux = "";
			for (int i = 0; i < alfabeto.size(); i++)
				if (alfabeto[i] != '&')
					aux.push_back(alfabeto[i]);
			aux.push_back('&');
			return aux;
		}

		bool operando(string simbolo) {
			for (int i = 0; i < simbolo.size(); i++) {
				if (operadorUnario(simbolo) || operadorBinario(simbolo))
					return false;
			}
			return true;
		}

		bool operando(char simbolo) {
			string simb;
			simb = simbolo;
			if (operadorUnario(simb) || operadorBinario(simb))
				return false;
			return true;
		}

		bool operadorUnario(string simbolo) {
			if (simbolo == "*")
				return true;
			return false;
		}

		bool operadorBinario(string simbolo) {
			if (simbolo == "+" || simbolo == ".")
				return true;
			return false;
		}

		bool operadorConcatenacao(string simbolo) {
			if (simbolo == ".")
				return true;
			return false;
		}

		bool operadorUniao(string simbolo) {
			if (simbolo == "+")
				return true;
			return false;
		}

		Automato base(char simbolo) {
			Automato automato;
			automato.setAlfabeto(simbolo);
			automato.setEstado("q0");
			automato.setEstado("q1");
			automato.setTransicao("q0", "q1", simbolo);
			automato.setEstadoInicial("q0");
			automato.setEstadoFinal("q1");

			return automato;
		}

		Automato concatenacao(Automato a, Automato b) {
			Automato automato;

			b = renomeiaConcatenacaoB(b, a.getEstadoFinal());

			automato.setAlfabeto(uneAlfabetos(a.getAlfabeto(), b.getAlfabeto()));
			automato.setEstados(uneEstados(a.getEstados(), b.getEstados()));
			automato.setTransicoes(uneTransicoes(a.getTransicoes(), b.getTransicoes()));
			automato.setEstadoInicial("q0");
			automato.setEstadoFinal(b.getEstadoFinal());

			automato.setTransicao(a.getEstadoFinal(), b.getEstadoInicial(), '&');

			return automato;
		}

		Automato uniao(Automato a, Automato b) {
			Automato automato;

			a = renomeiaUniaoA(a);
			b = renomeiaUniaoB(b);

			automato.setEstado("inicial");
			automato.setTransicao("inicial", a.getEstadoInicial(), '&');
			automato.setTransicao("inicial", b.getEstadoInicial(), '&');

			automato.adicionaEstados(uneEstados(a.getEstados(), b.getEstados()));
			automato.adicionaTransicoes(uneTransicoes(a.getTransicoes(), b.getTransicoes()));

			automato.setEstado("final");
			automato.setTransicao(a.getEstadoFinal(), "final", '&');
			automato.setTransicao(b.getEstadoFinal(), "final", '&');

			automato.setAlfabeto(uneAlfabetos(a.getAlfabeto(), b.getAlfabeto()));
			automato.setEstadoInicial("inicial");
			automato.setEstadoFinal("final");

			automato = renomeiaUniao(automato);

			return automato;
		}

		Automato fechoDeKleene(Automato a) {
			Automato automato;

			a = renomeiaFechoA(a);

			automato.setEstado("inicial");
			automato.setTransicao("inicial", a.getEstadoInicial(), '&');
			automato.setTransicao("inicial", "final", '&');

			automato.setAlfabeto(a.getAlfabeto());
			automato.adicionaEstados(a.getEstados());
			automato.adicionaTransicoes(a.getTransicoes());

			automato.setEstado("final");
			automato.setTransicao(a.getEstadoFinal(), a.getEstadoInicial(), '&');
			automato.setTransicao(a.getEstadoFinal(), "final", '&');

			automato.setEstadoInicial("inicial");
			automato.setEstadoFinal("final");

			automato = renomeiaFecho(automato);

			return automato;
		}

		char retiraAspas(string simbolo) {
			char letra;

			for (int i = 0; i < simbolo.size(); i++)
				if (simbolo[i] != '\'')
					letra = simbolo[i];

			return letra;
		}

		vector<Transicao> uneTransicoes(vector<Transicao> transicoes1, vector<Transicao> transicoes2) {
			vector<Transicao> transicoes;

			for (int i = 0; i < transicoes1.size(); i++)
				transicoes.push_back(transicoes1[i]);

			for (int i = 0; i < transicoes2.size(); i++)
				transicoes.push_back(transicoes2[i]);

			return transicoes;
		}

		vector<string> uneEstados(vector<string> estados1, vector<string> estados2) {
			vector<string> estados;

			for (int i = 0; i < estados1.size(); i++)
				estados.push_back(estados1[i]);

			for (int i = 0; i < estados2.size(); i++)
				estados.push_back(estados2[i]);

			return estados;
		}

		string uneAlfabetos(string alfabeto1, string alfabeto2) {
			string alfabeto;
			alfabeto = alfabeto1;

			for (int i = 0; i < alfabeto2.size(); i++) {
				if (!contemLetra(alfabeto, alfabeto2[i]))
					alfabeto.push_back(alfabeto2[i]);
			}

			return alfabeto;
		}

		bool contemLetra(string alfabeto, char simbolo) {
			for (int i = 0; i < alfabeto.size(); i++) {
				if (alfabeto[i] == simbolo)
					return true;
			}
			return false;
		}


		Automato renomeiaConcatenacaoB(Automato automato, string estadoFinal) {
			string final = "";
			for (int i = 1; i < estadoFinal.size(); i++)
				final.push_back(estadoFinal[i]);

			int contador = stoi(final);
			contador++;
			string novo, anterior;

			for (int i = 0; i < automato.getNumeroEstados(); i++, contador++) {
				anterior = automato.getEstado(i);
				novo = "q" + to_string(contador);
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		};

		Automato renomeiaUniaoA(Automato automato) {
			string novo, anterior;

			for (int i = 0; i < automato.getNumeroEstados(); i++) {
				anterior = automato.getEstado(i);
				novo = "a" + anterior;
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		}

		Automato renomeiaUniaoB(Automato automato) {
			string novo, anterior;

			for (int i = 0; i < automato.getNumeroEstados(); i++) {
				anterior = automato.getEstado(i);
				novo = "b" + anterior;
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		}

		Automato renomeiaUniao(Automato automato) {
			string novo, anterior;

			for (int i = 0, contador = 0; i < automato.getNumeroEstados(); i++, contador++) {
				anterior = automato.getEstado(i);
				novo = "q" + to_string(contador);
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		}

		Automato renomeiaFechoA(Automato automato) {
			string novo, anterior;

			for (int i = 0; i < automato.getNumeroEstados(); i++) {
				anterior = automato.getEstado(i);
				novo = "a" + anterior;
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		}

		Automato renomeiaFecho(Automato automato) {
			string novo, anterior;

			for (int i = 0, contador = 0; i < automato.getNumeroEstados(); i++, contador++) {
				anterior = automato.getEstado(i);
				novo = "q" + to_string(contador);
				automato.alteraEstado(anterior, novo);
			}

			return automato;
		}
};
