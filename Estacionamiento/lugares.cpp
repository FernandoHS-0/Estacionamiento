#include "lugares.h"
#include "ui_lugares.h"

Lugares::Lugares(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lugares)
{
    ui->setupUi(this);
}

Lugares::~Lugares()
{
    delete ui;
}
