#include "plotter.h"
#include "sculptor.h"
#include "QMessageBox"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QMouseEvent>
#include <QPointF>
#include <QDebug>
#include <cstring>


Plotter::Plotter(QWidget *parent) : QWidget(parent){
    sizeX=50; sizeY=50; sizeZ=50;
        s = new Sculptor(sizeX,sizeY,sizeZ);
            dim=0; plane=XY;
            x=0; y=0; z=0; radius=0; rx=0;ry=0;rz=0;

            r = 1; g=1; b=1; a = 254;

            _shape=1;

}

void Plotter::paintEvent(QPaintEvent *event){
    QPainter pa(this);
        QPen pen;
        QBrush brush;
        pen.setColor(QColor(0,0,0));
        pen.setWidth(1);
        pa.setPen(pen);
        brush.setColor(QColor(255,255,255));
        brush.setStyle(Qt::SolidPattern);
        pa.setBrush(brush);
        p.clear();
        p = s->readMx(dim,plane);
        int dim1 = width()/p[0].size();
        int dim2 = height()/p.size();
        (dim1>=dim2) ? square=dim2 : square=dim1;
        _width = dim1;
        _height = dim2;
        for(unsigned int i =0; i<p.size(); i++){
               for(unsigned int j =0; j<p[0].size(); j++){
                pa.drawRect(i*square,j*square,square, square);
        }
    }

        for(unsigned int i=0; i<p.size();i++){
               for(unsigned int j=0; j<p[0].size();j++){
                    if(p[i][j].isOn){
                        brush.setStyle(Qt::SolidPattern);
                        brush.setColor(QColor(p[i][j].r,p[i][j].g,p[i][j].b,p[i][j].a));
                        pa.setBrush(brush);
                        qDebug() << p[i][j].r <<p[i][j].g <<p[i][j].b;
                        pa.drawRect(i*square,j*square,square, square);
                    }
               }
            }
}

void Plotter::mouseReleaseEvent(QMouseEvent *event){
    if(!(event->button() == Qt::LeftButton)){
    press = false;
    }
}

void Plotter::mouseMoveEvent(QMouseEvent *event){
    if(press){
        emit clickX(event->x());
        emit clickY(event->y());
        press = true;
        mx = (event->x())/square;
        my = (event->y())/square;
        emit moveX(mx);
        emit moveY(my);

          if(plane == XY){
              px=mx;
              py=my;
              pz=dim;
          }else if(plane == YZ){
              py=mx;
              pz=my;
              px=dim;
          }else if(plane== XZ){
              pz=mx;
              px=my;
              py=dim;
          }
          Plotter::shape(_shape);
        }
}

void Plotter::mousePressEvent(QMouseEvent *event){
  if(event->button() == Qt::LeftButton ){
    emit clickX(event->x());
    emit clickY(event->y());
    press = true;
      mx = (event->x())/square;
      my = (event->y())/square;
    emit moveX(mx);
    emit moveY(my);

      if(plane == XY){
              px=mx;
              py=my;
              pz=dim;
          }

          else if(plane == YZ){
              py=mx;
              pz=my;
              px=dim;
          }

          else if(plane== XZ){
              pz=mx;
              px=my;
              py=dim;
          }
      Plotter::shape(_shape);
  }
}

void Plotter::shape(int _shape){
    if(_shape == 1){
       s->setColor(r,g,b,a);
       s->putVoxel(px,py,pz);
    }
    if(_shape == 2){
       s->cutVoxel(px,py,pz);
    }
    if(_shape == 3){
        s->setColor(r,g,b,a);
        s->putBox(px,(px+x),py,(py+y),pz,(pz+z));
    }
    if(_shape == 4){
       s->cutBox(px,(px+x),py,(py+y),pz,(pz+z));
    }
    if(_shape == 5){
        s->setColor(r,g,b,a);
        s->putSphere(px,py,pz,radius);
    }
    if(_shape == 6){
       s->cutSphere(px,py,pz,radius);
    }
    if(_shape == 7){
        s->setColor(r,g,b,a);
        s->putEllipsoid(px,py,pz,rx,ry,rz);
    }
    if(_shape == 8){
       s->cutEllipsoid(px,py,pz,rx,ry,rz);
    }
    repaint();
}

void Plotter::changeRed(int red){   if(red <= 255 && red >=0)
    r = red;
}
void Plotter::changeGreen(int green){
    g = green;
}
void Plotter::changeBlue(int blue){
    b = blue;
}
void Plotter::changeAlfa(int alpha){
    a = alpha;
}
void Plotter::changeDimX(int size){
    x=size;
}
void Plotter::changeDimY(int size){
    y=size;
}
void Plotter::changeDimZ(int size){
    z=size;
}
void Plotter::changeRadius(int rd){
    radius=rd;
}
void Plotter::changeRx(int radx){
    rx=radx;
}
void Plotter::changeRy(int rady){
    ry=rady;
}
void Plotter::changeRz(int radz){
    rz=radz;
}
void Plotter::changePlane(int pln){
    dim = pln;
    repaint();
}

void Plotter::createOff(){
    s->writeOFF((char*)"teste.off");
    QMessageBox box;
    QString msg;
    msg = "O arquivo .OFF foi criado.";
    box.setText(msg);
    box.exec();
}




