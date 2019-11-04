#include <iostream>
#include <string>
#include "data.hpp"
#include "conta.hpp"
#include "cliente.hpp"

using namespace std;

//contagem do número de contas & clientes
int cContas = 0;
int cClientes = 0;

//funcoes gerais
int getQuantidadeDeContas(){
	return  cContas;
}
int getQuantidadeDeClientes(){
	return  cClientes;
}

int main(){
    cout << "GERENCIADOR CONTA CORRENTE" << endl;
    
    cout << "- TESTE ARQUIVO DATA" << endl;
    conta A;
    A.setData();  
    Data temp = A.getData();
    cout << "dia." << temp.dia << "; mes." << temp.mes << "; ano." << temp.ano << endl;


    cout << "- TESTE CLASSE CLIENTE" << endl;
    cliente Bruno;
    Bruno.setNome();
    cout << "o nome digitado foi = " << Bruno.getNome() << endl;

    cout << "- TESTE CLASSE CONTA" << endl;
    A.setSaldo();
    A.setFatura();
    A.setLancamento();
    
    return 0;
}