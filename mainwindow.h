#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "section.h"
#include "matiere.h"
#include "dialogmatiere.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    vector<Section> vectSections;
    vector<Matiere> vectMatieres;
    Section* sectionCourante;



private slots:
    void on_actionQuitter_triggered();

    void on_pushButtonNewSection_clicked();

    void on_pushButtonNewMatiere_clicked();

    void on_pushButtonAddMatiere_clicked();

    void on_pushButtonNewEleve_clicked();

    void afficherSectionEleves();

    void actualiserSectionEleves(QString nomEleve, QString prenomEleve);

    void afficherSectionMatieres();

    void actualiserSectionMatieres(QString nomMatiere, int coeffMatiere);

    void on_comboBoxSection_activated(const QString &arg1);


private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
