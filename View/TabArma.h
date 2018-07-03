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
    QLabel* LblPeso;
    QDoubleSpinBox* peso;
    QLabel* LblUsura;
    QDoubleSpinBox* usura;
    QLabel* LblDannoBase;
    QSpinBox* DannoBase;
    QLabel* LblForzaRichiesta;
    QSpinBox* forzaRichiesta;
    QLabel* LblIntelligenzaRichiesta;
    QSpinBox* intelligenzaRichiesta;

 protected:
	QGridLayout *winLayout;
	std::map<std::string, Equipaggiamento*>* equipMap;

public:
    TabArma(QWidget *parent = nullptr, std::map<std::string, Equipaggiamento*>* equipMap = nullptr, int playerNumber = 1);
    virtual void FinishInit();
    ~TabArma() = default;
};

#endif //  TABARMA_H
