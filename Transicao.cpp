#include <string>
#include <vector>

using namespace std;


class Transicao{
	private:
		string origem;
		string destino;
		char simbolo;

	public:
		Transicao(){
			void setOrigem(string);
			void setDestino(string);
			void setSimbolo(char);
			string getOrigem();
			string getDestino();
			char getSimbolo();
		};

		void setOrigem(string origem) {
			this->origem = origem;
		}

		void setDestino(string destino) {
			this->destino = destino;
		}

		void setSimbolo(char simbolo) {
			this->simbolo = simbolo;
		}

		string getOrigem() {
			return origem;
		}

		string getDestino() {
			return destino;
		}

		char getSimbolo() {
			return simbolo;
		}
};
