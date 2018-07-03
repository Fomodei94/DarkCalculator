#ifndef ARMAMAGICA_H
#define ARMAMAGICA_H

#include"Arma.h"
#include"Armatura.h"
#include"Scudo.h"

class ArmaMagica : public Arma{
	private:
		double fuoco; //Percentuale di danno da fuoco
		double magico;
		double elettrico;
		double oscuro;
		char scalingIntelligenza;
		char scalingFede;
		
	public:
		ArmaMagica(double p=0.0, double u=0.0, double d=0.0, int f=5, int i=5, double fu=25.0, double ma=25.0, double el=25.0, double os=25.0, char in='E', char fe='E');
		
		//GETTER
		
		double GetMagico() const;
		double GetFuoco() const;
		double GetElettrico() const;
		double GetOscuro() const;
		char GetScalingIntelligenza() const;
		char GetScalingFede() const;
		
		//SETTER
		
		void SetFuoco(double x);
		void SetMagico(double x);
		void SetElettrico(double x);
		void SetOscuro(double x);
		void SetScalingIntelligenza(char x='E');
		void SetScalingFede(char x='E');
		
		//OVERRIDE
		
		virtual bool VerificaUsabilita(const Caratteristiche&) const override;
		virtual double DannoEffettivo(const Caratteristiche&) const;
		virtual double Efficacia(const Caratteristiche&, Armamento*) const override; //NB Ora valuta Scaling ed eventuale tipo di difesa
		virtual bool operator==(const Equipaggiamento&) const override;
		virtual bool operator!=(const Equipaggiamento&) const override; 
		
		//FUNZIONALITA AGGIUNTE
		
		void Incanta();
		void Infuoca();
		void Benedici();
		void Maledici();
		double ArteMistica(const Caratteristiche&);
};


#endif

