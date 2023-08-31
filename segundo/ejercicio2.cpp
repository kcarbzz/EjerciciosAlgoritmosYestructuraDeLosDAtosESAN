#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generarPatronDesdeArchivo(const string& nombreArchivo) {
    // Abrir el archivo de entrada
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return;
    }

    // Leer el número desde el archivo de entrada
    int numero;
    archivoEntrada >> numero;
    archivoEntrada.close();

    // Abrir el archivo de salida
    ofstream archivoSalida("salida.txt");
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return;
    }

    // Generar el contorno del arreglo y escribirlo en el archivo de salida
    string linea;
    for (int i = 0; i < numero; i++) {
        linea = "";
        if (i == 0 || i == numero - 1) {
            for (int j = 0; j < numero; j++) {
                linea += 'a' + j;
            }
        } else {
            linea += 'a';
            for (int j = 0; j < numero - 2; j++) {
                linea += ' ';
            }
            linea += 'a';
        }
        archivoSalida << linea << endl;
    }

    archivoSalida.close();
}

int main() {
    generarPatronDesdeArchivo("entrada.txt");
    return 0;
}
