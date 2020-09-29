/********************************************************************************
** Form generated from reading UI file 'administrador.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
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
    QWidget *widget_2;
    QPushButton *Acualizar1;
    QLabel *TipoTarifa1;
    QPushButton *actualizar2;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *TipoTarifa2;
    QDoubleSpinBox *NuevaTarifa2;
    QLabel *label_4;
    QLabel *TarifaActual2;
    QDoubleSpinBox *NuevaTarifa1;
    QLabel *TarifaActual1;
    QWidget *page_2;
    QWidget *widget;
    QTableWidget *Registros;
    QLabel *label_5;
    QWidget *Comentarios;
    QWidget *widget_3;
    QLabel *label;
    QTableWidget *tablacomentarios;
    QPushButton *btnSalir;

    void setupUi(QDialog *Administrador)
    {
        if (Administrador->objectName().isEmpty())
            Administrador->setObjectName(QString::fromUtf8("Administrador"));
        Administrador->resize(789, 571);
        Administrador->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	background-color: #2A4161;\n"
"}"));
        btnTaridas = new QPushButton(Administrador);
        btnTaridas->setObjectName(QString::fromUtf8("btnTaridas"));
        btnTaridas->setGeometry(QRect(20, 90, 81, 71));
        btnTaridas->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/TarifasBlanca.png);\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/TarifasAzul.png);\n"
"}"));
        btnRegistros = new QPushButton(Administrador);
        btnRegistros->setObjectName(QString::fromUtf8("btnRegistros"));
        btnRegistros->setGeometry(QRect(20, 200, 81, 71));
        btnRegistros->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/RegistroBlanco.png);\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/RegistroAzul.png);\n"
"}"));
        btnComentarios = new QPushButton(Administrador);
        btnComentarios->setObjectName(QString::fromUtf8("btnComentarios"));
        btnComentarios->setGeometry(QRect(20, 310, 81, 71));
        btnComentarios->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/ComentariosBlanco.png);\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/ComentariosAzul.png);\n"
"}"));
        stackedWidget = new QStackedWidget(Administrador);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(110, 0, 681, 571));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: #B8BDD9;"));
        Tafifas = new QWidget();
        Tafifas->setObjectName(QString::fromUtf8("Tafifas"));
        widget_2 = new QWidget(Tafifas);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(20, 50, 641, 481));
        widget_2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: white;\n"
"}\n"
"\n"
"QLabel{\n"
"	font: 12pt \"Corbel\";\n"
"	color: black,\n"
"}\n"
"\n"
"QLineEdit{\n"
"	border: 1px solid #A1C1E6;\n"
"}\n"
"\n"
"QDoubleSpinBox{\n"
"	border: 1px solid #A1C1E6;\n"
"}"));
        Acualizar1 = new QPushButton(widget_2);
        Acualizar1->setObjectName(QString::fromUtf8("Acualizar1"));
        Acualizar1->setGeometry(QRect(540, 180, 81, 31));
        Acualizar1->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #2A4161;\n"
"	color: white;\n"
"	font: 10pt \"Corbel\";\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: #C2C9F2;\n"
"}"));
        TipoTarifa1 = new QLabel(widget_2);
        TipoTarifa1->setObjectName(QString::fromUtf8("TipoTarifa1"));
        TipoTarifa1->setGeometry(QRect(60, 180, 111, 31));
        actualizar2 = new QPushButton(widget_2);
        actualizar2->setObjectName(QString::fromUtf8("actualizar2"));
        actualizar2->setGeometry(QRect(540, 290, 81, 31));
        actualizar2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #2A4161;\n"
"	color: white;\n"
"	font: 10pt \"Corbel\";\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: #C2C9F2;\n"
"}"));
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 10, 141, 61));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Corbel\";"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(420, 95, 91, 31));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(247, 95, 101, 31));
        TipoTarifa2 = new QLabel(widget_2);
        TipoTarifa2->setObjectName(QString::fromUtf8("TipoTarifa2"));
        TipoTarifa2->setGeometry(QRect(60, 290, 111, 31));
        NuevaTarifa2 = new QDoubleSpinBox(widget_2);
        NuevaTarifa2->setObjectName(QString::fromUtf8("NuevaTarifa2"));
        NuevaTarifa2->setGeometry(QRect(420, 290, 81, 31));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 95, 91, 31));
        TarifaActual2 = new QLabel(widget_2);
        TarifaActual2->setObjectName(QString::fromUtf8("TarifaActual2"));
        TarifaActual2->setGeometry(QRect(240, 290, 111, 31));
        NuevaTarifa1 = new QDoubleSpinBox(widget_2);
        NuevaTarifa1->setObjectName(QString::fromUtf8("NuevaTarifa1"));
        NuevaTarifa1->setGeometry(QRect(420, 180, 81, 31));
        TarifaActual1 = new QLabel(widget_2);
        TarifaActual1->setObjectName(QString::fromUtf8("TarifaActual1"));
        TarifaActual1->setGeometry(QRect(240, 180, 111, 31));
        stackedWidget->addWidget(Tafifas);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        widget = new QWidget(page_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 60, 641, 481));
        widget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: white;\n"
"}\n"
"\n"
"QLabel{\n"
"	font: 12pt \"Corbel\";\n"
"	color: black,\n"
"}\n"
"\n"
"QLineEdit{\n"
"	border: 1px solid #A1C1E6;\n"
"}\n"
"\n"
"QTableWidget{\n"
"	border: 1px solid #A1C1E6;\n"
"}"));
        Registros = new QTableWidget(widget);
        Registros->setObjectName(QString::fromUtf8("Registros"));
        Registros->setGeometry(QRect(30, 90, 591, 351));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 40, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Corbel\";"));
        stackedWidget->addWidget(page_2);
        Comentarios = new QWidget();
        Comentarios->setObjectName(QString::fromUtf8("Comentarios"));
        widget_3 = new QWidget(Comentarios);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(20, 60, 641, 481));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: white;\n"
"}\n"
"\n"
"QLabel{\n"
"	font: 12pt \"Corbel\";\n"
"	color: black,\n"
"}\n"
"\n"
"QLineEdit{\n"
"	border: 1px solid #A1C1E6;\n"
"}\n"
"\n"
"QTableWidget{\n"
"	border: 1px solid #A1C1E6;\n"
"}"));
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(239, 40, 181, 31));
        label->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Corbel\";"));
        tablacomentarios = new QTableWidget(widget_3);
        tablacomentarios->setObjectName(QString::fromUtf8("tablacomentarios"));
        tablacomentarios->setGeometry(QRect(30, 90, 591, 351));
        stackedWidget->addWidget(Comentarios);
        btnSalir = new QPushButton(Administrador);
        btnSalir->setObjectName(QString::fromUtf8("btnSalir"));
        btnSalir->setGeometry(QRect(20, 430, 71, 61));
        btnSalir->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/logout.png);\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/logout_hover.png);\n"
"}"));

        retranslateUi(Administrador);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Administrador);
    } // setupUi

    void retranslateUi(QDialog *Administrador)
    {
        Administrador->setWindowTitle(QCoreApplication::translate("Administrador", "Dialog", nullptr));
        btnTaridas->setText(QString());
        btnRegistros->setText(QString());
        btnComentarios->setText(QString());
        Acualizar1->setText(QCoreApplication::translate("Administrador", "Actualizar", nullptr));
        TipoTarifa1->setText(QString());
        actualizar2->setText(QCoreApplication::translate("Administrador", "Actualizar", nullptr));
        label_2->setText(QCoreApplication::translate("Administrador", "Modificar tarifas", nullptr));
        label_6->setText(QCoreApplication::translate("Administrador", "Nueva Tarifa", nullptr));
        label_3->setText(QCoreApplication::translate("Administrador", "Tarifa actual", nullptr));
        TipoTarifa2->setText(QString());
        label_4->setText(QCoreApplication::translate("Administrador", "Tipo de tarifa", nullptr));
        TarifaActual2->setText(QString());
        TarifaActual1->setText(QString());
        label_5->setText(QCoreApplication::translate("Administrador", "Registros", nullptr));
        label->setText(QCoreApplication::translate("Administrador", "Quejas y sugerencias", nullptr));
        btnSalir->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Administrador: public Ui_Administrador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRADOR_H
