#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.hpp"
#include  "Sculptor.hpp"

class putEllipsoid : public figuraGeometrica{
	int xc, yc, zc,  rx, ry, rz;
	public:
	putEllipsoid ( int xc, int yc, int zc, int rx, int ry, int rz, float r, float g, float b, float a);
    ~putEllipsoid(){}
	void  draw (Sculptor &s);
};

#endif
