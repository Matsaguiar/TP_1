#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

using namespace std;

class cadastroJogo{

public:
    cadastroJogo(string cpfAux, string codJogoAux, string nomeAux, string codIngAux, string dataAux, string horarioAux, float precoAux, string nomeEstadAux, string cidadeAux, string estadoAux);
    string getCPF();
    string getNome();
    string getData();
    float getPreco();
    string getCodIng();
    string getCidade();
    string getEstado();
    string getCodJogo();
    string getHorario();
    string getNomeEstad();
    int qtIngressoDisponivel;
    string compraCpfIngresso;


private:
    string cpf;
    string nome;
    string data;
    float preco;
    string codIng;
    string cidade;
    string estado;
    string codJogo;
    string horario;
    string nomeEstad;

    void setCPF(string cpfAux);
    void setNome(string nomeAux);
    void setData(string dataAux);
    void setPreco(float precoAux);
    void setCodIng(string codIngAux);
    void setCidade(string cidadeAux);
    void setEstado(string estadoAux);
    void setCodJogo(string codJogoAux);
    void setHorario(string horarioAux);
    void setNomeEstad(string nomeEstadAux);
};

string cadastroJogo::getCPF(){
    return cpf;
}
string cadastroJogo::getCodJogo(){
    return codJogo;
}
string cadastroJogo::getCodIng(){
    return codIng;
}
string cadastroJogo::getNome(){
    return nome;
}
string cadastroJogo::getData(){
    return data;
}
string cadastroJogo::getHorario(){
    return horario;
}
float cadastroJogo::getPreco(){
    return preco;
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

void cadastroJogo::setCPF(string cpfAux){
    cpf = cpfAux;
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
void cadastroJogo::setData(string dataAux){
    data = dataAux;
}
void cadastroJogo::setHorario(string horarioAux){
    horario = horarioAux;
}
void cadastroJogo::setPreco(float precoAux){
    preco = precoAux;
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

cadastroJogo::cadastroJogo(string cpfAux, string codJogoAux, string nomeAux, string codIngAux, string dataAux, string horarioAux, float precoAux, string nomeEstadAux, string cidadeAux, string estadoAux){
    setCPF(cpfAux);
    setCodJogo(codJogoAux);
    setNome(nomeAux);
    setCodIng(codIngAux);
    setData(dataAux);
    setHorario(horarioAux);
    setPreco(precoAux);
    setNomeEstad(nomeEstadAux);
    setCidade(cidadeAux);
    setEstado(estadoAux);
    qtIngressoDisponivel = 250;
}

#endif // USUARIO_H_INCLUDED
