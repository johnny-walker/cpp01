//http://kaiching.org/pydoing/cpp-guide/unit-11-encapsulation.html
#include <iostream>
using namespace std;

/*
物件導向程式設計 (object-oriented programming) 有三大基本特性，分別是
(1) 封裝 (encapsulation)
(2) 繼承 (inheritance) 及
(3) 多型 (polymorphism)

(1)封裝的意思就是把資料 (data) 封在類別中，這還牽涉到程式設計中另一個重要的概念: 資訊隱藏 (information hiding)，
   主要就是不讓外界隨意存取類別的資料，也就是說，只讓類別的資料成員 (data member) 給同個類別的成員函數 (member function) 存取。

(2)繼承的目的是讓類別 (class) 具有像是親屬的垂直關係（父母子女），子類別 (subclass) 可以擁有父類別 (superclass) 的成員 (member) ，
   這就要用到 private 存取標籤 (access label) 了，就是把成員變數放在 private 之後，而其他可供外界存取的成員函數放在 public 之後

(3)而多型像是親屬的平行關係（兄弟姊妹）， 長得很像，但有不同的特性 (see class04/class05)

另外，多個子類別繼承自單一父類別之時，這些子類別就可以用父類別代替，父類別如同家族裡的「姓」，子類別則是「名」。
*/

class Demo {
// 宣告 public 的成員
public:
    void set_a(int n);
    void set_b(int n);
    int get_a();
    int get_b();
    int DoSomething();
    
// 宣告 private 的成員 
private:
    int a;
    int b;
};

int Demo::DoSomething() {
    // 改成呼叫 getter 成員函數
    return get_a() + get_b();
}

// setter 與 getter 成員函數
void Demo::set_a(int n) {
    a = n;
}

void Demo::set_b(int n) {
    b = n;
}

int Demo::get_a() {
    return a;
}

int Demo::get_b() {
    return b;
}

int main(void) {
    Demo t;
    // 由呼叫 setter 設定成員變數
    t.set_a(12);
    t.set_b(23);
    
    cout << endl << t.DoSomething() << endl << endl;
    
    return 0;
}