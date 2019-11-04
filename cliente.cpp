//versão 2.0
#include "cliente.hpp"

//validação?????????????????

cliente::cliente(){}

//setters
void cliente::setCpf(){
    int c;
    cout<<"digite cpf:"<<endl;
    cin >> c;
    cpf = c;
}
void cliente::setTelefone(){
    int t;
    cout<<"digite telefone:"<<endl;
    cin >> t;
    telefone = t;
}
void cliente::setNome(){
    string n;
    cout<<"digite nome: ";
    cin >> n;
    nome = n;
}
void cliente::setEmail(){
    string e;
    cout<<"digite email:"<<endl;
    cin >> e;
    email = e;
}
void cliente::setEndereco(){
    string e;
    cout<<"digite endereço:"<<endl;
    cin >> e;
    endereco = e;
}

//getters
int cliente::getCpf(){return cpf;}
int cliente::getTelefone(){return telefone;}
string cliente::getNome(){return nome;}
string cliente::getEndereco(){return endereco;}
string cliente::getEmail(){return email;}