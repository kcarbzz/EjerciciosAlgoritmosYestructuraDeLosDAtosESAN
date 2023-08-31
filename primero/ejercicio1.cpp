#include <iostream>
#include <fstream>
using namespace std;

bool esBisiesto(int age) {
    bool bisiesto;

    if (age % 4 == 0) {
        if (age % 100 == 0) {
            if (age % 400 == 0)
                bisiesto = true;
            else
                bisiesto = false;
        } else
            bisiesto = true;
    } else
        bisiesto = false;

    return bisiesto;
}

bool esFechaValida(int dia, int mes, int age) {
    if (mes >= 1 && mes <= 12) {
        switch (mes) {
            case 1: // enero
            case 3: // marzo
            case 5: // mayo
            case 7: // julio
            case 8: // agosto
            case 10: // octubre
            case 12: // diciembre
                return dia >= 1 && dia <= 31;
            case 4: // abril
            case 6: // junio
            case 9: // septiembre
            case 11: // noviembre
                return dia >= 1 && dia <= 30;
            case 2: // febrero
                if (esBisiesto(age)) {
                    return dia >= 1 && dia <= 29;
                } else {
                    return dia >= 1 && dia <= 28;
                }
        }
    }
    return false;
}

void comprobarFecha(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int dia, mes, age;
    archivo >> dia >> mes >> age;
    archivo.close();

    bool fechaValida = esFechaValida(dia, mes, age);

    ofstream archivoSalida(nombreArchivo, ios::app);
    if (fechaValida) {
        archivoSalida << "Válido" << endl;
	cout<< "Válido" <<endl;
    } else {
        archivoSalida << "Inválido" << endl;
	cout<< "Invalido"<<endl;
    }
    
    archivoSalida.close();
}
bool verificarLecturaExitosa(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;

    if (archivo.is_open()) {
        if (getline(archivo, linea)) {
            cout << "La primera línea del archivo es: " << linea << endl;
            archivo.close();
            return true;
        } else {
            cerr << "Error al leer la primera línea del archivo." << endl;
        }
        archivo.close();
    } else {
        cerr << "Error al abrir el archivo." << endl;
    }

    return false;
}
int main() {
    string nombreArchivo = "prueba.txt";
    verificarLecturaExitosa(nombreArchivo);
    comprobarFecha(nombreArchivo);
    return 0;
}

