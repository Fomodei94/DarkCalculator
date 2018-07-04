#ifndef TABARMA_H
#define TABARMA_H

#include<QWidget>
#include<QGridLayout>
#include<QLabel>
#include<QSpinBox>
#include<QDoubleSpinBox>
#include"../Model/Arma.h"

class TabArma : public QWidget
{
    Q_OBJECT

private:
		Arma* arma;
    Caratteristiche* car;
    QLabel* LblPeso;
    QDoubleSpinBox* peso;
    QLabel* LblUsura;
    QDoubleSpinBox* usura;
    QLabel* LblDannoBase;
    QDoubleSpinBox* DannoBase;
    QLabel* LblForzaRichiesta;
    QSpinBox* forzaRichiesta;
    QLabel* LblIntelligenzaRichiesta;
    QSpinBox* intelligenzaRichiesta;

 protected:
	QGridLayout *winLayout;
	std::map<std::string, Equipaggiamento*>* equipMap;
	void connectSignals();

public:
    TabArma(QWidget *parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber = 1, Caratteristiche* car = nullptr);
    virtual void FinishInit();
    ~TabArma() = default;
    
public slots:
	virtual void setPeso(double d);
	virtual void setUsura(double d);
	virtual void setDannoBase(double d);
	virtual void setForzaRichiesta(int i);
	virtual void setIntelligenzaRichiesta(int i);
};

#endif //  TABARMA_H
