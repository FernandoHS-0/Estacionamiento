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
    explicit Usuario(Usua *,QWidget *parent = nullptr);
    ~Usuario();

private:
    Ui::Usuario *ui;
    QSqlDatabase db;
    Usua * sesionUsuario;
};

#endif // USUARIO_H
