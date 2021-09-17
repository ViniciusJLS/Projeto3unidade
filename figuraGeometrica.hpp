#ifndef FiguraGeometrica_header
#define FiguraGeometrica_header
#include "Sculptor.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class figuraGeometrica{
  protected:
    float r, g, b, a;
  public:
    virtual ~figuraGeometrica(){}
      virtual void draw(Sculptor &s)=0;
};

#endif //FiguraGeometrica_header
