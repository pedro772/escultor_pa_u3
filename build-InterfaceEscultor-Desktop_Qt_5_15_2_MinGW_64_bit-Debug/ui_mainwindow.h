/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "color.h"
#include "plotter.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionSave;
    QWidget *centralwidget;
    Plotter *widget;
    QPushButton *pushButtonCriaCanvas;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Profundidade;
    QSpinBox *spinBoxProf;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *Vermelho;
    QSpinBox *spinBoxA;
    QSpinBox *spinBoxR;
    QSpinBox *spinBoxG;
    QLabel *label;
    QLabel *Alfa;
    Color *widget_2;
    QLabel *Azul;
    QSpinBox *spinBoxB;
    QLabel *Verde;
    QWidget *widget2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButtonPutVoxel;
    QRadioButton *radioButtonPutEllipsoid;
    QRadioButton *radioButtonPutSphere;
    QRadioButton *radioButtonPutBox;
    QRadioButton *radioButtonCutBox;
    QRadioButton *radioButtonCutVoxel;
    QRadioButton *radioButtonCutEllipsoid;
    QRadioButton *radioButtonCutSphere;
    QWidget *widget3;
    QGridLayout *gridLayout_3;
    QLabel *labelBox;
    QSpinBox *spinBoxDimX;
    QLabel *DimX;
    QSpinBox *spinBoxDimY;
    QLabel *DimY;
    QSpinBox *spinBoxDimZ;
    QLabel *DimZ;
    QWidget *widget4;
    QGridLayout *gridLayout_4;
    QLabel *labelEllipsoid;
    QSpinBox *spinBoxRx;
    QLabel *Rx;
    QSpinBox *spinBoxRy;
    QLabel *Ry;
    QSpinBox *spinBoxRz;
    QLabel *Rz;
    QWidget *widget5;
    QGridLayout *gridLayout_5;
    QLabel *labelSphere;
    QSpinBox *spinBoxRaio;
    QLabel *Raio;
    QWidget *widget6;
    QGridLayout *gridLayout_6;
    QLabel *XGeral;
    QSpinBox *spinBoxXCanvas;
    QLabel *YGeral;
    QSpinBox *spinBoxYCanvas;
    QLabel *ZGeral;
    QSpinBox *spinBoxZCanvas;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(757, 527);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new Plotter(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 10, 441, 371));
        pushButtonCriaCanvas = new QPushButton(centralwidget);
        pushButtonCriaCanvas->setObjectName(QString::fromUtf8("pushButtonCriaCanvas"));
        pushButtonCriaCanvas->setGeometry(QRect(500, 120, 81, 23));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(500, 10, 61, 24));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 400, 339, 55));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Profundidade = new QLabel(layoutWidget);
        Profundidade->setObjectName(QString::fromUtf8("Profundidade"));

        horizontalLayout_2->addWidget(Profundidade);

        spinBoxProf = new QSpinBox(layoutWidget);
        spinBoxProf->setObjectName(QString::fromUtf8("spinBoxProf"));

        horizontalLayout_2->addWidget(spinBoxProf);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(510, 350, 81, 119));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Vermelho = new QLabel(widget1);
        Vermelho->setObjectName(QString::fromUtf8("Vermelho"));

        gridLayout->addWidget(Vermelho, 1, 2, 1, 1);

        spinBoxA = new QSpinBox(widget1);
        spinBoxA->setObjectName(QString::fromUtf8("spinBoxA"));
        spinBoxA->setMaximum(255);

        gridLayout->addWidget(spinBoxA, 4, 1, 1, 1);

        spinBoxR = new QSpinBox(widget1);
        spinBoxR->setObjectName(QString::fromUtf8("spinBoxR"));
        spinBoxR->setMaximum(255);

        gridLayout->addWidget(spinBoxR, 1, 1, 1, 1);

        spinBoxG = new QSpinBox(widget1);
        spinBoxG->setObjectName(QString::fromUtf8("spinBoxG"));
        spinBoxG->setMaximum(255);

        gridLayout->addWidget(spinBoxG, 2, 1, 1, 1);

        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        Alfa = new QLabel(widget1);
        Alfa->setObjectName(QString::fromUtf8("Alfa"));

        gridLayout->addWidget(Alfa, 4, 2, 1, 1);

        widget_2 = new Color(widget1);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout->addWidget(widget_2, 0, 0, 5, 1);

        Azul = new QLabel(widget1);
        Azul->setObjectName(QString::fromUtf8("Azul"));

        gridLayout->addWidget(Azul, 3, 2, 1, 1);

        spinBoxB = new QSpinBox(widget1);
        spinBoxB->setObjectName(QString::fromUtf8("spinBoxB"));
        spinBoxB->setMaximum(255);

        gridLayout->addWidget(spinBoxB, 3, 1, 1, 1);

        Verde = new QLabel(widget1);
        Verde->setObjectName(QString::fromUtf8("Verde"));

        gridLayout->addWidget(Verde, 2, 2, 1, 1);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(510, 150, 79, 180));
        gridLayout_2 = new QGridLayout(widget2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButtonPutVoxel = new QRadioButton(widget2);
        radioButtonPutVoxel->setObjectName(QString::fromUtf8("radioButtonPutVoxel"));

        gridLayout_2->addWidget(radioButtonPutVoxel, 0, 0, 1, 1);

        radioButtonPutEllipsoid = new QRadioButton(widget2);
        radioButtonPutEllipsoid->setObjectName(QString::fromUtf8("radioButtonPutEllipsoid"));

        gridLayout_2->addWidget(radioButtonPutEllipsoid, 1, 0, 1, 1);

        radioButtonPutSphere = new QRadioButton(widget2);
        radioButtonPutSphere->setObjectName(QString::fromUtf8("radioButtonPutSphere"));

        gridLayout_2->addWidget(radioButtonPutSphere, 2, 0, 1, 1);

        radioButtonPutBox = new QRadioButton(widget2);
        radioButtonPutBox->setObjectName(QString::fromUtf8("radioButtonPutBox"));

        gridLayout_2->addWidget(radioButtonPutBox, 3, 0, 1, 1);

        radioButtonCutBox = new QRadioButton(widget2);
        radioButtonCutBox->setObjectName(QString::fromUtf8("radioButtonCutBox"));

        gridLayout_2->addWidget(radioButtonCutBox, 4, 0, 1, 1);

        radioButtonCutVoxel = new QRadioButton(widget2);
        radioButtonCutVoxel->setObjectName(QString::fromUtf8("radioButtonCutVoxel"));

        gridLayout_2->addWidget(radioButtonCutVoxel, 5, 0, 1, 1);

        radioButtonCutEllipsoid = new QRadioButton(widget2);
        radioButtonCutEllipsoid->setObjectName(QString::fromUtf8("radioButtonCutEllipsoid"));

        gridLayout_2->addWidget(radioButtonCutEllipsoid, 6, 0, 1, 1);

        radioButtonCutSphere = new QRadioButton(widget2);
        radioButtonCutSphere->setObjectName(QString::fromUtf8("radioButtonCutSphere"));

        gridLayout_2->addWidget(radioButtonCutSphere, 7, 0, 1, 1);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(660, 240, 64, 93));
        gridLayout_3 = new QGridLayout(widget3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        labelBox = new QLabel(widget3);
        labelBox->setObjectName(QString::fromUtf8("labelBox"));

        gridLayout_3->addWidget(labelBox, 0, 0, 1, 1);

        spinBoxDimX = new QSpinBox(widget3);
        spinBoxDimX->setObjectName(QString::fromUtf8("spinBoxDimX"));

        gridLayout_3->addWidget(spinBoxDimX, 1, 0, 1, 1);

        DimX = new QLabel(widget3);
        DimX->setObjectName(QString::fromUtf8("DimX"));

        gridLayout_3->addWidget(DimX, 1, 1, 1, 1);

        spinBoxDimY = new QSpinBox(widget3);
        spinBoxDimY->setObjectName(QString::fromUtf8("spinBoxDimY"));

        gridLayout_3->addWidget(spinBoxDimY, 2, 0, 1, 1);

        DimY = new QLabel(widget3);
        DimY->setObjectName(QString::fromUtf8("DimY"));

        gridLayout_3->addWidget(DimY, 2, 1, 1, 1);

        spinBoxDimZ = new QSpinBox(widget3);
        spinBoxDimZ->setObjectName(QString::fromUtf8("spinBoxDimZ"));

        gridLayout_3->addWidget(spinBoxDimZ, 3, 0, 1, 1);

        DimZ = new QLabel(widget3);
        DimZ->setObjectName(QString::fromUtf8("DimZ"));

        gridLayout_3->addWidget(DimZ, 3, 1, 1, 1);

        widget4 = new QWidget(centralwidget);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setGeometry(QRect(660, 130, 62, 93));
        gridLayout_4 = new QGridLayout(widget4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        labelEllipsoid = new QLabel(widget4);
        labelEllipsoid->setObjectName(QString::fromUtf8("labelEllipsoid"));

        gridLayout_4->addWidget(labelEllipsoid, 0, 0, 1, 1);

        spinBoxRx = new QSpinBox(widget4);
        spinBoxRx->setObjectName(QString::fromUtf8("spinBoxRx"));

        gridLayout_4->addWidget(spinBoxRx, 1, 0, 1, 1);

        Rx = new QLabel(widget4);
        Rx->setObjectName(QString::fromUtf8("Rx"));

        gridLayout_4->addWidget(Rx, 1, 1, 1, 1);

        spinBoxRy = new QSpinBox(widget4);
        spinBoxRy->setObjectName(QString::fromUtf8("spinBoxRy"));

        gridLayout_4->addWidget(spinBoxRy, 2, 0, 1, 1);

        Ry = new QLabel(widget4);
        Ry->setObjectName(QString::fromUtf8("Ry"));

        gridLayout_4->addWidget(Ry, 2, 1, 1, 1);

        spinBoxRz = new QSpinBox(widget4);
        spinBoxRz->setObjectName(QString::fromUtf8("spinBoxRz"));

        gridLayout_4->addWidget(spinBoxRz, 3, 0, 1, 1);

        Rz = new QLabel(widget4);
        Rz->setObjectName(QString::fromUtf8("Rz"));

        gridLayout_4->addWidget(Rz, 3, 1, 1, 1);

        widget5 = new QWidget(centralwidget);
        widget5->setObjectName(QString::fromUtf8("widget5"));
        widget5->setGeometry(QRect(660, 70, 62, 41));
        gridLayout_5 = new QGridLayout(widget5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        labelSphere = new QLabel(widget5);
        labelSphere->setObjectName(QString::fromUtf8("labelSphere"));

        gridLayout_5->addWidget(labelSphere, 0, 0, 1, 1);

        spinBoxRaio = new QSpinBox(widget5);
        spinBoxRaio->setObjectName(QString::fromUtf8("spinBoxRaio"));

        gridLayout_5->addWidget(spinBoxRaio, 1, 0, 1, 1);

        Raio = new QLabel(widget5);
        Raio->setObjectName(QString::fromUtf8("Raio"));

        gridLayout_5->addWidget(Raio, 1, 1, 1, 1);

        widget6 = new QWidget(centralwidget);
        widget6->setObjectName(QString::fromUtf8("widget6"));
        widget6->setGeometry(QRect(506, 40, 51, 74));
        gridLayout_6 = new QGridLayout(widget6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        XGeral = new QLabel(widget6);
        XGeral->setObjectName(QString::fromUtf8("XGeral"));

        gridLayout_6->addWidget(XGeral, 0, 0, 1, 1);

        spinBoxXCanvas = new QSpinBox(widget6);
        spinBoxXCanvas->setObjectName(QString::fromUtf8("spinBoxXCanvas"));

        gridLayout_6->addWidget(spinBoxXCanvas, 0, 1, 1, 1);

        YGeral = new QLabel(widget6);
        YGeral->setObjectName(QString::fromUtf8("YGeral"));

        gridLayout_6->addWidget(YGeral, 1, 0, 1, 1);

        spinBoxYCanvas = new QSpinBox(widget6);
        spinBoxYCanvas->setObjectName(QString::fromUtf8("spinBoxYCanvas"));

        gridLayout_6->addWidget(spinBoxYCanvas, 1, 1, 1, 1);

        ZGeral = new QLabel(widget6);
        ZGeral->setObjectName(QString::fromUtf8("ZGeral"));

        gridLayout_6->addWidget(ZGeral, 2, 0, 1, 1);

        spinBoxZCanvas = new QSpinBox(widget6);
        spinBoxZCanvas->setObjectName(QString::fromUtf8("spinBoxZCanvas"));

        gridLayout_6->addWidget(spinBoxZCanvas, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 757, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(sair()));
        QObject::connect(spinBoxXCanvas, SIGNAL(valueChanged(int)), spinBoxXCanvas, SLOT(setValue(int)));
        QObject::connect(spinBoxYCanvas, SIGNAL(valueChanged(int)), spinBoxYCanvas, SLOT(setValue(int)));
        QObject::connect(spinBoxZCanvas, SIGNAL(valueChanged(int)), spinBoxZCanvas, SLOT(setValue(int)));
        QObject::connect(spinBoxDimX, SIGNAL(valueChanged(int)), spinBoxDimX, SLOT(setValue(int)));
        QObject::connect(spinBoxDimY, SIGNAL(valueChanged(int)), spinBoxDimY, SLOT(setValue(int)));
        QObject::connect(spinBoxDimZ, SIGNAL(valueChanged(int)), spinBoxDimZ, SLOT(setValue(int)));
        QObject::connect(spinBoxRaio, SIGNAL(valueChanged(int)), spinBoxRaio, SLOT(setValue(int)));
        QObject::connect(spinBoxRx, SIGNAL(valueChanged(int)), spinBoxRx, SLOT(setValue(int)));
        QObject::connect(spinBoxRy, SIGNAL(valueChanged(int)), spinBoxRy, SLOT(setValue(int)));
        QObject::connect(spinBoxRz, SIGNAL(valueChanged(int)), spinBoxRz, SLOT(setValue(int)));
        QObject::connect(spinBoxR, SIGNAL(valueChanged(int)), spinBoxR, SLOT(setValue(int)));
        QObject::connect(spinBoxG, SIGNAL(valueChanged(int)), spinBoxG, SLOT(setValue(int)));
        QObject::connect(spinBoxB, SIGNAL(valueChanged(int)), spinBoxB, SLOT(setValue(int)));
        QObject::connect(spinBoxA, SIGNAL(valueChanged(int)), spinBoxA, SLOT(setValue(int)));
        QObject::connect(spinBoxR, SIGNAL(valueChanged(int)), widget_2, SLOT(set_r(int)));
        QObject::connect(spinBoxG, SIGNAL(valueChanged(int)), widget_2, SLOT(set_g(int)));
        QObject::connect(spinBoxB, SIGNAL(valueChanged(int)), widget_2, SLOT(set_b(int)));
        QObject::connect(spinBoxProf, SIGNAL(valueChanged(int)), spinBoxProf, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        pushButtonCriaCanvas->setText(QCoreApplication::translate("MainWindow", "Criar Canvas", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Dimens\303\265es</p></body></html>", nullptr));
        Profundidade->setText(QCoreApplication::translate("MainWindow", "                Profundidade", nullptr));
        Vermelho->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Cores", nullptr));
        Alfa->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        Azul->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        Verde->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        radioButtonPutVoxel->setText(QCoreApplication::translate("MainWindow", "PutVoxel", nullptr));
        radioButtonPutEllipsoid->setText(QCoreApplication::translate("MainWindow", "PutEllipsoid", nullptr));
        radioButtonPutSphere->setText(QCoreApplication::translate("MainWindow", "PutSphere", nullptr));
        radioButtonPutBox->setText(QCoreApplication::translate("MainWindow", "PutBox", nullptr));
        radioButtonCutBox->setText(QCoreApplication::translate("MainWindow", "CutBox", nullptr));
        radioButtonCutVoxel->setText(QCoreApplication::translate("MainWindow", "CutVoxel", nullptr));
        radioButtonCutEllipsoid->setText(QCoreApplication::translate("MainWindow", "CutEllipsoid", nullptr));
        radioButtonCutSphere->setText(QCoreApplication::translate("MainWindow", "CutSphere", nullptr));
        labelBox->setText(QCoreApplication::translate("MainWindow", "Caixa", nullptr));
        DimX->setText(QCoreApplication::translate("MainWindow", "DimX", nullptr));
        DimY->setText(QCoreApplication::translate("MainWindow", "DimY", nullptr));
        DimZ->setText(QCoreApplication::translate("MainWindow", "DimZ", nullptr));
        labelEllipsoid->setText(QCoreApplication::translate("MainWindow", "Elipsoide", nullptr));
        Rx->setText(QCoreApplication::translate("MainWindow", "Rx", nullptr));
        Ry->setText(QCoreApplication::translate("MainWindow", "Ry", nullptr));
        Rz->setText(QCoreApplication::translate("MainWindow", "Rz", nullptr));
        labelSphere->setText(QCoreApplication::translate("MainWindow", "Esfera", nullptr));
        Raio->setText(QCoreApplication::translate("MainWindow", "Raio", nullptr));
        XGeral->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        YGeral->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        ZGeral->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
