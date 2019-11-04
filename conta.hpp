#ifndef CONTA_H
#define CONTA_H

#include<iostream>
#include <string>
using namespace std;


struct data {
	int dia=0, 
		mes=0,
		ano=0;
};
typedef struct data Data;

class conta{
    public:
        conta();
        //metodos set
        void setId(int);
        void setData();
        void setSaldo();
        void setFatura(bool);
        void setGastoCredito(float);
        void setGastoDebito(float);
        void setLancamento();
        //metodos get
        int getId();
        Data getData();
        float getSaldo();
        float getFatura();
        //data
        Data validaData(int, int, int);
        void imprimeData();
        //conta
        void novaConta(int );
        void imprimeConta();

    private:
        int id;
        Data datum;
        float saldo, fatura;
};

#endif