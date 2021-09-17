#include "putEllipsoid.hpp"
#include  "Sculptor.hpp"
#include "FiguraGeometrica.hpp"

putEllipsoid::putEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz, float r, float g, float b, float a){
    this -> xc = xc; this -> yc = yc; this -> zc = zc;
    this -> rx = rx; this -> ry = ry; this -> rz = rz;
	this -> r = r; this -> g = g; this -> b = b; this -> a = a;
}

void putEllipsoid::draw(Sculptor&s){
    s.setColor(this -> r, this -> g, this -> b, this -> a);    
    s.putEllipsoid(this -> xc, this -> yc, this -> zc, this -> rx, this -> ry, this -> rz);
}
