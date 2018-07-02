#ifndef CARATTERISTICHE_GUI_H
#define CARATTERISTICHE_GUI_H

#include<QGridLayout>
// #include<QBoxLayout>
#include <QWidget>
#include<QFrame>
#include<QLabel>
#include<QSpinBox>
#include<QLCDNumber>
#include<QMessageBox>
#include "../Model/Caratteristiche.h"

class Caratteristiche_gui : public QWidget {
    Q_OBJECT
public:
    Caratteristiche_gui(QWidget *parent, int p, Caratteristiche *car);

private:
    QGridLayout *layout;
    QLabel *label_Caratt;
    QFrame *frame_Caratt;
    QLabel *label_Fede;
    QSpinBox *spinBox_Fede;
    QLabel *label_Forza;
    QSpinBox *spinBox_Forza;
    QLabel *label_Vigore;
    QSpinBox *spinBox_Vigore;
    QLabel *label_Destrezza;
    QSpinBox *spinBox_Destrezza;
    QLabel *label_Intelligenza;
    QSpinBox *spinBox_Intelligenza;
    QLabel *label_Vitalita;
    QSpinBox *spinBox_Vitalita;
    QLabel *label_Energia;
    QSpinBox *spinBox_Energia;
    QLabel *label_Livello;
    QLCDNumber *lcdNumber_Livello;

signals:

public slots:
};

#endif // CARATTERISTICHE_GUI_H
