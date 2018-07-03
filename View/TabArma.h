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
    QGridLayout *winLayout;
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

public:
    TabArma(QWidget *parent = nullptr, Arma* armaptr=nullptr);
    ~TabArma() = default;
};

#endif //  TABARMA_H
