#ifndef COLOR_H
#define COLOR_H

#include <QWidget>

/**
 * @brief A classe Color é responsável pela ferramenta de alteração de cores.
 */
class Color : public QWidget{
    Q_OBJECT
private:
    int r,g,b;
public:
    explicit Color(QWidget *parent = nullptr);
    /**
     * @brief paintEvent é um evento que permite o desenho do grid por meio de uma mtriz de cubos.
     */
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    /**
     * @brief set_r é responsável por alterar o valor da variável r para o valor escolhido pelo usuário
     */
    void set_r(int _r);
    /**
     * @brief set_g é responsável por alterar o valor da variável g para o valor escolhido pelo usuário
     */
    void set_g(int _g);
    /**
     * @brief set_b é responsável por alterar o valor da variável b para o valor escolhido pelo usuário
     */
    void set_b(int _b);
};

#endif // COLOR_H
