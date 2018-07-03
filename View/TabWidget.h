#ifndef TABWIDGET_H
#define TABWIDGET_H

#include<QGridLayout>
#include<QTabWidget>
#include"TabArma.h"
#include "TabArmaFisica.h"
#include <map>

class TabWidget : public QWidget {
    Q_OBJECT
public:
    TabWidget(QWidget *parent, std::map<std::string, Equipaggiamento*>* equipMap, int playerNumber);

private:
    QGridLayout *layout;
    QTabWidget *tabwid;
	TabArma* tabArma;
	TabArmaFisica* tabArmaFisica;
	std::map<std::string, Equipaggiamento*>* MappaEquipaggiamenti;
};

#endif // TABWIDGET_H
