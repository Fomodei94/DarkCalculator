#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include"View/Caratteristiche_gui.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QWidget *centralWidget;
    Caratteristiche_gui *CaratteristicheP1;
    Caratteristiche_gui *CaratteristicheP2;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
