#include "matiere.h"
#include <iostream>
#include <QDebug>
using namespace std;

Matiere::Matiere() { }
Matiere::Matiere(QString nomLaMatiere, int leCoeff){
    nomMatiere=nomLaMatiere;
    coeff=leCoeff;
    }

void Matiere::setNomMatiere ( QString laMatiere)   {
	nomMatiere = laMatiere;
}
QString Matiere::getNomMatiere ( )   {
	return nomMatiere;
}

void Matiere::affiche()
{
    qDebug() << "nom: " << nomMatiere << " coeff: " << coeff << endl;

}

void Matiere::setCoeff( int leCoeff)   {
	coeff = leCoeff;
}

int Matiere::getCoeff ( )   {
	return coeff;
}

