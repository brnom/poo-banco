#include "conta.hpp"

conta::conta(){
    saldo=0;
    fatura=0;
}

//SET
void conta::setId(int i){
    id = i;
}
void conta::setData(){
    int d, m, a;
    cout << "digite data (dd mm aaaa): ";
    cin >> d >> m >> a;
    datum = this->validaData(d, m, a);
};
void conta::setSaldo(){
    float s;
    cout << "digita saldo: ";
    cin >> s;
    saldo = s;
};
void conta::setFatura(bool z){
    if(!z)
        fatura=z;
    else{
        float f;
        cout << "digita fatura: ";
        cin >> f;
        fatura = f;
    }
        
};
void conta::setGastoCredito(float gasto){ //adicionar gasto à fatura
    fatura += gasto;
    cout << "LANCAMENTO APROVADO!" << endl <<" NOVA FATURA: R$" << this->getFatura() << endl;
};
void conta::setGastoDebito(float gasto){ //subtrair gasto do saldo
    if(this->getSaldo() < gasto){
    	cout << "SALDO INSUFICIENTE!" << endl;
	}
    else{
        saldo=this->getSaldo()-gasto;
        cout << "LANCAMENTO APROVADO!" << endl <<" NOVO SALDO: R$" << this->getSaldo() << endl;
    }
    
};
void conta::setLancamento(){
    int op=0;
    float valor=0;

    cout << "NOVO LANCAMENTO!" << endl;
    this->setData(); //data do lancamento
    cout << "VALOR: R$"; 
    cin >> valor;

    cout << "CREDITO [1] ou DEBITO [2]? ";
    cin >> op;
    if(op==1)
        setGastoCredito(valor);
    else if(op==2)
        setGastoDebito(valor);
    else
        cout<<"OPCAO INVALIDA!"<<endl;
};

//DATA
Data conta::validaData(int d, int m, int a){
	Data aux;

	//verifica se eh uma data valida
	int limDia=31, limMes=12, limAno=2019;
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
    if (m > limMes)
        m = limMes;
    if (a > limAno || a<1900)
        a = limAno;
	//guarda a data no struct
	aux.dia = d;
	aux.mes = m;
	aux.ano = a;	
	return aux;
};
void conta::imprimeData(){
    Data aux;
    aux = this->getData();
    cout << "CONTA CRIADA EM: " << aux.dia << "/" << aux.mes << "/"<< aux.ano <<endl;
};


//GET
int conta::getId(){return id;};
Data conta::getData(){return datum;};
float conta::getSaldo(){return saldo;};
float conta::getFatura(){return fatura;};


//CONTA
void conta::novaConta(int _id){
    this->setId(_id);
    this->setData();
    this->setSaldo();
    this->setFatura(0);
};
void conta::imprimeConta(){
    cout << "ID: " << this->getId() << endl;
    this->imprimeData();
    cout << "SALDO: R$" << this->getSaldo() << endl;
    cout << "FATURA: R$" << this->getFatura() << endl;
};