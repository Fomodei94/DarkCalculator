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
    //OperazioniArma* operazioniArma;
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
    TabArma(QWidget *parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2);
    TabArma(QWidget *parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber);
    virtual void FinishInit();
    ~TabArma() = default;

signals:
	void MostraRisultatoNumerico2(double x);
	void MostraRisultatoBooleano2(bool x);

public slots:
	virtual void setPeso(double d);
	virtual void setUsura(double d);
	virtual void setDannoBase(double d);
	virtual void setForzaRichiesta(int i);
	virtual void setIntelligenzaRichiesta(int i);
};

#endif //  TABARMA_H
