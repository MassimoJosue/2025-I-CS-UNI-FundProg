#include <iostream>
#include <cstring>
#include "Practica.h"
using namespace std;

void printRever(char* p){
    int len = strlen(p);
    char *p1 = p; 
    char *p2 = p + len -1 ;

    while (p2 >= p1){
        cout << *p2;
        p2--;
    }
    cout << endl;
}
// Para compilar usar "g++ main.cpp Practica.cpp" luego "./reverso"