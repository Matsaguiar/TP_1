#ifndef ARQUIVAR_H
#define ARQUIVAR_H
#include "abstrata.h"

using namespace std;

class arquivar : public abstrata {
    public:
        arquivar() {}
        virtual ~arquivar() {}
        salvarUsu (string *cpfaux, string *senhaAux, string *numCartaoAux, string *codSegCartaoAux, string *dataValCartaoAux){
            *cpfaux = (string) cpfaux2;
            *senhaAux = (string) senhaAux2;
            *numCartaoAux = (string) numCartaoAux2;
            *codSegCartaoAux = (string) codSegCartaoAux2;
            *dataValCartaoAux = (string) dataValCartaoAux2;
        }
        salvarJogo (string *cpfaux, string *codJogoAux, string *nomeAux, string *codIngAux, string *dataAux, string *horarioAux, string *nomeEstadAux, string *cidadeAux, string *estadoAux, float *preco){
            *cpfaux = (string) cpfaux2;
            *codJogoAux = (string) codJogoAux2;
            *nomeAux = (string) nomeAux2;
            *codIngAux = (string) codIngAux2;
            *dataAux = (string) dataAux2;
            *horarioAux = (string) horarioAux2;
            *nomeEstadAux = (string) nomeEstadAux2;
            *cidadeAux = (string) cidadeAux2;
            *estadoAux = (string) estadoAux2;
            *preco = precoAux2;
        }
};
#endif // ARQUIVAR_H
