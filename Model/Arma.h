#ifndef ARMA_H
#define ARMA_H

#include"Equipaggiamento.h"
#include"Armamento.h"

class Arma : public Equipaggiamento{ //CLASSE CONCRETA
	private:
		double dannoBase;
		int forzaRichiesta;
		int intelligenzaRichiesta;
		
	public:
		Arma(double p=0.0, double u=0.0, double d=0.0, int f=5, int i=5);
		
		//GETTER
		
		double GetDannoBase() const;
		int GetForzaRichiesta() const;
		int GetIntelligenzaRichiesta() const;
		
		//SETTER
		
		void SetDannoBase(double x=0.0);
		void SetForzaRichiesta(int x=0);
		void SetIntelligenzaRichiesta(int x=0);
		
		//OVERRIDE
		
		virtual bool VerificaUsabilita(const Caratteristiche&) const override; //IMPLEMENTAZIONE
		virtual bool operator==(const Equipaggiamento&) const override;
		virtual bool operator!=(const Equipaggiamento&) const override;
		
		//FUNZIONALITA AGGIUNTE
		
		virtual double DannoEffettivo(const Caratteristiche&) const;
		double operator+(const Arma&) const;
		virtual double Efficacia(const Caratteristiche&, Armamento*) const;
		double ConfrontaDanno(const Caratteristiche&, Arma*) const;
};

#endif

