#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "PutBox.hpp"
#include "PutVoxel.hpp"
#include "PutEllipsoid.hpp"
#include "CutEllipsoid.hpp"
#include "CutBox.hpp"
#include "PutBox.hpp"
#include "CutVoxel.hpp"
#include "PutSphere.hpp"
#include "CutSphere.hpp"
#include <iostream>
#include "Interpretador.hpp"
#include "FiguraGeometrica.hpp"

using namespace std;

Interpretador::Interpretador(){
}

    vector <figuraGeometrica *> Interpretador::parse(string filename){
    vector <figuraGeometrica *> figs;
    ifstream fin;
    stringstream ss;
    string s, token;

    fin.open("bola.txt");

    if(!fin.is_open()){
        cout << "O arquivo não foi aberto " << filename << endl;
        exit(0);
    }
    cout << "Arquivo aberto" << endl;
    while(fin.good())
	{
        getline(fin, s);
        if(fin.good())
		{
            ss.clear();
            ss.str(s);
            ss >> token;
        if(ss.good()){

            if(token.compare("Dim") == 0){//Verifica o primeira informação
                ss >> Dimx >> Dimy >> Dimz;

            }else if(token.compare("putVoxel") == 0){//Acessou o putVoxel
                int x0, y0, z0;
                ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                figs.push_back(new putVoxel(x0, y0, z0, r, g, b, a));
                
            }else if(token.compare("cutVoxel") == 0){//Acessou o cutVoxel
                int x, y, z;
                ss >> x >> y >> z;
                figs.push_back(new cutVoxel(x, y, z));

            }else if(token.compare("putSphere") == 0){//Acessou o putSphere
                int xc, yc, zc, e;
                ss >> xc >> yc >> zc >> e >> r >> g >> b >> a;
                figs.push_back(new putSphere(xc, yc, zc, e, r, g, b, a));

            }else if (token.compare("cutSphere")== 0){//Acessou o cutShepere
                int xc, yc, zc, e;
                ss >> xc >> yc >> zc >> e;
                figs.push_back(new cutSphere(xc, yc, zc, e));

            }else if(token.compare("putBox") == 0){//Acessou o putBox
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >>  y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                figs.push_back(new putBox(x0, x1, y0, y1, z0, z1, r, g, b, a));

			}else if(token.compare("cutBox") ==0){//Acessou o cutbox
                int x0, x1, y0, y1, z0, z1;
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1));

            }else if(token.compare("putEllipsoid") == 0){//Acessou o putEllipsoid
                int xc, yc, zc, rx, ry, rz;
                ss >> xc >> yc >> zc >> rx >> ry >> rz >>  r >> g >> b >> a;
                figs.push_back(new putEllipsoid(xc, yc, zc, rx, ry, rz, r, g, b, a));

            }else if (token.compare("cutEllipsoid")== 0){//Acessou o cutEllipsoid
                int xc, yc, zc, rx, ry, rz;
                ss >> xc >> yc >> zc >> rx >> ry >> rz;
                figs.push_back(new cutEllipsoid(xc, yc, zc, rx, ry, rz));

            }
        }
        }
	}
    cout << "\nBola foi representada em 3D!" << endl;

    return(figs);
}
int Interpretador::getDimx(){
    return Dimx;
    }
int Interpretador::getDimy(){
    return Dimy;
    }
int Interpretador::getDimz(){
    return Dimz;
    }
