#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "FiguraGeometrica.hpp"
#include  "Sculptor.hpp"

class cutEllipsoid : public figuraGeometrica{
	int xc,  yc,  zc,  rx,  ry,  rz;
	public:
	cutEllipsoid ( int xc, int yc, int zc, int rx, int ry, int rz);
    ~cutEllipsoid(){}
	void  draw (Sculptor &s);		
};

#endif
