#include "evaluation.h"
#include <iostream>
#include <QDebug>
using namespace std;
// Constructors/Destructors
//  

Evaluation::Evaluation() {
  vectNotes.clear();
}

void Evaluation::viderLesNotes() {
  vectNotes.clear();
}

void Evaluation::fromKeyboard()
{
	viderLesNotes();
	qDebug() << endl << "****Nouvelle evaluation****" << endl;
	qDebug() << "Coefficient: ";
	cin >> coefficient;
	cin.ignore(1);
	qDebug() << "Date: ";
//	getline(cin,date);
	qDebug() << "Numero: ";
	cin >> numero;
	cin.ignore(1);
}

void Evaluation::setNumero ( int new_var )   {
	numero = new_var;
}

/**
 * Get the value of numero
 * @return the value of numero
 */
int Evaluation::getNumero ( )   {
	return numero;
}

/**
 * Set the value of date
 * @param new_var the new value of date
 */
void Evaluation::setDate ( QString new_var )   {
	date = new_var;
}

/**
 * Get the value of date
 * @return the value of date
 */
QString Evaluation::getDate ( )   {
	return date;
}

/**
 * Set the value of coefficient
 * @param new_var the new value of coefficient
 */
void Evaluation::setCoefficient ( int new_var )   {
	coefficient = new_var;
}

/**
 * Get the value of coefficient
 * @return the value of coefficient
 */
int Evaluation::getCoefficient ( )   {
	return coefficient;
}

/**
 * Set the value of laMatiere
 * @param new_var the new value of laMatiere
 */
void  Evaluation::setLaMatiere ( Matiere* new_var )   {
	laMatiere = new_var;
}

/**
 * Get the value of laMatiere
 * @return the value of laMatiere
 */
Matiere*  Evaluation::getLaMatiere ( )   {
	return laMatiere;
}

/**
 * Set the value of vectNotes
 * @param new_var the new value of vectNotes
 */
void  Evaluation::setVectNotes ( vector<Note> new_var )   {
	vectNotes = new_var;
}

/**
 * Get the value of vectNotes
 * @return the value of vectNotes
 */
vector<Note>&  Evaluation::getVectNotes ( )   {
	return vectNotes;
}
void Evaluation::addNote(Note laNote)
{
	vectNotes.push_back(laNote);
}
/**
 * @brief affiche l'evaluation
 * Affiche le numéro, le nom de la matière, la date, 
 * et pour chaque note les noms et prénoms de l'élève
 * la note en elle-même
 * Enfin affiche la moyenne de l'évaluation
 */
void Evaluation::affiche()
{
  qDebug() << endl << "*************Evaluation ***************" << endl;	
  qDebug() << "Numéro d'évaluation: " << numero << endl;
  laMatiere->affiche();
  qDebug() << "Date: " << date << endl;
  double sommeDesNotes=0,moyenne;
  for(int noNote=0;noNote<vectNotes.size();noNote++)
  {
	  vectNotes[noNote].affiche();
	  sommeDesNotes+=vectNotes[noNote].getValeur();
  }
  qDebug() << "La moyenne de cette évaluation est de: " << sommeDesNotes/vectNotes.size() << endl;
}
