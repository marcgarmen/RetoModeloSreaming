#include "Pelicula.h"
#include <iostream>

using namespace std;

Pelicula::Pelicula(string id, string nombre, int duracion, string genero, float calificacion)
    : Video(id, nombre, duracion, genero) {
    this->calificacion = calificacion;
}

void Pelicula::mostrar() {
    cout << "Película - ID: " << id << ", Nombre: " << nombre << ", Duración: " << duracion << " min, Género: " << genero << ", Calificación: " << calificacion << endl;
}
