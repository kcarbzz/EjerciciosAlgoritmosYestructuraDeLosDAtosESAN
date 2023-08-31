#include <fstream>
#include <iostream>  
using namespace std;

int main() {
    ofstream archivo("archivo.txt");

    if (archivo.is_open()) {
        archivo << "13 01 2004" << endl;
        archivo << "toro" << endl;

        archivo.close();
        cout << "Archivo creado exitosamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
