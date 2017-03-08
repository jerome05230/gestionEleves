#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sectionCourante=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    int ret=QMessageBox::question(this,tr("GestElves"),tr("Etes-vous sur de vouloir quitter ?"), QMessageBox::Yes | QMessageBox::No,QMessageBox::No);
    if(ret==QMessageBox::Yes){
        close();
    }
}


void MainWindow::on_pushButtonNewSection_clicked()
{
    bool ok;
    QString nomSection=QInputDialog::getText(
                this,
                tr("GestEleves"),
                tr("Section Name: "),
                QLineEdit::Normal,
                "SIO_XXX",
                &ok);
    if (ok && !nomSection.isEmpty())
    {
        int poss=ui->comboBoxSection->findText(nomSection);

        if (poss==-1){
            Section nouvelleSection(nomSection);
            vectSections.push_back(nouvelleSection);
            ui->comboBoxSection->addItem(nomSection);
        }
        else {
            ui->statusBar->showMessage(tr("This section already exist"), 5000);
        }
    }
    else qDebug()<<"Erreur"<<endl;
}

void MainWindow::on_pushButtonNewMatiere_clicked()
{
    DialogMatiere FormMatiere;

    if (FormMatiere.exec() ==QDialog::Accepted){
        QString nomMat=FormMatiere.getNomMatiere();
        int coeffMat=FormMatiere.getCoeffMatiere();
        int poss=ui->comboBoxMatiere->findText(nomMat);
        bool exist=false;
        unsigned int noMat=0;
        while (noMat<vectMatieres.size())
        {
            if (nomMat==vectMatieres[noMat].getNomMatiere())
            {
                exist=true;
            }
            noMat++;
        }
        if (!(nomMat.size()==0)||(exist==false)){
                if(poss==-1){
                ui->comboBoxMatiere->addItem(nomMat);
                Matiere nouvelleMatiere(nomMat,coeffMat);
                vectMatieres.push_back(nouvelleMatiere);
            }
            else{
                ui->statusBar->showMessage(tr("This subject abready exist or is null"), 5000);
            }
        }
        else
        {
            ui->statusBar->showMessage(tr("subject name is not set"), 5000);
        }
    }
}

void MainWindow::on_pushButtonAddMatiere_clicked()
{
    QString matiereSection=(ui->comboBoxMatiere->currentText());
    unsigned int noMat=0;
    vector<Matiere*> monVectMatiereSection=sectionCourante->getVectMatieresSection();
    bool exist=false;
    if(monVectMatiereSection.size()>0)
    {
        while(noMat<monVectMatiereSection.size() || exist==false)
        {
            if (matiereSection==monVectMatiereSection[noMat]->getNomMatiere())
            {
                exist=true;
            }
            noMat++;
        }
    }
    while(!(matiereSection==vectMatieres[noMat].getNomMatiere()))
    {
        noMat++;
    }
    if (exist==false)
    {
        Matiere* pMat=&vectMatieres[noMat];
        sectionCourante->addMatiere(pMat);
        actualiserSectionMatieres(vectMatieres[noMat].getNomMatiere(),vectMatieres[noMat].getCoeff());
    }
}

void MainWindow::actualiserSectionMatieres(QString nomMatiere,int coeffMatiere)
{
    ui->tableWidgetMatiere->setRowCount(ui->tableWidgetMatiere->rowCount()+1);
    int ligne=ui->tableWidgetMatiere->rowCount();

    QTableWidgetItem *itemNomMatiere=new QTableWidgetItem(nomMatiere);
    ui->tableWidgetMatiere->setItem(ligne-1,0,itemNomMatiere);
    QString coeffMatiereBis = QString::number(coeffMatiere);
    QTableWidgetItem *itemCoeffMatiere=new QTableWidgetItem(coeffMatiereBis);
    ui->tableWidgetMatiere->setItem(ligne-1,1,itemCoeffMatiere);
}
//affiches toutes les matières de la section courante
void MainWindow::afficherSectionMatieres(){
    if(sectionCourante!=NULL)
    {
        vector<Matiere*> monVectMatieresSection=sectionCourante->getVectMatieresSection();
        unsigned int nbMat=monVectMatieresSection.size();
        ui->tableWidgetMatiere->setRowCount(nbMat);
        for (unsigned int noMat=0;noMat<nbMat;noMat++)
        {
            QString nomMatiere=monVectMatieresSection[noMat]->getNomMatiere();
            QTableWidgetItem *itemNomMatiere=new QTableWidgetItem(nomMatiere);
            ui->tableWidgetMatiere->setItem(noMat,0,itemNomMatiere);
            QString coeffMatiere=QString::number(monVectMatieresSection[noMat]->getCoeff());
            QTableWidgetItem *itemCoeffMatiere=new QTableWidgetItem(coeffMatiere);
            ui->tableWidgetMatiere->setItem(noMat,1,itemCoeffMatiere);
        }
    }
    else qDebug()<<"Attention section courante non définie"<<endl;
}

//Nouvel élève dans la section courante
void MainWindow::on_pushButtonNewEleve_clicked()
{
    QString nomEleve=ui->lineEditNomEleve->text();
    QString prenomEleve=ui->lineEditPrenomEleve->text();
    sectionCourante->addEleve(nomEleve,prenomEleve);
    actualiserSectionEleves(nomEleve,prenomEleve);
}
//affiche le nouvel élève de la section courante
void MainWindow::actualiserSectionEleves(QString nomEleve,QString prenomEleve)
{
    ui->tableWidgetEleve->setRowCount(ui->tableWidgetEleve->rowCount()+1);
    int ligne=ui->tableWidgetEleve->rowCount();

    QTableWidgetItem *itemNomEleve=new QTableWidgetItem(nomEleve);
    ui->tableWidgetEleve->setItem(ligne-1,0,itemNomEleve);
    QTableWidgetItem *itemPrenomEleve=new QTableWidgetItem(prenomEleve);
    ui->tableWidgetEleve->setItem(ligne-1,1,itemPrenomEleve);
}
//affiche tous les élèves
void MainWindow::afficherSectionEleves(){
    if(sectionCourante!=NULL)
    {
        vector<Etudiant> monVectEtudiant=sectionCourante->getVectEtudiants();
        unsigned int nbElv=monVectEtudiant.size();
        ui->tableWidgetEleve->setRowCount(nbElv);
        for (unsigned int noElv=0;noElv<nbElv;noElv++)
        {
            QString nomEleve=monVectEtudiant[noElv].getNom();
            QTableWidgetItem *itemNomEleve=new QTableWidgetItem(nomEleve);
            ui->tableWidgetEleve->setItem(noElv,0,itemNomEleve);
            QString prenomEleve=monVectEtudiant[noElv].getPrenom();
            QTableWidgetItem *itemPrenomEleve=new QTableWidgetItem(prenomEleve);
            ui->tableWidgetEleve->setItem(noElv,1,itemPrenomEleve);
        }
    }
    else qDebug()<<"Attention section courante non définie"<<endl;
}


void MainWindow::on_comboBoxSection_activated(const QString &arg1)
{ if(!arg1.isEmpty() )
    {
        unsigned int noSec=0;
        while(noSec<vectSections.size() && arg1!=vectSections[noSec].getNomSection())
        {
            noSec++;
        }
        if (arg1==vectSections[noSec].getNomSection())
        {
            ui->labelSection->setText(arg1);
            sectionCourante=&vectSections[noSec];
            afficherSectionEleves();
            //ui->tableWidgetMatiere->setRowCount(0);
            afficherSectionMatieres();
        }
    }
    else qDebug()<<"Section vide"<<endl;

}

