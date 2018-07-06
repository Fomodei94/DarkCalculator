#ifndef OPERAZIONI_ARMAMAGICA
#define OPERAZIONI_ARMAMAGICA
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "../Model/ArmaMagica.h"
#include"OperazioniArma.h"

class OperazioniArmaMagica: public OperazioniArma{
        Q_OBJECT
	private:
	QPushButton *Incanta,
							*Infuoca,
							*Benedici,
							*Maledici,
							*ArteMistica;
		ArmaMagica* armaMagicaIstanza;
		Caratteristiche* car;
  protected:
		void connectSignalsOperazioniProprie();
		
	public:
		OperazioniArmaMagica(QWidget* parent = nullptr, ArmaMagica* arma = nullptr, Caratteristiche* car=nullptr);
  
  signals:
		void MostraRisultatoNumerico(double x);
		void MostraRisultatoBooleano(bool x);
		
  public slots:
		void CalcolaDannoEffettivo() override;
		void CalcolaEfficacia() override;
		void CalcolaUsabilita() override;
		void CalcolaConfronto() override;
		void CalcolaSomma() override;
		void EseguiIncanta();
		void EseguiInfuoca();
		void EseguiBenedici();
		void EseguiMaledici();
		void CalcolaArteMistica();
};
#endif

