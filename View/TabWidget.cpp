#include "TabWidget.h"

TabWidget::TabWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    tabwid = new QTabWidget(parent);
    tabArma = new TabArma();
    tabwid->addTab(tabArma,QString("Arma"));
    layout->addWidget(tabwid,0,0);
    //tabwid->insertTab(0,this,QString("Arma"));
    this->setLayout(layout);
}
