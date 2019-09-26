#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>

using namespace std;

int maiuscula (char a) { //função para descobrir se é maiuscula
    return (a>='A' && a<='Z');
}

int minuscula (char a) { //função para descobrir se é minuscula
	return (a>='a' && a<='z');
}

int numero (char a) { //função para descobrir se é número
	return (a>='0' && a<='9');
}

int caracterEstranho (char a) { //função para determinar se existe um caracter estranho, como espaço ou pontuação.
	return (a>='A' && a<'Z') || (a>='a' && a<='z') || (a>='0' && a<='9');
}

/*#######################################################################################################################################################
#########################################################################################################################################################*/
int senha(string senhaAux, int tamanho){
	int validade = 0, i;
  	//análise da string de caracter por caracter até encontrar a primeira letra maiúscula, ao achar e se achar, a variável validade aumenta uma unidade
	for (i = 0; i < tamanho; i++) {
		if (maiuscula(senhaAux[i]) == 1){
			validade+=1;
			break;
		}
	}
  	//análise da string de caracter por caracter até encontrar a primeira letra minuscula, ao achar e se achar, a variável validade aumenta uma unidade
	for (i = 0; i < tamanho; i++) {
		if (minuscula(senhaAux[i]) == 1){
			validade+=1;
			break;
		}
	}
  	//análise da string de caracter por caracter até encontrar um caracter estranho, ao achar e se achar, a variável validade decaí uma unidade
	for (i = 0; i < tamanho; i++) {
		if (caracterEstranho(senhaAux[i]) == 0){
			validade-=1;
			break;
		}else if (i == tamanho-1) {
          	// se não encontrar em momento nenhum um caracter estranho até a última vez do loop, a validade aumenta uma unidadade
			validade+=1;
		}
	}
  	//análise da string de caracter por caracter até encontrar o primeiro número, ao achar e se achar, a variável validade aumenta uma unidade
	for (i = 0;i < tamanho; i++) {
		if (numero(senhaAux[i]) == 1){
			validade+=1;
			break;
		}
	}
  	//Se a senha tiver 6 caracteres, a validade aumenta uma unidade
	if (tamanho == 6){
		validade+=1;
	}

  	//caso o somatório da validade resulte em 5, atendeu todos os critérios e pode ser considerada com senha valida, senão será considerada senha invalida
	if (validade == 5){
		//cout <<"Senha valida\n";
		return 1;
	}else{
		//cout << "Senha invalida\n";
		return 0;
	}
}
/*######################################################################################################################################################
########################################################################################################################################################
########################################################################################################################################################
########################################################################################################################################################
######################################################################################################################################################*/
#include <bits/stdc++.h>

// Returns true if given card number is valid
bool checkLuhn(string cardNo){
	int nDigits = cardNo.length();

	int nSum = 0, isSecond = false;
	for (int i = nDigits - 1; i >= 0; i--) {

		int d = cardNo[i] - '0';

		if (isSecond == true)
			d = d * 2;

		// We add two digits to handle
		// cases that make two digits after
		// doubling
		nSum += d / 10;
		nSum += d % 10;

		isSecond = !isSecond;
	}
	return (nSum % 10 == 0);
}

// Driver code
int cartao(string cardNo){

	//string cardNo = "4975230016422686";
	if (checkLuhn(cardNo)){
		return 1;
	}else{
		return 0;
	}
}

/*##################################################################################################################################################
####################################################################################################################################################
##################################################################################################################################################*/

inline bool validaCPF(const int * const cpf)
{
    int digito1, digito2, temp = 0;

    for(char i = 0; i < 9; i++)
        temp += (cpf[i] * (10 - i));

    temp %= 11;

    if(temp < 2)
        digito1 = 0;
    else
        digito1 = 11 - temp;

    temp = 0;
    for(char i = 0; i < 10; i++)
        temp += (cpf[i] * (11 - i));

    temp %= 11;

    if(temp < 2)
        digito2 = 0;
    else
        digito2 = 11 - temp;

    if(digito1 == cpf[9] && digito2 == cpf[10])
        return true;
    else
        return false;
}

int verificaCPF(string cpfAux){

    if(cpfAux.size() != 11){
        return 0;
    }

    int cpf[11];
    string input;

    input = cpfAux;

    for(char i = 0; i < 11; i++)
    {
        cpf[i] = static_cast<int>(input[i] - 48); //Convertendo char para valor absoluto segundo tabela ASCII e passando para array de inteiros//

        if(cpf[i] < 0 || cpf[i] > 9){ //Validando a entrada de dados
            cout << "ENTRADA INVALIDA" << endl;
            return 1;}
    }

    if(validaCPF(cpf) == true){
        return 1;
    }else{
        return 0;
    }
}


