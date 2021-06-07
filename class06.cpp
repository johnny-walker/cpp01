//純虛擬函式和抽象類
/*
在多型中，通常父類中虛擬函式的實現是毫無意義的，主要都是呼叫子類重寫的內容，因此可以將虛擬函式改寫為純虛擬函式
純虛擬函式的語法：virtual 返回值型別 函式名 (引數列表)=0
當類中有了純虛擬函式，這個類也稱為抽象類
抽象類的特點：

無法例項化物件
子類必須重寫抽象類中的純虛擬函式，否則也屬於抽象類
*/

#include <iostream>
#include <string>
using namespace std;
class Base
{
public:
    virtual void func() = 0;
};

class Son : public Base
{
public:
    virtual void func()
    {
        cout << "func函式呼叫" << endl;
    }
};

void test01()
{
    //Son s;
    Base *base = new Son;
    base->func();
}

int main()
{
    test01();
    return 0;
}