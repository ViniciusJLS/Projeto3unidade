#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "FiguraGeometrica.hpp"
#include  "Sculptor.hpp"

class cutSphere : public figuraGeometrica{
	int xc, yc, zc, e;
	public:
	cutSphere (int xc, int yc, int zc, int e);
    ~cutSphere(){}
  void  draw (Sculptor &s);
};

#endif
