#include "TabWidget.h"

TabWidget::TabWidget(QWidget *parent,  std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* carP1, Caratteristiche* carP2) : QWidget(parent), carP1(carP1), carP2(carP2)
{
    layout = new QGridLayout(this);
    tabwid = new QTabWidget(parent);
    tabArma = new TabArma(this, equipMap, playerNumber, carP1, carP2);
    tabArmaFisica = new TabArmaFisica(this, equipMap, playerNumber, carP1, carP2);
    tabwid->addTab(tabArma,QString("Arma"));
    tabwid->addTab(tabArmaFisica,QString("Arma Fisica"));
    layout->addWidget(tabwid,0,0);
    MappaEquipaggiamenti = equipMap;
    //tabwid->insertTab(0,this,QString("Arma"));
    connect(tabArmaFisica, SIGNAL(MostraRisultatoNumerico2(double)), this, SIGNAL(MostraRisultatoNumerico3(double)));
    connect(tabArma, SIGNAL(MostraRisultatoNumerico2(double)), this, SIGNAL(MostraRisultatoNumerico3(double)));
    connect(tabArma, SIGNAL(MostraRisultatoBooleano2(bool)), this, SIGNAL(MostraRisultatoBooleano3(bool)));
    this->setLayout(layout);
}
