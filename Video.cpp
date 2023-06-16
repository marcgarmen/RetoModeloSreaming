#include "Video.h"

using namespace std;

Video::Video(string id, string nombre, int duracion, string genero)
    : id(id), nombre(nombre), duracion(duracion), genero(genero), calificacion(0) {}

void Video::calificar(float valor) {
    calificacion = valor;
}

float Video::obtenerCalificacion() const {
    return calificacion;
}

void Video::mostrar() {
    
}
