#include <iostream>
using namespace std;

class Animal{
public:
	virtual void speak(){//虛擬函式
		cout<<"動物在說話"<<endl;
	}
};
class Cat:public Animal{
public:
	void speak(){
		cout<<"小貓在說話"<<endl;
	}
};

class Dog:public Animal{
public:
	void speak(){
		cout<<"小狗在說話"<<endl;
	}
};


//執行doSpeak函式，地址早繫結，編譯階段確定函式地址
//如果想讓貓說話，那麼這個函式地址就不能提前繫結，需要在執行階段進行繫結，地址晚繫結
void doSpeak(Animal &animal){//Animal &animal=cat 父類引用指向子類的物件，C++中允許父子之間的型別轉換，不需要做強制型別轉換，父類的引用/指標可以直接指向子類物件
	animal.speak();
}

int main(){
    Animal animal;
	doSpeak(animal);
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}