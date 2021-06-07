//http://kaiching.org/pydoing/cpp-guide/unit-12-constructor.html
#include <iostream>
using namespace std;

/*
函數 (function) 可以有多個參數 (parameter) 版本，
建構函數 (constructor) 亦同，具有多個參數版本的函數被稱為多載函數 (overloaded function)

為什麼會需要多載函數呢？這是因為多載函數可以處理不同型態的參數，例如我們需要一個將數字相加的函數
由於 C++ 是強型態 (strong typing) 的程式語言，浮點數的 double 與整數 int 是不同的資料型態 (data type) 
int a = add(12, 32);
double b = add(2.53, 32);


計算兩種資料型態前要先做型態轉換，不然就有可能會出現無法預期的結果
因此我們打算設置三種參數版本，分別是沒有參數、一個參數及兩個參數
Demo();
Demo(int);
Demo(int, int);

沒有參數的建構函數直接呼叫修改函數將 a 與 b 都設定為整數 1 ，一個參數的建構函數將 a 與 b 都設定為參數值，至於兩個參數的建構函數， a 設定為第一個參數， b 設定為第二個參數，實作如下
*/

class Demo {
// 宣告 public 的成員
public:
    Demo();
    Demo(int n1);
    Demo(int n1, int n2);
    
    ~Demo() {
        cout << "Bye Bye~" << endl;
    };

    void set_a(int n);
    void set_b(int n);
    int get_a();
    int get_b();
    int do_something();
    
// 宣告 private 的成員
private:
    int a;
    int b;
};