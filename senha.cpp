#include <cstdio>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>

using namespace std;

int maiuscula (char a) { //fun��o para descobrir se � maiuscula
    return (a>='A' && a<='Z');
}

int minuscula (char a) { //fun��o para descobrir se � minuscula
	return (a>='a' && a<='z');
}

int numero (char a) { //fun��o para descobrir se � n�mero
	return (a>='0' && a<='9');
}

int caracterEstranho (char a) { //fun��o para determinar se existe um caracter estranho, como espa�o ou pontua��o.
	return (a>='A' && a<'Z') || (a>='a' && a<='z') || (a>='0' && a<='9');
}

/*#######################################################################################################################################################
#########################################################################################################################################################*/
int senha(string senhaAux, int tamanho){
	int validade = 0, i;
  	//an�lise da string de caracter por caracter at� encontrar a primeira letra mai�scula, ao achar e se achar, a vari�vel validade aumenta uma unidade
	for (i = 0; i < tamanho; i++) {
		if (maiuscula(senhaAux[i]) == 1){
			validade+=1;
			break;
		}
	}
  	//an�lise da string de caracter por caracter at� encontrar a primeira letra minuscula, ao achar e se achar, a vari�vel validade aumenta uma unidade
	for (i = 0; i < tamanho; i++) {
		if (minuscula(senhaAux[i]) == 1){
			validade+=1;
			break;
		}
	}
  	//an�lise da string de caracter por caracter at� encontrar um caracter estranho, ao achar e se achar, a vari�vel validade deca� uma unidade
	for (i = 0; i < tamanho; i++) {
		if (caracterEstranho(senhaAux[i]) == 0){
			validade-=1;
			break;
		}else if (i == tamanho-1) {
          	// se n�o encontrar em momento nenhum um caracter estranho at� a �ltima vez do loop, a validade aumenta uma unidadade
			validade+=1;
		}
	}
  	//an�lise da string de caracter por caracter at� encontrar o primeiro n�mero, ao achar e se achar, a vari�vel validade aumenta uma unidade
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

  	//caso o somat�rio da validade resulte em 5, atendeu todos os crit�rios e pode ser considerada com senha valida, sen�o ser� considerada senha invalida
	if (validade == 5){
		//cout <<"Senha valida\n";
		return 1;
	}else{
		//cout << "Senha invalida\n";
		return 0;
	}
}
