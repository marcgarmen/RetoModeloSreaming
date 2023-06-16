#ifndef VIDEO_H
#define VIDEO_H

#include <string>

using namespace std;

class Video {
public:
    string id;
    string nombre;
    int duracion;
    string genero;
    float calificacion;

public:
    Video(string id, string nombre, int duracion, string genero);

    virtual void mostrar() = 0;

    void calificar(float valor);

    float obtenerCalificacion ()const;
};

#endif
