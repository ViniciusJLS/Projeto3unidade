#include "putSphere.hpp"
#include "Sculptor.hpp"
#include "FiguraGeometrica.hpp"

putSphere::putSphere(int xc, int yc, int zc, int e, float r, float g, float b, float a){
    this -> xc = xc; this -> yc = yc; this -> zc = zc; this -> e = e;
    this -> r = r; this -> g = g; this -> b = b; this -> a = a;
}

void putSphere::draw(Sculptor& s){
	
    s.setColor(this -> r, this -> g, this -> b, this -> a);	
	s.putSphere(this -> xc, this -> yc, this -> zc, this -> e);		
	
}
