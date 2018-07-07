#ifndef OPERAZIONI_ARMATURAP2
#define OPERAZIONI_ARMATURAP2

#include"OperazioniArmamentoP2.h"


class OperazioniArmaturaP2: public OperazioniArmamentoP2{
	Q_OBJECT
	
	private:
		Caratteristiche* carP1;
		Caratteristiche* carP2;
		Armatura* armaturaIstanza;
	
	public:
		OperazioniArmaturaP2(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, Caratteristiche* carP1 = nullptr, Caratteristiche* carP2 = nullptr);
		
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

