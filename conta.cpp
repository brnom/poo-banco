//versão 2.0
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
    datum = this->validaData(d, m, a);
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
Data conta::validaData(int d, int m, int a){
	Data aux;
	//verifica se eh uma data valida
	int limDia = 31;
	bool bissexto = false;
	if (a%100!=0 && a%4==0)
		bissexto = true;
	if(m==4 || m==6 || m==9 || m==11)
		limDia = 30;
	else if (m==2){
		if (bissexto)
			limDia=29;
		else
			limDia=28;
	}
	if (d > limDia)
		d = limDia;
	//guarda a data no struct
	aux.dia = d;
	aux.mes = m;
	aux.ano = a;	
	return aux;
};
void conta::imprimeData(){
    Data aux;
    aux = this->getData();
    cout << "DATA: " << aux.dia << "/" << aux.mes << "/"<< aux.ano <<endl;
};


//GET
Data conta::getData(){return datum;};
float conta::getSaldo(){return saldo;};
float conta::getFatura(){return fatura;};