#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

using namespace std;

class cadastroUsuario{

public:
    cadastroUsuario(string cpfAux, string senhaAux);
    string getCPF();
    string getSenha();

private:
    void setCPF(string cpfAux);
    void setSenha(string senhaAux);
    string cpf;
    string senha;

};

void cadastroUsuario::setCPF(string cpfAux){
    cpf = cpfAux;
}
void cadastroUsuario::setSenha(string senhaAux){
    senha = senhaAux;
}
string cadastroUsuario::getCPF(){
    return cpf;
}
string cadastroUsuario::getSenha(){
    return senha;
}

cadastroUsuario::cadastroUsuario(string cpfAux, string senhaAux){
    setCPF(cpfAux);
    setSenha(senhaAux);
}

#endif // USUARIO_H_INCLUDED
