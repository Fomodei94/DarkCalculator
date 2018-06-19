#include"Caratteristiche.h"

//COSTRUTTORE

Caratteristiche::Caratteristiche(int vit, int en, int vig, int fo, int de, int in, int fe): vitalita(vit), energia(en), vigore(vig), forza(fo), destrezza(de), intelligenza(in), fede(fe){
	if(vit<5)	vitalita=5;
	if(en<5)	energia=5;
	if(vig<5)	vigore=5;
	if(fo<5)	forza=5;
	if(de<5)	destrezza=5;
	if(in<5)	intelligenza=5;
	if(fe<5)	fede=5;
}

//GETTER

int Caratteristiche::GetVitalita() const{return vitalita;}
int Caratteristiche::GetEnergia() const{return energia;}
int Caratteristiche::GetVigore() const{return vigore;}
int Caratteristiche::GetForza() const{return forza;}
int Caratteristiche::GetDestrezza() const{return destrezza;}
int Caratteristiche::GetIntelligenza() const{return intelligenza;}
int Caratteristiche::GetFede() const{return fede;}

//SETTER

void Caratteristiche::SetVitalita(int x){
	if(x>=5 && x<=99)
		vitalita=x;
}

void Caratteristiche::SetEnergia(int x){
	if(x>=5 && x<=99)
		energia=x;
}
		
void Caratteristiche::SetVigore(int x){
	if(x>=5 && x<=99)
		vigore=x;
}
		
void Caratteristiche::SetForza(int x){
	if(x>=5 && x<=99)
		forza=x;
}
		
void Caratteristiche::SetDestrezza(int x){
	if(x>=5 && x<=99)
		destrezza=x;
}
		
void Caratteristiche::SetIntelligenza(int x){
	if(x>=5 && x<=99)
		intelligenza=x;
}
		
void Caratteristiche::SetFede(int x){
	if(x>=5 && x<=99)
		fede=x;
}

//FUNZIONALITA

int Caratteristiche::Livello() const {return vitalita+energia+vigore+forza+destrezza+intelligenza+fede-34;}

int Caratteristiche::CalcolaSalute() const{
	int ret=0, aux=vitalita;
	if(aux<=20)
		return 40*aux;
	ret=40*20;
	aux-=20;
	if(aux<=30)
		return ret+(20*aux);
	ret+=20*30;
	aux-=30;
	return ret+(5*aux);
}
		
int Caratteristiche::CalcolaStamina() const{
	int ret=0, aux=energia;
	if(aux<=20)
		return 10*aux;
	ret=10*20;
	aux-=20;
	if(aux<=30)
		return ret+(5*aux);
	ret+=5*30;
	aux-=30;
	return ret+(2*aux);
}

