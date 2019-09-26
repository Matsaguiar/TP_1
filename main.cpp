#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "usuario.h"
#include "jogo.h"
#include "validacao.cpp"

#ifdef _WIN32
    # define CLEAR "cls"
#else
    # define CLEAR "clear"
#endif

using namespace std;

int main(){

    vector <cadastroUsuario> usuarios;
    vector <cadastroJogo> jogos;

    int operacao, i, aceito=0;
    string cpfAux;
    string senhaAux;
    string numCartaoAux;
    string codSegCartaoAux;
    string dataValCartaoAux;
    string codJogoAux;
    string codIngAux;
    string nomeAux;
    string data1Aux;
    string data2Aux;
    string horario1Aux;
    string horario2Aux;
    string preco1Aux;
    string preco2Aux;
    string nomeEstadAux;
    string cidadeAux;
    string estadoAux;

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
                    cout << "Informe seu CPF sem pontos, espacos ou tracos!" << endl << "Informe sua senha (com 6 caracteres) que DEVE conter pelo menos 1 letra maiscula, 1 letra minuscula e 1 numero!" << endl;
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

                    if(verificaCPF(cpfAux) == 1)
                        aceito++;

                    if(senha(senhaAux, (senhaAux.size())) == 1)
                        aceito++;

                    if(cartao(numCartaoAux) == 1)
                        aceito++;

                    if(codSegCartaoAux.size() == 3)
                        aceito++;
                    aceito = 4;
                    if(aceito == 4){
                        cadastroUsuario user(cpfAux, senhaAux, numCartaoAux, codSegCartaoAux, dataValCartaoAux);
                        usuarios.push_back(user);
                        //system(CLEAR);
                        cout << endl << "\tUsuario cadastrado com sucesso!" << endl << endl << "Aperte qualquer botao para continuar!";
                    }else {
                        cout << endl << "\tUsuario nao cadastrado!" << endl << endl;

                        if(verificaCPF(cpfAux) == 0)
                            cout << "CPF invalido!" << endl;

                        if(senha(senhaAux, (senhaAux.size())) == 0)
                            cout << "Senha invalida!" << endl;

                        if(cartao(numCartaoAux) == 0)
                            cout << "Numero do cartao de credito invalido!" << endl;

                        if(codSegCartaoAux.size() != 3)
                            cout << "Codigo de seguranca fora do formato padrao!" << endl;
                    }
                    cout << endl << "\tTente novamente" << endl << endl << "Aperte qualquer botao para continuar!";
                    getchar();
                    getchar();
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
                    system(CLEAR);
                    cout << "Informe o codigo do jogo: ";
                    cin >> codJogoAux;
                    cout << "Informe o nome do jogo: ";
                    cin >> nomeAux;
                    cout << "Informe o codigo do ingresso: ";
                    cin >> codIngAux;
                    cout << "Informe a data da primeira partida: ";
                    cin >> data1Aux;
                    cout << "Informe a data da segunda partida: ";
                    cin >> data2Aux;
                    cout << "Informe o horario da primeira partida: ";
                    cin >> horario1Aux;
                    cout << "Informe o horario da segunda partida: ";
                    cin >> horario2Aux;
                    cout << "Informe o preco da primeira partida: ";
                    cin >> preco1Aux;
                    cout << "Informe o preco da segunda partida: ";
                    cin >> preco2Aux;
                    cout << "Informe o nome do estadio: ";
                    cin >> nomeEstadAux;
                    cout << "Informe a cidade: ";
                    cin >> cidadeAux;
                    cout << "Informe o estado: ";
                    cin >> estadoAux;
                    cadastroJogo jogo(codJogoAux, nomeAux, codIngAux, data1Aux, data2Aux, horario1Aux, horario2Aux, preco1Aux, preco2Aux, nomeEstadAux, cidadeAux, estadoAux);
                    jogos.push_back(jogo);
                    cout << endl << "\tUsuario cadastrado com sucesso!" << endl << endl << "Aperte qualquer botao para continuar!";
                    getchar();
                    getchar();
                    system(CLEAR);
                }
                if(operacao == 2){

                }
                if(operacao == 3){
                    system(CLEAR);
                    for(i = 0; i < jogos.size(); i++){
                        cout << "Codigo do jogo: " << jogos[i].getCodJogo() << endl;
                        cout << "Nome do jogo: " << jogos[i].getNome() << endl;
                        cout << "Codigo do ingresso: " << jogos[i].getCodIng() << endl;
                        cout << "Data primeira partida: " << jogos[i].getData1() << endl;
                        cout << "Data segunda partida: " << jogos[i].getData2() << endl;
                        cout << "Horario primeira partida: " << jogos[i].getHorario1() << endl;
                        cout << "Horario segunda partida: " << jogos[i].getHorario2() << endl;
                        cout << "Preco da primeira partida: " << jogos[i].getPreco1() << endl;
                        cout << "Preco da segunda partida: " << jogos[i].getPreco2() << endl;
                        cout << "Nome do estadio: " << jogos[i].getNomeEstad() << endl;
                        cout << "Cidade: " << jogos[i].getCidade() << endl;
                        cout << "Estado: " << jogos[i].getEstado() << endl;
                        cout << " " << endl;
                    }
                    cout << endl << "Aperte qualquer botao para continuar!";
                    getchar();
                    getchar();
                    system(CLEAR);
                }
                if(operacao == 4){

                }

            }while(operacao != 0 && operacao != -1);
        }
    }while(operacao != -1);

    return 0;
}
