#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

using namespace std;

class cadastroJogo{

public:
    cadastroJogo(string cpfAux, string codJogoAux, string nomeAux, string codIngAux, string dataAux, string horarioAux, string precoAux, string nomeEstadAux, string cidadeAux, string estadoAux);
    string getCPF();
    string getCodJogo();
    string getNome();
    string getCodIng();
    string getData();
    string getHorario();
    string getPreco();
    string getNomeEstad();
    string getCidade();
    string getEstado();

private:
    string cpf;
    string codJogo;
    string codIng;
    string nome;
    string data;
    string horario;
    string preco;
    string nomeEstad;
    string cidade;
    string estado;

    void setCPF(string cpfAux);
    void setCodJogo(string codJogoAux);
    void setNome(string nomeAux);
    void setCodIng(string codIngAux);
    void setData(string dataAux);
    void setHorario(string horarioAux);
    void setPreco(string precoAux);
    void setNomeEstad(string nomeEstadAux);
    void setCidade(string cidadeAux);
    void setEstado(string estadoAux);
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
string cadastroJogo::getPreco(){
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
void cadastroJogo::setPreco(string precoAux){
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

cadastroJogo::cadastroJogo(string cpfAux, string codJogoAux, string nomeAux, string codIngAux, string dataAux, string horarioAux, string precoAux, string nomeEstadAux, string cidadeAux, string estadoAux){
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
}

#endif // USUARIO_H_INCLUDED
