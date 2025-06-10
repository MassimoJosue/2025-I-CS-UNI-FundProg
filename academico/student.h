#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "person.h"

class Student : public Person{
    private:
    StudentCode m_code;
    public:
    Student(NameType name, DocType doctype, string document, StudentCode code);
    virtual ~Student();

    void setCode(StudentCode code){m_code = code ;}
    StudentCode getCode() {return m_code;}

        virtual string toString(){
        ostrstream ostr;
        ostr << Person :: toString()
             << " Codigo: " << getCode();
        return ostr.str();
    }
};

#endif