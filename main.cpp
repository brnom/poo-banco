#include <iostream>
#include <string>
#include "conta.hpp"
#include "cliente.hpp"

using namespace std;

//contagem do número de contas & clientes
int cContas = 0;
int cClientes = 0;

//array com os ÍNDECES (i) apagados
int apagado[100];
int k=0;
bool busca_apagado(int idx){
    for(int i=0; i<=k; i++){
        if(apagado[i]==idx){
            return false;
        }
    }
    return true;
}
void insere_apagado(int idx){
    apagado[k++]=idx;
}

//funcoes gerais
int validaCpf(cliente *c, long long int cpf){
    for(int i=1 ; i<100; i++){
        if(c[i].getCpf()==cpf && busca_apagado(i)){
            cout<<"CPF JA CADASTRADO!"<<endl;
            return i;
        }
    }
    return 0;
}
int getQuantidadeDeContas(){
	return  cContas;
}
int getQuantidadeDeClientes(){
	return  cClientes;
}
float getMontanteTotal(conta *c){
    float montante;
    for (int i = 0; i <= 100; i++){
        if (busca_apagado(i))
		    montante += c[i].getSaldo();
	}
    return montante;
}


int main(){
    int i=1, //cont
        op=0; //opção da interface
    conta Contas[100];
    cliente Clientes[100];
    long long int cpf;

    while(op!=-1){
        cout << "GERENCIADOR CONTA CORRENTE" << endl;
        cout << "- CADASTRAR CLIENTE [1]" << endl;
        cout << "- CRIAR CONTA [2]" << endl;
        cout << "- VER DADOS [3]" << endl;
        cout << "- DEPOSITO [4]" << endl;
        cout << "- APAGAR CONTA [5]" << endl;
        cout << "- TOTAL DE CLIENTES [6]" << endl;
        cout << "- TOTAL DE CONTAS [7]" << endl;
        cout << "- TOTAL DE MONTANTE [8]" << endl;
        cout << "- NOVO LANCAMENTO [9]" << endl;
        cin >> op;
        cout << endl;

        //CADASTRAR CLIENTE
        if(op==1){
            cout<<"digite cpf: ";
            cin>>cpf;
            int n=validaCpf(Clientes, cpf);
            if(!n){
                Clientes[i].cadastraCliente(cpf);
                cClientes ++;
                i++;
                cout<<"CLIENTE CADASTRADO!"<<endl;
            }
        }

        //CRIAR CONTA
        if(op==2){
            cout<<"digita cpf: ";
            cin >> cpf;

            int n=validaCpf(Clientes, cpf);
            if(n>0){
                Contas[n].novaConta(n);
                cout<<"CONTA ID="<< n <<" CRIADA!"<<endl;
                cContas ++;
            }
            else
                cout<<"CPF NAO EXISTE!"<<endl;
        }

        //VER DADOS
        if(op==3){
            int n;
            cout << "digite o ID da conta: ";
            cin >> n;
            if (busca_apagado(n)){
                Clientes[n].imprimeCliente();
                Contas[n].imprimeConta();
            }
            else
                cout<<"NAO ENCONTRADO!"<<endl;
        }

        //DEPOSITO
        if(op==4){
            int n;
            cout << "digite o ID da conta: ";
            cin >> n;
            if (busca_apagado(n)){
                Contas[n].setSaldo();
            }
            else
                cout<<"NAO ENCONTRADO!"<<endl;
        }

        //APAGAR CONTA
        if(op==5){
            int n;
            cout << "digite o ID da conta: ";
            cin >> n;
            insere_apagado(n);
            cContas--;
            cClientes--;
            cout << "CONTA E CLIENTE APAGADOS!" << endl;
        }

        //TOTAL CLIENTES
        if(op==6){
            cout << "total de clientes: " << getQuantidadeDeClientes() << endl;
        }

        //TOTAL CONTAS
        if(op==7){
            cout << "total de contas: " << getQuantidadeDeContas() << endl;
        }

        //TOTAL MONTANTE
        if(op==8){
            cout << "montante total: R$" << getMontanteTotal(Contas) << endl;
        }

        //NOVO LANCAMENTO
        if(op==9){
            int n;
            cout << "digite o ID da conta: ";
            cin >> n;

            if (busca_apagado(n)){
                Contas[n].setLancamento();
            }
            else
                cout<<"NAO ENCONTRADO!"<<endl;
        }
        
        cout << endl;

    }

    
    return 0;
}