#include "cutEllipsoid.hpp"
#include "Sculptor.hpp"
#include "FiguraGeometrica.hpp"

cutEllipsoid::cutEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){
    this -> xc = xc; this -> yc = yc; this -> zc = zc;  
    this -> rx = rx; this -> ry = ry; this -> rz = rz;
}

void cutEllipsoid::draw(Sculptor &s){
    s.cutEllipsoid(this -> xc, this -> yc, this -> zc, this -> rx, this -> ry, this -> rz);
	
}
