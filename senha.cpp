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
