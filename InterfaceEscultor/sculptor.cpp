#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <string>
#include <math.h>

using std::cout;
using std::endl;

#include "sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;

    if (nx <= 0 || ny <= 0 || nz <= 0)
        nx = ny = nz = 0;

    v = new Voxel**[nz];
    v[0] = new Voxel*[nz*nx];

    for (int z = 1; z < nz; z++){
        v[z] = v[z-1] + nx;
    }

    v[0][0] = new Voxel[nz*nx*ny];
    int n = 0;

    for (int z = 0; z < nz; z++){
        for(int x = 0; x < nx; x++){
            v[z][x] = v[0][0] + n*ny;
            n++;
        }
    }
}

Sculptor::~Sculptor(){
    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    r = _r;
    g = _g;
    b = _b;
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if(x<nx && x >= 0 && y < ny && y >= 0 && z < nz && z>= 0) {
        v[x][y][z].isOn = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z){
    if(x < nx && x >= 0 && y < ny && y >= 0 && z < nz && z >= 0)
        v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int z=z0; z<=z1; z++){
        for(int y=y0; y<=y1; y++){
            for(int x=x0; x<=x1; x++){
                putVoxel(x,y,z);
            }
        }
    }

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int z=z0; z<=z1; z++){
        for(int x=x0; x<=x1; x++){
            for(int y=y0; y<=y1; y++){
                cutVoxel(x,y,z);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    double distance;

    for(int z=0; z<=nz; z++){
        for(int y=0; y<=ny; y++){
            for(int x=0; x<=nz; x++){
                distance = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2);

                if(distance <= pow(radius,2) )
                    putVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    double distance;

    for(int z=0; z<=nz; z++){
        for(int y=0; y<=ny; y++){
            for(int x=0; x<=nx; x++){
                distance = pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2);

                if(distance <= pow(radius,2))
                    cutVoxel(x, y, z);
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float distanceX, distanceY, distanceZ;
    int x1 = xcenter-rx, x2 = xcenter+rx;
    int y1 = ycenter-ry, y2 = ycenter+ry;
    int z1 = zcenter-rz, z2 = zcenter+rz;

    for(int i=x1; i<x2; i++){
        distanceX=((static_cast<float>(i)-xcenter)/rx)*((static_cast<float>(i)-xcenter)/rx);
        for(int j=y1; j<y2; j++){
            distanceY=((static_cast<float>(j)-ycenter)/ry)*((static_cast<float>(j)-ycenter)/ry);
            for (int k=z1; k<z2; k++) {
                 distanceZ=((static_cast<float>(k)-zcenter)/rz)*((static_cast<float>(k)-zcenter)/rz);
                if(distanceX+distanceY+ distanceZ<=1){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float distanceX, distanceY, distanceZ;
    int x1 = xcenter-rx, x2 = xcenter+rx;
    int y1 = ycenter-ry, y2 = ycenter+ry;
    int z1 = zcenter-rz, z2 = zcenter+rz;

    for(int i=x1; i<x2; i++){
        distanceX=((static_cast<float>(i)-xcenter)/rx)*((static_cast<float>(i)-xcenter)/rx);
        for(int j=y1; j<y2; j++){
            distanceY=((static_cast<float>(j)-ycenter)/ry)*((static_cast<float>(j)-ycenter)/ry);
            for (int k=z1; k<z2; k++) {
                distanceZ=((static_cast<float>(k)-zcenter)/rz)*((static_cast<float>(k)-zcenter)/rz);
                if(distanceX+distanceY+distanceZ<=1){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(char *filename){
    int NVoxels = 0, NVertices, NFaces;
    float faces = 0;

    ofstream fout;

    fout.open(filename);
    if (!fout.is_open()){
       exit(1);
       cout << "Não foi possivel gravar no arquivo";
    }

    fout << "OFF \n";

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if (v[i][j][k].isOn == true){
                    NVoxels++;
                }
            }
        }
    }

    NVertices = 8*NVoxels;
    NFaces = 6*NVoxels;

    fout << NVertices << " " << NFaces << " " << 0 << endl;

    //Vertices do cubo sendo inseridos no aqruivo OFF
    for(int i=0; i<nz; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nx; k++){
                if(v[i][j][k].isOn){
                    fout << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl
                         << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl
                         << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl
                         << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl
                         << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl
                         << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl
                         << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl
                         << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                 }
            }
        }
    }
    //Faces do cubo sendo inseridos no arquivo OFF
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].isOn){
                    fout << 4 << " " << 0+faces << " " << 3+faces << " " << 2+faces << " " << 1+faces << " "
                         << v[i][j][k].r/255 << " " << v[i][j][k].g/255  << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl
                         << 4 << " " << 4+faces << " " << 5+faces << " " << 6+faces << " " << 7+faces<< " "
                         << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl
                         << 4 << " " << 0+faces << " " << 1+faces << " " << 5+faces << " " << 4+faces << " "
                         << v[i][j][k].r/255  << " " << v[i][j][k].g/255  << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl
                         << 4 << " " << 0+faces << " " << 4+faces << " " << 7+faces << " " << 3+faces << " "
                         << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl
                         << 4 << " " << 3+faces << " " << 7+faces << " " << 6+faces << " " << 2+faces << " "
                         << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl
                         << 4 << " " << 1+faces << " " << 2+faces << " " << 6+faces << " " << 5+faces<< " "
                         << v[i][j][k].r/255 << " " << v[i][j][k].g/255 << " " << v[i][j][k].b/255 << " " << v[i][j][k].a/255 << endl;
                    faces = faces+8;

                 }
            }
        }
    }

    fout.close();
}

vector<vector<Voxel>> Sculptor::readMx(int dim, int pl){
    vector<vector<Voxel>> m;
    vector<Voxel> l;
    if (pl == XY){
        l.resize(ny);
        for(int i = 0; i<nx; i++){
            for(int j = 0; j<ny; j++){
                l[j].isOn = v[i][j][dim].isOn;
                l[j].r = v[i][j][dim].r;
                l[j].g = v[i][j][dim].g;
                l[j].b = v[i][j][dim].b;
                l[j].a = v[i][j][dim].a;
            }
            m.push_back(l);
        }
    }
    if (pl == YZ){
        l.resize(nz);
        for(int i = 0; i<ny; i++){
            for(int j = 0; j<nz; j++){
                l[j].isOn = v[dim][i][j].isOn;
                l[j].r = v[dim][i][j].r;
                l[j].g = v[dim][i][j].g;
                l[j].b = v[dim][i][j].b;
                l[j].a = v[dim][i][j].a;
            }
            m.push_back(l);
        }
    }

    if (pl == XZ){
        l.resize(nx);
        for(int i = 0; i<nz; i++){
            for(int j = 0; j<nx; j++){
                l[j].isOn = v[j][dim][i].isOn;
                l[j].r = v[j][dim][i].r;
                l[j].g = v[j][dim][i].g;
                l[j].b = v[j][dim][i].b;
                l[j].a = v[j][dim][i].a;
            }
            m.push_back(l);
        }
    }
    l.clear();
    return m;
}
