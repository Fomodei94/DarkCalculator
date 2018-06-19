#ifndef CARATTERISTICHE_H
#define CARATTERISTICHE_H

class Caratteristiche{
	private:
		int vitalita; //HP
		int energia; //Stamina
		int vigore; //Peso trasportabile, effeciacia uso scudo
		int forza; //Danni Armi fisiche
		int destrezza; //Danni Armi fisiche
		int intelligenza; //Danni Armi Magiche magia 100%, fuoco 75%, oscurita 25%
		int fede; //Danni armi Magiche elettricita 100%, orscurita 75%, fuoco 25%
		
	public:
		Caratteristiche(int vit=5, int en=5, int vig=5, int fo=5, int de=5, int in=5, int fe=5);
		
		//GETTER
		
		int GetVitalita() const;
		int GetEnergia() const;
		int GetVigore() const;
		int GetForza() const;
		int GetDestrezza() const;
		int GetIntelligenza() const;
		int GetFede() const;
		
		//SETTER
		
		void SetVitalita(int x);
		void SetEnergia(int x);
		void SetVigore(int x);
		void SetForza(int x);
		void SetDestrezza(int x);
		void SetIntelligenza(int x);
		void SetFede(int x);
		
		//FUNZIONALITA
		
		int Livello() const;
		int CalcolaSalute() const;
		int CalcolaStamina() const;
			
};

#endif

