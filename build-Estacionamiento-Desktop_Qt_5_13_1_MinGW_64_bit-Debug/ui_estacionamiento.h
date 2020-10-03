/********************************************************************************
** Form generated from reading UI file 'estacionamiento.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESTACIONAMIENTO_H
#define UI_ESTACIONAMIENTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Estacionamiento
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *btnAcceder;
    QWidget *widget;
    QPushButton *accederEst;
    QLineEdit *txtNoCliente;
    QLabel *label;
    QPushButton *pushButton;
    QWidget *page_2;
    QWidget *widget_2;
    QLineEdit *txtAdmin;
    QLabel *label_3;
    QPushButton *btnIngresar;
    QLineEdit *txtPswrd;
    QLabel *label_2;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *Estacionamiento)
    {
        if (Estacionamiento->objectName().isEmpty())
            Estacionamiento->setObjectName(QString::fromUtf8("Estacionamiento"));
        Estacionamiento->resize(718, 573);
        centralWidget = new QWidget(Estacionamiento);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: #2A4161;\n"
"}"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 711, 531));
        stackedWidget->setStyleSheet(QString::fromUtf8("QStackedWidget{\n"
"	background-color: #2A4161;\n"
"}"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        btnAcceder = new QPushButton(page);
        btnAcceder->setObjectName(QString::fromUtf8("btnAcceder"));
        btnAcceder->setGeometry(QRect(640, 20, 71, 61));
        btnAcceder->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/LlaveBlanca.png);\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/LlaveAzul.png);\n"
"}"));
        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 220, 501, 231));
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
"}"));
        accederEst = new QPushButton(widget);
        accederEst->setObjectName(QString::fromUtf8("accederEst"));
        accederEst->setGeometry(QRect(190, 160, 121, 31));
        accederEst->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #2A4161;\n"
"	color: white;\n"
"	font: 10pt \"Corbel\";\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: #C2C9F2;\n"
"}"));
        txtNoCliente = new QLineEdit(widget);
        txtNoCliente->setObjectName(QString::fromUtf8("txtNoCliente"));
        txtNoCliente->setGeometry(QRect(130, 110, 251, 31));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 421, 21));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 30, 171, 161));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border: none;\n"
"image: url(:/img/img/park_w.png);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        widget_2 = new QWidget(page_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(90, 240, 501, 201));
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
"}"));
        txtAdmin = new QLineEdit(widget_2);
        txtAdmin->setObjectName(QString::fromUtf8("txtAdmin"));
        txtAdmin->setGeometry(QRect(180, 40, 200, 30));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 90, 81, 31));
        btnIngresar = new QPushButton(widget_2);
        btnIngresar->setObjectName(QString::fromUtf8("btnIngresar"));
        btnIngresar->setGeometry(QRect(180, 130, 151, 31));
        btnIngresar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #2A4161;\n"
"	color: white;\n"
"	font: 10pt \"Corbel\";\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: #C2C9F2;\n"
"}"));
        txtPswrd = new QLineEdit(widget_2);
        txtPswrd->setObjectName(QString::fromUtf8("txtPswrd"));
        txtPswrd->setGeometry(QRect(180, 90, 201, 30));
        txtPswrd->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 42, 81, 20));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 60, 161, 141));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgba(0,0,0,0);\n"
"	border: none;\n"
"	image: url(:/img/img/AdministradorBlanco.png);\n"
"}\n"
""));
        stackedWidget->addWidget(page_2);
        Estacionamiento->setCentralWidget(centralWidget);

        retranslateUi(Estacionamiento);

        QMetaObject::connectSlotsByName(Estacionamiento);
    } // setupUi

    void retranslateUi(QMainWindow *Estacionamiento)
    {
        Estacionamiento->setWindowTitle(QCoreApplication::translate("Estacionamiento", "Estacionamiento", nullptr));
        btnAcceder->setText(QString());
        accederEst->setText(QCoreApplication::translate("Estacionamiento", "Acceder", nullptr));
        label->setText(QCoreApplication::translate("Estacionamiento", "Introduzca su n\303\272mero de cliente para acceder a su reservaci\303\263n:", nullptr));
        pushButton->setText(QString());
        label_3->setText(QCoreApplication::translate("Estacionamiento", "Contrase\303\261a", nullptr));
        btnIngresar->setText(QCoreApplication::translate("Estacionamiento", "Ingresar", nullptr));
        label_2->setText(QCoreApplication::translate("Estacionamiento", "No. Usuario", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Estacionamiento: public Ui_Estacionamiento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTACIONAMIENTO_H
