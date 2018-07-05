#include<iostream>
#include<typeinfo>
#include"ArmaFisica.h"

using std::cerr; using std::cout; using std::endl;

ArmaFisica::ArmaFisica(double p, double u, double d, int f, int i, char t, char fo, char dx): Arma(p,u,d,f,i), tipoDanno(t), scalingForza(fo), scalingDestrezza(dx){
	if(t!='T' && t!='A' && t!='C') //Rispettivamente "taglio", "affondo" e "contundente"
	{
		cerr << "Attenzione, inserito un Tipo di Danno non valido. Tipo di Danno portato al default 'T' ovvero 'taglio'. Valori validi: 'T', 'C', 'A'" << endl;
		tipoDanno='E';
	}
	if(fo!='E' && fo!='D' && fo!='C' && fo!='B' && fo!='A' && fo!='S')
	{
		cerr << "Attenzione, inserito un valore di Scaling per la Forza non corretto. Valore settato al default 'E'." << endl;
		scalingForza='E';
	}
	if(dx!='E' && dx!='D' && dx!='C' && dx!='B' && dx!='A' && dx!='S')
	{
		cerr << "Attenzione, inserito un valore di Scaling per la Destrezza non corretto. Valore settato al default 'E'." << endl;
		scalingDestrezza='E';
	}
}

//GETTER

char ArmaFisica::GetTipoDanno() const {return tipoDanno;}
char ArmaFisica::GetScalingForza() const {return scalingForza;}
char ArmaFisica::GetScalingDestrezza() const {return scalingDestrezza;}

//SETTER

void ArmaFisica::SetTipoDanno(char x){
	if(x=='T' || x=='A' || x=='C')
		tipoDanno=x;
	else
		cerr << "Attenzione, inserito un valore per il tipo di Danno dell'Arma non valido, quindi non appartenete all'insieme {'A','T','C'}. Operazione non valida" << endl;
}

void ArmaFisica::SetScalingForza(char x){
	if(x=='S' || x=='A' || x=='B' || x=='C' || x=='D' || x=='E')
		scalingForza=x;
	else
		cerr << "Attenzione, inserito un valore per lo scaling della Forza dell'Arma non valido, quindi non appartenete all'insieme {'S','A','B','C','D','E'}. Operazione non valida" << endl;
}

void ArmaFisica::SetScalingDestrezza(char x){
	if(x=='S' || x=='A' || x=='B' || x=='C' || x=='D' || x=='E')
		scalingDestrezza=x;
	else
		cerr << "Attenzione, inserito un valore per lo scaling della Destrezza dell'Arma non valido, quindi non appartenete all'insieme {'S','A','B','C','D','E'}. Operazione non valida" << endl;
}

//OVERRIDE

double ArmaFisica::DannoEffettivo(const Caratteristiche& c) const{
	if(VerificaUsabilita(c))
		return Arma::DannoEffettivo(c) + (Moltiplicatore(scalingForza)*c.GetForza()) + (Moltiplicatore(scalingDestrezza)*c.GetDestrezza());	
	else
	{
		//cerr << "Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Danno pari a 0" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida (Danno pari a 0)");
	}
}

double ArmaFisica::Efficacia(const Caratteristiche& c, Armamento* a) const{
	if(!VerificaUsabilita(c))
	{
		//cerr << "Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Danno pari a 0" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida (Danno pari a 0)");
	}
	//ARMA UTILIZZABILE
	Armatura* aux = dynamic_cast<Armatura*>(a);
	Scudo* temp = dynamic_cast<Scudo*>(a);
	if(aux) //Arma viene utilizzata contro un'armatura
	{
		double incremento=0.0;
		if(tipoDanno=='T')
			incremento = aux->GetDifesaTaglio();
		else if(tipoDanno=='C')
			incremento = aux->GetDifesaContundente();
		else
			incremento = aux->GetDifesaAffondo();
		if((a->GetDifesa()-(a->GetDifesa()*a->GetUsura()/200))+incremento<DannoEffettivo(c))
			return DannoEffettivo(c)-(a->GetDifesa()-(a->GetDifesa()*a->GetUsura()/200))-incremento;
		else
			return 0;
	}
	else if(temp) //Arma utilizzata contro Scudo
	{
		if((temp->GetDifesa()-(temp->GetDifesa()*temp->GetUsura()/200))<DannoEffettivo(c))
			return ((DannoEffettivo(c)-(temp->GetDifesa()-(temp->GetDifesa()*temp->GetUsura()/200)))*(100-temp->GetAssorbimentoFisico())/100.0);
		else 
			return 0;
	}
	else // a e' di tipo dinamico Armamento
	{
		if((a->GetDifesa()-(a->GetDifesa()*a->GetUsura()/200))<DannoEffettivo(c))
			return DannoEffettivo(c) - (a->GetDifesa()-(a->GetDifesa()*a->GetUsura()/200));
		else
			return 0;
	}
}


