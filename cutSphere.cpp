#include "cutSphere.hpp"
#include "Sculptor.hpp"
#include "FiguraGeometrica.hpp"

cutSphere::cutSphere(int xc, int yc, int zc, int e){
    this -> xc = xc; this -> yc = yc; this -> zc = zc; this -> e = e;
}

void cutSphere::draw(Sculptor &s){
    s.cutSphere(this -> xc, this -> yc, this -> zc, this -> e);

}
