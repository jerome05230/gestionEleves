#ifndef DIALOGMATIERE_H
#define DIALOGMATIERE_H

#include <QDialog>

namespace Ui {
class DialogMatiere;
}

class DialogMatiere : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMatiere(QWidget *parent = 0);
    ~DialogMatiere();
    QString getNomMatiere();
    int getCoeffMatiere();

private:
    Ui::DialogMatiere *ui;
};

#endif // DIALOGMATIERE_H
