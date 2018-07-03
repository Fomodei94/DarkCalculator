#include "TabWidget.h"

TabWidget::TabWidget(QWidget *parent,  std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber) : QWidget(parent)
{
    layout = new QGridLayout(this);
    tabwid = new QTabWidget(parent);
    tabArma = new TabArma(this, equipMap, playerNumber);
    tabArmaFisica = new TabArmaFisica(this, equipMap, playerNumber);
    tabwid->addTab(tabArma,QString("Arma"));
    tabwid->addTab(tabArmaFisica,QString("Arma Fisica"));
    layout->addWidget(tabwid,0,0);
    MappaEquipaggiamenti = equipMap;
    //tabwid->insertTab(0,this,QString("Arma"));
    this->setLayout(layout);
}
