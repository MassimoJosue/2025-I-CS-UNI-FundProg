#include <iostream>
#include "inheritance.h"
#include "academico/professor.h"
#include "academico/student.h"
#include "academico/undergradstudent.h"
#include "academico/graduatestudent.h"
#include "academico/admin.h"

using namespace std;

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
}