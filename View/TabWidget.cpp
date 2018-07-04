#include "TabWidget.h"

TabWidget::TabWidget(QWidget *parent,  std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2) : QWidget(parent), carP1(carP1), carP2(carP2)
{
    layout = new QGridLayout(this);
    tabwid = new QTabWidget(parent);
    tabArma = new TabArma(this, equipMap, playerNumber, carP1, carP2);
    tabArmaFisica = new TabArmaFisica(this, equipMap, playerNumber, carP1, carP2);
    tabArmamento = new TabArmamento(this, equipMap, playerNumber, carP1, carP2);
    tabArmatura = new TabArmatura(this, equipMap, playerNumber, carP1, carP2);
    tabwid->addTab(tabArma,QString("Arma"));
    tabwid->addTab(tabArmaFisica,QString("Arma Fisica"));
    tabwid->addTab(tabArmamento, QString("Armamento"));
    tabwid->addTab(tabArmatura, QString("Armatura"));
    layout->addWidget(tabwid,0,0);
    MappaEquipaggiamenti = equipMap;
    connect(tabArmaFisica, SIGNAL(MostraRisultatoNumerico2(double)), this, SIGNAL(MostraRisultatoNumerico3(double)));
    connect(tabArma, SIGNAL(MostraRisultatoNumerico2(double)), this, SIGNAL(MostraRisultatoNumerico3(double)));
    connect(tabArma, SIGNAL(MostraRisultatoBooleano2(bool)), this, SIGNAL(MostraRisultatoBooleano3(bool)));
    connect(tabArmamento, SIGNAL(MostraRisultatoBooleano2(bool)), this, SIGNAL(MostraRisultatoBooleano3(bool)));
    
    this->setLayout(layout);
}
