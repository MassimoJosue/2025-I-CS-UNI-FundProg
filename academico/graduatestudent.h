#ifndef __GRADUATE_STUDENT_H__
#define __GRADUATE_STUDENT_H__
#include "student.h"
#include <sstream>

class GraduateStudent : public Student {
    private: 
        string m_GraduateProgram = "No graduate program";
    public:
        
        GraduateStudent(NameType name, DocType doctype, string document, string code, string GraduateProgram);

        virtual ~GraduateStudent();
        void setGraduateProgram(const string GraduateProgram) { m_GraduateProgram = GraduateProgram; }
        string getGraduateProgram() { return m_GraduateProgram; }

        virtual string toString() {
            std::ostringstream ostr;
            ostr << Student::toString() << " GraduateProgram: " << getGraduateProgram();
            return ostr.str();
        }
};

#endif // __GRADUATE_STUDENT_H__