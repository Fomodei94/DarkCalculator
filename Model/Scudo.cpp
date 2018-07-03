#include<iostream>
#include<typeinfo>
#include"Scudo.h"
#include"ArmaFisica.h"
#include"ArmaMagica.h"

using std::cerr; using std::cout; using std::endl;

Scudo::Scudo(double p, double u, double d, int v, double am, double af, int st, char sv): Armamento(p,u,d,v), assorbimentoMagico(am), assorbimentoFisico(af), stabilita(st), scalingVigore(sv){
	if(sv!='E' && sv!='D' && sv!='C' && sv!='B' && sv!='A' && sv!='S')
	{
		cerr << "Attenzione, inserito un valore di Scaling per il Vigore non corretto. Valore settato al default 'E'. Se si desiderma modificare riprovare inserendo un valore compreso tra 'A' ed 'E' oppure 'S'" << endl;
		scalingVigore='E';
	}
	if(am<0 || am>100)
	{
		cerr << "Attenzione: Costruito uno Scudo con Assorbimento Magico negativo oppure superiore al 100%. Valore di Assorbimento Magico settato al default 0%." << endl;
		am=0.0;
	}
	if(af<0 || af>100)
	{
		cerr << "Attenzione: Costruito uno Scudo con Assorbimento Fisico negativo oppure superiore al 100%. Valore di Assorbimento Fisico settato al default 0%." << endl;
		af=0.0;
	}
	if(st<0)
	{
		cerr << "Attenzione: Costruito uno Scudo con valore di Stabilita' negativo. Stabilita' settata al default 0." << endl;
		st=0;
	}
}

//GETTER

double Scudo::GetAssorbimentoMagico() const {return assorbimentoMagico;}
double Scudo::GetAssorbimentoFisico() const {return assorbimentoFisico;}
int Scudo::GetStabilita() const {return stabilita;}
char Scudo::GetScalingVigore() const {return scalingVigore;}

//SETTER

void Scudo::SetAssorbimentoMagico(double x){
	if(x>=0 && x<=100)
		assorbimentoMagico=x;
	else if(x<0)
		cerr << "Attenzione: inserita una percentuale di Assorbimento Magico negativa per lo Scudo. Operazione non valida." << endl;
	else
		cerr << "Attenzione: inserita una percentuale si Assorbimento Magico superiore al 100% per lo Scudo. Operazione non valida" << endl;
}

void Scudo::SetAssorbimentoFisico(double x){
	if(x>=0 && x<=100)
		assorbimentoFisico=x;
	else if(x<0)
		cerr << "Attenzione: inserita una percentuale di Assorbimento Fisico negativa per lo Scudo. Operazione non valida." << endl;
	else
		cerr << "Attenzione: inserita una percentuale si Assorbimento Fisico superiore al 100% per lo Scudo. Operazione non valida" << endl;
}

void Scudo::SetStabilita(int x){
	if(x>0)
		stabilita=x;
	else
		cerr << "Attenzione: inserito un valore per la stabilita' dello Scudo negativo. Operazione non valida" << endl;
}

void Scudo::SetScalingVigore(char x){
	if(x=='S' || x=='A' || x=='B' || x=='C' || x=='D' || x=='E')
		scalingVigore=x;
	else
		cerr << "Attenzione, inserito un valore per lo scaling del Vigore dello Scudo non valido, quindi non appartenete all'insieme {'S','A','B','C','D','E'}. Operazione non valida" << endl;
}

//OVERRIDE

