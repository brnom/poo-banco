//versão 2.0
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
        void setCpf();
        void setTelefone();
        //metodos get
        string getNome();
        string getEmail();
        string getEndereco();
        int getCpf();
        int getTelefone();
        
    private:
        int cpf, telefone;
        string nome, email, endereco;
};

#endif
