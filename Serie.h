#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"
#include <vector>

using namespace std;

class Serie : public Video {
public:
    vector<Episodio> episodios;

public:
    Serie(string id, string nombre, int duracion, string genero);

    void agregarEpisodio(Episodio episodio);

    void mostrar();
};

#endif
