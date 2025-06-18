#include <iostream>
#include "Pointers.h"
#include "util.h"

using namespace std;


void DemoSwitch(){
    int a, b, rpta, opt;
    cout << "ingrese a y b";
    cin >> a >> b;
    cout << "ingrese operacion:\n0: Suma\n1: Resta\n2: Mult\n3: Div:";
    cin >> opt;
    switch(opt)
    {
        case 0: rpta = Suma(a, b);
                break;
        case 1: rpta = Resta(a, b);
                break;
        case 2: rpta = Mult(a, b);
                break;
        case 3: rpta = Division(a, b);
                break;
        default:
                rpta = 0;
    }
    cout << "Rpta: " << rpta;
}

void DemoArrayFunctPointers(){
    int a, b, rpta, opt;
    cout << "ingrese a y b";
    cin >> a >> b;
    cout << "ingrese operacion:\n0: Suma\n1: Resta\n2: Mult\n3: Div:";
    cin >> opt;
    int (*apf[4])(int, int) = {&Suma, &Resta, &Mult, &Division};
    rpta = (*apf[opt])(a, b);
    cout << "Rpta sin Switch: " << rpta;
}

class Worker{
public:
    int    a = 5,   b = 10;
    double c = 5.3, d = 8.7;
    int suma() {return a+b; };
    int resta(){return a-b; };
};

ostream &operator<<(ostream &os, Worker &w){
    return os << "a: " << w.a << " b: " << w.b;
}

void Print(Worker &w, string str){
    cout << str << " " << w << endl;
}

void DemoPointertoClassMembers(){
    Worker obj1;
    Worker *pObj = nullptr;
    pObj = new Worker; 

    auto    *pi1 = &obj1.a;
    // double *pd1 = &obj1.c;

    int Worker::*pAtt     = &Worker::a;
    // int Worker::*apAtt[2]  = {&Worker::a, &Worker::b};
    int (Worker::*pMet)() = &Worker::suma;
    // int (Worker::*apMet[2])() = {&Worker::suma, &Worker::resta};
    
    *pi1 += 7; // Puntero normal a un int

    obj1.a += 10;
    int r = obj1.suma();
    Print(obj1, "obj1");
    cout << "r: " << r << endl;

    pObj->a += 3;
    r = pObj->suma();
    Print(*pObj, "pObj");
    cout << "r: " << r << endl;

    obj1.*pAtt += 5;
    r = (obj1.*pMet)();
    Print(obj1, "obj1");
    cout << "r: " << r << endl;

    pObj->*pAtt += 11;
    r = (pObj->*pMet)();
    Print(*pObj, "pObj");
    cout << "r: " << r << endl;
}

void DemoPointers(){
    DemoSwitch();
    DemoArrayFunctPointers();
}
