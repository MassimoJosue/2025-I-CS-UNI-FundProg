#ifndef __UNDERGRADUATE_STUDENT_H__
#define __UNDERGRADUATE_STUDENT_H__
#include "student.h"
#include <sstream>

class UndergraduateStudent : public Student {
    private: 
        string m_Career= "NoCareer";
    public:
        
        UndergraduateStudent(NameType name, DocType doctype, string document, string code, string career);

        virtual ~UndergraduateStudent();
        void setCareer(const string career) { m_Career = career; }
        string getCareer() { return m_Career; }

        string toString() override {
            std::ostringstream ostr;
            ostr << Student::toString() << " Career: " << getCareer();
            return ostr.str();
        }
};

#endif // __UNDERGRADUATE_STUDENT_H__