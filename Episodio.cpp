#include "Episodio.h"
#include <iostream>

using namespace std;

Episodio::Episodio(string titulo, int temporada)
    : titulo(titulo), temporada(temporada), calificacion(0) {}

void Episodio::calificar(float valor) {
    calificacion = valor;
}

float Episodio::obtenerCalificacion() const {
    return calificacion;
}

void Episodio::mostrar() const {
    cout << "Episodio - Título: " << titulo << ", Temporada: " << temporada << ", Calificación: " << calificacion << std::endl;
}