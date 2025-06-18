#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "DemoFiles.h"

using namespace std;

struct Persona {
    char nombre[50];
    int edad;
    double altura;
};

// Esta funcion escribe 3 estructuras en su forma binaria en un archivo.
// Los ejemplos anteriores lo hacian en modo texto solamente
// Es decir, si escribes un int x = 123456;
// Como texto ocuparia 6 caracteres y lo podrias leer al abrir el archivo
// En cambio, si lo escribes como binario, solo ocupa 4 bytes (sizeof(int)) y 
// se escribe en su forma nativa. Es decir, en binario tal lcual 
// esta en la memoria
void DemoBinaryFiles(){
    // Datos a escribir
    vector<Persona> personas = {
        {"Juan Fernández", 30, 1.75},
        {"María García", 25, 1.68},
        {"Carlos López", 40, 1.82}
    };

    // Abrir archivo en modo binario para escritura
    ofstream archivo_salida("personas.dat", ios::binary);
    
    if (!archivo_salida) {
        cerr << "Error al abrir el archivo para escritura." << endl;
        return;
    }

    // Escribir cada persona en el archivo
    for (const auto& persona : personas) {
        archivo_salida.write(reinterpret_cast<const char*>(&persona), sizeof(Persona));
        
        if (!archivo_salida) {
            cerr << "Error al escribir en el archivo." << endl;
            return;
        }
    }

    // Cerrar el archivo
    archivo_salida.close();

    cout << "Datos escritos correctamente en el archivo binario." << endl;
}

Persona leerPersona(const string& nombreArchivo, int n) {
    // Abrir archivo en modo binario para lectura
    ifstream archivo_entrada(nombreArchivo, ios::binary);
    
    if (!archivo_entrada) {
        throw runtime_error("Error al abrir el archivo para lectura.");
    }

    // Calcular la posición del registro n en el archivo
    // seekg mueve el punbtero de lectura a una posicion
    archivo_entrada.seekg(n * sizeof(Persona), ios::beg);
    
    if (!archivo_entrada) {
        throw runtime_error("Error al buscar la posición del registro.");
    }

    // Leer el registro
    Persona persona;
    archivo_entrada.read(reinterpret_cast<char*>(&persona), sizeof(Persona));
    
    if (!archivo_entrada) {
        throw runtime_error("Error al leer el registro del archivo.");
    }

    // Cerrar el archivo (se cierra automáticamente al salir del ámbito)
    return persona;
}

void DemoRandomFiles() {
    try {
        // Leer el segundo registro (el indice empieza en 0)
        Persona p = leerPersona("personas.dat", 1);
        
        cout << "Nombre: " << p.nombre << "\n"
             << "Edad: "   << p.edad   << "\n"
             << "Altura: " << p.altura << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return;
    }
}

void DemoFiles(){
    DemoBinaryFiles();
    DemoRandomFiles();
    cout << sizeof(Persona) << endl;
    cout << sizeof(Persona::nombre) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(double) << endl;
    
}