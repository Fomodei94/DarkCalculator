#ifndef ARMATURA_H
#define ARMATURA_H

#include"Armamento.h"
#include"Arma.h"

class Armatura : public Armamento{
	private:
		double difesaTaglio; //bonus alla difesa extra (flat), a seconda del danno subito
		double difesaContundente;
		double difesaAffondo;
		double difesaFuoco;
		double difesaMagia;
		double difesaElettricita;
		double difesaOscurita;
		static double pesoMinimoHyperArmor;
		
	public:
		Armatura(double p=0.0, double u=0.0, double d=0.0, int v=0, double ta=0.0, double im=0.0, double pe=0.0, double fu=0.0, double ma=0.0, double el=0.0, double os=0.0);
	
		//GETTER
		
		double GetDifesaTaglio() const;
		double GetDifesaContundente() const;
		double GetDifesaAffondo() const;
		double GetDifesaFuoco() const;
		double GetDifesaMagia() const;
		double GetDifesaElettricita() const;
		double GetDifesaOscurita() const;
		
		//SETTER
		
		void SetDifesaTaglio(double x=0);
		void SetDifesaContundente(double x=0);
		void SetDifesaAffondo(double x=0);
		void SetDifesaFuoco(double x=0);
		void SetDifesaMagica(double x=0);
		void SetDifesaElettricita(double x=0);
		void SetDifesaOscurita(double x=0);
		
		//OVERRIDE
		
		virtual bool operator==(const Equipaggiamento&) const override;
		virtual bool operator!=(const Equipaggiamento&) const override;
		virtual double ConfrontaDifesa(const Caratteristiche&, Armamento*) const override;
		virtual double Equilibrio(const Caratteristiche&) const override;
		
		//FUNZIONALITA AGGIUNTE
		
		void Appesantisci(); //Aumenta peso e difesa da danno contundente, riduce tutte le difese magiche
		void Allegerisci(); //Diminuisce peso e difesa da danno contundente, aumenta difesa da affondo
		void CottaDiMaglia(); //Aumenta peso e difesa da taglio, riduce difesa da affondo
		unsigned int Sopravvivenza(const Caratteristiche&, Arma*, const Caratteristiche&) const; //Calcola il numero di colpi che si possono ricevere con tale armatura dall'arma indicata prima di morire o prima che l'armatura si rompa 		
		double HyperArmor(const Caratteristiche&, Arma*) const; //Ritorna la quantita' di danni sopportabili senza essere interrotti duranti un'attacco caricato dell'arma passata per parametro

};

#endif

