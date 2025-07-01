#include <iostream>
#include "inheritance.h"
#include "academico/professor.h"
#include "academico/student.h"
#include "academico/undergradstudent.h"
#include "academico/graduatestudent.h"
#include "academico/admin.h"

using namespace std;

void FuncionPrueba(int i, Person &person){
        cout << i << ": " << person.toString() << endl;
}

void DemoInheritance(){
    cout << "DemoInheritance" << endl;

    Professor o1 ("Ernesto", DocTypeDNI, "12345678", 100);
    cout << endl;

    Student o2("Nicole", DocTypeDNI, "12345678", "20202125C");
    cout << endl;

    UndergraduateStudent o3("Yamil", DocTypeDNI, "12345678", "20202125C", "CS undegraduate");
    cout << endl;
    
    GraduateStudent o4("Diego", DocTypeDNI, "12345678", "20202125C", "Master CS");
    cout << endl;

    Admin o5("Eduardo", DocTypeCE, "23417H", 5000, "Con balcon");
    cout << endl;

    Admin *pObj1 = new Admin("Jose", DocTypeCE, "123", 2000, "Sin balcon");
    Person *pObj[6] = {&o1, &o2, &o3, &o4, &o5, pObj1};

    cout << "Iniciando primera forma para cada objeto\n";
    for( auto i = 0; i < 6 ; ++i ){
        cout << i << ": " << pObj[i]->toString() << endl;
    }
    cout << "Fin primera forma\n" << endl;

    cout << "Iniciando segunda forma para cada objeto\n";
    for( auto i = 0; i < 6 ; ++i ){
        cout << i << ": " << (*pObj[i]).toString() << endl;
    }
    cout << "Fin segunda forma\n" << endl;
    cout << "Iniciando tercera forma para cada objeto\n";
    for( auto i = 0; i < 6 ; ++i ){
        Person &person = *pObj[i];
        cout << i << ": " << person.toString() << endl;
    }
    cout << "Fin tercera forma\n" << endl;

    cout << "Iniciando cuarta forma para cada objeto\n";
    for( auto i = 0; i < 6 ; ++i ){
        FuncionPrueba(i, *pObj[i]);
    }
    cout << "Fin cuarta forma\n" << endl;
    delete pObj1;

    // Calling methods in different Scopes
    cout << o4.toString() << endl;
    cout << o4.Student::toString() << endl;
    cout << o4.Person::toString() << endl;
}

void DemoPolymorphism(){

}