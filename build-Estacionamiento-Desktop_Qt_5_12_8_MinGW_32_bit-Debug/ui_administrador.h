/********************************************************************************
** Form generated from reading UI file 'administrador.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRADOR_H
#define UI_ADMINISTRADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Administrador
{
public:
    QPushButton *btnTaridas;
    QPushButton *btnRegistros;
    QPushButton *btnComentarios;
    QStackedWidget *stackedWidget;
    QWidget *Tafifas;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *TipoTarifa1;
    QLabel *TarifaActual1;
    QPushButton *Acualizar1;
    QLabel *TipoTarifa2;
    QLabel *TarifaActual2;
    QPushButton *actualizar2;
    QDoubleSpinBox *NuevaTarifa1;
    QDoubleSpinBox *NuevaTarifa2;
    QWidget *page_2;
    QWidget *Comentarios;
    QLabel *label;
    QTableWidget *tablacomentarios;
    QPushButton *btnSalir;

    void setupUi(QDialog *Administrador)
    {
        if (Administrador->objectName().isEmpty())
            Administrador->setObjectName(QString::fromUtf8("Administrador"));
        Administrador->resize(789, 571);
        btnTaridas = new QPushButton(Administrador);
        btnTaridas->setObjectName(QString::fromUtf8("btnTaridas"));
        btnTaridas->setGeometry(QRect(50, 100, 75, 23));
        btnRegistros = new QPushButton(Administrador);
        btnRegistros->setObjectName(QString::fromUtf8("btnRegistros"));
        btnRegistros->setGeometry(QRect(50, 180, 75, 23));
        btnComentarios = new QPushButton(Administrador);
        btnComentarios->setObjectName(QString::fromUtf8("btnComentarios"));
        btnComentarios->setGeometry(QRect(50, 260, 75, 23));
        stackedWidget = new QStackedWidget(Administrador);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(130, 10, 651, 541));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: white;"));
        Tafifas = new QWidget();
        Tafifas->setObjectName(QString::fromUtf8("Tafifas"));
        label_2 = new QLabel(Tafifas);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 40, 101, 31));
        label_3 = new QLabel(Tafifas);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 100, 101, 31));
        label_4 = new QLabel(Tafifas);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 100, 81, 31));
        label_6 = new QLabel(Tafifas);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(430, 100, 91, 31));
        TipoTarifa1 = new QLabel(Tafifas);
        TipoTarifa1->setObjectName(QString::fromUtf8("TipoTarifa1"));
        TipoTarifa1->setGeometry(QRect(90, 160, 111, 31));
        TarifaActual1 = new QLabel(Tafifas);
        TarifaActual1->setObjectName(QString::fromUtf8("TarifaActual1"));
        TarifaActual1->setGeometry(QRect(260, 160, 91, 31));
        Acualizar1 = new QPushButton(Tafifas);
        Acualizar1->setObjectName(QString::fromUtf8("Acualizar1"));
        Acualizar1->setGeometry(QRect(570, 140, 75, 23));
        TipoTarifa2 = new QLabel(Tafifas);
        TipoTarifa2->setObjectName(QString::fromUtf8("TipoTarifa2"));
        TipoTarifa2->setGeometry(QRect(100, 240, 81, 31));
        TarifaActual2 = new QLabel(Tafifas);
        TarifaActual2->setObjectName(QString::fromUtf8("TarifaActual2"));
        TarifaActual2->setGeometry(QRect(260, 240, 111, 31));
        actualizar2 = new QPushButton(Tafifas);
        actualizar2->setObjectName(QString::fromUtf8("actualizar2"));
        actualizar2->setGeometry(QRect(570, 240, 75, 23));
        NuevaTarifa1 = new QDoubleSpinBox(Tafifas);
        NuevaTarifa1->setObjectName(QString::fromUtf8("NuevaTarifa1"));
        NuevaTarifa1->setGeometry(QRect(440, 150, 62, 22));
        NuevaTarifa2 = new QDoubleSpinBox(Tafifas);
        NuevaTarifa2->setObjectName(QString::fromUtf8("NuevaTarifa2"));
        NuevaTarifa2->setGeometry(QRect(450, 240, 62, 22));
        stackedWidget->addWidget(Tafifas);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        Comentarios = new QWidget();
        Comentarios->setObjectName(QString::fromUtf8("Comentarios"));
        label = new QLabel(Comentarios);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 40, 121, 16));
        tablacomentarios = new QTableWidget(Comentarios);
        tablacomentarios->setObjectName(QString::fromUtf8("tablacomentarios"));
        tablacomentarios->setGeometry(QRect(10, 70, 621, 421));
        stackedWidget->addWidget(Comentarios);
        btnSalir = new QPushButton(Administrador);
        btnSalir->setObjectName(QString::fromUtf8("btnSalir"));
        btnSalir->setGeometry(QRect(50, 390, 75, 23));

        retranslateUi(Administrador);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Administrador);
    } // setupUi

    void retranslateUi(QDialog *Administrador)
    {
        Administrador->setWindowTitle(QApplication::translate("Administrador", "Dialog", nullptr));
        btnTaridas->setText(QApplication::translate("Administrador", "Tarifas", nullptr));
        btnRegistros->setText(QApplication::translate("Administrador", "Registros", nullptr));
        btnComentarios->setText(QApplication::translate("Administrador", "Comentarios", nullptr));
        label_2->setText(QApplication::translate("Administrador", "Modificar tarifas:", nullptr));
        label_3->setText(QApplication::translate("Administrador", "tarifa actual", nullptr));
        label_4->setText(QApplication::translate("Administrador", "Tipo de tarifa", nullptr));
        label_6->setText(QApplication::translate("Administrador", "Nueva Tarifa", nullptr));
        TipoTarifa1->setText(QString());
        TarifaActual1->setText(QString());
        Acualizar1->setText(QApplication::translate("Administrador", "PushButton", nullptr));
        TipoTarifa2->setText(QString());
        TarifaActual2->setText(QString());
        actualizar2->setText(QApplication::translate("Administrador", "PushButton", nullptr));
        label->setText(QApplication::translate("Administrador", "Quejas y sugerencias", nullptr));
        btnSalir->setText(QApplication::translate("Administrador", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Administrador: public Ui_Administrador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRADOR_H
