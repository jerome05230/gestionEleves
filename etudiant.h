
#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <QString>
#include <vector>
using namespace std;

class Etudiant
{
private:
  QString nom;
  QString prenom;
public:
  Etudiant();
  Etudiant(QString leNom, QString lePrenom);
  void affiche();
  void fromKeyboard();

  /**
   * Set the value of nom
   * @param new_var the new value of nom
   */
  void setNom ( QString leNom );

  /**
   * Get the value of nom
   * @return the value of nom
   */
  QString getNom ( );  

  /**
   * Set the value of prénom
   * @param new_var the new value of prénom
   */
  void setPrenom ( QString lePrenom ); 

  /**
   * Get the value of prénom
   * @return the value of prénom
   */
  QString getPrenom ( );
};

#endif // ETUDIANT_H
