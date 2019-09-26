#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

using namespace std;

class cadastroJogo{

public:
    cadastroJogo(string codJogoAux, string nomeAux, string codIngAux, string data1Aux, string data2Aux, string horario1Aux, string horario2Aux, string preco1Aux, string preco2Aux, string nomeEstadAux, string cidadeAux, string estadoAux);
    string getCodJogo();
    string getNome();
    string getCodIng();
    string getData1();
    string getData2();
    string getHorario1();
    string getHorario2();
    string getPreco1();
    string getPreco2();
    string getNomeEstad();
    string getCidade();
    string getEstado();

private:
    string codJogo;
    string codIng;
    string nome;
    string data1;
    string data2;
    string horario1;
    string horario2;
    string preco1;
    string preco2;
    string nomeEstad;
    string cidade;
    string estado;
    void setCodJogo(string codJogo);
    void setNome(string nome);
    void setCodIng(string codIng);
    void setData1(string data1);
    void setData2(string data2);
    void setHorario1(string horario1);
    void setHorario2(string horario2);
    void setPreco1(string preco1);
    void setPreco2(string preco2);
    void setNomeEstad(string nomeEstad);
    void setCidade(string cidade);
    void setEstado(string estado);
};

string cadastroJogo::getCodJogo(){
    return codJogo;
}
string cadastroJogo::getCodIng(){
    return codIng;
}
string cadastroJogo::getNome(){
    return nome;
}
string cadastroJogo::getData1(){
    return data1;
}
string cadastroJogo::getData2(){
    return data2;
}
string cadastroJogo::getHorario1(){
    return horario1;
}
string cadastroJogo::getHorario2(){
    return horario2;
}
string cadastroJogo::getPreco1(){
    return preco1;
}
string cadastroJogo::getPreco2(){
    return preco2;
}
string cadastroJogo::getNomeEstad(){
    return nomeEstad;
}
string cadastroJogo::getCidade(){
    return cidade;
}
string cadastroJogo::getEstado(){
    return estado;
}

void cadastroJogo::setCodJogo(string codJogoAux){
    codJogo = codJogoAux;
}
void cadastroJogo::setCodIng(string codIngAux){
    codIng = codIngAux;
}
void cadastroJogo::setNome(string nomeAux){
    nome = nomeAux;
}
void cadastroJogo::setData1(string data1Aux){
    data1 = data1Aux;
}
void cadastroJogo::setData2(string data2Aux){
    data2 = data2Aux;
}
void cadastroJogo::setHorario1(string horario1Aux){
    horario1 = horario1Aux;
}
void cadastroJogo::setHorario2(string horario2Aux){
    horario2 = horario2Aux;
}
void cadastroJogo::setPreco1(string preco1Aux){
    preco1 = preco1Aux;
}
void cadastroJogo::setPreco2(string preco2Aux){
    preco2 = preco2Aux;
}
void cadastroJogo::setNomeEstad(string NomeEstadAux){
    nomeEstad = NomeEstadAux;
}
void cadastroJogo::setCidade(string cidadeAux){
    cidade = cidadeAux;
}
void cadastroJogo::setEstado(string estadoAux){
    estado = estadoAux;
}

cadastroJogo::cadastroJogo(string codJogoAux, string nomeAux, string codIngAux, string data1Aux, string data2Aux, string horario1Aux, string horario2Aux, string preco1Aux, string preco2Aux, string nomeEstadAux, string cidadeAux, string estadoAux){
    setCodJogo(codJogoAux);
    setNome(nomeAux);
    setCodIng(codIngAux);
    setData1(data1Aux);
    setData2(data2Aux);
    setHorario1(horario1Aux);
    setHorario2(horario2Aux);
    setPreco1(preco1Aux);
    setPreco2(preco2Aux);
    setNomeEstad(nomeEstadAux);
    setCidade(cidadeAux);
    setEstado(estadoAux);
}


#endif // USUARIO_H_INCLUDED
