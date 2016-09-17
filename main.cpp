#include <iostream>
#include "Posfixa.cpp"
#include "Thompson.cpp"
using namespace std;

int main(){
    int op;
    string expressao, posTho;
    Posfixa *pos = new Posfixa();
    Thompson *tho = new Thompson();
    
    do{
        cout << "---------------------------------------------------" << endl;
        cout << "\t MENU DE OPÇÃO" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " 1 -- INSERIR EXPRESSÃO " << endl;
        cout << " 2 -- VISUALIZAR O AUTÔMATO " << endl;
        cout << " 0 -- SAIR" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " OPÇÃO: ";
        cin >> op;
        cout << "---------------------------------------------------" << endl;

        switch(op){
            case 1:
                cout << "---------------------------------------------------" << endl;
                cout << "\t INSERÇÃO DA EXPRESSÃO REGULAR" << endl;
                cout << "---------------------------------------------------" << endl;
                cout << " EXPRESSÃO: ";
                cin >> expressao;
                pos->operadoresBinariosVerificacao(expressao);
                posTho = pos->retorno();
                //cout << "TESTE " <<  posTho << endl;
                //tho->testandoExpressao(posTho); // Testando, depois remover
                break;
            case 2:
                cout << "---------------------------------------------------" << endl;
                cout << "\t VISUALIZAÇÃO DO AUTÔMATO" << endl;
                cout << "---------------------------------------------------" << endl;
                break;
            case 0:
                cout << "\tAPLICAÇÃO ENCERRADA COM SUCESSO!" << endl << endl;
                break;
            default:
                cout << "\tOPÇÃO INVÁLIDA, POR FAVOR ESCOLHA UMA VÁLIDA" << endl;
        }

    }while(op != 0);
};
