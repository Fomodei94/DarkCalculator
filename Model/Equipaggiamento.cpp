#include<iostream>
#include"Equipaggiamento.h"

using std::cerr; using std::endl;

Equipaggiamento::Equipaggiamento(double p, double u): peso(p), usura(u) {
	if(u >= 100.0 || u < 0.0)//Costruito oggetto con percentuale di usura eccessiva o nulla
	{
		cerr << "Attenzione, costruto un Equipaggiamento con % usura maggiore del 100% oppure negativa. % Automaticamente settata al default 0%." << endl;
		usura=0.0;
	}
	if(p < 0.0) //Costruito oggetto con peso negativo
	{
		cerr << "Attenzione, costruito un Euipaggiamento con peso negativo. Peso riportato al valore di default 0." << endl;
		peso = 0; 
	}
}

//PARTE PROTETTA

double Equipaggiamento::Moltiplicatore(char s) const{
	double ret=0.5; //Valore di default associato ad 'E'
	switch(s)
	{
		case 'E' :
			ret=0.5;
			break;
		case 'D' :
			ret=0.7;
			break;
		case 'C' :
			ret=1.0;
			break;
		case 'B' :
			ret=1.5;
			break;
		case 'A' :
			ret=2.0;
			break;
		case 'S' :
			ret=3.0;
			break;
	}
	return ret;
}

//GETTER

double Equipaggiamento::GetPeso() const {return peso;}
double Equipaggiamento::GetUsura() const {return usura;}

//SETTER

void Equipaggiamento::SetPeso(double x){
	if(x>=0)
		peso=x;
	else
		cerr << "Attenzione, inserito un peso negativo per l'Equipaggiamento. Operazione non valida." << endl;
}

void Equipaggiamento::SetUsura(double x){
	if(x>=0 && x<100)
		usura=x;
	else if(x<0)
		cerr << "Attenzione, inserito una percentuale di usura negativa per l'Equipaggiamento. Operazione non valida." << endl;
	else
		cerr << "Attenzione, inserita una percentuale di usura superiore al 100%. Operazione non valida" << endl;
}

//METODI PROPRI

bool Equipaggiamento::operator==(const Equipaggiamento& e) const{
	return (peso==e.peso) && (usura==e.usura);
}

bool Equipaggiamento::operator!=(const Equipaggiamento& e) const{
	return (peso!=e.peso) || (usura!=e.usura);
}
