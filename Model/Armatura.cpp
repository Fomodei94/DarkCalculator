#include<iostream>
#include<typeinfo>
#include"Armatura.h"
#include"ArmaFisica.h"
#include"ArmaMagica.h"

using std::cerr; using std::cout; using std::endl;

double Armatura::pesoMinimoHyperArmor = 15;

Armatura::Armatura(double p, double u, double d, int v, double ta, double im, double pe, double fu, double ma, double el, double os): Armamento(p,u,d,v), difesaTaglio(ta), difesaContundente(im), difesaAffondo(pe), difesaFuoco(fu), difesaMagia(ma), difesaElettricita(el), difesaOscurita(os){
	if(ta<0)
	{cerr<<"Attenzione! Inserito un valore di difesa da Taglio negativo. Valore Settato al default 0." << endl;difesaTaglio=0;}
	if(im<0)
	{cerr<<"Attenzione! Inserito un valore di difesa da danno Contundente negativo. Valore Settato al default 0." << endl;difesaContundente=0;}
	if(pe<0)
	{cerr<<"Attenzione! Inserito un valore di difesa da Affondo negativo. Valore Settato al default 0." << endl;difesaAffondo=0;}
	if(fu<0)
	{cerr<<"Attenzione! Inserito un valore di difesa da Fuoco negativo. Valore Settato al default 0." << endl;difesaFuoco=0;}
	if(ma<0)
	{cerr<<"Attenzione! Inserito un valore di difesa da Magia negativo. Valore Settato al default 0." << endl;difesaMagia=0;}
	if(el<0)
	{cerr<<"Attenzione! Inserito un valore di difesa da Elettricita' negativo. Valore Settato al default 0." << endl;difesaElettricita=0;}
	if(os<0)
	{cerr<<"Attenzione! Inserito un valore di difesa da Oscurita' negativo. Valore Settato al default 0." << endl;difesaOscurita=0;}
}

//GETTER

double Armatura::GetDifesaTaglio() const {return difesaTaglio;}
double Armatura::GetDifesaContundente() const {return difesaContundente;}
double Armatura::GetDifesaAffondo() const {return difesaAffondo;}
double Armatura::GetDifesaFuoco() const {return difesaFuoco;}
double Armatura::GetDifesaMagia() const {return difesaMagia;}
double Armatura::GetDifesaElettricita() const {return difesaElettricita;}
double Armatura::GetDifesaOscurita() const {return difesaOscurita;}

//SETTER

void Armatura::SetDifesaTaglio(double x){
	if(x>0)
		difesaTaglio=x;
	else
		cerr << "Attenzione: inserito un valore per la difesa da Taglio dell'Armatura negativo. Operazione non valida" << endl;
}

void Armatura::SetDifesaAffondo(double x){
	if(x>0)
		difesaAffondo=x;
	else
		cerr << "Attenzione: inserito un valore per la difesa da Penetrazione dell'Armatura negativo. Operazione non valida" << endl;
}

void Armatura::SetDifesaContundente(double x){
	if(x>0)
		difesaContundente=x;
	else
		cerr << "Attenzione: inserito un valore per la difesa da Impatto dell'Armatura negativo. Operazione non valida" << endl;
}

void Armatura::SetDifesaFuoco(double x){
	if(x>0)
		difesaFuoco=x;
	else
		cerr << "Attenzione: inserito un valore per la difesa da Fuoco dell'Armatura negativo. Operazione non valida" << endl;
}

void Armatura::SetDifesaMagica(double x){
	if(x>0)
		difesaMagia=x;
	else
		cerr << "Attenzione: inserito un valore per la difesa Magica dell'Armatura negativo. Operazione non valida" << endl;
}

void Armatura::SetDifesaElettricita(double x){
	if(x>0)
		difesaElettricita=x;
	else
		cerr << "Attenzione: inserito un valore per la difesa Elettrica dell'Armatura negativo. Operazione non valida" << endl;
}

void Armatura::SetDifesaOscurita(double x){
	if(x>0)
		difesaOscurita=x;
	else
		cerr << "Attenzione: inserito un valore per la difesa da Oscurita' dell'Armatura negativo. Operazione non valida" << endl;
}

//OVERRIDE

