#include <iostream>
#include <vector>
#include "DemoTemplates.h"
using namespace std;

void DemoTemplates1(){
    int x = 5, y = 8;
    Procesar(x, y);

    string str1 = "CS", str2 = "UNI";
    Procesar(str1, str2);

    float f1 = 3.14, f2 = 2.71;
    Procesar(f1, f2);
}

void printVector(vector<int>& v) {
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
}

void DemoTemplates2(){

    cout << "DemoTemplates2\n";
    vector<int> v1 = {1, 4, 2, 8, 5};
    v1[3] = 11; // operator [] has been overloaded
    printVector(v1);

    vector<int> v2 = {3, 2, 9, 0, -1, 7, 15, 4};
    printVector(v2);
}


auto sum1(){
    return 0;
}

template <typename T, typename ...Q>
auto sum1(T arg1, Q... args){
    return arg1 + sum1(args...);
}

template <typename ... T>
auto sum2(T ... args)
{
    return (... + args);
}

template <typename... T>
auto sum3(T ... args)
{
    return (... + args);
}

template <typename... T>
auto print1(T ... args)
{
    (cout << ... << args) << "fin!\n";
}

template <typename... T>
auto print2(T ... args)
{
    cout << (args << ...);
}

template<typename T>
const T& spaceBefore(const T& arg)
{   cout << ' ';
    return arg;
}

template <typename First, typename... Args>
void printx(const First& firstarg, const Args&... args)
{
    cout << firstarg;
    (cout << ... << spaceBefore(args)) << '\n';
}

template <typename First, typename... Args>
void printy(const First& firstarg, const Args&... args)
{
    cout << firstarg;
    auto spaceBeforex = [](const auto& arg) -> const auto&
    { cout << ' ';
      return arg;
    };
    (cout << ... << spaceBeforex(args)) << '\n';
}

template <std::size_t ... idx, typename Container>
void printIdx(const Container& coll)
{
    printx(coll[idx]...);
}

template <typename Container, typename... Idx>
void printIdx2(const Container& coll, const Idx&... idx)
{
    printx(idx...);
    printx(coll[idx]...);
}

/*template <typename Container>
void printIdx3(const Container& coll, std::size_t ... idx)
{
     printIdx<idx...>(coll);
}*/

void DemoVariadicTemplates()
{
    auto rpta1 = sum1(7, 10, 4, 10.5);
    cout << rpta1 << endl;

    // auto rpta2 = sum2(6, 8, 2.5, 10);
    // cout << rpta2 << endl;

    // auto rpta3 = sum3(6, 8, 7.5, 10);
    // cout << rpta3 << endl;

    // auto rpta4 = sum2(string("Hola"), "que", "tal! ", "prueba ", "de", "variadic", "templates");
    // cout << rpta4 << endl;

    // //auto rpta5 = sum2("Hola", "que", "tal! ", "prueba ", "de ", "variadic ", "templates ");
    // //cout << rpta5 << endl;
    // print1("Holax", "quex", "tal! ", "prueba ", "de ", "variadic ", "templates ");

    // std:vector<std::string> strVect = {"Hello", "testing", "variadic", "indices", "in", "C++17"};
    // printIdx<1, 3, 5, 0>(strVect);
    // printIdx2(strVect, 1, 3, 5, 0);
    // //printIdx3(strVect, 1, 3, 5, 0); // Error Pending
}