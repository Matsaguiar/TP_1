#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "usuario.h"
#include "validacao.cpp"

#ifdef _WIN32
    # define CLEAR "cls"
#else
    # define CLEAR "clear"
#endif

using namespace std;

int main(){

    vector <cadastroUsuario> usuarios;

    int operacao, i, aceito=0;
    string cpfAux;
    string senhaAux;
    string numCartaoAux;
    string codSegCartaoAux;
    string dataValCartaoAux;

    do{
        system(CLEAR);

        cout << "\n\tVenda de ingressos de jogos de futebol" << endl << endl;
        cout << "    (1)  - Iteracao usuario" << endl;
        cout << "    (2)  - Iteracao jogo" << endl << endl;
        cout << "   (-1) - Sair do programa" << endl << endl;
        cout << "Digite uma opcao: ";


        cin >> operacao;

        if(operacao == 1){
            system(CLEAR);

            do{
                system(CLEAR);
                cout << "\tOperacao usuario\n\n" << endl;
                cout << "    (1)  - Cadastrar usuario" << endl;
                cout << "    (2)  - Descadastrar usuario" << endl;
                cout << "    (0)  - Voltar para o menu" << endl << endl;
                cout << "   (-1) - Sair do programa" << endl << endl;
                cout << "Digite uma opcao: ";

                cin >> operacao;

                if(operacao == 1){
                    system(CLEAR);
                    cout << "Informe seu CPF sem pontos e sem barra!" << endl << "Informe sua senha (com 6 caracteres) que DEVE conter pelo menos 1 letra maiscula, 1 letra minuscula e 1 numero!" << endl;
                    cout << "Informe os numeros do seu cartao de credito sem pontos!" << endl << "Informe a data de validade do cartao no formato: MM/AA" << endl << endl;
                    cout << "Informe seu CPF: ";
                    cin >> cpfAux;
                    cout << "Informe a senha: ";
                    cin >> senhaAux;
                    cout << "Informe os numeros do seu cartao de credito: ";
                    cin >> numCartaoAux;
                    cout << "Informe o codigo de segurança: ";
                    cin >> codSegCartaoAux;
                    cout << "Informe a validade do seu cartao de credito: ";
                    cin >> dataValCartaoAux;

                    if(senha(senhaAux, (senhaAux.size())) == 1){
                        cout << endl << "\tSenha aceita!" << endl;
                        aceito++;
                    }else {
                        cout << endl << "\tSenha nao aceita!" << endl;
                    }

                    if(cartao(numCartaoAux) == 1){
                        cout << endl << "\tCartao aceito!" << endl;
                        aceito++;
                    }else {
                        cout << endl << "\tCartao nao aceito!" << endl;
                    }

                    if(codSegCartaoAux.size() == 3){
                        aceito++;
                        cout << endl << "\tCodigo de seguranca aceito!" << endl;
                    }else {
                        cout << endl << "\tCodigo de seguranca nao aceito!" << endl;
                    }

                    if(aceito == 3){
                        cadastroUsuario user(cpfAux, senhaAux, numCartaoAux, codSegCartaoAux, dataValCartaoAux);
                        usuarios.push_back(user);
                        system(CLEAR);
                        cout << endl << "\tUsuario descadastrado com sucesso!" << endl << endl << "Aperte qualquer botao para continuar!";
                        getchar();
                        getchar();
                    }
                }
                if(operacao == 2){
                    system(CLEAR);
                    for(i = 0; i < usuarios.size(); i++){
                        cout << "Usuario " << i + 1 << endl;
                        cout << "   CPF: " << usuarios[i].getCPF() << endl;
                    }
                    if(usuarios.size() > 0){
                        int du; /*Descadastrar Usuario*/
                        cout << endl << "Digite o numero do usuario que deseja descadastrar: ";
                        cin >> du;
                        cout << endl << "Digite sua senha: ";
                        cin >> senhaAux;
                        du -=1;
                        if (senhaAux == usuarios[du].getSenha()){
                            usuarios.erase(usuarios.begin()+du);
                            system(CLEAR);
                            cout << endl << "\tUsuario descadastrado com sucesso!" << endl << endl << "Aperte qualquer botao para continuar!";
                            getchar();
                            getchar();
                        }else {
                            system(CLEAR);
                            cout << endl << "\tSenha incorreta! Nao foi possivel descadastrar usuario!" << endl << endl << "Aperte qualquer botao para continuar!";
                            getchar();
                            getchar();
                        }
                    }
                    else{
                        system(CLEAR);
                        cout << endl << "\tNao ha usuarios cadastrados!" << endl << endl << "Aperte qualquer botao para continuar!";
                        getchar();
                        getchar();
                    }
                }
            }while(operacao != 0 && operacao != -1);
        }

        if(operacao == 2){
            system(CLEAR);

            do{
                cout << "\tOperacao jogo\n\n" << endl;
                cout << "    (1)  - Cadastrar jogo" << endl;
                cout << "    (2)  - Descadastrar jogo" << endl;
                cout << "    (3)  - Informacoes de jogos" << endl;
                cout << "    (4)  - Informacao de venda de um jogo" << endl;
                cout << "    (0)  - Voltar para o menu" << endl << endl;
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
