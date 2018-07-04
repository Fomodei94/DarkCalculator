#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QWidget>
#include<QGridLayout>
#include<QLCDNumber>
#include"View/Caratteristiche_gui.h"
#include"View/TabWidget.h"
#include <map>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QGridLayout *winLayout;
    QWidget *centralWidget;
    Caratteristiche_gui *CaratteristicheP1;
    Caratteristiche_gui *CaratteristicheP2;
    TabWidget *EquipaggiamentoP1;
    TabWidget *EquipaggiamentoP2;
	std::map<std::string, Equipaggiamento*> *mappaEquipaggiamenti;
    QLabel *Risultato;
    QLabel *lblRisultato;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void MostraRisultatoNumericoFinale(double x);
    void MostraRisultatoBooleanoFinale(bool x);
};

#endif // MAINWINDOW_H
