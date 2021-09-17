#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "FiguraGeometrica.hpp"
#include  "Sculptor.hpp"

class putSphere : public figuraGeometrica{
	int xc, yc, zc, e;
	public:
	putSphere ( int xc, int yc, int zc, int e, float r, float g, float b, float a);
    ~putSphere(){}
	void  draw(Sculptor &s);
};

#endif
