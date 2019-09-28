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

    int operacao, i, ok, aceito;
    int qtCadIngAux;
    string cpfAux;
    string senhaAux;
    string numCartaoAux;
    string codSegCartaoAux;
    string dataValCartaoAux;
    string codJogoAux;
    string codIngAux;
    string nomeAux;
    string dataAux;
    string horarioAux;
    string precoAux;
    string nomeEstadAux;
    string cidadeAux;
    string estadoAux;

    do{
        system(CLEAR);

        cout << endl << "                         ##################################################" << endl;
        cout << "                         ##     Venda de ingressos de jogos de futebol   ##" << endl;
        cout << "                         ##################################################" << endl << endl;
        cout << "    (1)  - Interacao com usuario" << endl;
        cout << "    (2)  - Interacao com jogo" << endl;
        cout << "    (3)  - Informacoes de ingressos a venda" << endl << endl;
        cout << "   (-1)  - Sair do programa" << endl << endl;
        cout << "Digite uma opcao: ";

        cin >> operacao;

        if(operacao == 1){
            system(CLEAR);

            do{
                system(CLEAR);
                cout << endl << "                           #################################" << endl;
                cout << "                           ##     Interacao com Usuario   ##" << endl;
                cout << "                           #################################" << endl << endl;
                cout << "    (1)  - Cadastrar usuario" << endl;
                cout << "    (2)  - Descadastrar usuario" << endl;
                cout << "    (3)  - Comprar ingresso" << endl;
                cout << "    (0)  - Voltar para o menu" << endl << endl;
                cout << "   (-1)  - Sair do programa" << endl << endl;
                cout << "Digite uma opcao: ";

                cin >> operacao;

                if(operacao == 1){
                    system(CLEAR);
                    cout << endl << "                           #################################" << endl;
                    cout << "                           ##     Cadastro de Usuario     ##" << endl;
                    cout << "                           #################################" << endl << endl;
                    cout << "Informe seu CPF sem pontos, espacos ou tracos!" << endl << "Informe sua senha (com 6 caracteres) que DEVE conter pelo menos 1 letra maiscula, 1 letra minuscula e 1 numero!" << endl;
                    cout << "Informe os numeros do seu cartao de credito sem pontos!" << endl << "Informe a data de validade do cartao no formato: MM/AA" << endl << endl;
                    cout << "Informe seu CPF............................: ";
                    cin >> cpfAux;
                    ok = 0;
                    for(i = 0; i < usuarios.size(); i++){
                        if (cpfAux == usuarios[i].getCPF()){
                            ok = 1;
                            cout << endl << "\tCPF ja cadastrado!"<< endl << endl << "Aperte <ENTER> para continuar!";
                            getchar();
                            getchar();
                            break;
                        }
                    }
                    aceito = 0;
                    if(ok == 0){
                        cout << "Informe a senha............................: ";
                        cin >> senhaAux;
                        cout << "Informe os numeros do seu cartao de credito: ";
                        cin >> numCartaoAux;
                        cout << "Informe o codigo de segurança..............: ";
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
                            (usuarios.back()).qtCadIng = 0;
                            cout << endl << "\tUsuario cadastrado com sucesso!" << endl << endl << "Aperte <ENTER> para continuar!";
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

                            cout << endl << "\tTente novamente" << endl << endl << "Aperte <ENTER> para continuar!";
                        }
                        getchar();
                        getchar();
                    }
                }

                if(operacao == 2){
                    system(CLEAR);
                    cout << endl << "                           #################################" << endl;
                    cout << "                           ##    Descadastro de Usuario   ##" << endl;
                    cout << "                           #################################" << endl << endl;

                    if(usuarios.size() < 1){
                        cout << endl << "\tNao ha usuarios cadastrados!" << endl << endl << "Aperte <ENTER> para continuar!";
                    }else{
                        ok = 0;
                        cout << "Digite seu CPF cadastrado: ";
                        cin >> cpfAux;
                        for(i = 0; i < usuarios.size(); i++){
                            if (cpfAux == usuarios[i].getCPF()){
                                ok = 1;
                                cout << "Digite sua senha.........: ";
                                cin >> senhaAux;

                                if(senhaAux != usuarios[i].getSenha()){
                                    cout << endl << "\tSenha incorreta! Nao foi possivel descadastrar usuario!" << endl << endl << "Aperte <ENTER> para continuar!";
                                    break;
                                }else{
                                    usuarios.erase(usuarios.begin()+i);
                                    cout << endl << "\tUsuario descadastrado com sucesso!" << endl << endl << "Aperte <ENTER> para continuar!";
                                }
                            }
                        }
                        if(ok == 0){
                            cout << endl << "\tErro! CPF nao cadastrado!" << endl << endl << "Aperte <ENTER> para continuar!";
                        }
                    }
                    getchar();
                    getchar();
                }

                if(operacao == 3){
                    system(CLEAR);
                    cout << endl << "                           #################################" << endl;
                    cout << "                           ##     Compra de Ingressos     ##" << endl;
                    cout << "                           #################################" << endl << endl;
                    if(jogos.size() > 0){
                        cout << "Para mais detalhes dos ingressos disponiveis, va em 'Informacoes de ingressos a venda'." << endl << endl;
                        cout << "Digite seu CPF cadastrado........................: ";
                        cin >> cpfAux;
                        ok = 0;
                        int okCod = 0;
                        for(i = 0; i < usuarios.size(); i++){ /* i eh o contador do vector usuarios*/
                            if (cpfAux == usuarios[i].getCPF()){
                                ok = 1;
                                cout << "Digite sua senha.................................: ";
                                cin >> senhaAux;
                                if(senhaAux != usuarios[i].getSenha()){
                                    cout << endl << "\tErro! Senha incorreta! Nao foi possivel fazer login!" << endl << endl << "Aperte <ENTER> para continuar!";
                                    break;
                                }else{                    /*Senha correta!*/
                                    int qtIngresso, j;
                                    cout << "Insira o codigo do jogo que se deseja o ingresso.: ";
                                    cin >> codJogoAux;
                                    for(j = 0; j < jogos.size(); j++){ /* j eh o contador do vector jogos*/
                                        if(codJogoAux == jogos[j].getCodJogo()){ /*Verifica o codigo do jogo*/
                                            okCod = 1;
                                            cout << endl << "Quantidade de ingressos disponveis para esse jogo: " << jogos[j].qtIngressoDisponivel << endl << endl;
                                            if(jogos[j].qtIngressoDisponivel < 1){
                                                cout << endl << "Estao esgotados os ingressos para esse jogo!" << endl << endl << "Aperte <ENTER> para continuar!";
                                                break;
                                            }
                                            cout << "Informe a quantidade ingressos que deseja comprar: ";
                                            cin >> qtIngresso;
                                            if(qtIngresso < 1 || jogos[j].qtIngressoDisponivel < qtIngresso){
                                                cout << endl << "\tErro na quantidade de ingresso! Operacao cancelada!" << endl << endl << "Aperte <ENTER> para continuar!";
                                            }else{
                                                cout << endl << "\tIngresso comprado com sucesso!" << endl << endl << "Aperte <ENTER> para continuar!";
                                                jogos[j].qtIngressoDisponivel -=qtIngresso;
                                            }
                                            break;
                                        }
                                    }
                                    if (okCod == 0)
                                        cout << endl << "\tNao ha jogo cadastrado com esse codigo!" << endl << endl << "Aperte <ENTER> para continuar!";
                                }
                            }
                        }
                        if(ok == 0 || usuarios.size() < 1)
                            cout << endl << "\tErro! CPF nao cadastrado! Cadastre seu CPF antes de comprar ingresso!" << endl << endl << "Aperte <ENTER> para continuar!";

                    }else
                        cout << endl << "\tNao ha jogo cadastrado ate o momento!" << endl << endl << "Aperte <ENTER> para continuar!";

                    getchar();
                    getchar();
                }

            }while(operacao != 0 && operacao != -1);
        }

        if(operacao == 2){
            system(CLEAR);

            do{
                system(CLEAR);
                cout << endl << "                           #################################" << endl;
                cout << "                           ##     Interacao com Jogo      ##" << endl;
                cout << "                           #################################" << endl << endl;
                cout << "    (1)  - Cadastrar jogo" << endl;
                cout << "    (2)  - Descadastrar jogo" << endl;
                cout << "    (3)  - Informacao de venda de um jogo" << endl;
                cout << "    (0)  - Voltar para o menu" << endl << endl;
                cout << "   (-1)  - Sair do programa" << endl << endl;
                cout << "Digite uma opcao: ";

                cin >> operacao;

                if(operacao == 1){
                    system(CLEAR);
                    cout << endl << "                           #################################" << endl;
                    cout << "                           ##      Cadastro de Jogo       ##" << endl;
                    cout << "                           #################################" << endl << endl;
                    cout << "OBS.: Cada CPF so pode cadastrar ate 5 jogos." << endl << endl;
                    cout << "Digite seu CPF cadastrado...: ";
                    cin >> cpfAux;

                    ok = 0;
                    for(i = 0; i < usuarios.size(); i++){
                        if (cpfAux == usuarios[i].getCPF()){
                            ok = 1;
                            if(usuarios[i].qtCadIng >= 5){
                                cout << endl << "\tEsse CPF ja atingiu a capacidade maxima de cadastrar jogo!" << endl << endl << "Aperte <ENTER> para continuar!";
                                getchar();
                                getchar();
                                break;
                            }
                            cout << "Digite sua senha............: ";
                            cin >> senhaAux;
                            if(senhaAux != usuarios[i].getSenha()){
                                cout << endl << "\tErro! Senha incorreta! Nao foi possivel fazer login!" << endl << endl << "Aperte <ENTER> para continuar!";
                                getchar();
                                getchar();
                                break;
                            }
                            cout << "Informe o codigo do jogo....: ";
                            cin >> codJogoAux;
                            cout << "Informe o nome do jogo......: ";
                            cin >> nomeAux;
                            cout << "Informe o codigo do ingresso: ";
                            cin >> codIngAux;
                            cout << "Informe a data da partida...: ";
                            cin >> dataAux;
                            cout << "Informe o horario da partida: ";
                            cin >> horarioAux;
                            cout << "Informe o preco do ingresso.: ";
                            cin >> precoAux;
                            cout << "Informe o nome do estadio...: ";
                            cin >> nomeEstadAux;
                            cout << "Informe a cidade............: ";
                            cin >> cidadeAux;
                            cout << "Informe o estado............: ";
                            cin >> estadoAux;
                            cadastroJogo jogo(cpfAux, codJogoAux, nomeAux, codIngAux, dataAux, horarioAux, precoAux, nomeEstadAux, cidadeAux, estadoAux);
                            jogos.push_back(jogo);
                            qtCadIngAux = usuarios[i].qtCadIng;
                            qtCadIngAux+=1;
                            usuarios[i].qtCadIng = qtCadIngAux;
                            cout << endl << "\tJogo cadastrado com sucesso!" << endl << endl << "Aperte <ENTER> para continuar!";
                            getchar();
                            getchar();
                        }
                    }
                    if(ok == 0 || usuarios.size() < 1){
                        cout << endl << "\tErro! CPF nao cadastrado! Cadastre seu CPF antes de cadastrar jogo!" << endl << endl << "Aperte <ENTER> para continuar!";
                        getchar();
                        getchar();
                    }
                }

                if(operacao == 2){
                    system(CLEAR);
                    cout << endl << "                           #################################" << endl;
                    cout << "                           ##     Descadastro de Jogo     ##" << endl;
                    cout << "                           #################################" << endl << endl;
                    cout << "Para descadastrar um jogo, usar o mesmo CPF no qual foi cadastrado!" << endl << endl;
                    cout << "Digite seu CPF....: ";
                    cin >> cpfAux;

                    ok = 0;
                    for(i = 0; i < usuarios.size(); i++){
                        if (cpfAux == usuarios[i].getCPF()){
                            ok = 1;
                            cout << "Digite sua senha..: ";
                            cin >> senhaAux;
                            if(senhaAux != usuarios[i].getSenha()){
                                cout << endl << "\tErro! Senha incorreta! Nao foi possivel fazer login!" << endl << endl << "Aperte <ENTER> para continuar!";
                                getchar();
                                getchar();
                                break;
                            }else{
                                int j, k = 0;
                                for(j = 0; j < jogos.size(); j++){
                                    if(jogos[j].getCPF() == cpfAux){
                                        cout << endl << "Jogo..............: " << k+1 << endl << endl;
                                        cout << "Codigo do jogo....: " << jogos[j].getCodJogo() << endl;
                                        cout << "Nome do jogo......: " << jogos[j].getNome() << endl;
                                        cout << "Data da partida...: " << jogos[j].getData() << endl;
                                        cout << "Horario da partida: " << jogos[j].getHorario() << endl;
                                        cout << "Estadio da partida: " << jogos[j].getEstado() << endl;
                                        cout << "=======================================================" << endl << endl;
                                        k++;
                                    }
                                }
                                cout << "Digite o codigo do jogo que deseja descadastrar: ";
                                cin >> codJogoAux;
                                for(j = 0; j < jogos.size(); j++){
                                    if(jogos[j].getCodJogo() == codJogoAux){
                                        jogos.erase(jogos.begin()+j);
                                        break;
                                    }
                                }
                                cout << endl << "\tJogo descadastrado com sucesso!" << endl << endl << "Aperte <ENTER> para continuar!";
                                getchar();
                                getchar();
                            }
                        }
                    }
                    if(ok == 0 || usuarios.size() < 1){
                        cout << endl << "\tErro! Esse CPF nao cadastrou nenhum jogo!" << endl << endl << "Aperte <ENTER> para continuar!";
                        getchar();
                        getchar();
                    }

                }

                if(operacao == 3){

                }

            }while(operacao != 0 && operacao != -1);
        }

        if(operacao == 3){
            system(CLEAR);

            cout << endl << "                           ###########################################" << endl;
            cout << "                           ##    Informacoes de ingressos a venda   ##" << endl;
            cout << "                           ###########################################" << endl << endl << endl;

            if(jogos.size() > 0){
                for(i = 0; i < jogos.size(); i++){
                    cout << "Codigo do jogo.....................: " << jogos[i].getCodJogo() << endl;
                    cout << "Nome do jogo.......................: " << jogos[i].getNome() << endl;
                    cout << "Data da partida....................: " << jogos[i].getData() << endl;
                    cout << "Horario da partida.................: " << jogos[i].getHorario() << endl;
                    cout << "Preco do ingresso..................: " << jogos[i].getPreco() << endl;
                    cout << "Nome do estadio....................: " << jogos[i].getNomeEstad() << endl;
                    cout << "Cidade.............................: " << jogos[i].getCidade() << endl;
                    cout << "Estado.............................: " << jogos[i].getEstado() << endl;
                    cout << "Quantidade de ingressos disponiveis: " << jogos[i].qtIngressoDisponivel << endl;
                    cout << "=========================================================" << endl;
                }
            }else
                cout << endl << "\tNao ha ingressos disponiveis no momento!" << endl << endl;

            cout << endl << "Aperte <ENTER> para continuar!";
            getchar();
            getchar();
        }

    }while(operacao != -1);

    return 0;
}
