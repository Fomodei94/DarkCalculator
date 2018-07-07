#ifndef OPERAZIONI_SCUDOP2
#define OPERAZIONI_SCUDOP2

#include"OperazioniArmamentoP2.h"


class OperazioniScudoP2: public OperazioniArmamentoP2{
	Q_OBJECT
	
	private:
		std::map<std::string, Equipaggiamento*>* equipMap;
		Caratteristiche* carP1;
		Caratteristiche* carP2;
    Scudo* scudoIstanza;
	
	public:
		OperazioniScudoP2(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, Caratteristiche* carP1 = nullptr, Caratteristiche* carP2 = nullptr);
		
	signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
		void update();

  public slots:
		void CalcolaConfrontaConArmamento() override;
		void CalcolaConfrontaConArmatura() override;
		void CalcolaConfrontaConScudo() override;
		void CalcolaSommaConArmamento() override;
		void CalcolaSommaConArmatura() override;
		void CalcolaSommaConScudo() override;
		void CalcolaFrantuma() override;
		void CalcolaEfficaciaConArma() override;
		void CalcolaEfficaciaConArmaFisica() override;
		void CalcolaEfficaciaConArmaMagica() override;
};

#endif

