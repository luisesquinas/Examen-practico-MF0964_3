#include <iostream>
#include <fstream>  // Incluir esta biblioteca para trabajar con archivos
#include "vol.h"


int main() {
    // Ubicación 1: Aeropuerto de Barcelona-El Prat (A)
    double lat1 = 41.2974;
    double lon1 = 2.0833;


    // Ubicación 2: Aeropuerto de Madrid-Barajas (B)
    double lat2 = 40.4719;
    double lon2 = -3.5626;


    // Ubicación 3: Aeropuerto de Sevilla (C)
    double lat3 = 37.4180;
    double lon3 = -5.8931;


    // Velocidad constante de un avión (por ejemplo, 900 km/h)
    double velocitat = 900.0;


    // Calcular tiempo de vuelo entre Barcelona y Madrid (AB)
    double tempsVolAB = calcularTempsVol(lat1, lon1, lat2, lon2, velocitat);
    double tempsVolMinutsAB = tempsVolAB * 60;


    // Calcular tiempo de vuelo entre Madrid y Sevilla (BC)
    double tempsVolBC = calcularTempsVol(lat2, lon2, lat3, lon3, velocitat);
    double tempsVolMinutsBC = tempsVolBC * 60;


    // Calcular tiempo de vuelo entre Barcelona y Sevilla (AC)
    double tempsVolAC = calcularTempsVol(lat1, lon1, lat3, lon3, velocitat);
    double tempsVolMinutsAC = tempsVolAC * 60;


    // Crear y abrir el archivo salida.txt
    std::ofstream outfile("salida.txt");


    if (outfile.is_open()) {
        // Mostrar resultados
        outfile << "El temps estimat de vol entre l'Aeroport de Barcelona-El Prat i "
                << "l'Aeroport de Madrid-Barajas és de: "
                << tempsVolMinutsAB << " minuts." << std::endl;


        outfile << "El temps estimat de vol entre l'Aeroport de Madrid-Barajas i "
                << "l'Aeroport de Sevilla és de: "
                << tempsVolMinutsBC << " minuts." << std::endl;


        outfile << "El temps estimat de vol entre l'Aeroport de Barcelona-El Prat i "
                << "l'Aeroport de Sevilla és de: "
                << tempsVolMinutsAC << " minuts." << std::endl;


        // Determinar el vuelo más corto
        if (tempsVolMinutsAB <= tempsVolMinutsBC && tempsVolMinutsAB <= tempsVolMinutsAC) {
            outfile << "El vol més curt és entre Barcelona i Madrid, amb una durada de "
                    << tempsVolMinutsAB << " minuts." << std::endl;
        } else if (tempsVolMinutsBC <= tempsVolMinutsAB && tempsVolMinutsBC <= tempsVolMinutsAC) {
            outfile << "El vol més curt és entre Madrid i Sevilla, amb una durada de "
                    << tempsVolMinutsBC << " minuts." << std::endl;
        } else {
            outfile << "El vol més curt és entre Barcelona i Sevilla, amb una durada de "
                    << tempsVolMinutsAC << " minuts." << std::endl;
        }


        // Cerrar el archivo
        outfile.close();
    } else {
        std::cerr << "No se pudo abrir el archivo salida.txt." << std::endl;
    }


    return 0;
}
