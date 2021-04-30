#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sculptor.h"
#include "plotter.h"
#include <cstdlib>
#include "QMessageBox"
#include "QProcess"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);
            ui->spinBoxDimX->setMaximum(ui->widget->sizeX-1);
            ui->spinBoxDimY->setMaximum(ui->widget->sizeY-1);
            ui->spinBoxDimZ->setMaximum(ui->widget->sizeZ-1);
            ui->spinBoxRaio->setMaximum(ui->widget->sizeX/2 -1);
            ui->spinBoxRx->setMaximum(ui->widget->sizeX/2 -1);
            ui->spinBoxRy->setMaximum(ui->widget->sizeY/2 -1);
            ui->spinBoxRz->setMaximum(ui->widget->sizeZ/2 -1);
            ui->spinBoxProf->setMaximum(ui->widget->sizeZ -1);
            ui->spinBoxA->setValue(10);
            ui->radioButtonPutVoxel->setChecked(true);

            connect(ui->spinBoxProf,
                                SIGNAL(valueChanged(int)),
                                ui->widget, // Envia a informação da interface para o desenho.
                                SLOT(changePlane(int)));

                        connect(ui->radioButtonPutVoxel,
                                SIGNAL(clicked(bool)),
                                this, // "This" refere-se ao MainWindow
                                SLOT(CallPutVoxel()));

                        connect(ui->radioButtonCutVoxel,
                                SIGNAL(clicked(bool)),
                                this,
                                SLOT(CallCutVoxel()));

                        connect(ui->radioButtonPutBox,
                                SIGNAL(clicked(bool)),
                                this,
                                SLOT(CallPutBox()));

                        connect(ui->radioButtonCutBox,
                                SIGNAL(clicked(bool)),
                                this,
                                SLOT(CallCutBox()));

                        connect(ui->radioButtonPutSphere,
                                SIGNAL(clicked(bool)),
                                this,
                                SLOT(CallPutSphere()));

                        connect(ui->radioButtonCutSphere,
                                SIGNAL(clicked(bool)),
                                this,
                                SLOT(CallCutSphere()));

                        connect(ui->radioButtonPutEllipsoid,
                                SIGNAL(clicked(bool)),
                                this,
                                SLOT(CallPutEllipsoid()));

                        connect(ui->radioButtonCutEllipsoid,
                                SIGNAL(clicked(bool)),
                                this,
                                SLOT(CallCutEllipsoid()));

                        connect(ui->spinBoxR,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeRed(int)));

                        connect(ui->spinBoxB,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeBlue(int)));

                        connect(ui->spinBoxG,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeGreen(int)));

                        connect(ui->spinBoxA,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeAlfa(int)));

                        connect(ui->spinBoxDimX,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeDimX(int)));

                        connect(ui->spinBoxDimY,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeDimY(int)));

                        connect(ui->spinBoxDimZ,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeDimZ(int)));

                        connect(ui->spinBoxRaio,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeRadius(int)));

                        connect(ui->spinBoxRx,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeRx(int)));

                        connect(ui->spinBoxRy,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeRy(int)));

                        connect(ui->spinBoxRz,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(changeRz(int)));

                        connect(ui->actionSave,
                                SIGNAL(triggered(bool)),
                                ui->widget,
                                SLOT(createOff()));

                        connect(ui->pushButtonCriaCanvas,
                                SIGNAL(clicked(bool)),
                                this,
                                SLOT(CreateCanvas()));

                        connect(ui->spinBoxXCanvas,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(CreateCanvas()));

                        connect(ui->spinBoxYCanvas,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(CreateCanvas()));

                        connect(ui->spinBoxZCanvas,
                                SIGNAL(valueChanged(int)),
                                ui->widget,
                                SLOT(CreateCanvas()));

                        connect(ui->actionQuit,
                                SIGNAL(triggered(bool)),
                                ui->widget,
                                SLOT(quit()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::quit(){
    exit(0);
}

void MainWindow::CreateCanvas(){
      ui->widget->sizeX = ui->spinBoxXCanvas->value();
      ui->widget->sizeY = ui->spinBoxYCanvas->value();
      ui->widget->sizeZ = ui->spinBoxZCanvas->value();
      ui->widget->s->~Sculptor();
      ui->widget->s = new Sculptor(ui->widget->sizeX,ui->widget->sizeY,ui->widget->sizeZ);
      ui->spinBoxDimX->setMaximum(ui->widget->sizeX-1);
      ui->spinBoxDimY->setMaximum(ui->widget->sizeY-1);
      ui->spinBoxDimZ->setMaximum(ui->widget->sizeZ-1);
      ui->spinBoxRaio->setMaximum(ui->widget->sizeX/2 -1);
      ui->spinBoxRx->setMaximum(ui->widget->sizeX/2 -1);
      ui->spinBoxRy->setMaximum(ui->widget->sizeY/2 -1);
      ui->spinBoxRz->setMaximum(ui->widget->sizeZ/2 -1);
      ui->spinBoxProf->setMaximum(ui->widget->sizeZ -1);
      ui->widget->repaint();
}


void MainWindow::PickPlaneXY(){  // Mostra o plano XY
    ui->widget->plane = XY;
    emit ui->widget->planeChosen(XY);
    ui->widget->dim = ui->widget->sizeZ/2;
    ui->spinBoxProf->setMaximum(ui->widget->sizeZ -1);
    ui->widget->repaint();
}

void MainWindow::PickPlaneYZ(){ //Mostrar o plano YZ
    ui->widget->plane = YZ;
    emit ui->widget->planeChosen(YZ);
    ui->widget->dim = ui->widget->sizeX/2;
    ui->spinBoxProf->setMaximum(ui->widget->sizeX -1);
    ui->widget->repaint();
}

void MainWindow::PickPlaneXZ(){ //Mostrar o plano XZ{
    ui->widget->plane = XZ;
    emit ui->widget->planeChosen(XZ);
    ui->widget->dim = ui->widget->sizeY/2;
    ui->spinBoxProf->setMaximum(ui->widget->sizeY -1);
    ui->widget->repaint();
}

void MainWindow::CallPutVoxel(){ //PutVoxel
    ui->widget->_shape = 1;
}
void MainWindow::CallCutVoxel(){ //CutVoxel
    ui->widget->_shape = 2;
}
void MainWindow::CallPutBox(){ //PutBox
    ui->widget->_shape = 3;
}
void MainWindow::CallCutBox(){ //CutBox
    ui->widget->_shape= 4;
}
void MainWindow::CallPutSphere(){ //PutSphere
    ui->widget->_shape = 5;
}
void MainWindow::CallCutSphere(){ //CutSphere
    ui->widget->_shape = 6;
}
void MainWindow::CallPutEllipsoid(){ //PutEllipsoid
    ui->widget->_shape = 7;
}
void MainWindow::CallCutEllipsoid(){ //PutEllipsoid
    ui->widget->_shape= 8;
}

