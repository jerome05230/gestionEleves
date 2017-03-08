#ifndef EVALUATION_H
#define EVALUATION_H

#include <QString>
#include <vector>
#include "matiere.h"
#include "note.h"
using namespace std;

class Evaluation
{
private:

  
  // Private attributes
  //  

  int numero;
  QString date;
  int coefficient;
  Matiere* laMatiere;
  vector<Note> vectNotes;

public:
Evaluation ( );


  void setNumero ( int new_var ); 
  int getNumero ( );  
  void setDate ( QString new_var );
   QString getDate ( ); 
  void setCoefficient ( int new_var );
  int getCoefficient ( ); 
  void setLaMatiere ( Matiere* new_var ); 
  Matiere* getLaMatiere ( );  
  void setVectNotes ( vector<Note> new_var );
  vector<Note>& getVectNotes ( );
  void fromKeyboard();
  void addNote(Note laNote);
  void affiche();
/**
*	@brief vide le vecteur de notes
*/
  void viderLesNotes();
};

#endif // EVALUATION_H
