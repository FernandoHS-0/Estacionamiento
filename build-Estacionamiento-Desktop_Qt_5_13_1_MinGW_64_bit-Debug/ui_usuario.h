/********************************************************************************
** Form generated from reading UI file 'usuario.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USUARIO_H
#define UI_USUARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Usuario
{
public:
    QWidget *widget_2;
    QLabel *Piso;
    QLabel *label_10;
    QLabel *Pago;
    QLabel *label_11;
    QTimeEdit *TiempoSalida;
    QLabel *label_12;
    QLabel *TipoTarifa;
    QLabel *NumeroEspacio;
    QTimeEdit *TiempoLLegada;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *Aceptar;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Usuario)
    {
        if (Usuario->objectName().isEmpty())
            Usuario->setObjectName(QString::fromUtf8("Usuario"));
        Usuario->resize(729, 571);
        Usuario->setStyleSheet(QString::fromUtf8("QDialog{\n"
"	background-color: #2A4161;\n"
"}"));
        widget_2 = new QWidget(Usuario);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(40, 170, 651, 381));
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
        Piso = new QLabel(widget_2);
        Piso->setObjectName(QString::fromUtf8("Piso"));
        Piso->setGeometry(QRect(190, 180, 91, 31));
        label_10 = new QLabel(widget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(90, 240, 81, 31));
        Pago = new QLabel(widget_2);
        Pago->setObjectName(QString::fromUtf8("Pago"));
        Pago->setGeometry(QRect(190, 320, 101, 31));
        label_11 = new QLabel(widget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(470, 120, 101, 21));
        TiempoSalida = new QTimeEdit(widget_2);
        TiempoSalida->setObjectName(QString::fromUtf8("TiempoSalida"));
        TiempoSalida->setEnabled(false);
        TiempoSalida->setGeometry(QRect(460, 260, 118, 22));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(450, 220, 131, 21));
        TipoTarifa = new QLabel(widget_2);
        TipoTarifa->setObjectName(QString::fromUtf8("TipoTarifa"));
        TipoTarifa->setGeometry(QRect(190, 120, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Corbel"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        TipoTarifa->setFont(font);
        NumeroEspacio = new QLabel(widget_2);
        NumeroEspacio->setObjectName(QString::fromUtf8("NumeroEspacio"));
        NumeroEspacio->setGeometry(QRect(190, 240, 111, 31));
        NumeroEspacio->setFont(font);
        TiempoLLegada = new QTimeEdit(widget_2);
        TiempoLLegada->setObjectName(QString::fromUtf8("TiempoLLegada"));
        TiempoLLegada->setEnabled(false);
        TiempoLLegada->setGeometry(QRect(460, 150, 118, 22));
        label_13 = new QLabel(widget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(130, 180, 41, 20));
        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(119, 320, 51, 20));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(70, 120, 101, 21));
        Aceptar = new QPushButton(widget_2);
        Aceptar->setObjectName(QString::fromUtf8("Aceptar"));
        Aceptar->setGeometry(QRect(410, 320, 91, 31));
        Aceptar->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #2A4161;\n"
"	color: white;\n"
"	font: 10pt \"Corbel\";\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: #C2C9F2;\n"
"}"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 20, 371, 61));
        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(530, 320, 91, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #2A4161;\n"
"	color: white;\n"
"	font: 10pt \"Corbel\";\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:Hover{\n"
"	background-color: #C2C9F2;\n"
"}"));
        pushButton_2 = new QPushButton(Usuario);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 20, 141, 141));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border: none;\n"
"image: url(:/img/img/park_w.png);"));

        retranslateUi(Usuario);

        QMetaObject::connectSlotsByName(Usuario);
    } // setupUi

    void retranslateUi(QDialog *Usuario)
    {
        Usuario->setWindowTitle(QCoreApplication::translate("Usuario", "Dialog", nullptr));
        Piso->setText(QString());
        label_10->setText(QCoreApplication::translate("Usuario", "NoEspacio:", nullptr));
        Pago->setText(QString());
        label_11->setText(QCoreApplication::translate("Usuario", "Hora de inicio", nullptr));
        label_12->setText(QCoreApplication::translate("Usuario", "Hora de finalizacion", nullptr));
        TipoTarifa->setText(QString());
        NumeroEspacio->setText(QString());
        label_13->setText(QCoreApplication::translate("Usuario", "Piso :", nullptr));
        label_14->setText(QCoreApplication::translate("Usuario", "Monto:", nullptr));
        label_15->setText(QCoreApplication::translate("Usuario", "Tipo de tarifa:", nullptr));
        Aceptar->setText(QCoreApplication::translate("Usuario", "Aceptar", nullptr));
        label->setText(QCoreApplication::translate("Usuario", "Bienvenido, por favor, acceda a su lugar", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Usuario", "Salir", nullptr));
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Usuario: public Ui_Usuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USUARIO_H
