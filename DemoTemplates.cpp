#include <iostream>
#include <vector>
#include "DemoTemplates.h"
using namespace std;

void DemoTemplates1(){
    int x = 5, y = 8;
    Procesar(x, y);

    string str1 = "CS", str2 = "UNI";
    Procesar(str1, str2);

    float f1 = 3.14, f2 = 2.71;
    Procesar(f1, f2);
}

void printVector(vector<int>& v) {
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
}

void DemoTemplates2(){

    cout << "DemoTemplates2\n";
    vector<int> v1 = {1, 4, 2, 8, 5};
    v1[3] = 11; // operator [] has been overloaded
    printVector(v1);

    vector<int> v2 = {3, 2, 9, 0, -1, 7, 15, 4};
    printVector(v2);
}
