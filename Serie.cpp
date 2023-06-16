#include "Serie.h"
#include <iostream>

using namespace std;

Serie::Serie(string id, string nombre, int duracion, string genero)
    : Video(id, nombre, duracion, genero) {}

void Serie::agregarEpisodio(Episodio episodio) {
    episodios.push_back(episodio);
}

void Serie::mostrar() {
    cout << "Serie - ID: " << id << ", Nombre: " << nombre << ", Duración: " << duracion << " min, Género: " << genero << ", Calificación: " << calificacion << endl;
    cout << "Episodios:" << endl;
    for (const auto& episodio : episodios) {
        episodio.mostrar();
    }
}

