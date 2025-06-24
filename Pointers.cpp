#include <iostream>
#include "Pointers.h"
#include "util.h"

using namespace std;


void DemoSwitch(){
    int a, b, rpta, optTmp;
    OpeType opt;
    cout << "ingrese a y b";
    cin >> a >> b;
    cout << "ingrese operacion:\n0: Suma\n1: Resta\n2: Mult\n3: Div:";
    cin >> optTmp;
    opt = (OpeType)optTmp;
    switch(opt){
        case Adding : rpta = Suma(a, b);
                break;
        case Substracting : rpta = Resta(a, b);
                break;
        case Multiplying : rpta = Mult(a, b);
                break;
        case Dividing : rpta = Division(a, b);
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
using PWorkerMethod = int (Worker::*)();

ostream &operator<<(ostream &os, Worker &w){
    return os << "a: " << w.a << " b: " << w.b;
}

void Print(Worker &w, string str){
    cout << str << " " << w << endl;
}

void Fx(Worker &obj, PWorkerMethod pMet){
    auto rpta = (obj.*pMet)();
    Print(obj, "obj");
    cout << "rpta: " << rpta << endl;
}

void DemoPointertoClassMembers(){
    Worker obj1;
    Worker *pObj = nullptr;
    pObj = new Worker; 

    auto    *pi1 = &obj1.a;
    // double *pd1 = &obj1.c;

    // int Worker::*pAtt     = &Worker::a;
    auto pAtt     = &Worker::a;
    // int Worker::*apAtt[2]  = {&Worker::a, &Worker::b};
    
    // int (Worker::*pMet)() = &Worker::suma;
    auto pMet     = &Worker::suma;
    // int (Worker::*apMet[2])() = {&Worker::suma, &Worker::resta};
    
    *pi1 += 7; // Puntero normal a un int

    obj1.a += 10;
    auto r = obj1.suma();
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

    Fx(obj1, &Worker::suma);
    Fx(obj1, &Worker::resta);
    Fx(*pObj, &Worker::suma);
    Fx(*pObj, &Worker::resta);
}

using PF = int (*)(int, int);
// int (*GetOperation(int n))(int, int)
PF GetOperation(int n){
    // int (*apf[4])(int, int) = {&Suma, &Resta, &Mult, &Division};
    PF apf[4] = {&Suma, &Resta, &Mult, &Division};
    return apf[n];
}

void ExecuteOperation(int iOpe, int v1, int v2){
    PF pf = nullptr;
    pf = GetOperation(iOpe);
    auto rpta = (*pf)(v1, v2);
    cout << "v1: " << v1 << " v2:" << v2 
         << " Ope: "<< iOpe << " rpta: " << rpta << endl;
}

// int (Worker::*GetMethod(int iOpe))(){
//     int (Worker::*apMet[2])() = {&Worker::suma, &Worker::resta};
//     return apMet[iOpe];
// }

auto GetMethod(OpeType iOpe){
    PWorkerMethod apMet[2];
    apMet[(int)Adding]       = &Worker::suma;
    apMet[(int)Substracting] = &Worker::resta;
    return apMet[iOpe];
}

// void ExecuteMethod(Worker &obj, int iMet){
//     int (Worker::*pMet)() = GetMethod(iMet);
//     int rpta = (obj.*pMet)();
//     Print(obj, "obj");
//     cout << "rpta: " << rpta << endl;
// }

void ExecuteMethod(Worker &obj, OpeType iMet){
    auto pMet = GetMethod(iMet);
    int rpta = (obj.*pMet)();
    Print(obj, "obj");
    cout << "rpta: " << rpta << endl;
}

void DemoComplexReturnValues(){
    ExecuteOperation(Adding, 5, 7); // Suma
    ExecuteOperation(Multiplying, 6, 8); // Multiplicacion

    Worker obj1;
    ExecuteMethod(obj1, Adding);
    ExecuteMethod(obj1, Substracting);

    Worker *pObj = nullptr;
    pObj = new Worker; 
    pObj->a = 12;   pObj->b = 9;
    ExecuteMethod(*pObj, Adding);
    ExecuteMethod(*pObj, Substracting);
}

void DemoPointers(){
    DemoSwitch();
    DemoArrayFunctPointers();
}
