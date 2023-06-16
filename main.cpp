#include <iostream>
#include <vector>
#include <string>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

using namespace std;

int main() {
    vector<Video*> videos;

    // Películas
    videos.push_back(new Pelicula("1", "Inception", 148, "Ciencia ficción", 5));
    videos.push_back(new Pelicula("2", "The Shawshank Redemption", 142, "Drama", 2));
    videos.push_back(new Pelicula("3", "The Dark Knight", 152, "Acción", 4));

    // Series
    Serie* serie1 = new Serie("4", "Breaking Bad", 60, "Drama");
    serie1->agregarEpisodio(Episodio("Pilot", 1));
    serie1->agregarEpisodio(Episodio("Crazy Handful of Nothin'", 1));
    serie1->agregarEpisodio(Episodio("Full Measure", 2));
    videos.push_back(serie1);

    Serie* serie2 = new Serie("5", "Stranger Things", 50, "Drama de ciencia ficción");
    serie2->agregarEpisodio(Episodio("Chapter One: The Vanishing of Will Byers", 1));
    serie2->agregarEpisodio(Episodio("Chapter Two: The Weirdo on Maple Street", 1));
    videos.push_back(serie2);

    while (true) {
        cout << "\n----- Menú -----" << endl;
        cout << "1. Cargar archivo de datos" << endl;
        cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género" << endl;
        cout << "3. Mostrar los episodios de una determinada serie" << endl;
        cout << "4. Mostrar las películas con cierta calificación" << endl;
        cout << "5. Calificar un video" << endl;
        cout << "0. Salir" << endl;

        int opcion;
        cout << "\nSelecciona una opción: ";
        cin >> opcion;

        if (opcion == 0) {
            break;
        }

        switch (opcion) {
            case 1:
                cout << "Archivos y Datos cargados :D" << endl;
                break;
            case 2: {
                // Mostrar los videos en general con una cierta calificación o de un cierto género
                float calificacionMinima;
                string genero;

                cout << "Ingrese la calificación mínima: ";
                cin >> calificacionMinima;
                cout << "Ingrese el género: ";
                cin.ignore();
                getline(cin, genero);

                cout << "\nVideos encontrados:" << endl;
                for (const auto& video : videos) {
                    if (video->obtenerCalificacion() >= calificacionMinima && video->genero == genero) {
                        video->mostrar();
                    }
                }

                break;
            }
            case 3: {
                // Mostrar los episodios de una determinada serie
                string idSerie;

                cout << "Ingrese el ID de la serie: ";
                cin >> idSerie;

                cout << "\nEpisodios encontrados:" << endl;
                for (const auto& video : videos) {
                    Serie* serie = dynamic_cast<Serie*>(video);
                    if (serie && serie->id == idSerie) {
                        for (const auto& episodio : serie->episodios) {
                            episodio.mostrar();
                        }
                        break;
                    }
                }

                break;
            }
            case 4: {
                // Mostrar las películas con cierta calificación
                float calificacionMinima;

                cout << "Ingrese la calificación mínima: ";
                cin >> calificacionMinima;

                cout << "\nPelículas encontradas:" << endl;
                bool encontradas = false;
                for (const auto& video : videos) {
                    Pelicula* pelicula = dynamic_cast<Pelicula*>(video);
                    if (pelicula && (pelicula->obtenerCalificacion() >= calificacionMinima || pelicula->obtenerCalificacion() == 0)) {
                        pelicula->mostrar();
                        encontradas = true;
                    }
                }

                if (!encontradas) {
                    cout << "No se encontraron películas con la calificación mínima especificada." << endl;
                }

                break;
            }
            case 5: {
                // Calificar un video
                string titulo;
                float valor;

                cout << "Ingrese el título del video: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese la calificación (1-5): ";
                cin >> valor;

                for (const auto& video : videos) {
                    if (video->nombre == titulo) {
                        video->calificar(valor);
                        break;
                    }
                }

                break;
            }
            default:
                cout << "Opción inválida. Por favor, selecciona una opción válida." << endl;
                break;
        }
    }

    // Liberar memoria de los videos
    for (const auto& video : videos) {
        delete video;
    }

    return 0;
}
