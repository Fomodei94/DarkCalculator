#ifndef TABARMAFISICA_H
#define TABARMAFISICA_H

#include <QComboBox>
#include "OperazioniArmaFisica.h"
#include"OperazioniArmaFisicaP2.h"
#include<QString>
#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QSpinBox>
#include<QDoubleSpinBox>

class TabArmaFisica: public QWidget{
	Q_OBJECT
	private:
		ArmaFisica* armaFisica;
		QWidget* operazioniArmaFisica;
		QLabel* LblPeso;
    QLabel* LblUsura;
    QLabel* LblDannoBase;
    QDoubleSpinBox* peso;
    QDoubleSpinBox* usura;
    QDoubleSpinBox* DannoBase;
    QLabel* LblForzaRichiesta;
    QSpinBox* forzaRichiesta;
    QLabel* LblIntelligenzaRichiesta;
    QSpinBox* intelligenzaRichiesta;
		QLabel *LblTipoDanno,
						*LblScalingForza,
						*LblScalingDestrezza;
		QComboBox *TipoDanno,
								*ScalingForza,
								*ScalingDestrezza;
    Caratteristiche* carP1;
    Caratteristiche* carP2;
		int playerNumber;
		QGridLayout *winLayout;
		std::map<std::string, Equipaggiamento*>* equipMap;
		void connectSignalsArmaFisica();
		
	public:
		TabArmaFisica(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber=1, Caratteristiche* carP1=nullptr, Caratteristiche* carP2=nullptr);
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
		void setTipoDanno(int i);
		void setScalingForza(int i);
		void setScalingDestrezza(int i);
    void update();
};
#endif
