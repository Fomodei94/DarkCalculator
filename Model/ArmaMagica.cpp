#include<iostream>
#include<typeinfo>
#include"ArmaMagica.h"

using std::cerr; using std::cout; using std::endl;

ArmaMagica::ArmaMagica(double p, double u, double d, int f, int i, double fu, double ma, double el, double os, char in, char fe): Arma(p,u,d,f,i), fuoco(fu), magico(ma), elettrico(el), oscuro(os), scalingIntelligenza(in), scalingFede(fe){
	if(fu<0 || fu>100) 
	{
		cerr << "Attenzione: Inserito un valore di percentuale danno da Fuoco dell'Arma negativo o superiore al 100%. Costruita un'Arma Magica con percentuale di Danno da Fuoco pari al 25% (Valore di Default)" << endl;
		fuoco=25.0;
	}

	if(ma<0 || ma>100) 
	{
		cerr << "Attenzione: Inserito un valore di percentuale danno da Magia dell'Arma negativo o superiore al 100%. Costruita un'Arma Magica con percentuale di Danno da Magia pari al 25% (Valore di Default)" << endl;
		magico=25.0;
	}

	if(el<0 || el>100) 
	{
		cerr << "Attenzione: Inserito un valore di percentuale danno Elettrico dell'Arma negativo o superiore al 100%. Costruita un'Arma Magica con percentuale di Danno Elettrico pari al 25% (Valore di Default)" << endl;
		elettrico=25.0;
	}
		
	if(os<0 || os>100) 
	{
		cerr << "Attenzione: Inserito un valore di percentuale danno da Oscurita' dell'Arma negativo o superiore al 100%. Costruita un'Arma Magica con percentuale di Danno da Oscurita' pari al 25% (Valore di Default)" << endl;
		oscuro=25.0;
	}
		
	if(fuoco+magico+elettrico+oscuro!=100.0)
	{
		cerr << "Attenzione: Le percentuali di danno 'fuoco', 'magico', 'elettrico' e 'oscuro' devono totalizzare la somma 100% se sommate. Sono stati inseriti valori non corretti in tal senso. Riportato al default 25% per ogni tipo di danno" << endl;
		fuoco=magico=elettrico=oscuro=25.0;
	}
	if(in!='E' && in!='D' && in!='C' && in!='B' && in!='A' && in!='S')
	{
		cerr << "Attenzione, inserito un valore di Scaling per l'intelligenza non corretto. Valore settato al default 'E'." << endl;
		scalingIntelligenza='E';
	}
	if(fe!='E' && fe!='D' && fe!='C' && fe!='B' && fe!='A' && fe!='S')
	{
		cerr << "Attenzione, inserito un valore di Scaling per la Fede non corretto. Valore settato al default 'E'." << endl;
		scalingFede='E';
	}
}

//GETTER

double ArmaMagica::GetMagico() const {return magico;}
double ArmaMagica::GetFuoco() const {return fuoco;}
double ArmaMagica::GetElettrico() const {return elettrico;}
double ArmaMagica::GetOscuro() const {return oscuro;}
char ArmaMagica::GetScalingIntelligenza() const {return scalingIntelligenza;}
char ArmaMagica::GetScalingFede() const {return scalingFede;}
		
//SETTER

void ArmaMagica::SetFuoco(double x){
	if(x<0 || x>100)
		cerr << "Attenzione: Inserito un valore di percentuale danno da Fuoco dell'Arma negativo o superiore al 100%. Operazione non valida" << endl;
	else
		fuoco=x;
}

void ArmaMagica::SetMagico(double x){
	if(x<0 || x>100)
		cerr << "Attenzione: Inserito un valore di percentuale danno Magico dell'Arma negativo o superiore al 100%. Operazione non valida" << endl;
	else
		magico=x;
}

void ArmaMagica::SetElettrico(double x){
	if(x<0 || x>100)
		cerr << "Attenzione: Inserito un valore di percentuale danno Elettrico dell'Arma negativo o superiore al 100%. Operazione non valida" << endl;
	else
		elettrico=x;
}

void ArmaMagica::SetOscuro(double x){
	if(x<0 || x>100)
		cerr << "Attenzione: Inserito un valore di percentuale danno Oscuro dell'Arma negativo o superiore al 100%. Operazione non valida" << endl;
	else
		oscuro=x;
}

void ArmaMagica::SetScalingFede(char x){
	if(x=='S' || x=='A' || x=='B' || x=='C' || x=='D' || x=='E')
		scalingFede=x;
	else
		cerr << "Attenzione: inserito un valore per lo scaling della Fede dell'Arma non valido, quindi non appartenete all'insieme {'S','A','B','C','D','E'}. Operazione non valida" << endl;
}

void ArmaMagica::SetScalingIntelligenza(char x){
	if(x=='S' || x=='A' || x=='B' || x=='C' || x=='D' || x=='E')
		scalingIntelligenza=x;
	else
		cerr << "Attenzione: inserito un valore per lo scaling dell'intelligenza dell'Arma non valido, quindi non appartenete all'insieme {'S','A','B','C','D','E'}. Operazione non valida" << endl;
}

//OVERRIDE

bool ArmaMagica::VerificaUsabilita(const Caratteristiche& c) const{
	double percentuale= fuoco+magico+elettrico+oscuro;
	if(percentuale!=100)
	{
		/* VERSIONE RIGA DI COMANDO
		cerr << "Attenzione: Le percentuali di danno dell'arma non sono corrette in quanto la somma e' diversa dal 100%" << endl;
		return false;
		*/
		throw("Attenzione: Le percentuali di danno dell'arma non sono corrette in quanto la somma e' diversa dal 100%. Arma NON Utilizzabile.");
	}
	return Arma::VerificaUsabilita(c);
}

