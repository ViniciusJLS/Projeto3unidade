#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "FiguraGeometrica.hpp"
#include  "Sculptor.hpp"

class cutVoxel : public figuraGeometrica{
	int x, y, z;
	public:
	cutVoxel ( int x, int y, int z);
	~cutVoxel(){}
    void  draw (Sculptor& s);
};

#endif
