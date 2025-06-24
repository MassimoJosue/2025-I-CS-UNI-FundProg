#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // Para function
#include "DemoLambda.h"
using namespace std;

void imprimir1(int n) { 
    cout << n << " ";
}

void DemoLambdaFunctions() {
    cout << "=== DEMOSTRACIÓN DE FUNCIONES LAMBDA EN C++ ===\n\n";
    
    // 1. Preparación del vector de ejemplo
    vector<int> numeros = {1, 2, 3, 4, 5};
    imprimir1(100);

    // ---------------------------------------------------------------------
    // 2. Iteración tradicional (sin lambdas)
    cout << "1A. Iteración tradicional (sin lambdas):\n";
    for(size_t i = 0; i < numeros.size(); ++i)
        cout << numeros[i] << " ";
    cout << "\n\n";

    cout << "1B. Iteración tradicional (sin lambdas):\n";
    for(auto n: numeros)
        cout << n << " ";
    cout << "\n\n";
    
    // ---------------------------------------------------------------------
    // 3. Lambda básica para imprimir
    cout << "2A. Iteración con funcion externa básica:\n";
    numeros[2] = 7;
    // Usamos for_each aplicando una funcion externa normal
    for_each(numeros.begin(), numeros.end(), imprimir1);
    cout << "\n\n";

    // Definimos una lambda que toma un entero y lo imprime
    auto imprimir2 = [](int n) { 
        cout << n << " "; 
        // numeros[2] = 7;
    };

    cout << "2B. Iteración con lambda básica:\n";
    for_each(numeros.begin(), numeros.end(), imprimir2);
    cout << "\n\n";

    cout << "2C. Iteración con lambda definida en a llamada:\n";
    for_each(numeros.begin(), numeros.end(), 
            [](int n) { cout << n << " "; } );
    cout << "\n\n";
    
    // ---------------------------------------------------------------------
    // 4. Lambda definida e invocada inmediatamente (IIFE - Immediately Invoked Function Expression)
    cout << "3A. Lambda definida e invocada inmediatamente:\n";
    [](const vector<int>& nums) {
        cout << "Elementos: ";
        for (int n : nums) {
            cout << n << " ";
        }
        cout << "\n";
    }(numeros); // Pasamos el vector como argumento
    cout << "\n";

    cout << "3B. Lambda definida e invocada a continuación:\n";
    auto imprimir3B = [](const vector<int>& nums) {
        cout << "Elementos: ";
        for (int n : nums) {
            cout << n << " ";
        }
        cout << "\n";
    };
    imprimir3B(numeros);
    imprimir3B(numeros);

    // // ---------------------------------------------------------------------
    // // 5. Lambda con parámetro extra y captura de variables
    // cout << "4. Lambda con parámetro extra y captura de variables:\n";
    // string prefijo = "Valor: ";
    // int factor = 2;
    
    // // Lambda que captura 'prefijo' por valor y 'factor' por referencia
    // auto imprimirConOperacion = [prefijo, &factor](int n) {
    //     cout << prefijo << n << ", " << n << " × " << factor << " = " << n * factor << "\n";
    //     factor++; // Modificamos factor (capturado por referencia)
    // };
    
    // for_each(numeros.begin(), numeros.end(), imprimirConOperacion);
    // cout << "Factor final: " << factor << "\n\n";
    
    // // ---------------------------------------------------------------------
    // // 6. Diferentes formas de captura
    // cout << "5. Diferentes formas de captura:\n";
    // int a = 10, b = 20, c = 30;
    
    // // Captura específica: a por valor, b por referencia, c por valor
    // auto lambdaCapturas = [a, &b, c](int x) {
    //     cout << "a=" << a << ", b=" << b << ", c=" << c << ", x=" << x << "\n";
    //     b++; // Solo podemos modificar b (capturada por referencia)
    // };
    
    // lambdaCapturas(1);
    // lambdaCapturas(2);
    // cout << "b modificado: " << b << "\n\n"; // b ha cambiado
    
    // // Captura todo por valor
    // auto capturaTodoPorValor = [=](int x) {
    //     cout << "Todo por valor: a=" << a << ", x=" << x << "\n";
    // };
    // capturaTodoPorValor(3);
    
    // // Captura todo por referencia
    // auto capturaTodoPorReferencia = [&](int x) {
    //     a++; // Podemos modificar las variables originales
    //     cout << "Todo por referencia: a=" << a << ", x=" << x << "\n";
    // };
    // capturaTodoPorReferencia(4);
    // cout << "a modificado: " << a << "\n\n";
    
    // // ---------------------------------------------------------------------
    // // 7. Punteros a funciones lambda
    // cout << "6. Punteros a funciones lambda:\n";
    
    // // a) Lambda sin capturas puede convertirse a puntero de función tradicional
    // void(*ptrFuncion)(int) = [](int x) {
    //     cout << "Puntero tradicional: " << x << "\n";
    // };
    // ptrFuncion(42);
    
    // // b) Lambda con capturas necesita function
    // function<void(int)> ptrConCaptura = [a](int x) { // Capturamos 'a' por valor
    //     cout << "function: " << x << ", a=" << a << "\n";
    // };
    // ptrConCaptura(100);
    
    // // ---------------------------------------------------------------------
    // // 8. Lambda mutable (permite modificar variables capturadas por valor)
    // cout << "\n7. Lambda mutable:\n";
    // int contador = 0;
    
    // auto lambdaMutable = [contador]() mutable {
    //     contador++;
    //     cout << "Contador interno: " << contador << "\n";
    //     return contador;
    // };
    
    // cout << "Contador original: " << contador << "\n";
    // lambdaMutable();
    // lambdaMutable();
    // cout << "Contador después (no cambia): " << contador << "\n";
}