double Armatura::ConfrontaDifesa(const Caratteristiche& c, Armamento* a) const{
	if(!VerificaUsabilita(c))
		//cerr << "Attenzione: Caratteristiche insufficienti per il primo Armamento. Operazione non valida." << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per il primo Armamento. Operazione non valida.");
	else if(!a->VerificaUsabilita(c))
		//{cerr << "Attenzione: Caratteristiche insufficienti per il secondo Armamento. Operazione non valida." << endl; return 0;}VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insufficienti per il secondo Armamento. Operazione non valida.");
	else //CARATTERISCHE SUFFICIENTI PER COMPIERE CORRETAMENTE L'OPERAZIONE
	{
		Armatura* aux= dynamic_cast<Armatura*>(a);
		if(aux)
		{
			double x1= difesaTaglio+difesaAffondo+difesaContundente;
			double x2= aux->difesaTaglio+aux->difesaAffondo+aux->difesaContundente;
			/* VERSIONE DA RIGA DI COMANDO
			if(x1>x2)
				cout<<"La prima Armatura ha maggior predisposizione a difesa Fisica rispetto alla seconda." << endl;
			else if(x1<x2)
				cout<<"La seconda Armatura ha maggior predisposizione a difesa Fisica rispetto alla prima." << endl;
			else
				cout<<"Le due Armature hanno pari protezioni aggiuntive di tipo Fisico." << endl;
			*/
			double y1= difesaFuoco+difesaMagia+difesaElettricita+difesaOscurita;
			double y2= aux->difesaFuoco+aux->difesaMagia+aux->difesaElettricita+aux->difesaOscurita;
			/* VERSIONE DA RIGA DI COMANDO
			if(y1>y2)
				cout<<"La prima Armatura ha maggior predisposizione a difesa Magica rispetto alla seconda." << endl;
			else if(y1<y2)
				cout<<"La seconda Armatura ha maggior predisposizione a difesa Magica rispetto alla prima." << endl;
			else
				cout<<"Le due Armature hanno pari protezioni aggiuntive di tipo Magico." << endl;
			*/
			double z=(GetDifesa()-(GetDifesa()*GetUsura()/200)+x1+y1) - (aux->GetDifesa()-(aux->GetDifesa()*aux->GetUsura()/200)+x2+y2);
			/*
			if(z>0)
				cout<<"La prima Armatura ha una difesa generale superiore di: "<<z<<" rispetto alla seconda." << endl;
			else if(z<0)
				cout<<"La seconda Armatura ha una difesa generale superiore di: "<<(-1*z)<<" rispetto alla prima." << endl;
			else
				cout<<"Le due armature hanno pari difesa generale." << endl;
			*/
			return z;
		}
		else
		{
			//cout<<"Attenzione, L'Equipaggiamento di confronto deve essere un'Armatura e non lo e'. In ogni caso a livello di difesa base e' possibile confrontare come segue: "<<endl; VERSIONE DA RIGA DI COMANDO
			Armamento::ConfrontaDifesa(c,a);
		}
	}
}

bool Armatura::operator==(const Equipaggiamento& e) const{
	return typeid(e)==typeid(const Armatura&) && (difesaTaglio==static_cast<const Armatura&>(e).difesaTaglio) && (difesaContundente==static_cast<const Armatura&>(e).difesaContundente) && (difesaAffondo==static_cast<const Armatura&>(e).difesaAffondo) && (difesaFuoco==static_cast<const Armatura&>(e).difesaFuoco) && (difesaMagia==static_cast<const Armatura&>(e).difesaMagia) && (difesaElettricita==static_cast<const Armatura&>(e).difesaElettricita) && (difesaOscurita==static_cast<const Armatura&>(e).difesaOscurita) && Armamento::operator==(static_cast<const Armamento&>(e));
}

bool Armatura::operator!=(const Equipaggiamento& e) const{
	return typeid(e)!=typeid(const Armatura&) || (difesaTaglio!=static_cast<const Armatura&>(e).difesaTaglio) || (difesaContundente!=static_cast<const Armatura&>(e).difesaContundente) || (difesaAffondo!=static_cast<const Armatura&>(e).difesaAffondo) || (difesaFuoco!=static_cast<const Armatura&>(e).difesaFuoco) || (difesaMagia!=static_cast<const Armatura&>(e).difesaMagia) || (difesaElettricita!=static_cast<const Armatura&>(e).difesaElettricita) || (difesaOscurita!=static_cast<const Armatura&>(e).difesaOscurita) || Armamento::operator!=(static_cast<const Armamento&>(e));
}

