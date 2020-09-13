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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Estacionamiento
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLineEdit *txtNoCliente;
    QPushButton *accederEst;
    QPushButton *btnAcceder;
    QWidget *page_2;
    QLineEdit *txtAdmin;
    QLineEdit *txtPswrd;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnIngresar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Estacionamiento)
    {
        if (Estacionamiento->objectName().isEmpty())
            Estacionamiento->setObjectName(QString::fromUtf8("Estacionamiento"));
        Estacionamiento->resize(718, 573);
        centralWidget = new QWidget(Estacionamiento);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 0, 711, 531));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 200, 231, 71));
        txtNoCliente = new QLineEdit(page);
        txtNoCliente->setObjectName(QString::fromUtf8("txtNoCliente"));
        txtNoCliente->setGeometry(QRect(220, 250, 251, 31));
        accederEst = new QPushButton(page);
        accederEst->setObjectName(QString::fromUtf8("accederEst"));
        accederEst->setGeometry(QRect(310, 290, 75, 23));
        btnAcceder = new QPushButton(page);
        btnAcceder->setObjectName(QString::fromUtf8("btnAcceder"));
        btnAcceder->setGeometry(QRect(600, 40, 75, 23));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        txtAdmin = new QLineEdit(page_2);
        txtAdmin->setObjectName(QString::fromUtf8("txtAdmin"));
        txtAdmin->setGeometry(QRect(280, 220, 113, 20));
        txtPswrd = new QLineEdit(page_2);
        txtPswrd->setObjectName(QString::fromUtf8("txtPswrd"));
        txtPswrd->setGeometry(QRect(280, 270, 113, 20));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 220, 61, 16));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 260, 61, 31));
        btnIngresar = new QPushButton(page_2);
        btnIngresar->setObjectName(QString::fromUtf8("btnIngresar"));
        btnIngresar->setGeometry(QRect(290, 320, 75, 23));
        stackedWidget->addWidget(page_2);
        Estacionamiento->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Estacionamiento);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 718, 21));
        Estacionamiento->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Estacionamiento);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Estacionamiento->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Estacionamiento);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Estacionamiento->setStatusBar(statusBar);

        retranslateUi(Estacionamiento);

        QMetaObject::connectSlotsByName(Estacionamiento);
    } // setupUi

    void retranslateUi(QMainWindow *Estacionamiento)
    {
        Estacionamiento->setWindowTitle(QCoreApplication::translate("Estacionamiento", "Estacionamiento", nullptr));
        label->setText(QCoreApplication::translate("Estacionamiento", "Introduzca su n\303\272mero de cliente para acceder", nullptr));
        accederEst->setText(QCoreApplication::translate("Estacionamiento", "Acceder", nullptr));
        btnAcceder->setText(QCoreApplication::translate("Estacionamiento", "Boton coulto ", nullptr));
        label_2->setText(QCoreApplication::translate("Estacionamiento", "No. Usuario", nullptr));
        label_3->setText(QCoreApplication::translate("Estacionamiento", "Contrase\303\261a", nullptr));
        btnIngresar->setText(QCoreApplication::translate("Estacionamiento", "Ingresar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Estacionamiento: public Ui_Estacionamiento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESTACIONAMIENTO_H
