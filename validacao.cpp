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
int codSeg(string codSegCartaoAux, int tamanho){
    int validade = 0, i;
    if(tamanho == 3)
        validade+=1;
    else
        return 0;
    for (i = 0; i < tamanho; i++) {
		if (numero(codSegCartaoAux[i]) == 1){
			validade+=1;
		}
	}
	if(validade == 4)
        return 1;
    else
        return 0;
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
	//Se a senha tiver caracter repetido
	for (i = 0; i < (tamanho - 1); i++) {
        int j;
        for(j = (i+1); j < tamanho; j++){
            if (senhaAux[i] == senhaAux[j])
                return 0;
        }
	}
  	//Se a senha tiver 6 caracteres, a validade aumenta uma unidade
	if (tamanho == 6){
		validade+=1;
	}else
        return 0;

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
######################################################################################################################################################*/

int validaCodJogo(string cod){
    int i, ok;
    if (cod.size() != 3)
        return 0;
    for (i = 0; i < 3; i++){
        if (!numero(cod[i]))
            return 0;
    }
    return 1;
}

/*######################################################################################################################################################
######################################################################################################################################################*/

int validaCodIng(string cod){
    int i, ok;
    if (cod.size() != 5)
        return 0;
    for (i = 0; i < 5; i++){
        if (!numero(cod[i]))
            return 0;
    }
    return 1;
}

/*######################################################################################################################################################
######################################################################################################################################################*/

int validaData(string data){
    int i, ok, a1, a2;
    if (data.size() != 8)
        return 0;
    for (i = 0; i < 8; i++){
        if (i != 2 && i != 5){
            if (!numero(cod[i]))
                return 0;
        }
    }
    a1 = ((int)data[0]) * 10;
    a2 = ((int)data[1]) + a1;
    if (a2 > 31 || a2 == 0)
        return 0;

    a1 = ((int)data[3]) * 10;
    a2 = ((int)data[4]) + a1;
    if (a2 > 12 || a2 == 0)
        return 0;

    return 1;
}

/*######################################################################################################################################################
######################################################################################################################################################*/

int validaHora(string hora){
    int i, ok, a1, a2;
    if (hora.size() != 5)
        return 0;
    for (i = 0; i < 5; i++){
        if (i != 2){
            if (!numero(cod[i]))
                return 0;
        }
    }

    a1 = ((int)data[0]) * 10;
    a2 = ((int)data[1]) + a1;
    if (a2 < 7 || a2 > 22)
        return 0;

    a1 = ((int)data[3]) * 10;
    a2 = ((int)data[4]) + a1;
    if (a2 != 0 || a2 != 15 || a2 != 30 || a2 != 45)
        return 0;
    return 1;
}

/*######################################################################################################################################################
######################################################################################################################################################*/



/*######################################################################################################################################################
######################################################################################################################################################*/

int validaNomeJogo(string nome){
    int val = 0, i, letr = 0;
    for (i = 0; nome[i] != '\0'; i++){
        if (maiuscula(nome[i]) || minuscula(nome[i]))
            letr++;
        if (nome[i] == ' ' && nome[i+1] == ' ')
            return 0;

        if (!maiuscula(nome[i]) && !minuscula(nome[i]) && nome[i] != ' ' && !numero(nome[i]))
            return 0;

        if (i >= 20)
            return 0;
    }
    if (letr == 0)
        return 0;
    return 1;
}


/*######################################################################################################################################################
######################################################################################################################################################*/
int dataValCar(string dataValCartaoAux, int tamanho){
    int validade = 0, i;

    if(tamanho == 5){
        validade++;
    }else
        return 0;

    if(dataValCartaoAux[0] == '0'){
        if(dataValCartaoAux[1] >= '1' && dataValCartaoAux[1] <= '9')
            validade++;
        else
            return 0;
    }else if(dataValCartaoAux[0] == '1'){
        if(dataValCartaoAux[1] >= '0' && dataValCartaoAux[1] <= '2')
            validade++;
        else
            return 0;
    }else
        return 0;

    if(dataValCartaoAux[2] == '/')
        validade++;
    else
        return 0;

    if(dataValCartaoAux[3] >='0' && dataValCartaoAux[3]<='9')
        validade++;
    else
        return 0;

    if(dataValCartaoAux[4]>='0' && dataValCartaoAux[4]<='9')
        validade++;
    else
        return 0;

    return 1;

}

/*######################################################################################################################################################
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
##################################################################################################################################################*/

inline bool validaCPF(const int * const cpf){
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
