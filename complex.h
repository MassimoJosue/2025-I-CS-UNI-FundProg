#ifndef __COMPLEX_H__
#define __COMPLEX_H__

using RealType = double;
using ImagType = double;

// Complex
class Complex
{
private:
    // Real part
    RealType m_r = 0;
    // Real part
    ImagType m_i = 0;
public:
    // Constructores

    // Destructor

    // Operadores
    Complex& operator+=(const Complex& other) {
        m_r += other.getReal();
        m_i += other.getImag();
        return *this;
    }
};

#endif // __COMPLEX_H__