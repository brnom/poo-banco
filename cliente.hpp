#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
using namespace std;

class cliente{
    public:
        cliente();
        //metodos set
        void setNome();
        void setEmail();
        void setEndereco();
        void setCpf(long long int);
        void setTelefone();
        //metodos get
        string getNome();
        string getEmail();
        string getEndereco();
        long long int getCpf();
        long long int getTelefone();

        //cliente
        void cadastraCliente(long long int);
        void imprimeCliente();
        
    private:
        long long int cpf, telefone;
        string nome, email, endereco;
};

#endif
