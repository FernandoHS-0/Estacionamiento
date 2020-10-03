#ifndef LUGARES_H
#define LUGARES_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include "objetos.h"

namespace Ui {
class Lugares;
}

class Lugares : public QDialog
{
    Q_OBJECT

public:
    explicit Lugares(Usua*, QWidget *parent = nullptr);
    ~Lugares();

private slots:
    void on_espacio01_clicked();

    void on_btnCancelar_clicked();

private:
    Ui::Lugares *ui;
    QSqlDatabase dbconexion;
    Usua *sesCliente;
};

#endif // LUGARES_H
