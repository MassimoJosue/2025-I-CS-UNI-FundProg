#include "graduatestudent.h"

GraduateStudent::GraduateStudent(NameType name, DocType doctype, 
                        string document, string code, string GraduateProgram)
                    : Student(name, doctype, document, code)
{
    setGraduateProgram(GraduateProgram);
    cout<<"Constructor Graduate Student("<<toString()<<");"<<endl;
}

GraduateStudent::~GraduateStudent(){
    cout<<"Destructor Graduate Student("<<toString()<<");"<<endl;
}