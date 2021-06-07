#include "class03.h"
/*
標頭檔(declare the class)的副檔名則是 .h
程式檔(define the member functions)的副檔名為 .cpp 

為什麼要這麼區分呢？因為標頭檔代表的是程式與程式間的介面 (interface) ，
通常已經開發完成的程式只需要看介面就能獲悉如何使用，不需要在乎實際實作的細節，畢竟知道怎麼用就夠了，
*/

// 沒有參數的建構函數
Demo::Demo() {
    set_a(1);
    set_b(1);
}

// 一個參數的建構函數
Demo::Demo(int n1) {
    set_a(n1);
    set_b(n1);
}

// 兩個參數的建構函數
Demo::Demo(int n1, int n2) {
    set_a(n1);
    set_a(n1);
    set_b(n2);
}

int Demo::do_something() {
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
    Demo t1;
    Demo t2(11);
    Demo t3(11, 22);
    
    cout << endl;
    cout << t1.do_something() << endl;
    cout << t2.do_something() << endl;
    cout << t3.do_something() << endl;
    cout << endl;
    
    return 0;
}