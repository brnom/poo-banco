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
        void setData();
        void setSaldo();
        void setFatura();
        void setGastoCredito(float);
        void setGastoDebito(float);
        void setLancamento();
        //metodos get
        Data getData();
        float getSaldo();
        float getFatura();
        //data managin
        Data validaData(int, int, int);
        void imprimeData();

    private:
        Data datum;
        float saldo, fatura;
};

#endif