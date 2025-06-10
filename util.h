#ifndef __UTIL_H__
#define __UTIL_H__

template <typename T>
void intercambiar(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int Suma    (int a, int b);
int Resta   (int a, int b);
int Mult    (int a, int b);
int Division(int a, int b);

#endif // __UTIL_H__