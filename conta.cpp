//versão 2.0
#include "data.hpp"
#include "conta.hpp"


conta::conta(){
    saldo=0;
    fatura=0;
}

//SET
void conta::setData(){
    cout << "digite data (dd mm aaaa): ";
    int d, m, a;
    cin >> d >> m >> a;
    //verificaData(d, m, a, datum); //ta dando algum erro sla pq
    datum.dia=d;
    datum.mes=m;
    datum.ano=a;
};
void conta::setSaldo(){
    float s;
    cout << "digita saldo: ";
    cin >> s;
    saldo = s;
};
void conta::setFatura(){
    float f;
    cout << "digita fatura: ";
    cin >> f;
    fatura = f;
};
void conta::setGastoCredito(float gasto){ //adicionar gasto à fatura
    fatura += gasto;
    cout << "Lancamento aprovado! Nova fatura: R$" << this->getFatura() << endl;
};
void conta::setGastoDebito(float gasto){ //subtrair gasto do saldo
    if(this->getSaldo() < gasto){
    	cout << "Saldo insuficiente!" << endl;
	}
    else{
        saldo=this->getSaldo()-gasto;
        cout << "Lancamento aprovado! Novo saldo: R$" << this->getSaldo() << endl;
    }
    
};
void conta::setLancamento(){
    int op=0;
    float valor=0;

    cout << "NOVO LANCAMENTO!" << endl;
    this->setData(); //data do lancamento
    cout << "digite valor gasto: "; 
    cin >> valor;

    cout << "credito [1] ou debito [2]? ";
    cin >> op;
    if(op==1)
        setGastoCredito(valor);
    else if(op==2)
        setGastoDebito(valor);
    else
        cout<<"opcao invalida.."<<endl;
};


//GET
Data conta::getData(){return datum;};
float conta::getSaldo(){return saldo;};
float conta::getFatura(){return fatura;};