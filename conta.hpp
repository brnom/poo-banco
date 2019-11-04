#ifndef CONTA_H
#define CONTA_H

#include<iostream>
#include <string>
#include "data.hpp"
using namespace std;


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

    private:
        Data datum;
        float saldo, fatura;
};

#endif