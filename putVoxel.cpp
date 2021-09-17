#include "putVoxel.hpp"
#include  "Sculptor.hpp"
#include  "FiguraGeometrica.hpp"

putVoxel::putVoxel(int x, int y, int z, float r, float g, float b, float a){
    this -> x = x; this -> y = y; this -> z = z;
    this -> r = r; this -> g = g; this -> b = b; this -> a = a;
}

void putVoxel::draw(Sculptor& s){
    s.setColor(this -> r, this -> g, this -> b, this -> a);
	s.putVoxel(this -> x, this -> y, this -> z);
}
