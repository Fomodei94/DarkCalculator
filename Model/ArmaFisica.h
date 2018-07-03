#ifndef ARMAFISICA_H
#define ARMAFISICA_H

#include"Arma.h"
#include"Armatura.h"
#include"Scudo.h"

class ArmaFisica : public Arma{
	private:
		char tipoDanno;
		char scalingForza; //Valori compresi tra E-S
		char scalingDestrezza; //Valori compresi tra E-S
		
	public:
		ArmaFisica(double p=0.0, double u=0.0, double d=0.0, int f=5, int i=5, char t='T', char fo='E', char dx='E');
		
		//GETTER
		
		char GetTipoDanno() const;
		char GetScalingForza() const;
		char GetScalingDestrezza() const;
		
		//SETTER
		
		void SetTipoDanno(char x='T');
		void SetScalingForza(char x='E');
		void SetScalingDestrezza(char x='E');
		
		//OVERRIDE
		
		virtual double DannoEffettivo(const Caratteristiche&) const override; 
		virtual double Efficacia(const Caratteristiche&, Armamento*) const override;
		virtual bool operator==(const Equipaggiamento&) const override; 
		virtual bool operator!=(const Equipaggiamento&) const override; 
		
		//FUNZIONALITA AGGIUNTE
		
		void Raffina();
		void Riforgia();
		void Cristallizza(); 
		double Frantuma(const Caratteristiche&, Equipaggiamento*) const;
	
};

#endif

