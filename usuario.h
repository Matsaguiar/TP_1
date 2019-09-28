#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

using namespace std;

class cadastroUsuario{

public:
    cadastroUsuario(string cpfAux, string senhaAux, string numCartaoAux, string codSegCartaoAux, string dataValCartaoAux);
    string getCPF();
    string getSenha();
    string getNumCartao();
    string getCodSegCartao();
    string getDataValCartao();
    int qtCadIng;

private:
    string cpf;
    string senha;
    string numCartao;
    string codSegCartao;
    string dataValCartao;

    void setCPF(string cpfAux);
    void setSenha(string senhaAux);
    void setNumCartao(string numCartaoAux);
    void setCodSegCartao(string codSegCartaoAux);
    void setDataValCartao(string dataValCartaoAux);
};

string cadastroUsuario::getCPF(){
    return cpf;
}
string cadastroUsuario::getSenha(){
    return senha;
}
string cadastroUsuario::getNumCartao(){
    return numCartao;
}
string cadastroUsuario::getCodSegCartao(){
    return codSegCartao;
}
string cadastroUsuario::getDataValCartao(){
    return dataValCartao;
}

void cadastroUsuario::setCPF(string cpfAux){
    cpf = cpfAux;
}
void cadastroUsuario::setSenha(string senhaAux){
    senha = senhaAux;
}
void cadastroUsuario::setNumCartao(string numCartaoAux){
    numCartao = numCartaoAux;
}
void cadastroUsuario::setCodSegCartao(string codSegCartaoAux){
    codSegCartao = codSegCartaoAux;
}
void cadastroUsuario::setDataValCartao(string dataValCartaoAux){
    dataValCartao = dataValCartaoAux;
}

cadastroUsuario::cadastroUsuario(string cpfAux, string senhaAux, string numCartaoAux, string codSegCartaoAux, string dataValCartaoAux){
    setCPF(cpfAux);
    setSenha(senhaAux);
    setNumCartao(numCartaoAux);
    setCodSegCartao(codSegCartaoAux);
    setDataValCartao(dataValCartaoAux);
}

#endif // USUARIO_H_INCLUDED
