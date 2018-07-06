#ifndef TABARMAMAGICA_H
#define TABARMAMAGICA_H
#include "TabArma.h"
#include "../Model/ArmaMagica.h"
#include <QLabel>
#include <QComboBox>
#include<QDoubleSpinBox>
#include "OperazioniArmaMagica.h"
#include<QString>

class TabArmaMagica: public TabArma{
	Q_OBJECT
	private:
		ArmaMagica* armaMagica;
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
		OperazioniArmaMagica* operazioniArmaMagica;
    Caratteristiche* carP1;
    Caratteristiche* carP2;
		int playerNumber;
	protected:
		void connectSignalsArmaMagica();
	public:
		TabArmaMagica(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber=1, Caratteristiche* carP1=nullptr, Caratteristiche* carP2=nullptr);
		virtual void FinishInit() override;
                void update();
	signals:
		void MostraRisultatoNumerico2(double x);
		void MostraRisultatoBooleano2(bool x);
	public slots:
		virtual void setPeso(double d) override;
		virtual void setUsura(double d) override;
		virtual void setDannoBase(double d) override;
		virtual void setForzaRichiesta(int i) override;
		virtual void setIntelligenzaRichiesta(int i) override;
		void setFuoco(double d);
		void setMagico(double d);
		void setElettrico(double d);
		void setOscuro(double d);
		void setScalingFede(int i);
		void setScalingIntelligenza(int i);
};
#endif

