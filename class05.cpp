//多型實現計算器
#include<iostream>
#include <string>
using namespace std;
class Calculator{
public:
    int getResult(string oper){
        if (oper=="+") {
            return m_Num1+m_Num2;
        }
        else if (oper=="-"){
            return m_Num1-m_Num2;
        }
        else if (oper=="*"){
            return m_Num1*m_Num2;
        }
        else return 0;
    }
    int m_Num1;
    int m_Num2;
};

void test01(){
    Calculator c;
    c.m_Num1=10;
    c.m_Num2=10;
    cout<< c.m_Num1 << "+" << c.m_Num2 <<"=" << c.getResult("+") << endl;
    cout<< c.m_Num1 << "-" << c.m_Num2 <<"=" << c.getResult("-") << endl;
    cout<< c.m_Num1 << "*" << c.m_Num2 <<"=" << c.getResult("*") << endl;
}

//利用多型實現計算器
//實現計算器抽象類
class AbstractCalculator{
public:
    virtual int getResult(int num1, int num2){
        return 0;
    }
};
//加法計算器類
class AddCalculator:public AbstractCalculator{
public:
    int getResult(int num1, int num2){
        cout << "AddCalculator ";
        return num1 + num2;
    }
};
//減法計算器類
class SubCalculator:public AbstractCalculator{
public:
    int getResult(int num1, int num2){
        cout << "SubCalculator ";
        return num1 - num2;
    }
};
//乘法計算器類
class MulCalculator:public AbstractCalculator{
public:
    int getResult(int num1, int num2){
        cout << "MulCalculator ";
        return num1 * num2;
    }
};

//除法計算器類
class ChuCalculator:public AbstractCalculator{
public:
    int getResult(int num1, int num2){
        cout << "ChuCalculator ";
        return num1 / num2;
    }
};

void test02(){
    //多型的引用條件
    //父類指標或引用指向子類物件
    //加法運算
    AbstractCalculator* abc = new AddCalculator;
    cout << abc->getResult(100, 100) << endl;
    delete abc;//用完記得銷燬
    
    //減法運算
    abc = new SubCalculator;
    cout << abc->getResult(100, 100) << endl;
    delete abc;//用完記得銷燬
    
    //乘法法運算
    abc = new MulCalculator;
    cout << abc->getResult(100, 100) << endl;
    delete abc;//用完記得銷燬
    
    //整除運算
    abc = new ChuCalculator;
    cout << abc->getResult(100, 100) << endl;
    delete abc;//用完記得銷燬
}

int main(){
    //test01();
    test02();
    return 0;
}