#include "TabWidget.h"

TabWidget::TabWidget(QWidget *parent,  std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche* car) : QWidget(parent), car(car)
{
    layout = new QGridLayout(this);
    tabwid = new QTabWidget(parent);
    tabArma = new TabArma(this, equipMap, playerNumber, car);
    tabArmaFisica = new TabArmaFisica(this, equipMap, playerNumber, car);
    tabwid->addTab(tabArma,QString("Arma"));
    tabwid->addTab(tabArmaFisica,QString("Arma Fisica"));
    layout->addWidget(tabwid,0,0);
    MappaEquipaggiamenti = equipMap;
    //tabwid->insertTab(0,this,QString("Arma"));
    connect(tabArmaFisica, SIGNAL(MostraRisultatoNumerico2(double)), this, SIGNAL(MostraRisultatoNumerico3(double)));
    this->setLayout(layout);
}
