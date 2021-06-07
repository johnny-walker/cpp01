#include<iostream>
#include <string>
using namespace std;
class Animal{
public:
    Animal(){
        cout<<"Animal建構函式呼叫"<<endl;
    }
    virtual ~Animal(){
        cout<<"Animal純解構函式呼叫"<<endl;
    }//解構

    virtual void speak()=0;//純虛擬函式
};

class Cat:public Animal{
public:
    Cat(string name){
        cout<<"Cat建構函式呼叫"<<endl;
        m_Name=new string(name);
    }
    ~Cat(){
        if (m_Name!=NULL) {
            cout<<"Cat解構函式呼叫"<<endl;
            delete m_Name;
            m_Name=NULL;
        }
    }
    virtual void speak(){
        cout<<*m_Name<<"小貓在說話"<<endl;
    }
    
private:
    string *m_Name;
};

void test01(){
    Animal* animal = new Cat("Tom");
    animal->speak();
    delete animal;
}

int main(){
    test01();
    return 0;
}
