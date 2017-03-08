#include "etudiant.h"
#include <iostream>
#include <QDebug>

// Constructors/Destructors
//  

Etudiant::Etudiant() { }
Etudiant::Etudiant(QString leNom,QString lePrenom)
{
    nom=leNom;
    prenom=lePrenom;
}

QString Etudiant::getNom(){return nom;}

QString Etudiant::getPrenom(){return prenom;}

void Etudiant::setNom( QString leNom)
{
	nom=leNom;
}

void Etudiant::setPrenom( QString lePrenom) 
{
	prenom=lePrenom;
}
void Etudiant::affiche()
{
	qDebug() << "Nom: " << nom << "\tPrenom: " << prenom << endl;
}
void Etudiant::fromKeyboard()
{
	qDebug() << "Saisie d'un nouvel Etudiant" << endl;
	qDebug() << "Nom: ";
//	getline(cin,nom);
	qDebug() << "Prenom: ";
//	getline(cin,prenom);
}

