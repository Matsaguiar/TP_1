#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "usuario.h"

#ifdef _WIN32
    # define CLEAR "cls"
#else
    # define CLEAR "clear"
#endif

using namespace std;

int main(){

    vector <cadastroUsuario> usuarios;

    int operacao, i;
    string cpfAux;
    string senhaAux;

    do{
        system(CLEAR);

        cout << "\n\tVenda de ingressos de jogos de futebol" << endl << endl;
        cout << "   (1)  - Operacao usuario" << endl;
        cout << "   (2)  - Operacao jogo" << endl << endl;
        cout << "   (-1) - Sair do programa" << endl << endl;
        cout << "Digite uma opcao: ";


        cin >> operacao;

        if(operacao == 1){
            system(CLEAR);

            do{
                cout << "\tOperacao usuario\n\n" << endl;
                cout << "   (1)  - Cadastrar usuario" << endl;
                cout << "   (2)  - Descadastrar usuario" << endl;
                cout << "   (0)  - Voltar para o menu" << endl << endl;
                cout << "   (-1) - Sair do programa" << endl << endl;
                cout << "Digite uma opcao: ";

                cin >> operacao;

                if(operacao == 1){
                    cout << "Digite o CPF (sem pontos e sem barra): ";
                    cin >> cpfAux;
                    cout << "Digite sua senha: ";
                    cin >> senhaAux;
                    cadastroUsuario user(cpfAux, senhaAux);
                    usuarios.push_back(user);
                    /*for(i = 0; i < usuarios.size(); i++){
                        cout << "Usuario " << i + 1 << endl;
                        cout << "   CPF..: " << usuarios[i].getCPF() << endl;
                        cout << "   Senha: " << usuarios[i].getSenha() << endl << endl;
                    }
                    system("PAUSE");*/

                }
                if(operacao == 2){

                }


            }while(operacao != 0 && operacao != -1);
        }

        if(operacao == 2){
            system(CLEAR);

            do{
                cout << "\tOperacao jogo\n\n" << endl;
                cout << "   (1)  - Cadastrar jogo" << endl;
                cout << "   (2)  - Descadastrar jogo" << endl;
                cout << "   (3)  - Informacoes de jogos" << endl;
                cout << "   (4)  - Informacao de venda de um jogo" << endl;
                cout << "   (0)  - Voltar para o menu" << endl << endl;
                cout << "   (-1) - Sair do programa" << endl << endl;
                cout << "Digite uma opcao: ";

                cin >> operacao;

                if(operacao == 1){

                }
                if(operacao == 2){

                }
                if(operacao == 3){

                }
                if(operacao == 4){

                }

            }while(operacao != 0 && operacao != -1);
        }
    }while(operacao != -1);

    return 0;
}
