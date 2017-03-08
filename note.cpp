#include "note.h"
#include <iostream>
#include <QDebug>
Note::Note ( ) { }

void Note::setLEtudiant ( Etudiant* new_var)
{
	lEtudiant=new_var;
}
Etudiant* Note::getLEtudiant ( )
{
	return lEtudiant;
}    
void Note::setValeur ( double new_var )   {
	valeur = new_var;
}

double Note::getValeur ( )   {
	return valeur;
}
void Note::fromKeyboard()
{
	qDebug() << "Tapez la note de l'eleve " << lEtudiant->getPrenom() << " " << lEtudiant->getNom() << ": ";
	cin >> valeur;
	cin.ignore(1);
}
void Note::affiche()
{
	qDebug() << lEtudiant->getPrenom() << " " << lEtudiant->getNom() << ": " << valeur << endl;
}


