#include "Caratteristiche_gui.h"

Caratteristiche_gui::Caratteristiche_gui(QWidget *parent, int p, Caratteristiche *car) : QWidget(parent)
{
    layout = new QGridLayout(this);
    label_Caratt = new QLabel(QString("<h3>Caratteristiche Personaggio %1</h3>").arg(p), this);

    label_Vitalita = new QLabel("Vitalità", this);
    spinBox_Vitalita = new QSpinBox(this);
    spinBox_Vitalita->setRange(5,99);

    label_Energia = new QLabel("Energia",this);
    spinBox_Energia = new QSpinBox(this);
    spinBox_Energia->setRange(5,99);

    label_Vigore = new QLabel("Vigore",this);
    spinBox_Vigore = new QSpinBox(this);
    spinBox_Vigore->setRange(5,99);

    label_Forza = new QLabel("Forza",this);
    spinBox_Forza = new QSpinBox(this);
    spinBox_Forza->setRange(5,99);

    label_Destrezza = new QLabel("Destrezza",this);
    spinBox_Destrezza = new QSpinBox(this);
    spinBox_Destrezza->setRange(5,99);

    label_Intelligenza = new QLabel("Intelligenza",this);
    spinBox_Intelligenza = new QSpinBox(this);
    spinBox_Intelligenza->setRange(5,99);

    label_Fede = new QLabel("Fede",this);
    spinBox_Fede = new QSpinBox(this);
    spinBox_Fede->setRange(5,99);

    label_Livello = new QLabel("<h4>Livello</h4>",this);
    lcdNumber_Livello = new QLCDNumber(3);

    layout->addWidget(label_Caratt,0,0,1,-2);
    layout->addWidget(label_Vitalita,1,0);
    layout->addWidget(spinBox_Vitalita,1,1);
    layout->addWidget(label_Energia,2,0);
    layout->addWidget(spinBox_Energia,2,1);
    layout->addWidget(label_Vigore,1,3);
    layout->addWidget(spinBox_Vigore,1,4);
    layout->addWidget(label_Forza,2,3);
    layout->addWidget(spinBox_Forza,2,4);
    layout->addWidget(label_Destrezza,1,5);
    layout->addWidget(spinBox_Destrezza,1,6);
    layout->addWidget(label_Intelligenza,2,5);
    layout->addWidget(spinBox_Intelligenza,2,6);
    layout->addWidget(label_Fede,1,7);
    layout->addWidget(spinBox_Fede,1,8);
    layout->addWidget(label_Livello,2,7);
    layout->addWidget(lcdNumber_Livello,2,8);
    layout->setSpacing(15);
    setLayout(layout);

}

