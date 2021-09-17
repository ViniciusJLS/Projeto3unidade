#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include "FiguraGeometrica.hpp"
#include <vector>
#include <string>

// Faz uma leitura para depois implementar 
class Interpretador{
	int Dimx, Dimy, Dimz; 
	float r, g, b, a;
	public:
		Interpretador();
		std:: vector <figuraGeometrica*> parse (std::string filename);
		int getDimx();
		int getDimy();
		int getDimz();
	};

#endif
