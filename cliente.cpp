#include "cliente.hpp"

cliente::cliente(){}

//SET
/*
void cliente::setCpf(){
    long long int c;
    cout<<"digite cpf: ";
    cin >> c;
    cpf = c;
};*/
void cliente::setCpf(long long int c){
    cpf=c;
};
void cliente::setTelefone(){
    long long int t;
    cout<<"digite telefone: ";
    cin >> t;
    telefone = t;
};
void cliente::setNome(){
    string n;
    cout<<"digite nome: ";
    cin >> n;
    nome = n;
};
void cliente::setEmail(){
    string e;
    cout<<"digite email: ";
    cin >> e;
    email = e;
};
void cliente::setEndereco(){
    string e;
    cout<<"digite endereço: ";
    cin >> e;
    endereco = e;
};

//GET
long long int cliente::getCpf(){return cpf;};
long long int cliente::getTelefone(){return telefone;};
string cliente::getNome(){return nome;};
string cliente::getEndereco(){return endereco;};
string cliente::getEmail(){return email;};

//CLIENTE
void cliente::cadastraCliente(long long int c){
    setNome();
    setCpf(c);
    setTelefone();
    setEmail();
    setEndereco();
};
void cliente::imprimeCliente(){
    cout << "NOME: " << this->getNome() << endl;
    cout << "CPF: " << this->getCpf() << endl;
    cout << "TELEFONE: " << this->getTelefone() << endl;
    cout << "EMAIL: " << this->getEmail() << endl;
    cout << "ENDERECO: " << this->getEndereco() << endl;
};