bool ArmaFisica::operator==(const Equipaggiamento& e) const{
	return typeid(e)==typeid(const ArmaFisica&) && (tipoDanno==(static_cast<const ArmaFisica&>(e).tipoDanno)) && (scalingForza==(static_cast<const ArmaFisica&>(e).scalingForza)) && (scalingDestrezza==(static_cast<const ArmaFisica&>(e).scalingDestrezza)) && Arma::operator==(static_cast<const Arma&>(e));
}

bool ArmaFisica::operator!=(const Equipaggiamento& e) const{
	return typeid(e)!=typeid(const ArmaFisica&) || (tipoDanno!=(static_cast<const ArmaFisica&>(e).tipoDanno)) || (scalingForza!=(static_cast<const ArmaFisica&>(e).scalingForza)) || (scalingDestrezza!=(static_cast<const ArmaFisica&>(e).scalingDestrezza)) || Arma::operator!=(static_cast<const Arma&>(e));
}

void ArmaFisica::Raffina(){
	SetPeso(GetPeso()*8/10); //NB Peso diminuito del 20%
	scalingForza='E';
	switch(scalingDestrezza)
	{
		case 'E' :
			scalingDestrezza='C';
			break;
		case 'D' :
			scalingDestrezza='C';
			break;
		case 'C' :
			scalingDestrezza='B';
			break;
		case 'B' :
			scalingDestrezza='A';
			break;
		case 'A' :
			scalingDestrezza='S';
			break;
		case 'S' :
			break;
	}
}

void ArmaFisica::Riforgia(){
	SetPeso(GetPeso()*12/10); //NB Peso incrementato del 20%
	scalingDestrezza='E';
	switch(scalingForza)
	{
		case 'E' :
			scalingForza='C';
			break;
		case 'D' :
			scalingForza='C';
			break;
		case 'C' :
			scalingForza='B';
			break;
		case 'B' :
			scalingForza='A';
			break;
		case 'A' :
			scalingForza='S';
			break;
		case 'S' :
			break;
	}
}

void ArmaFisica::Cristallizza(){
	scalingForza='E';
	scalingDestrezza='E';
	if(GetUsura()<90.0)
	{
		double aux= (90.0- GetUsura())*2;
		SetUsura(90);
		double temp= GetDannoBase()+(GetDannoBase()*aux/100.0);
		SetDannoBase(temp);
	}
}

double ArmaFisica::Frantuma(const Caratteristiche& c, Equipaggiamento* e) const{
	Armamento* aux= dynamic_cast<Armamento*>(e);
	Arma* temp= dynamic_cast<Arma*>(e);
	if(!VerificaUsabilita(c))
	{
		//cerr << "Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida.");
	}
	if(GetDannoBase()==0)
		return 0;
	if(aux)
	{
		double d= Efficacia(c,aux);
		if(d==0)
			return 0;
		else if(d<(aux->GetDifesa()/2))
		{
			if(scalingForza=='A' || scalingForza=='S')
				return 5.0;
			else
				return 3.0;
		}
		else
		{
			if(scalingForza=='A' || scalingForza=='S')
				return 8.0;
			else
				return 5.0;
		}
	}
	else if(temp)
	{
		if(GetDannoBase()<temp->GetDannoBase() && GetPeso()<temp->GetPeso())
			return 0;
		else
		{
			double d= GetDannoBase()-temp->GetDannoBase();
			if(d<0)
				d=d*(-1);
			if(d==0)
				d=1;
			return d/(GetDannoBase()+temp->GetDannoBase()) * 100;
		}
	}
}

