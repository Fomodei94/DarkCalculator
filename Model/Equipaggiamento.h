#ifndef EQUIPAGGIAMENTO_H
#define EQUIPAGGIAMENTO_H

#include"Caratteristiche.h"
#include "../View/MainWindow.h"

class Equipaggiamento{ //CLASSE BASE ASTRATTA
        private:
                double peso;
                double usura;
                mainWindow* view;

        protected:
                double Moltiplicatore(char) const; //METODO PURAMENTE IMPLEMENTATIVO PER LA GERARCHIA
                void notify();

        public:
                Equipaggiamento(double p=0.0, double u=0.0); //COSTRUTTORE A DUE PARAMETR

                //GETTER

                double GetPeso() const;
                double GetUsura() const;
                virtual ~Equipaggiamento()= default;

                //SETTER

                void SetPeso(double x=0.0);
                void SetUsura(double x=0.0);

                //METODI VIRTUALI

                virtual bool VerificaUsabilita(const Caratteristiche&) const = 0; //METODO VIRTUALE PURO
                virtual bool operator==(const Equipaggiamento&) const;
                virtual bool operator!=(const Equipaggiamento&) const;
};


#endif

