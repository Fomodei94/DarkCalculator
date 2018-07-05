#include<iostream>
#include<typeinfo>
#include"Arma.h"

using std::cerr; using std::cout; using std::endl;

Arma::Arma(double p, double u, double d, int f, int i): Equipaggiamento(p,u), dannoBase(d), forzaRichiesta(f), intelligenzaRichiesta(i) {
	if(d < 0) 
	{
		cerr << "Attenzione, inserito valore di Danno negativo. Costruita un'arma dal danno pari a 0" << endl;
		dannoBase= 0;
	}
	if(f<5 || f>99)
	{
		cerr << "Attenzione, inserito un valore di Forza Richiesta inferiore al minimo consentito (5) oppure superiore al massimo (99). Costruita un'arma con Forza Richiesta pari a 5 (Valore di Default)" << endl;
		forzaRichiesta = 5;
	}
	if(i<5 || i>99)
	{
		cerr << "Attenzione, inserito un valore di Intelligenza Richiesta inferiore al minimo consentito (5) oppure superiore al massimo (99). Costruita un'arma con Intelligenza Richiesta pari a 5 (Valore di Default)" << endl;
		intelligenzaRichiesta = 5;
	}
}

//GETTER

double Arma::GetDannoBase() const {return dannoBase;}
int Arma::GetForzaRichiesta() const {return forzaRichiesta;}
int Arma::GetIntelligenzaRichiesta() const {return intelligenzaRichiesta;}

//SETTER

void Arma::SetDannoBase(double x){
	if(x>0)
		dannoBase=x;
	else
		cerr << "Attenzione:  Inserito un valore negativo per il danno dell'Arma. Operazione non valida" << endl;
}

void Arma::SetForzaRichiesta(int x){
	if(x>=5 && x<=99)
		forzaRichiesta=x;
	else if(x<5)
		cerr << "Attenzione:  Inserito un valore inferiore al minimo consentito (5) per la forza richiesta per brandire l'Arma. Operazione non valida" << endl;
	else
		cerr << "Attenzione:  Inserito un valore superiore al massimo consentito (99) per la forza richiesta per brandire l'Arma. Operazione non valida" << endl;
}

void Arma::SetIntelligenzaRichiesta(int x){
	if(x>=5 && x<=99)
		intelligenzaRichiesta=x;
	else if(x<5)
		cerr << "Attenzione:  Inserito un valore inferiore al minimo consentito (5) per l'intelligenza richiesta per brandire l'Arma. Operazione non valida" << endl;
	else
		cerr << "Attenzione:  Inserito un valore superiore al massimo consentito (99) per l'intelligenza richiesta per brandire l'Arma. Operazione non valida" << endl;
}

//OVERRIDE

bool Arma::VerificaUsabilita(const Caratteristiche& c) const{ //IMPLEMENTAZIONE METODO VIRTUALE PURO
	return (forzaRichiesta <= c.GetForza()) && (intelligenzaRichiesta <= c.GetIntelligenza());
}

bool Arma::operator==(const Equipaggiamento& e) const{ //OVERRIDE
	return typeid(e) == typeid(const Arma&) && Equipaggiamento::operator==(e) && (dannoBase==(static_cast<const Arma&>(e)).dannoBase) && (forzaRichiesta==(static_cast<const Arma&>(e)).forzaRichiesta) && (intelligenzaRichiesta==(static_cast<const Arma&>(e)).intelligenzaRichiesta);
}

bool Arma::operator!=(const Equipaggiamento& e) const{ //OVERRIDE
	return typeid(e) != typeid(const Arma&) || Equipaggiamento::operator!=(e) || (dannoBase!=(static_cast<const Arma&>(e)).dannoBase) || (forzaRichiesta!=(static_cast<const Arma&>(e)).forzaRichiesta) || (intelligenzaRichiesta!=(static_cast<const Arma&>(e)).intelligenzaRichiesta);
}

//METODI PROPRI

double Arma::operator+(const Arma& a) const{ //METODO PROPRIO
	return dannoBase+a.dannoBase;
}

double Arma::DannoEffettivo(const Caratteristiche& c) const{
	if(VerificaUsabilita(c))
		return dannoBase - (dannoBase*GetUsura()/200);	
	else
	{
		//cerr << "Caratteristiche insufficienti per brandire l'arma in questione. Danno pari a 0" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida (Danno pari a 0)");
	}
}

double Arma::Efficacia(const Caratteristiche& c, Armamento* a) const{
	if(VerificaUsabilita(c))
		return DannoEffettivo(c) - (a->GetDifesa()-(a->GetDifesa()*a->GetUsura()/200));
	else
	{
		//cerr << "Caratteristiche insufficienti per brandire l'arma in questione. Danno pari a 0" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida (Danno pari a 0)");
	}
}

double Arma::ConfrontaDanno(const Caratteristiche& c, Arma* a) const{
	if(!VerificaUsabilita(c)) //NB POLIMORFO
		//cerr << "Attenzione: Caratteristiche insufficienti per brandire la prima arma. Operazione non valida." << endl; VERSIONE DA RIGA DI COMANDO
		throw("Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida");
	else if(!a->VerificaUsabilita(c))
		//cerr << "Attenzione: Caratteristiche insufficienti per brandire la seconda arma. Operazione non valida." << endl; VERSIONE DA RIGA DI COMANDO
		throw("Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida");
	else //CARATTERISCHE SUFFICIENTI PER COMPIERE CORRETAMENTE L'OPERAZIONE
	{
		double x = DannoEffettivo(c) - a->DannoEffettivo(c); //NB POLIMORFO
		/*if(x==0) VERSIONE DA RIGA DI COMANDO
			cout << "Il danno e' pari" << endl;
		else if(x>0)
			cout<< "La prima arma ha un danno maggiore di " << x << " unita' rispetto alla seconda" << endl;
		else
			cout<< "La seconda arma ha un danno maggiore di " << (-1*x) << " unita' rispetto alla prima" << endl; 
		*/ 
		return x;
	}	
}
