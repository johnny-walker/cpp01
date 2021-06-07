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

class AbstractDrinking
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomething() = 0;
    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }

    virtual ~AbstractDrinking()
    {
        cout << "delete AbstractDrinking" << endl;
    }
};

class Coffee : public AbstractDrinking
{
    virtual void Boil()
    {
        cout << "煮水" << endl;
    }
    virtual void Brew()
    {
        cout << "沖泡咖啡" << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入糖和牛奶" << endl;
    }

public:
    ~Coffee()
    {
        cout << "delete Coffee" << endl;
    }
};

class Tea : public AbstractDrinking
{
    virtual void Boil()
    {
        cout << "煮礦泉水" << endl;
    }
    virtual void Brew()
    {
        cout << "沖泡茶葉" << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void PutSomething()
    {
        cout << "加入檸檬" << endl;
    }

public:
    ~Tea()
    {
        cout << "delete Tea" << endl;
    }
};

void doWork(AbstractDrinking *abs)
{ //父類指標指向子類物件
    abs->makeDrink();
    cout << "______________" << endl;
}

void test01()
{
    AbstractDrinking *abd = new Coffee;
    doWork(abd);
    delete abd;

    abd = new Tea;
    doWork(abd);
    delete abd;
}

int main()
{
    test01();
    return 0;
}