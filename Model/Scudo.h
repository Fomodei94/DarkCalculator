#ifndef SCUDO_H
#define SCUDO_H

#include"Armamento.h"
#include"Arma.h"

class Scudo : public Armamento{
	private:
		double assorbimentoMagico; //Assorbimento in percentuale del danno 
		double assorbimentoFisico;
		int stabilita;
		char scalingVigore;
		
	public:
		Scudo(double p=0.0, double u=0.0, double d=0.0, int v=0, double am=0.0, double af=0.0, int st=0, char sv='E');
		
		//GETTER
		
		double GetAssorbimentoMagico() const;
		double GetAssorbimentoFisico() const;
		int GetStabilita() const;
		char GetScalingVigore() const;
		
		//SETTER
		
		void SetAssorbimentoMagico(double x=0.0);
		void SetAssorbimentoFisico(double x=0.0);
		void SetStabilita(int x=0);
		void SetScalingVigore(char x='E');
		
		//OVERRIDE
		
		virtual bool operator==(const Equipaggiamento&) const;
		virtual bool operator!=(const Equipaggiamento&) const;
		virtual double ConfrontaDifesa(const Caratteristiche&, Armamento*) const;
		virtual double Equilibrio(const Caratteristiche&) const override;
		
		//FUNZIONALITA AGGIUNTE
		
		double Parata(const Caratteristiche&) const; //Ritorna la percentuale di riuscita di un parry perfetto senza subire danni. Varia a seconda dello Scaling a vigore
		unsigned int SpezzaGuardia(const Caratteristiche&, Arma*, const Caratteristiche&) const; //Ritorna il numero di colpi dell'Arma indicata da cui ci si puo' parare prima di finire la stamina e che quindi la guardia sia rotta

};

#endif

