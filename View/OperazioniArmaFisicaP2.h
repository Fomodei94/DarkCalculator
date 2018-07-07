#ifndef OPERAZIONI_ARMAFISICAP2
#define OPERAZIONI_ARMAFISICAP2

#include"OperazioniArmaP2.h"


class OperazioniArmaFisicaP2: public OperazioniArmaP2{
	Q_OBJECT
	
	private:
		std::map<std::string, Equipaggiamento*>* equipMap;
		Caratteristiche* carP1;
		Caratteristiche* carP2;
    ArmaFisica* armaFisicaIstanza;
	
	public:
		OperazioniArmaFisicaP2(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, Caratteristiche* carP1 = nullptr, Caratteristiche* carP2 = nullptr);
		
	signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
		void update();

  public slots:
		void CalcolaConfrontaConArma() override;
		void CalcolaConfrontaConArmaFisica() override;
		void CalcolaConfrontaConArmaMagica() override;
		void CalcolaSommaConArma() override;
		void CalcolaSommaConArmaFisica() override;
		void CalcolaSommaConArmaMagica() override;
		void CalcolaFrantuma() override;
		void CalcolaSopravvivenza() override;
		void CalcolaHyperArmor() override;
		void CalcolaSpezzaGuardia() override;
};

#endif


