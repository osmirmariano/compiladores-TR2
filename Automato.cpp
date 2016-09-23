#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <iostream>
#include <string>
#include <vector>
#include "Transicao.cpp"


using namespace std;

class Automato {
	private:
		string alfabeto;
		vector<string> estados;
		vector<Transicao> transicoes;
		string estadoInicial;
		string estadoFinal;

	public:
		Automato(){
			void setAlfabeto(string);
			void setAlfabeto(char);
			void setEstados(vector<string>);
			void setEstado(string);
			void setTransicoes(vector<Transicao>);
			void setTransicao(string, string, char);
			void setEstadoInicial(string);
			void setEstadoFinal(string);

			void alteraEstado(string, string);
			void adicionaEstados(vector<string>);
			void adicionaTransicoes(vector<Transicao>);

			string getAlfabeto();
			vector<string> getEstados();
			string getEstado(int);
			vector<Transicao> getTransicoes();
			string getEstadoInicial();
			string getEstadoFinal();

			int getNumeroEstados();
			int getNumeroTransicoes();
			int getTamanhoAlfabeto();
		};

		void setAlfabeto(string alfabeto) {
			this->alfabeto = alfabeto;
		};

		void setAlfabeto(char letra) {
			this->alfabeto.push_back(letra);
		};

		void setEstados(vector<string> estados) {
			this->estados = estados;
		};

		void setEstado(string estado) {
			estados.push_back(estado);
		};

		void setTransicoes(vector<Transicao> transicoes) {
			this->transicoes = transicoes;
		};

		void setTransicao(string origem, string destino, char simbolo) {
			Transicao transicao;
			transicao.setOrigem(origem);
			transicao.setDestino(destino);
			transicao.setSimbolo(simbolo);
			this->transicoes.push_back(transicao);
		};

		void setEstadoInicial(string estadoInicial) {
			this->estadoInicial = estadoInicial;
		};

		void setEstadoFinal(string estadoFinal) {
			this->estadoFinal = estadoFinal;
		};

		void alteraEstado(string antigo, string novo) {
			for (int i = 0; i < estados.size(); i++)
				if (estados[i] == antigo)
					estados[i] = novo;

			for (int i = 0; i < transicoes.size(); i++) {
				if (transicoes[i].getOrigem() == antigo)
					transicoes[i].setOrigem(novo);
				if (transicoes[i].getDestino() == antigo)
					transicoes[i].setDestino(novo);
			}

			if (estadoInicial == antigo)
				estadoInicial = novo;

			if (estadoFinal == antigo)
				estadoFinal = novo;
		};

		void adicionaEstados(vector<string> estados) {
			for (int i = 0; i < estados.size(); i++)
				this->estados.push_back(estados[i]);
		};

		void adicionaTransicoes(vector<Transicao> transicoes) {
			for (int i = 0; i < transicoes.size(); i++)
				this->transicoes.push_back(transicoes[i]);
		};

		string getAlfabeto() {
			return alfabeto;
		};

		vector<string> getEstados() {
			return estados;
		};

		string getEstado(int indice) {
			return estados[indice];
		};

		vector<Transicao> getTransicoes() {
			return transicoes;
		};

		string getEstadoInicial() {
			return estadoInicial;
		};

		string getEstadoFinal() {
			return estadoFinal;
		};

		int getNumeroEstados() {
			return estados.size();
		};

		int getNumeroTransicoes() {
			return transicoes.size();
		};

		int getTamanhoAlfabeto() {
			return alfabeto.size();
		};
};

#endif // AUTOMATO_H