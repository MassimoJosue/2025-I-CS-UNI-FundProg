#ifndef __COMPLEX_H__
#define __COMPLEX_H__

using RealType = double;
using ImagType = double;

class Complex
{
private:
    // Real part
    RealType m_r = 0;
    // Real part
    ImagType m_i = 0;
public:
    // Constructores
    Complex() : m_r(0), m_i(0) {}
    Complex(double r, double i) : m_r(r), m_i(i) {}

    // Destructor
    ~Complex() = default;
    // Getters
    RealType getReal() const {return m_r;}
    ImagType getImag() const { return m_i; }

    // Operador suma

    Complex operator+(const Complex& other) const {
        return Complex(m_r + other.getReal(), m_i + other.getImag());
    }
    // Operadores
    Complex& operator+=(const Complex& other){
        m_r += other.getReal();
        m_i += other.getImag();
        return *this;
    }
    Complex& operator-=(const Complex& other) {
        m_r -= other.getReal();
        m_i -= other.getImag();
        return *this;
    }
    // a eliminar
    // Conversion de tipo Real/Imag 
    operator RealType() const { return m_r; }
    operator ImagType() const { return m_i; }
    // Operadores de flujo
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.m_r << " + " << c.m_i << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.m_r >> c.m_i;
        return is;
    }
    
};

#endif // __COMPLEX_H__