#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;

void unirPalabras(const string& nombreArchivoEntrada, const string& nombreArchivoSalida) {
    ifstream archivoEntrada(nombreArchivoEntrada);
    if (!archivoEntrada.is_open()) {
        throw runtime_error("No se pudo abrir el archivo de entrada.");
    }

    int cantidadPalabras;
    archivoEntrada >> cantidadPalabras;

    vector<string> palabras;
    for (int i = 0; i < cantidadPalabras; i++) {
        string palabra;
        archivoEntrada >> palabra;
        palabras.push_back(palabra);
    }

    archivoEntrada.close();

    ofstream archivoSalida(nombreArchivoSalida);
    if (!archivoSalida.is_open()) {
        throw runtime_error("No se pudo abrir el archivo de salida.");
    }

    // Escribir la primera palabra con la letra mayúscula
    string primeraPalabra = palabras[0];
    primeraPalabra[0] = toupper(primeraPalabra[0]);

    // Escribir las palabras restantes con espacios
    for (int i = 0; i < cantidadPalabras; i++) {
        archivoSalida << " " << palabras[i];
    }

    // Agregar el punto final
    archivoSalida << ".";

    archivoSalida.close();

    cout << "Archivo generado exitosamente: " << nombreArchivoSalida << endl;
}

int main() {
    try {
        string nombreArchivoEntrada = "entrada5.txt"; 
        string nombreArchivoSalida = "salida5.txt"; 

        unirPalabras(nombreArchivoEntrada, nombreArchivoSalida);
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
        return 1;
    }

    return 0;
}