void Scudo::ConfrontaDifesa(const Caratteristiche& c, Armamento* a) const{
	if(!VerificaUsabilita(c))
		cerr << "Caratteristiche insuffienti per il primo Armamento" << endl;
	else if(!a->VerificaUsabilita(c))
		cerr << "Caratteristiche insuffienti per il secondo Armamento" << endl;
	else //CARATTERISCHE SUFFICIENTI PER COMPIERE CORRETAMENTE L'OPERAZIONE
	{
		Scudo* aux= dynamic_cast<Scudo*>(a);
		if(aux)
		{
			double x = (GetDifesa() -(GetDifesa()*GetUsura()/200)) - (a->GetDifesa() - (a->GetDifesa()*a->GetUsura()/200));
			//DIFESA BASE
			if(x==0)
				cout << "La difesa di base dei due Scudi e' pari" << endl;
			else if(x>0)
				cout<< "Il primo Scudo ha una difesa di base maggiore di " << x << " unita' rispetto al secondo" << endl;
			else
				cout<< "Il secondo Scudo ha una difesa di base maggiore di " << (-1*x) << " unita' rispetto al primo" << endl;
			/*
			//ASSORBIMENTO FISICO
			if(assorbimentoFisico > aux->assorbimentoFisico)
				cout<< "Il primo Scudo possiede un maggior assorbimento fisico rispetto al secondo. E' quindi piu' efficace contro Armi Fisiche." << endl;
			else if(assorbimentoFisico < aux->assorbimentoFisico)
				cout<< "Il secondo Scudo possiede un maggior assorbimento fisico rispetto al primo. E' quindi piu' efficace contro Armi Fisiche." << endl;
			else
				cout<< "I due Scudi hanno pari assorbimento fisico." << endl;
			//ASSORBIMENTO MAGICO
			if(assorbimentoMagico > aux->assorbimentoMagico)
				cout<< "Il primo Scudo possiede un maggior assorbimento magico rispetto al secondo. E' quindi piu' efficace contro Armi Magiche." << endl;
			else if(assorbimentoMagico < aux->assorbimentoMagico)
				cout<< "Il secondo Scudo possiede un maggior assorbimento magico rispetto al primo. E' quindi piu' efficace contro Armi Magiche." << endl;
			else
				cout<< "I due Scudi hanno pari assorbimento magico." << endl;
			//STABILITA
			if(stabilita > aux->stabilita)
				cout<< "Il primo Scudo possiede una maggior stabilita' rispetto al secondo. Garantisce cosi' una guardia piu' solida e di conseguenza maggior resistenza contro SpezzaGuardia." << endl;
			else if(stabilita < aux->stabilita)
				cout<< "Il second Scudo possiede una maggior stabilita' rispetto al primo. Garantisce cosi' una guardia piu' solida e di conseguenza maggior resistenza contro SpezzaGuardia." << endl;
			else
				cout<< "I due Scudi hanno pari stabilita'." << endl;
			*/
		}
		else
		{
			cout<<"Attenzione, L'Equipaggiamento di confronto deve essere uno Scudo e non lo e'. In ogni caso a livello di difesa base e' possibile confrontare come segue: " << endl;
			Armamento::ConfrontaDifesa(c,a);
		}
	}
}

bool Scudo::operator==(const Equipaggiamento& e) const{
	return typeid(e)==typeid(const Scudo&) && (assorbimentoFisico==static_cast<const Scudo&>(e).assorbimentoFisico) && (assorbimentoMagico==static_cast<const Scudo&>(e).assorbimentoMagico) && (stabilita==static_cast<const Scudo&>(e).stabilita) && (scalingVigore==static_cast<const Scudo&>(e).scalingVigore) && Armamento::operator==(static_cast<const Armamento&>(e));
}

bool Scudo::operator!=(const Equipaggiamento& e) const{
	return typeid(e)!=typeid(const Scudo&) || (assorbimentoFisico!=static_cast<const Scudo&>(e).assorbimentoFisico) || (assorbimentoMagico!=static_cast<const Scudo&>(e).assorbimentoMagico) || (stabilita!=static_cast<const Scudo&>(e).stabilita) || (scalingVigore!=static_cast<const Scudo&>(e).scalingVigore) || Armamento::operator!=(static_cast<const Armamento&>(e));
}

double Scudo::Equilibrio(const Caratteristiche& c) const{
	if(!VerificaUsabilita(c))
		{cerr << "Attenzione, Caratteristiche insuffienti per equipaggiare lo Scudo. Operazione non valida." << endl; return 0;}
	double aux= Armamento::Equilibrio(c);
	cout<< "Attenzione: Essendo uno scudo questo Armamento garantisce equilibrio solo finche' si puo' mantenere la guardia. Se si desidera capire i limiti di tale guarda si puo' selezionare l'operazione SpezzaGuardia." << endl;
	return aux + (Moltiplicatore(scalingVigore)*c.GetVigore());
}

//METODI PROPRI

double Scudo::Parata(const Caratteristiche& c) const{
	if(!VerificaUsabilita(c))
		{cerr << "Attenzione, Caratteristiche insuffienti per equipaggiare lo Scudo. Operazione non valida." << endl; return 0;}
	double ret= (Moltiplicatore(scalingVigore)*c.GetVigore()) - GetPeso();
	if(ret>100)
		ret=100.0;
	if(ret<0)
		ret=0.0;
	return ret;
}

unsigned int Scudo::SpezzaGuardia(const Caratteristiche& c1, Arma* a, const Caratteristiche& c2) const{
	if(!VerificaUsabilita(c1))
		{cerr << "Attenzione, Caratteristiche insuffienti per equipaggiare lo Scudo. Operazione non valida." << endl; return 0;}
	if(!a->VerificaUsabilita(c2))
		{cerr << "Attenzione, Caratteristice indicate per l'Arma non suffienti per brandirla. Operazione non valida." << endl; return 0;}
	unsigned int ret=0;
	int stamina= c1.CalcolaStamina();
	double consumo=0;
	ArmaFisica* aux = dynamic_cast<ArmaFisica*>(a);
	if(aux)
		consumo= a->DannoEffettivo(c2) - stabilita; //NB Codice Polimorfo
	else
		consumo= a->GetDannoBase() - stabilita;
	if(consumo<0)
		consumo=0;
	while(stamina>0)
	{
		stamina-=consumo;
		if(ret>5)
			consumo+=5;
		ret++;
	}
	return ret;
}

