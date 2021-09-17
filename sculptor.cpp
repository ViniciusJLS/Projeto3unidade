#include "Sculptor.hpp" 
#include <stdlib.h>   
#include <string>
#include <iostream>  
#include <fstream>    
#include <iomanip>    
#include <cmath>      
#include <vector>     
#include <queue>    

using namespace std;

//Cria��o matriz
Sculptor::Sculptor(int _nx, int _ny, int _nz){ 
  nx = _nx;
  ny = _ny;
  nz = _nz;
  r = g = b = a = 0.5;
    v = new Voxel**[nx];
  for (int i = 0; i < nx; i++){
	v[i] = new Voxel*[ny];
  }

  for(int i = 0; i < nx; i++){
	for(int j = 0; j < ny; j++){
		v[i][j] = new Voxel[nz];
	}
  } 
  
  for(int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k = 0; k < nz; k++){
                this->v[i][j][k].isOn = false;
        		this->v[i][j][k].r = this->r;
        		this->v[i][j][k].g = this->g;
        		this->v[i][j][k].b = this->b;
        		this->v[i][j][k].a = this->a;
            }
        }
    }
}

Sculptor::~Sculptor(){
  for(int i = 0; i < nx; i++){
  	for(int j = 0; j < ny; j++){
  	   delete [] v[i][j];	
	}
  }
  for(int i = 0; i < nx; i++){
  	delete [] v[i];
  }
  delete [] v;  
}

void Sculptor::setColor(float _r, float _g, float _b, float _a){
  this -> r = _r;
  this -> g = _g;
  this -> b = _b;
  this -> a = _a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if ((this->nx > x) && (this->ny > y) && (this->nz > z)&&
    (x >= 0) && ( y>=0 ) && (z>=0)) {
        this->v[x][y][z].isOn = true;
        this->v[x][y][z].r = this->r;
        this->v[x][y][z].g = this->g;
        this->v[x][y][z].b = this->b;
        this->v[x][y][z].a = this->a;
    }
}

void Sculptor :: cutVoxel(int x, int y, int z){
     if ((this->nx > x) && (this->ny > y) && (this->nz > z)&&
    (x >= 0) && ( y>=0 ) && (z>=0)) {
	  v[x][y][z].isOn = false;
    }
}

void Sculptor :: putBox(int x0, int x1, int y0, int y1, int z0, int z1){
	if((this->nx >= x0 && this->nx >= x1) && (this->ny >= y0 && this->ny >= y1) && (this->nz >= z0 && this->nz >= z1)){
			for(l = x0; l < x1; l++){
				for(m = y0; m < y1; m++){
					for(n = z0; n < z1; n++){
					this->v[l][m][n].isOn = true;
            		this->v[l][m][n].r = this->r;
            		this->v[l][m][n].g = this->g;
            		this->v[l][m][n].b = this->b;
            		this->v[l][m][n].a = this->a;
            		}
				}
			}
	}		
}
	

void Sculptor :: cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
	for(l = x0; l < x1; l++){
		for(m = y0; m < y1; m++){
			for(n = z0; n < z1; n++){
			this -> v[l][m][n].isOn = false;
			}
	    }
   }
}


void Sculptor :: putEllipsoid (int xc, int yc, int zc, int rx, int ry, int rz){
    for(int l = 0; l < nx; l++){
        for(int m = 0; m < ny; m++){
            for(int n = 0; n < nz; n++){
                if((l-xc)*(l-xc)/(float)(rx*rx)+(m-yc)*(m-yc)/(float)(ry*ry)+(n-zc)*(n-zc)/(float)(rz*rz) <= 1){
                    this -> v[l][m][n].isOn = true;
                    this -> v[l][m][n].r = r;
                    this -> v[l][m][n].g = g;
                    this -> v[l][m][n].b = b;
                    this -> v[l][m][n].a = a;

                }
            }
        }
    }
}

