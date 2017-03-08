#ifndef SECTION_H
#define SECTION_H

#include <QString>
#include <vector>
#include <map>
#include "evaluation.h"
#include "etudiant.h"

class Section
{
public:

  Section ( );
  Section(QString leNom);
  virtual ~Section ( );
  void gerer();
  void affiche();
  void setNom(QString );
  QString getNomSection();
  vector<Matiere*> getVectMatieresSection();
  vector<Etudiant>  getVectEtudiants();
  void fromKeyboard();//saisie de la section
  void addMatiere(Matiere *);//ajoute une matière
  void addEleve(QString leNomEleve, QString lePrenomEleve);
  Matiere* matiereSelector(bool);//renvoie la matiereChoisie parmi toute si le paramètre est à true ou parmi les matieres de la section sinon
  bool dejaInscrite(Matiere * laMatiere);//renvoie vrai si la matiere est déjà pour la section

  //variables de classe
  static vector<Matiere>* vectAllMatieres;
  void preparerBulletins();
  void afficherMoyennesParEleveEtParMatiere();
  /*
   * @brief affiche les notes de l'élève s'il existe et sa moyenne par matiere
   * permet de demander la sisie du nom d'un étudiant de vérifier on existance et d'afficher toute les note par matiere ainsi que de calculer sa moyenne dans la matière
   */
  void afficherNotesEtMoyenneParMatiere();

private:
  QString nom;
  vector <Evaluation> vectEvaluations;
  vector <Etudiant> vectEtudiants;
  vector <Matiere*> vectMatieresSection;
  map<Etudiant*,map<Matiere*,vector<Note*> > > mapNotesParEtudiantEtParMatiere;
  void afficherMap();
};

#endif // SECTION_H
