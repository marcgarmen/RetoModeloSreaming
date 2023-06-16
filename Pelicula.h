#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

using namespace std;

class Pelicula : public Video {
public:
    Pelicula(string id,string nombre, int duracion, string genero, float calificacion);

    void mostrar();
};

#endif
