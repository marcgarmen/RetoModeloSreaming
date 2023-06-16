#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>

using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;
    float calificacion;

public:
    Episodio(string titulo, int temporada);

    void calificar(float valor);

    float obtenerCalificacion() const;

    void mostrar() const;
};

#endif
