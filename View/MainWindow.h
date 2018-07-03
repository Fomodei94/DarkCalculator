#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include<QGridLayout>
#include"View/Caratteristiche_gui.h"
#include"View/TabWidget.h"

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

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
