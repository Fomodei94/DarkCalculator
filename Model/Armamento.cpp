#include<iostream>
#include<typeinfo>
#include"Armamento.h"

using std::cerr; using std::endl; using std::cout;

double Armamento::pesoMinimoEquilibrio = 5;

Armamento::Armamento(double p, double u, double d, int v): Equipaggiamento(p,u), difesa(d), vigoreRichiesto(v){
	if(d < 0.0) 
	{
		cerr << "Attenzione, inserito valore di Difesa negativo. Costruito un Armamento di default con difesa pari a 0." << endl;
		difesa= 0;
	}
	if(v<5 || v>99)
	{
		cerr << "Attenzione, inserito un valore di Vigore Richiesto inferiore al minimo consentito (5) oppure superiore al massimo (99). Costruito un Armamento con Vigore Richiesto pari a 5 (Valore di Default)" << endl;
		vigoreRichiesto = 5;
	}
}

//GETTER

double Armamento::GetDifesa() const {return difesa;}
int Armamento::GetVigoreRichiesto() const {return vigoreRichiesto;}

//SETTER

void Armamento::SetDifesa(double x){
	if(x>0)
		difesa=x;
	else
		cerr << "Attenzione:  Inserito un valore negativo per la difesa dell'Armamento. Operazione non valida" << endl;
}

void Armamento::SetVigoreRichiesto(int x){
	if(x>=5 || x<=99)
		vigoreRichiesto=x;
	else if(x<5)
		cerr << "Attenzione:  Inserito un valore inferiore al minimo consentito (5) per il Vigore necessario per equipaggiare l'Armamento. Operazione non valida" << endl;
	else
		cerr << "Attenzione:  Inserito un valore superiore al massimo consentito (99) per il Vigore necessario per equipaggiare l'Armamento. Operazione non valida" << endl;
}

//OVERRIDE

bool Armamento::VerificaUsabilita(const Caratteristiche& c) const{ //IMPLEMENTAZIONE METODO VIRTUALE PURO
	return c.GetVigore() >= vigoreRichiesto;
}

bool Armamento::operator==(const Equipaggiamento& e) const{ //OVERRIDE
	return typeid(e) == typeid(const Armamento&) && Equipaggiamento::operator==(e) && (difesa==(static_cast<const Armamento&>(e)).difesa) && (vigoreRichiesto==(static_cast<const Armamento&>(e)).vigoreRichiesto);
}

bool Armamento::operator!=(const Equipaggiamento& e) const{ //OVERRIDE
	return typeid(e) != typeid(const Armamento&) || Equipaggiamento::operator!=(e) || (difesa!=(static_cast<const Armamento&>(e)).difesa) || (vigoreRichiesto!=(static_cast<const Armamento&>(e)).vigoreRichiesto);
}

//METODI PROPRI

double Armamento::operator+(const Armamento& a) const{
	return difesa + a.difesa;
}

double Armamento::ConfrontaDifesa(const Caratteristiche& c, Armamento* a) const{
	if(!VerificaUsabilita(c))
		//{cerr << "Attenzione: Caratteristiche insufficienti per il primo Armamento. Operazione non valida." << endl; return 0;} VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per il primo Armamento. Operazione non valida.");
	else if(!a->VerificaUsabilita(c))
		//{cerr << "Attenzione: Caratteristiche insufficienti per il secondo Armamento. Operazione non valida." << endl; return 0;}VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per il secondo Armamento. Operazione non valida.");
	else //CARATTERISCHE SUFFICIENTI PER COMPIERE CORRETAMENTE L'OPERAZIONE
	{
		double x = (difesa -(difesa*GetUsura()/200)) - (a->difesa - (a->difesa*a->GetUsura()/200));
		/* VERSIONE DA RIGA DI COMANDO
		if(x==0)
			cout << "La difesa e' pari" << endl;
		else if(x>0)
			cout<< "Il primo Armamento ha una difesa maggiore di " << x << " unita' rispetto al secondo" << endl;
		else
			cout<< "Il secondo Armamento ha una difesa maggiore di " << (-1*x) << " unita' rispetto al primo" << endl;
		*/
		if(x<0) x=-1*x;
		return x;
	}
}

double Armamento::Equilibrio(const Caratteristiche& c) const{
	if(!VerificaUsabilita(c))
	{
		//cerr << "Attenzione: Caratteristiche insuffienti per Equipaggiare l'Armamento in questione. Operazione non valida" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insuffienti per Equipaggiare l'Armamento in questione. Operazione non valida");
	}
	else
	{
		if(GetPeso()<pesoMinimoEquilibrio) //Equipaggiamento leggero
		{
			//cout<< "L'Armamento Equipaggiato, visto lo scarso peso viene considerato come 'Leggero' e dunque non garantisce Equilibrio." << endl; VERSIONE (Piu dettagliata) DA RIGA DI COMANDO
			return 0;
		}
		else
			return 1 + (GetPeso()-pesoMinimoEquilibrio)/3;
	}
}

