
#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <vector>
#include "etudiant.h"


class Note
{
	private:

		Etudiant* lEtudiant;
		double valeur;
	public:

		Note ( );
		void setLEtudiant ( Etudiant* new_var );   
		Etudiant* getLEtudiant ( ); 
		void setValeur ( double new_var ); 
		double getValeur ( );  
		void fromKeyboard();
		void affiche();
};

#endif // NOTE_H
