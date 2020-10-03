
#ifndef USUARIO_H
#define USUARIO_H

#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include <qdebug.h>
#include "estacionamiento.h"
#include <QString>
#include <QMessageBox>
#include "objetos.h"
#include <QTime>
namespace Ui {
class Usuario;
}

class Usuario : public QDialog
{
    Q_OBJECT

public:
    explicit Usuario(bool *,Usua *,QWidget *parent = nullptr);
    ~Usuario();

private slots:
    void on_Aceptar_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Usuario *ui;
    QSqlDatabase db;
    Usua * sesionUsuario;
};

#endif // USUARIO_H
