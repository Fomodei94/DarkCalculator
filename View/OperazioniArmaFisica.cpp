#include "OperazioniArmaFisica.h"

OperazioniArmaFisica::OperazioniArmaFisica(QWidget* parent, ArmaFisica* arma, Caratteristiche* car): QWidget(parent), armaIstanza(arma), car(car){
	label = new QLabel("<h4>Operazioni Arma Fisica</h4>", this);
	DannoEffettivo = new QPushButton("Danno Effettivo", this);
        connect(DannoEffettivo, SIGNAL(clicked()), this, SLOT(CalcolaDannoEffettivo()));
	Efficacia = new QPushButton("Efficacia", this);
	Raffina = new QPushButton("Raffina", this);
	Frantuma = new QPushButton("Frantuma", this);
	Cristallizza = new QPushButton("Cristallizza", this);
	Riforgia = new QPushButton("Riforgia", this);
	VerificaUsabilita = new QPushButton("Verifica Usabilità", this);
	winLayout = new QGridLayout(this);
	winLayout->addWidget(label, 0,0,1,2);
	winLayout->addWidget(DannoEffettivo, 1,0);
	winLayout->addWidget(Efficacia, 1,1);
	winLayout->addWidget(VerificaUsabilita,2,0);
	winLayout->addWidget(Raffina,2,1);
	winLayout->addWidget(Frantuma,3,0);
	winLayout->addWidget(Cristallizza,3,1);
	winLayout->addWidget(Riforgia,4,0);
	setLayout(winLayout);
}

void OperazioniArmaFisica::CalcolaDannoEffettivo(){
        double effettivo = armaIstanza->DannoEffettivo(*car);
        emit MostraDannoEffettivo(effettivo);
}