void Sculptor :: cutEllipsoid (int xc, int yc, int zc, int rx, int ry, int rz){
    for(int l = 0; l < nx; l++){
        for(int m = 0; m < ny; m++){
            for(int n = 0; n < nz; n++){
                if((l-xc)*(l-xc)/(float)(rx*rx)+(m-yc)*(m-yc)/(float)(ry*ry)+(n-zc)*(n-zc)/(float)(rz*rz) <= 1){
                    this -> v[l][m][n].isOn = false;
                }
            }
        }
    }

}

void Sculptor :: putSphere (int xc, int yc, int zc, int e){
    for(int l = 0; l < nx; l++){
        for(int m = 0; m < ny; m++){
            for(int n = 0; n < nz; n++){
                if((double)(l-xc)*(double)(l-xc)+(double)(m-yc)*(double)(m-yc)+(double)(n-zc)*(double)(n-zc) <= (e*e)){
                    this -> v[l][m][n].isOn = true;
                    this -> v[l][m][n].r = r;
                    this -> v[l][m][n].g = g;
                    this -> v[l][m][n].b = b;
                    this -> v[l][m][n].a = a;

                }
            }
        }
    }
}

void Sculptor :: cutSphere (int xc, int yc, int zc, int e){
    for(int l = 0; l < nx; l++){
        for(int m = 0; m < ny; m++){
            for(int n = 0; n < nz; n++){
                if((l-xc)*(l-xc)+(m-yc)*(m-yc)+(n-zc)*(n-zc) <= (e*e)){
                    this -> v[l][m][n].isOn = false;
                }
            }
        }
    }

}

void Sculptor::writeOFF(char *filename){
    int total, index;
    ofstream f;
    total = 0;
    f.open(filename);
    f << "OFF\n";

    for(i=0; i < nx; i++){
        for(j = 0; j <ny; j++){
            for(k=0; k <nz; k++){
                if(v[i][j][k].isOn == true){
                    total++;
                }
            }
        }
    }

    f << total*8 << " " << total * 6 <<" "<< 0 << "\n";
    for (i=0; i < nx; i++){
        for (j = 0; j <ny; j++){
            for (k=0; k <nz; k++){
                if(v[i][j][k].isOn == true){

                    f << i -0.5 << " " << j +0.5 << " " << k -0.5 << "\n" << flush;
                    f << i -0.5 << " " << j -0.5 << " " << k -0.5 << "\n" << flush;
                    f << i +0.5 << " " << j -0.5 << " " << k -0.5 << "\n" << flush;
                    f << i +0.5 << " " << j +0.5 << " " << k -0.5 << "\n" << flush;
                    f << i -0.5 << " " << j +0.5 << " " << k +0.5 << "\n" << flush;
                    f << i -0.5 << " " << j -0.5 << " " << k +0.5 << "\n" << flush;
                    f << i +0.5 << " " << j -0.5 << " " << k +0.5 << "\n" << flush;
                    f << i +0.5 << " " << j +0.5 << " " << k +0.5 << "\n" << flush;
                }
            }
        }
    }

    total = 0;
    for (i=0; i < nx; i++){
        for (j = 0; j <ny; j++){
            for (k=0; k <nz; k++){
                if(v[i][j][k].isOn == true){
                    index = total*8;
                    f << fixed;

                    f<< 4 << " " << index + 0 << " " << index + 3 << " " << index + 2 << " " << index + 1 << " ";
                    f << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " <<setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                    f<< 4 << " " << index + 4 << " " << index + 5 << " " << index + 6 << " " << index + 7 << " ";
                    f << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                    f<< 4 << " " << index + 0 << " " << index + 1 << " " << index + 5 << " " << index + 4 << " ";
                    f << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                    f<< 4 << " " << index + 0 << " " << index + 4 << " " << index + 7 << " " << index + 3 << " ";
                    f << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                    f<< 4 << " " << index + 7 << " " << index + 6 << " " << index + 2 << " " << index + 3 << " ";
                    f << setprecision(2) << v[i][j][k].r << " " <<setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " <<setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                    f<< 4 << " " << index + 1 << " " << index + 2 << " " << index + 6 << " " << index + 5 << " ";
                    f << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                    total++;    
                }
            }
        }
    }
    f.close();
}
