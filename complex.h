#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <iostream>
using namespace std;
using RealType = double;
using ImagType = float;

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
    inline Complex(RealType a, ImagType b){
        m_r = a;
        m_i = b;
    }
    // Destructor

    // Operadores
    Complex& operator+=(const Complex& other) {
        other;
        m_r += other.getReal();
        m_i += other.getImag();
        return *this;
    }
    Complex& operator-=(const Complex& other) {
        m_r -= other.getReal();
        m_i -= other.getImag();
        return *this;
    }
    Complex& operator*=(const Complex& other) {
        m_r = m_r*other.getReal() - m_i*other.getImag();
        m_i = m_r*other.getImag() + m_i*other.getReal();
        return *this;
    }
    Complex& operator/=(const Complex& other) {
        m_r = (m_r*other.getReal() + m_i*other.getImag()) / (other.getReal()*other.getReal() + other.getImag()*other.getImag());
        m_i = (m_i*other.getReal() - m_r*other.getImag()) / (other.getReal()*other.getReal() + other.getImag()*other.getImag());
        return *this;
    }

    Complex operator+(const Complex& other){
        RealType a = m_r + other.getReal();
        ImagType b = m_i + other.getImag();
        return Complex(a, b);
    }
    Complex operator-(const Complex& other){
        RealType a = m_r - other.getReal();
        ImagType b = m_i - other.getImag();
        return Complex(a, b);
    }
    Complex operator*(const Complex& other){
        RealType a = m_r*other.getReal() - m_i*other.getImag();
        ImagType b = m_r*other.getImag() + m_i*other.getReal();
        return Complex(a, b);
    }
    Complex operator/(const Complex& other) { // Deberia ser const Complex& other
        RealType a = (m_r*other.getReal() + m_i*other.getImag()) / (other.getReal()*other.getReal() + other.getImag()*other.getImag());
        ImagType b = (m_i*other.getReal() - m_r*other.getImag()) / (other.getReal()*other.getReal() + other.getImag()*other.getImag());
        return Complex(a, b);
    }

    friend istream &operator>>(istream &is, Complex &z);

    // Conversiones
    operator RealType() const{
        return (*this).getReal();
    }

    operator ImagType() const{
        return (*this).getImag();
    }

    // Getters
    RealType getReal() const { return m_r; }
    ImagType getImag() const { return m_i; }
};
// Operador salida
inline ostream &operator<<(ostream &os, Complex &z){
    return os << z.getReal() << ((z.getImag() < 0) ? " - " : " + ") << abs(z.getImag()) << "i";
}

// Operador entrada
istream &operator>>(istream &is, Complex &z){
    cout << "Ingrese la parte real: ";
    is >> z.m_r;
    cout << "Ingrese la parte imaginaria: ";
    is >> z.m_i;
    return is;
}

#endif // __COMPLEX_H__