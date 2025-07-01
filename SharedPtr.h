#ifndef __SHARED_PTR_H__
#define __SHARED_PTR_H__
#include <iostream>
#include <memory>
using namespace std;

struct MyObj
{
    MyObj() { cout << "MyObj constructed\n"; }
    ~MyObj() { cout << "MyObj destructed\n"; }
};

// note: public inheritance
struct Container : enable_shared_from_this<Container> 
{
    shared_ptr<MyObj> memberObj;
 
    void CreateMember() { memberObj = make_shared<MyObj>(); }
    shared_ptr<MyObj> GetAsMyObj()
    {
        // Use an alias shared ptr for member
        return shared_ptr<MyObj>(shared_from_this(), memberObj.get());
    }
};
 
#define COUT(str) cout << '\n' << str << '\n'
#define DEMO(...) cout << #__VA_ARGS__ << " = " << __VA_ARGS__ << '\n'
 
void DemoSharedPtr();

#endif