double Armatura::Equilibrio(const Caratteristiche& c) const{
	if(!VerificaUsabilita(c))
	{
		//cerr << "Attenzione: Caratteristiche insuffienti per equipaggiare l'Armatura" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insuffienti per equipaggiare l'Armatura.");
	}
	double aux= Armamento::Equilibrio(c);
	if(aux==0)
		return aux;
	double incremento= (1+difesaContundente+difesaAffondo+difesaTaglio)/((1+difesaElettricita+difesaFuoco+difesaMagia+difesaOscurita))*4/3;
	return aux + (incremento*5);
}

//METODI PROPRI

void Armatura::Appesantisci(){
	SetPeso(GetPeso()*5/4); //NB Aumenta il peso di 1/4
	difesaContundente+=difesaContundente/2;
	difesaFuoco-=difesaFuoco/4;
	difesaMagia-=difesaMagia/4;
	difesaElettricita-=difesaElettricita/4;
	difesaOscurita-=difesaOscurita/4;
}

void Armatura::Alleggerisci(){
	SetPeso(GetPeso()*3/4); //NB Diminuisce il peso di 1/4
	difesaContundente-=difesaContundente/3;
	difesaAffondo+=difesaAffondo/3;
}

void Armatura::CottaDiMaglia(){
	SetPeso(GetPeso()*5/4);
	difesaAffondo-=difesaAffondo/3;
	difesaTaglio+=difesaTaglio/3;
}

unsigned int Armatura::Sopravvivenza(const Caratteristiche& c1, Arma* a, const Caratteristiche& c2) const{
	if(!VerificaUsabilita(c1))
	{
		//cerr << "Attenzione: Caratteristiche insuffienti per equipaggiare l'Armatura. Operazione non valida" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insuffienti per equipaggiare l'Armatura. Operazione non valida");
	}
	if(!a->VerificaUsabilita(c2))
	{
		//cerr << "Attenzione: Caratteristice indicate per l'Arma non suffienti per brandirla. Operazione non valida" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristice indicate per l'Arma non suffienti per brandirla. Operazione non valida");
	}
	unsigned int ret=0;
	unsigned int salute= c1.CalcolaSalute();
	double danno= a->Efficacia(c2, const_cast<Armatura*>(this));
	ArmaFisica* temp= dynamic_cast<ArmaFisica*>(a);
	while(salute>danno)
	{
		salute-=danno;
		++ret;
		if(temp) //L'arma in questione danneggia l'armatura ad ogni colpo
		{
			double aux= GetUsura();
			double danneggiamento= temp->Frantuma(c2,const_cast<Armatura*>(this));
			if(aux+danneggiamento<100)
				aux+=danneggiamento;
			else
			{
				//cout<<"Attenzione, l'ultimo colpo avrebbe rotto l'armatura!"<<endl; VERSIONE DA RIGA DI COMANDO
				return ret;
			}
			danno= temp->Efficacia(c2,const_cast<Armatura*>(this));
		}
	}
	return ret;
}

double Armatura::HyperArmor(const Caratteristiche& c, Arma* a) const{
	if(!VerificaUsabilita(c))
	{
		//cerr << "Attenzione: Caratteristiche insuffienti per equipaggiare l'Armatura" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insuffienti per equipaggiare l'Armatura");
	}
	if(!a->VerificaUsabilita(c))
	{
		//cerr << "Attenzione: Caratteristiche insuffienti per impugnare l'Arma" << endl; return 0; VERSIONE DA RIGA DI COMANDO
		throw("Attenzione: Caratteristiche insuffienti per impugnare l'Arma");
	}
	ArmaFisica* aux= dynamic_cast<ArmaFisica*>(a);
	if(!aux)
	{
		//cout<< "Solo un'ArmaFisica puo' concedere HyperArmor" << endl; VERSIONE DA RIGA DI COMANDO
		return 0;
	}
	else if(aux->GetPeso()<pesoMinimoHyperArmor)
	{
		//cout << "L'arma in questione non e' sufficientemente pesante per garantire HyperArmor" << endl; VERSIONE DA RIGA DI COMANDO
		return 0;
	}
	else //ATTIVAZIONE HYPER ARMOR
	{
		double ret= Equilibrio(c);
		double incremento = Moltiplicatore(aux->GetScalingForza())*c.GetForza();
		return (ret*aux->GetPeso()) + incremento;
	}
}

