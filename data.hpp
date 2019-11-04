#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
using namespace std;

struct data {
	int dia=0, 
		mes=0,
		ano=0;
};
typedef struct data Data;

/* dando algum erro not yet known

Data verificaData(int d, int m, int a, Data datum){
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
	datum.dia = d;
	datum.mes = m;
	datum.ano = a;	
	return datum;	
}
*/
#endif