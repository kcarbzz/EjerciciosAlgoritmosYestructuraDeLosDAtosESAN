
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void encontrarDivisoresComunes(const string& nombreArchivo) {
    // Abrir el archivo de entrada
    ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return;
    }

    // Leer los dos números desde el archivo de entrada
    int num1, num2;
    archivoEntrada >> num1 >> num2;
    archivoEntrada.close();

    // Encontrar los divisores comunes
    vector<int> divisoresComunes;
    for (int i = 1; i <= min(num1, num2); i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            divisoresComunes.push_back(i);
        }
    }

    // Abrir el archivo de salida
    ofstream archivoSalida("salida2.txt");
    if (!archivoSalida.is_open()) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return;
    }

    // Escribir los divisores comunes en el archivo de salida
    for (int divisor : divisoresComunes) {
        archivoSalida << divisor << endl;
    }

    archivoSalida.close();
}

int main() {
    encontrarDivisoresComunes("entrada2.txt");
    return 0;
}
