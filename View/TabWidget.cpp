#include "TabWidget.h"

TabWidget::TabWidget(QWidget *parent) : QWidget(parent)
{
    layout = new QGridLayout(this);
    tabwid = new QTabWidget(parent);
    tabwid->addTab(this,QString("Arma"));
    //tabwid->insertTab(0,this,QString("Arma"));
}
