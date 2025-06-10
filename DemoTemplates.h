#ifndef __DEMO_TEMPLATES_H__
#define __DEMO_TEMPLATES_H__
#include <iostream>
#include "util.h"
using namespace std;

template <typename T>
void Procesar(T &v1, T &v2){
    cout << "v1: " << v1 << " v2: " << v2 << endl;
    intercambiar(v1, v2);
    cout << "v1: " << v1 << " v2: " << v2 << endl;
}

void DemoTemplates1();
void DemoTemplates2();

#endif // __DEMO_TEMPLATES_H__