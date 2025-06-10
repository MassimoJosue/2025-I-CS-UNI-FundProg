#include "student.h"

using namespace std;

Student::Student(NameType name, DocType doctype, string document, StudentCode code) 
        : Person(name,doctype,document){
    setCode(code);
    cout<<"Constructor Estudiante("<<toString()<<");"<<endl;
}

Student :: ~Student(){
    cout<<"Destructor Estudiante("<<toString()<<");"<<endl;
}