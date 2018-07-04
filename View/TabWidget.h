#ifndef TABWIDGET_H
#define TABWIDGET_H

#include<QGridLayout>
#include<QTabWidget>
#include "TabArma.h"
#include "TabArmaFisica.h"
#include "TabArmamento.h"
#include <map>

class TabWidget : public QWidget {
    Q_OBJECT
public:
    TabWidget(QWidget *parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber, Caratteristiche *carP1=nullptr, Caratteristiche *carP2=nullptr);

private:
  QGridLayout *layout;
  QTabWidget *tabwid;
	TabArma* tabArma;
	TabArmaFisica* tabArmaFisica;
	TabArmamento* tabArmamento;
	std::map<std::string, Equipaggiamento*>* MappaEquipaggiamenti;
  Caratteristiche* carP1;
  Caratteristiche* carP2;
signals:
	void MostraRisultatoNumerico3(double x);
	void MostraRisultatoBooleano3(bool x);
};

#endif // TABWIDGET_H
