#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "usuario.h"
#include "jogo.h"
#include "arquivar.h"
#include "validacao.cpp"
#include "abstrata.h"

#ifdef _WIN32
    # define CLEAR "cls"
#else
    # define CLEAR "clear"
#endif

using namespace std;

int main(){

    vector <cadastroUsuario> usuarios;
    vector <cadastroJogo> jogos;
    //vector <string> cpfCompraIngresso;

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
    float precoAux;
    string nomeEstadAux;
    string cidadeAux;
    string estadoAux;
    string cpfMaisCodigo;
    int l = 0;
    char cpfaux2[11];
    char senhaAux2[6];
    char numCartaoAux2[16];
    char codSegCartaoAux2[3];
    char dataValCartaoAux2[5];

    FILE *fd_jog;
    FILE *fd_usu;
    arquivar cc;

    if ((fd_usu = fopen("usuarios.txt", "r")) == NULL){

    } else {
        do {
            fscanf(fd_usu, "%s %s %s %s %s ", &cc.cpfaux2, &cc.senhaAux2, &cc.numCartaoAux2, &cc.codSegCartaoAux2, &cc.dataValCartaoAux2);
            cc.salvarUsu(&cpfAux, &senhaAux, &numCartaoAux, &codSegCartaoAux, &dataValCartaoAux);
            cadastroUsuario user(cpfAux, senhaAux, numCartaoAux, codSegCartaoAux, dataValCartaoAux);
            usuarios.push_back(user);
            (usuarios.back()).qtCadIng = 0;
        } while (!feof(fd_usu));
        fclose(fd_usu);
    }

    if ((fd_jog = fopen("jogos.txt", "r")) == NULL){

    } else {
        i = 0;
            int ingressosDisp;
        do{
            fscanf(fd_jog, "%s %s %s %f %s %s %s %s %s %s %d %s ", &cc.cpfaux2, &cc.nomeAux2, &cc.dataAux2, &cc.precoAux2, &cc.codIngAux2, &cc.cidadeAux2, &cc.estadoAux2, &cc.codJogoAux2, &cc.horarioAux2, &cc.nomeEstadAux2, &ingressosDisp, &cc.cpfIngressos);
            cc.salvarJogo(&cpfAux, &codJogoAux, &nomeAux, &codIngAux, &dataAux, &horarioAux, &nomeEstadAux, &cidadeAux, &estadoAux, &precoAux);
            cadastroJogo jogo(cpfAux, codJogoAux, nomeAux, codIngAux, dataAux, horarioAux, precoAux, nomeEstadAux, cidadeAux, estadoAux);
            jogos.push_back(jogo);
            qtCadIngAux = usuarios[i].qtCadIng;
            qtCadIngAux+=1;
            usuarios[i].qtCadIng = qtCadIngAux;
            jogos[i].qtIngressoDisponivel = ingressosDisp;
            jogos[i].compraCpfIngresso = (string)cc.cpfIngressos;
            cc.cpfIngressos[0] = NULL;
            i++;
        } while (!feof(fd_usu));
        fclose(fd_usu);
    }


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
                    cout << "Informe os numeros do seu cartao de credito sem pontos!" << endl << "Informe os 3 numeros do codigo de seguranca!" << endl << "Informe a data de validade do cartao no formato: MM/AA" << endl << endl;
                    cout << "Informe seu CPF.......................................: ";
                    cin >> cpfAux;
                    ok = 0;
                    for(i = 0; i < usuarios.size(); i++){
                        if (cpfAux == usuarios[i].getCPF()){
                            ok = 1;
                            cout << endl << "\tCPF ja cadastrado!"<< endl << endl << "Aperte <ENTER> para continuar!";
                            break;
                        }
                    }
                    aceito = 0;
                    if(ok == 0){
                        cout << "Informe a senha.......................................: ";
                        cin >> senhaAux;
                        cout << "Informe os numeros do seu cartao de credito...........: ";
                        cin >> numCartaoAux;
                        cout << "Informe o codigo de seguranca do seu cartao de credito: ";
                        cin >> codSegCartaoAux;
                        cout << "Informe a validade do seu cartao de credito...........: ";
                        cin >> dataValCartaoAux;
                        //5234 2143 6620 8316
                        if(verificaCPF(cpfAux) == 1)
                            aceito++;

                        if(senha(senhaAux, (senhaAux.size())) == 1)
                            aceito++;

                        if(cartao(numCartaoAux) == 1)
                            aceito++;

                        if( codSeg(codSegCartaoAux, (codSegCartaoAux.size())) == 1)
                            aceito++;

                        if(dataValCar(dataValCartaoAux, dataValCartaoAux.size()) == 1)
                            aceito++;

                        aceito = 5;
                        if(aceito == 5){
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

                            if(codSeg(codSegCartaoAux, (codSegCartaoAux.size())) == 0)
                                cout << "Codigo de seguranca fora do formato padrao!" << endl;

                            if(dataValCar(dataValCartaoAux, dataValCartaoAux.size()) == 0)
                                cout << "Data de validade do cartao invalido ou fora do formato padrao!" << endl;

                            cout << endl << "\tTente novamente" << endl << endl << "Aperte <ENTER> para continuar!";
                        }
                    }
                    getchar();
                    getchar();
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
                                }else if(usuarios[i].qtCadIng != 0){
                                    cout << endl << "\tNao foi possivel descadastrar usuario, visto que ha um jogo cadastrado nesse CPF" << endl << endl << "Aperte <ENTER> para continuar!";
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

                                                int k;
                                                for(k = 0; k < 11; k++){
                                                    jogos[j].compraCpfIngresso.push_back(cpfAux[k]);
                                                }
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
                cout << "    (4)  - Alterar um jogo" << endl;
                cout << "    (0)  - Voltar para o menu" << endl << endl;
                cout << "   (-1)  - Sair do programa" << endl << endl;
                cout << "Digite uma opcao: ";

                cin >> operacao;

                if(operacao == 1){
                    system(CLEAR);
                    cout << endl << "                           #################################" << endl;
                    cout << "                           ##      Cadastro de Jogo       ##" << endl;
                    cout << "                           #################################" << endl << endl;
                    cout << "OBS.: Cada CPF so pode cadastrar ate 5 jogos." << endl << "Codigo:  3 numeros" << endl << "Nome: 20 caracteres apenas de numeros, letras e espaco; Obrigatorio contar pelo menos uma letra" << endl;
                    cout << "Codigo do ingresso: 5 numeros" << endl << "Data: DD/MM/AA; DD deve estar entre 01 e 31; MM entre 01 e 12; AA entre 00 e 99" << endl << "Horario: HH:MM; HH deve estar entre 07 e 22; MM deve ser 00, 15, 30 ou 45" << endl;
                    cout << "Preco: Deve estar entre 0 e 1000" << endl << "Cidade: 15 caracteres, apenas numeros, letras, espaco e ponto" << endl << "Estado: 2 letras maiusculas" << endl << endl;
                    cout << "Digite seu CPF cadastrado...: ";
                    cin >> cpfAux;

                    ok = 0;
                    for(i = 0; i < usuarios.size(); i++){
                        if (cpfAux == usuarios[i].getCPF()){
                            ok = 1;
                            if(usuarios[i].qtCadIng >= 5){
                                cout << endl << "\tEsse CPF ja atingiu a capacidade maxima de cadastrar jogo!" << endl << endl << "Aperte <ENTER> para continuar!";
                                break;
                            }
                            cout << "Digite sua senha............: ";
                            cin >> senhaAux;
                            if(senhaAux != usuarios[i].getSenha()){
                                cout << endl << "\tErro! Senha incorreta! Nao foi possivel fazer login!" << endl << endl << "Aperte <ENTER> para continuar!";
                                break;
                            }
                            int ok = 1;
                            while (ok){
                                cout << "Informe o codigo do jogo....: ";
                                cin >> codJogoAux;
                                if (validaCodJogo(codJogoAux))
                                    ok = 0;
                                else
                                    cout << "Codigo invalido, insira novamente"<< endl <<endl;
                            }
                            ok = 1;
                            while (ok){
                                cout << "Informe o nome do jogo......: ";
                                cin >> nomeAux;
                                if (validaNomeJogo(nomeAux))
                                    ok = 0;
                                else
                                    cout << "Nome invalido, insira novamente"<< endl <<endl;
                            }
                            ok = 1;
                            while (ok){
                                cout << "Informe o codigo do ingresso: ";
                                cin >> codIngAux;
                                if (validaCodIng(codIngAux))
                                    ok = 0;
                                else
                                    cout << "Codigo invalido, insira novamente"<< endl <<endl;
                            }
                            ok = 1;
                            while (ok){
                                cout << "Informe a data da partida...: ";
                                cin >> dataAux;
                                if (validaData(dataAux))
                                    ok = 0;
                                else
                                    cout << "Data invalida, insira novamente"<< endl <<endl;
                            }
                            ok = 1;
                            while (ok){
                                cout << "Informe o horario da partida: ";
                                cin >> horarioAux;
                                if (validaHora(horarioAux))
                                    ok = 0;
                                else
                                    cout << "Hora invalida, insira novamente"<< endl <<endl;
                            }
                            ok = 1;
                            while (ok){
                                cout << "Informe o preco do ingresso.: ";
                                cin >> precoAux;
                                if (validaPreco(precoAux))
                                    ok = 0;
                                else
                                    cout << "Hora invalida, insira novamente"<< endl <<endl;
                            }
                            cout << "Informe o nome do estadio...: ";
                            cin >> nomeEstadAux;
                            ok = 1;
                            while (ok){
                                cout << "Informe a cidade............: ";
                                cin >> cidadeAux;
                                if (validaCidade(cidadeAux))
                                    ok = 0;
                                else
                                    cout << "Cidade invalida, insira novamente"<< endl <<endl;
                            }
                            ok = 1;
                            while (ok){
                                cout << "Informe o estado............: ";
                                cin >> estadoAux;
                                if (validaEstado(estadoAux))
                                    ok = 0;
                                else
                                    cout << "Estado invalido, insira novamente"<< endl <<endl;
                            }
                            cadastroJogo jogo(cpfAux, codJogoAux, nomeAux, codIngAux, dataAux, horarioAux, precoAux, nomeEstadAux, cidadeAux, estadoAux);
                            jogos.push_back(jogo);
                            qtCadIngAux = usuarios[i].qtCadIng;
                            qtCadIngAux+=1;
                            usuarios[i].qtCadIng = qtCadIngAux;
                            cout << endl << "\tJogo cadastrado com sucesso!" << endl << endl << "Aperte <ENTER> para continuar!";
                        }
                    }
                    if(ok == 0 || usuarios.size() < 1){
                        cout << endl << "\tErro! CPF nao cadastrado! Cadastre seu CPF antes de cadastrar jogo!" << endl << endl << "Aperte <ENTER> para continuar!";
                    }
                    getchar();
                    getchar();
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
                                break;
                            }else{
                                int j, k = 0, ok1 = 0;
                                for(j = 0; j < jogos.size(); j++){
                                    if(jogos[j].getCPF() == cpfAux){
                                        ok1 = 1;
                                        cout << endl << "Jogo...............................: " << k+1 << endl << endl;
                                        cout << "Codigo do jogo.....................: " << jogos[j].getCodJogo() << endl;
                                        cout << "Nome do jogo.......................: " << jogos[j].getNome() << endl;
                                        cout << "Data da partida....................: " << jogos[j].getData() << endl;
                                        cout << "Horario da partida.................: " << jogos[j].getHorario() << endl;
                                        cout << "Estadio da partida.................: " << jogos[j].getEstado() << endl;
                                        cout << "Quantidade de ingressos disponiveis: " << jogos[j].qtIngressoDisponivel << endl;
                                        cout << "=======================================================" << endl << endl;
                                        k++;
                                    }
                                }
                                if(ok1 == 0){
                                    cout << endl << "\tErro! Esse CPF nao cadastrou nenhum jogo!" << endl << endl << "Aperte <ENTER> para continuar!";
                                    break;
                                }
                                cout << "Digite o codigo do jogo que deseja descadastrar: ";
                                cin >> codJogoAux;
                                int ok2 = 0;
                                for(j = 0; j < jogos.size(); j++){
                                    if(jogos[j].getCodJogo() == codJogoAux){
                                        ok2 = 1;
                                        if(jogos[j].qtIngressoDisponivel == 250){
                                            jogos.erase(jogos.begin()+j);
                                            qtCadIngAux = usuarios[i].qtCadIng;
                                            qtCadIngAux-=1;
                                            usuarios[i].qtCadIng = qtCadIngAux;
                                            cout << endl << "\tJogo descadastrado com sucesso!" << endl << endl << "Aperte <ENTER> para continuar!";
                                            break;
                                        }else
                                            cout << "\tErro! Nao foi possivel descadastrar esse jogo, pois ja houve venda de ingresso!" << endl << endl << "Aperte <ENTER> para continuar!";
                                    }
                                }
                                if(ok2 == 0){
                                    cout << "\tCodigo invalido!" << endl << endl << "Aperte <ENTER> para continuar!";
                                    break;
                                }
                            }
                        }
                    }
                    if(ok == 0 || usuarios.size() < 1)
                        cout << endl << "\tErro! CPF nao cadastrado!" << endl << endl << "Aperte <ENTER> para continuar!";

                    getchar();
                    getchar();
                }

                if(operacao == 3){
                    system(CLEAR);
                    cout << endl << "                           #################################" << endl;
                    cout << "                           ##     Informacoes de venda    ##" << endl;
                    cout << "                           #################################" << endl << endl << endl;

                    cout << "Digite seu CPF....: ";
                    cin >> cpfAux;

                    ok = 0;
                    for(i = 0; i < usuarios.size(); i++){
                        if (cpfAux == usuarios[i].getCPF()){
                            ok = 1;
                            cout << "Digite sua senha..: ";
                            cin >> senhaAux;
                            cout << " " << endl << endl;
                            if(senhaAux != usuarios[i].getSenha()){
                                cout << endl << "\tErro! Senha incorreta! Nao foi possivel fazer login!" << endl << endl << "Aperte <ENTER> para continuar!" << endl;
                                getchar();
                                getchar();
                                break;
                            }else{
                                int j, k = 0, cont = 0;
                                for(j = 0; j < jogos.size(); j++){
                                    if(jogos[j].getCPF() == cpfAux){
                                        cout << "Codigo do jogo....: " << jogos[j].getCodJogo() << endl;
                                        cout << "Nome do jogo......: " << jogos[j].getNome() << endl;
                                        cout << "Ingressos vendidos: " << (250 - jogos[j].qtIngressoDisponivel) << endl;
                                        cout << "Compradores: ";

                                        l = jogos[j].compraCpfIngresso.size();
                                        cout << endl;
                                        for(k = 1; k <= l; k++){
                                            cout << jogos[j].compraCpfIngresso[k-1];
                                            if(k%11 == 0 && k > 0)
                                            cout << endl;
                                        }

                                        cout << "=======================================================" << endl << endl;
                                        k++;
                                    }
                                }
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

                if(operacao == 4){
                    system(CLEAR);
                    cout << endl << "                           #################################" << endl;
                    cout << "                           ##      Alteracao de Jogo      ##" << endl;
                    cout << "                           #################################" << endl << endl;
                    cout << "Para alterar um jogo, eh necessario usar o mesmo CPF que foi cadastrado e nenhum ingresso pode ter vendido!" << endl << endl;
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
                                break;
                            }else{
                                int j, k = 0, ok1 = 0;
                                for(j = 0; j < jogos.size(); j++){
                                    if(jogos[j].getCPF() == cpfAux){
                                        ok1 = 1;
                                        cout << endl << "Codigo do jogo.....................: " << jogos[j].getCodJogo() << endl;
                                        cout << "Nome do jogo.......................: " << jogos[j].getNome() << endl;
                                        cout << "Data da partida....................: " << jogos[j].getData() << endl;
                                        cout << "Horario da partida.................: " << jogos[j].getHorario() << endl;
                                        cout << "Estadio da partida.................: " << jogos[j].getEstado() << endl;
                                        cout << "Quantidade de ingressos disponiveis: " << jogos[j].qtIngressoDisponivel << endl;
                                        cout << "=======================================================" << endl << endl;
                                        k++;
                                    }
                                }
                                if(ok1 == 0){
                                    cout << endl << "\tErro! Esse CPF nao cadastrou nenhum jogo!" << endl << endl << "Aperte <ENTER> para continuar!";
                                    break;
                                }
                                cout << "Digite o codigo do jogo que deseja alterar: ";
                                cin >> codJogoAux;
                                int ok2 = 0;
                                for(j = 0; j < jogos.size(); j++){
                                    if(jogos[j].getCodJogo() == codJogoAux){
                                        ok2 = 1;
                                        if(jogos[j].qtIngressoDisponivel == 250){
                                            cout << "Informe o novo nome do jogo......: ";
                                            cin >> nomeAux;
                                            cout << "Informe o novo codigo do ingresso: ";
                                            cin >> codIngAux;
                                            cout << "Informe a nova data da partida...: ";
                                            cin >> dataAux;
                                            cout << "Informe o novo horario da partida: ";
                                            cin >> horarioAux;
                                            cout << "Informe o novo preco do ingresso.: ";
                                            cin >> precoAux;
                                            cout << "Informe o novo nome do estadio...: ";
                                            cin >> nomeEstadAux;
                                            cout << "Informe a nova cidade............: ";
                                            cin >> cidadeAux;
                                            cout << "Informe o novo estado............: ";
                                            cin >> estadoAux;
                                            cadastroJogo jogo(cpfAux, codJogoAux, nomeAux, codIngAux, dataAux, horarioAux, precoAux, nomeEstadAux, cidadeAux, estadoAux);
                                            jogos.insert(jogos.begin()+j, jogo);
                                            jogos.erase(jogos.begin()+j+1);
                                            cout << endl << "\tJogo alterado com sucesso!" << endl << endl << "Aperte <ENTER> para continuar!";
                                            break;
                                        }else
                                            cout << "\tErro! Nao foi possivel alterar esse jogo, pois ja houve venda de ingresso!" << endl << endl << "Aperte <ENTER> para continuar!";
                                    }
                                }
                                if(ok2 == 0){
                                    cout << "\tCodigo invalido!" << endl << endl << "Aperte <ENTER> para continuar!";
                                    break;
                                }
                            }
                        }
                    }
                    if(ok == 0 || usuarios.size() < 1){
                        cout << endl << "\tErro! CPF nao cadastrado!" << endl << endl << "Aperte <ENTER> para continuar!";
                    }
                    getchar();
                    getchar();
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

    fd_usu = fopen("usuarios.txt", "w");
    for(i = 0; i < usuarios.size(); i++){
        fprintf(fd_usu, "%s %s %s %s %s ", usuarios[i].getCPF().c_str(), usuarios[i].getSenha().c_str(), usuarios[i].getNumCartao().c_str(), usuarios[i].getCodSegCartao().c_str(), usuarios[i].getDataValCartao().c_str());
    }
    fclose(fd_usu);

    fd_jog = fopen("jogos.txt", "w");
    for(i = 0; i < jogos.size(); i++){
            fprintf(fd_jog, "%s %s %s %f %s %s %s %s %s %s %d %s ", jogos[i].getCPF().c_str(), jogos[i].getNome().c_str(), jogos[i].getData().c_str(), jogos[i].getPreco(), jogos[i].getCodIng().c_str(), jogos[i].getCidade().c_str(), jogos[i].getEstado().c_str(), jogos[i].getCodJogo().c_str(), jogos[i].getHorario().c_str(), jogos[i].getNomeEstad().c_str(), jogos[i].qtIngressoDisponivel, jogos[i].compraCpfIngresso.c_str());
    }
    fclose(fd_jog);

    return 0;
}
