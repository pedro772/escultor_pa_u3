#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sculptor.h"
#include "vector"
#include "plotter.h"
#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief A classe MainWindow é o elo de comunicação entre a classe sculptor e plotter.
 */
class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    /**
     * @brief A função CreateCanvas() é responsável por criar o ambiente onde as figuras serão desenhadas.
     */
    void CreateCanvas();
    /**
     * @brief A função PickPlaneXY() é responsável alterar o plano de visão do ambiente para o plano XY quando o botão for pressionado.
     */
    void PickPlaneXY();
    /**
     * @brief A função PickPlaneYZ() é responsável alterar o plano de visão do ambiente para o plano YZ quando o botão for pressionado.
     */
    void PickPlaneYZ();
    /**
     * @brief A função PickPlaneXZ() é responsável alterar o plano de visão do ambiente para o plano XZ quando o botão for pressionado.
     */
    void PickPlaneXZ();
    /**
     * @brief A função CallPutVoxel() é responsável por chamar PutVoxel() quando o botão for pressionado.
     * @sa PutVoxel
     */
    void CallPutVoxel();
    /**
     * @brief A função CallPutBox() é responsável por chamar PutBox() quando o botão for pressionado.
     * @sa PutBox
     */
    void CallPutBox();
    /**
     * @brief A função CallPutSphere() é responsável por chamar PutSphere() quando o botão for pressionado.
     * @sa PutSphere
     */
    void CallPutSphere();
    /**
     * @brief A função CallPutEllipsoid() é responsável por chamar PutEllipsoid() quando o botão for pressionado.
     * @brief PutEllipsoid
     */
    void CallPutEllipsoid();
    /**
     * @brief A função CallCutVoxel() é responsável por chamar CutVoxel() quando o botão for pressionado.
     * @sa CutVoxel
     */
    void CallCutVoxel();
    /**
     * @brief A função CallCutBox() é responsável por chamar CutBox() quando o botão for pressionado.
     * @sa CutBox
     */
    void CallCutBox();
    /**
     * @brief A função CallCutSphere() é responsável por chamar CutSphere() quando o botão for pressionado.
     * @sa CutSphere
     */
    void CallCutSphere();
    /**
     * @brief A função CallCutEllipsoid() é responsável por chamar CutEllipsoid() quando o botão for pressionado.
     * @sa CutEllipsoid
     */
    void CallCutEllipsoid();
    /**
     * @brief A função quit() permite que o programa seja encerrado.
     */
    void quit();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<Voxel>> m;
};
#endif // MAINWINDOW_H
