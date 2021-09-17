#include "cutvoxel.hpp"
#include "Sculptor.hpp"
#include "FiguraGeometrica.hpp"

cutVoxel::cutVoxel(int x,int y , int z){
    this -> x = x; this -> y = y; this -> z = z;
}

void cutVoxel::draw(Sculptor &s){
    s.cutVoxel(this -> x, this -> y, this -> z);
}
