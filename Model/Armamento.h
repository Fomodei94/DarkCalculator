#ifndef ARMAMENTO_H
#define ARMAMENTO_H

#include"Equipaggiamento.h"

class Armamento : public Equipaggiamento{ //Classe Concreta
	private:
		double difesa;
		int vigoreRichiesto;
		static double pesoMinimoEquilibrio;
	
	public:
		Armamento(double p=0.0, double u=0.0, double d=0.0, int v=5);
		
		//GETTER
		
		double GetDifesa() const;
		int GetVigoreRichiesto() const;
		
		//SETTER
		
		void SetDifesa(double x=0.0);
		void SetVigoreRichiesto(int x=0);
		
		//OVERRIDE
		
		virtual bool VerificaUsabilita(const Caratteristiche&) const override; //IMPLEMENTAZIONE
		virtual bool operator==(const Equipaggiamento&) const;
		virtual bool operator!=(const Equipaggiamento&) const;
		
		//FUNZIONALITA AGGIUNTE
		
		double operator+(const Armamento&) const;
		virtual void ConfrontaDifesa(const Caratteristiche&, Armamento*) const;
		virtual double Equilibrio(const Caratteristiche&) const;
		
};


#endif

