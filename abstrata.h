#ifndef ABSTRATA_H
#define ABSTRATA_H

using namespace std;

class abstrata{
    public:
        //abstrata();
        //virtual ~abstrata();
        char cpfaux2[12];
        char senhaAux2[7];
        char numCartaoAux2[17];
        char codSegCartaoAux2[4];
        char dataValCartaoAux2[6];
        char codJogoAux2[4];
        char codIngAux2[6];
        char nomeAux2[21];
        char dataAux2[9];
        char horarioAux2[6];
        char cpfIngressos[112];
        float precoAux2;
        char nomeEstadAux2[31];
        char cidadeAux2[16];
        char estadoAux2[3];
        void salvarUsu();
        void salvarJogo();
};

#endif // ABSTRATA_H
