#ifndef TABARMAMAGICA_H
#define TABARMAMAGICA_H

#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QSpinBox>
#include "../Model/ArmaMagica.h"
#include <QLabel>
#include <QComboBox>
#include<QDoubleSpinBox>
#include "OperazioniArmaMagica.h"
#include "OperazioniArmaMagicaP2.h"
#include<QString>

class TabArmaMagica: public QWidget{
	Q_OBJECT
	private:
		ArmaMagica* armaMagica;
		QWidget* operazioniArmaMagica;
		QLabel *LblPeso,
						*LblUsura,
						*LblDannoBase,
						*LblForzaRichiesta,
						*LblIntelligenzaRichiesta;
    QDoubleSpinBox *peso,
										*usura,
										*DannoBase;
		QSpinBox *forzaRichiesta,
							*intelligenzaRichiesta;
		QLabel *LblFuoco,
						*LblMagico,
						*LblElettrico,
						*LblOscuro,
						*LblScalingIntelligenza,
						*LblScalingFede;
		QDoubleSpinBox *Fuoco,
										*Magico,
										*Elettrico,
										*Oscuro;
		QComboBox *ScalingIntelligenza,
							*ScalingFede;
    Caratteristiche* carP1;
    Caratteristiche* carP2;
		int playerNumber;
		QGridLayout *winLayout;
		std::map<std::string, Equipaggiamento*>* equipMap;
		void connectSignalsArmaMagica();
		
	public:
		TabArmaMagica(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber=1, Caratteristiche* carP1=nullptr, Caratteristiche* carP2=nullptr);
		void FinishInit();
		
	signals:
		void MostraRisultatoNumerico2(double x);
		void MostraRisultatoBooleano2(bool x);
		
	public slots:
		void setPeso(double d);
		void setUsura(double d);
		void setDannoBase(double d);
		void setForzaRichiesta(int i);
		void setIntelligenzaRichiesta(int i);
		void setFuoco(double d);
		void setMagico(double d);
		void setElettrico(double d);
		void setOscuro(double d);
		void setScalingFede(int i);
		void setScalingIntelligenza(int i);
		void update();
};
#endif

