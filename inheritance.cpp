#include <iostream>
#include "inheritance.h"
#include "academico/professor.h"
#include "academico/student.h"
using namespace std;

void DemoInheritance(){
    cout << "DemoInheritance" << endl;

    Professor p1 ("Ernesto", DocTypeDNI, "12345678", 100);

    Student s1("Diego", DocTypeDNI, "12345678", "20202125C");
    
}