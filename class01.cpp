//http://kaiching.org/pydoing/cpp-guide/unit-10-class.html
#include <iostream>
using namespace std;

/*
類別 (class) 用來設計自己需要的物件 (object) ，這是說，類別是物件的藍圖。 
C++ 中設計類別使用關鍵字 (keyword) class ，後面接大括弧宣告 (declare) 類別的成員 (member)

成員可以是資料 (data) 、函數 (function) 與建構函數 (constructor) ，
(1)資料其實就是專屬於類別的變數 (variable) ，我們在這裡沿用 C++ 的習慣稱之為資料成員 (data member) ，
(2)同樣的，函數也是專屬於類別的，稱之為成員函數 (member function) ，
(3)至於建構函數屬於特別的成員函數，用來建立該類別物件的專屬函數。 (later will introduce it)

另外，類別定義必須利用存取標籤 (access label) public 或 private 將成員的權限歸類，
屬於 public 的成員可以在程式中的任何地方存取， private 則只能在同個類別裡。    
*/

// 宣告類別
class Demo {
// 宣告 public 成員
public:
    int a;
    int b;
    int DoSomething();
};

/*
為什麼要對存取權限歸類呢？
這是因為物件導向程式設計允許後續定義的類別， 繼承(inherit)之前定義類別的特性
這樣的機制使 public 成員會被繼承，而 private 不能被繼承。
還有另一個存取標籤 protected ，能被繼承, 但只有原類別或繼承者可存取。
*/


// 實作 Demo 的 DoSomething() 成員函數
int Demo::DoSomething() {
    return a + b;
}

// 程式執行的 main()
int main(void) {
    // 宣告並建立 Demo 型態的物件 t
    Demo t;
    t.a = 11; // 直接設定成員變數值
    t.b = 22;
    cout << endl;
    // 呼叫並印出 DoSomething() 的回傳值
    cout << t.DoSomething() << endl;
    cout << endl;
    return 0;
}