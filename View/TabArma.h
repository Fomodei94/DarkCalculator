#ifndef TABARMA_H
#define TABARMA_H

#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QSpinBox>
#include<QDoubleSpinBox>
#include"../Model/Arma.h"
#include "OperazioniArma.h"
#include "OperazioniArmaP2.h"

class TabArma : public QWidget
{
    Q_OBJECT

private:
		Arma* arma;
    Caratteristiche* carP1;
    Caratteristiche* carP2;
    QWidget* operazioniArma;
    int playerNumber;
    QLabel* LblPeso;
    QLabel* LblUsura;
    QLabel* LblDannoBase;
    QLabel* LblForzaRichiesta;
    QSpinBox* forzaRichiesta;
    QLabel* LblIntelligenzaRichiesta;
    QSpinBox* intelligenzaRichiesta;

 protected:
	QGridLayout *winLayout;
	std::map<std::string, Equipaggiamento*>* equipMap;
        QDoubleSpinBox* peso;
        QDoubleSpinBox* usura;
        QDoubleSpinBox* DannoBase;
	void connectSignals();

public:
    TabArma(QWidget* parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber=1, Caratteristiche* carP1=nullptr, Caratteristiche* carP2=nullptr);
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
};

#endif //  TABARMA_H
