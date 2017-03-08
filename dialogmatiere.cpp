#include "dialogmatiere.h"
#include "ui_dialogmatiere.h"
#include <QDebug>

DialogMatiere::DialogMatiere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMatiere)
{
    ui->setupUi(this);
}

DialogMatiere::~DialogMatiere()
{
    delete ui;
}

QString DialogMatiere::getNomMatiere()
{
    return ui->lineEditNomMat->text();
}

int DialogMatiere::getCoeffMatiere()
{
    return ui->spinBoxCoeffMat->value();
}