double ArmaMagica::DannoEffettivo(const Caratteristiche& c) const{
	if(!VerificaUsabilita(c))
	{
		//cerr << "Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Danno pari a 0" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida (Danno pari a 0)");
	}
	return Arma::DannoEffettivo(c) + (Moltiplicatore(scalingIntelligenza)*c.GetIntelligenza()*magico/100) + (Moltiplicatore(scalingIntelligenza)*c.GetIntelligenza()*fuoco/100*3/4) + (Moltiplicatore(scalingIntelligenza)*c.GetIntelligenza()*oscuro/100/4) + (Moltiplicatore(scalingFede)*c.GetFede()*elettrico/100) + (Moltiplicatore(scalingFede)*c.GetFede()*oscuro/100*3/4)  + (Moltiplicatore(scalingFede)*c.GetFede()*fuoco/100/4);
}

double ArmaMagica::Efficacia(const Caratteristiche& c, Armamento* a) const{
	if(!VerificaUsabilita(c))
	{
		//cerr << "Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Danno pari a 0" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida (Danno pari a 0)");
	}
	//ARMA UTILIZZABILE
	Armatura* aux = dynamic_cast<Armatura*>(a);
	Scudo* temp = dynamic_cast<Scudo*>(a);
	if(aux)
	{
		double incremento=0.0;
		if(fuoco>0)
			incremento+=fuoco*aux->GetDifesaFuoco()/100;
		if(magico>0)
			incremento+=magico*aux->GetDifesaMagia()/100;
		if(elettrico>0)
			incremento+=elettrico*aux->GetDifesaElettricita()/100;
		if(oscuro>0)
			incremento+=oscuro*aux->GetDifesaOscurita()/100;
		if(a->GetDifesa()+incremento<DannoEffettivo(c))
			return DannoEffettivo(c)-a->GetDifesa()-incremento;
		else
			return 0;
	}
	else if(temp)
	{
		if(temp->GetDifesa()<DannoEffettivo(c))
			return ((DannoEffettivo(c)-temp->GetDifesa())*(100-temp->GetAssorbimentoMagico())/100.0);
		else 
			return 0;
	}
	else // a e' di tipo dinamico Armamento
	{
		if(a->GetDifesa()<DannoEffettivo(c))
			return DannoEffettivo(c) - a->GetDifesa();
		else
			return 0;
	}
}

bool ArmaMagica::operator==(const Equipaggiamento& e) const{
	return typeid(e)==typeid(const ArmaMagica&) && (fuoco==(static_cast<const ArmaMagica&>(e).fuoco)) && (magico==(static_cast<const ArmaMagica&>(e).magico)) && (elettrico==(static_cast<const ArmaMagica&>(e).elettrico)) && (oscuro==(static_cast<const ArmaMagica&>(e).oscuro)) && (scalingIntelligenza==(static_cast<const ArmaMagica&>(e).scalingIntelligenza)) && (scalingFede==(static_cast<const ArmaMagica&>(e).scalingFede)) && Arma::operator==(static_cast<const Arma&>(e));
}

bool ArmaMagica::operator!=(const Equipaggiamento& e) const{
	return typeid(e)!=typeid(const ArmaMagica&) || (fuoco!=(static_cast<const ArmaMagica&>(e).fuoco)) || (magico!=(static_cast<const ArmaMagica&>(e).magico)) || (elettrico!=(static_cast<const ArmaMagica&>(e).elettrico)) || (oscuro!=(static_cast<const ArmaMagica&>(e).oscuro)) || (scalingIntelligenza!=(static_cast<const ArmaMagica&>(e).scalingIntelligenza)) || (scalingFede!=(static_cast<const ArmaMagica&>(e).scalingFede)) || Arma::operator!=(static_cast<const Arma&>(e));
}

//FUNZIONALITA AGGIUNTE

void ArmaMagica::Benedici(){
	elettrico= 100.0;
	fuoco=magico=oscuro= 0;
}

void ArmaMagica::Maledici(){
	oscuro= 100.0;
	fuoco=magico=elettrico= 0;
}

void ArmaMagica::Incanta(){
	double incremento = 0.0;
	if(fuoco>0)
	{	
		incremento += fuoco/4;
		fuoco-=fuoco/4;
	}
	if(elettrico>0)
	{	
		incremento += elettrico/4;
		elettrico-=elettrico/4;
	}
	if(oscuro>0)
	{	
		incremento += oscuro/4;
		oscuro-=oscuro/4;
	}
	magico+=incremento;
}

void ArmaMagica::Infuoca(){
	double incremento = 0.0;
	if(magico>0)
	{	
		incremento += magico/4;
		magico-=magico/4;
	}
	if(elettrico>0)
	{	
		incremento += elettrico/4;
		elettrico-=elettrico/4;
	}
	if(oscuro>0)
	{	
		incremento += oscuro/4;
		oscuro-=oscuro/4;
	}
	fuoco+=incremento;
}

double ArmaMagica::ArteMistica(const Caratteristiche& c){
	if(!VerificaUsabilita(c))
	{
		//cerr << "Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Danno pari a 0" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per brandire l'arma in questione. Operazione non valida (Danno pari a 0)");
	}
	//ARMA UTILIZZABILE
	double livello = c.Livello();
	double ret = livello/10 * GetDannoBase();
	if(GetUsura()<75.0)
		SetUsura(GetUsura()+25.0);
	else
	{
		//cerr << "Attezione: Livello di usura troppo elevato per eseguire l'operazione senza che questa causi la rottura dell'Arma in questione. Operazione non valida" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attezione: Livello di usura troppo elevato per eseguire l'operazione senza che questa causi la rottura dell'Arma in questione. Operazione non valida");
	}
	return ret;
}
