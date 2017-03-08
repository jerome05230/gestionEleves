#ifndef MATIERE_H
#define MATIERE_H

#include <QString>
#include <vector>

using namespace std;
class Matiere
{
private:
    QString nomMatiere;
	int coeff;
public:
  Matiere ( );
  Matiere(QString nomLaMatiere,int leCoeff);
  void setNomMatiere(QString laMatiere);
  QString getNomMatiere();
  void setCoeff(int leCoeff);
  int getCoeff();

  void affiche();

};//fin de la classe Matiere
#endif // MATIERE_H
