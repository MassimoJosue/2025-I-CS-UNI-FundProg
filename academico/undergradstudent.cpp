#include "undergradstudent.h"

UndergraduateStudent::UndergraduateStudent(NameType name, DocType doctype, 
                        string document, string code, string career)
                    : Student(name, doctype, document, code)
{
    setCareer(career);
    cout<<"Constructor UndergraduateStudent("<<toString()<<");"<<endl;
}

UndergraduateStudent::~UndergraduateStudent(){
    cout<<"Destructor UndergraduateStudent("<<toString()<<");"<<endl;
}