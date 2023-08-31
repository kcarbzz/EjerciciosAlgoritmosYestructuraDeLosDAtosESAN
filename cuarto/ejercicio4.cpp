#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Resultado {
    int suma;
    int cantidadPares;
    int cantidadImpares;
    double promedio;
    vector<int> listaOrdenada;
};

void ordenarLista(vector<int>& numeros) {
    int n = numeros.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

Resultado procesarArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo.");
    }

    int cantidadNumeros;
    archivo >> cantidadNumeros;

    vector<int> numeros;
    int numero;
    for (int i = 0; i < cantidadNumeros; ++i) {
        archivo >> numero;
        numeros.push_back(numero);
    }

    archivo.close();

    int suma = 0;
    int cantidadPares = 0;
    int cantidadImpares = 0;

    for (int num : numeros) {
        suma += num;
        if (num % 2 == 0) {
            cantidadPares++;
        } else {
            cantidadImpares++;
        }
    }

    double promedio = static_cast<double>(suma) / cantidadNumeros;

    vector<int> listaOrdenada = numeros;
    ordenarLista(listaOrdenada);

    return { suma, cantidadPares, cantidadImpares, promedio, listaOrdenada };
}

int main() {
    try {
        string nombreArchivo = "entrada4.txt"; 

        Resultado resultado = procesarArchivo(nombreArchivo);

        cout << "Suma de los números: " << resultado.suma << endl;
        cout << "Cantidad de números pares: " << resultado.cantidadPares << endl;
        cout << "Cantidad de números impares: " << resultado.cantidadImpares << endl;
        cout << "Promedio de los números: " << resultado.promedio << endl;
        cout << "Lista ordenada de números: ";
        for (int num : resultado.listaOrdenada) {
            cout << num << " ";
        }
        cout << endl;
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
        return 1;
    }

    return 0;
}
