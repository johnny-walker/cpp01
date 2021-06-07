#include<iostream>
#include <string>
using namespace std;
class CPU{
public:
    virtual void caculate()=0;
    virtual ~CPU(){};
};

class VideoCard{
public:
    virtual void display()=0;
    virtual ~VideoCard(){};
};

class Memory{
public:
    virtual void storage()=0;
    virtual ~Memory(){}; 
};

class Computer{
public:
    Computer(CPU*cpu,VideoCard*vc,Memory*mem){
        m_cpu=cpu;
        m_vc=vc;
        m_mem=mem;
    }
    ~Computer(){
        if (m_cpu!=NULL) {
            delete m_cpu;
            m_cpu=NULL;
        }
        if (m_vc!=NULL) {
            delete m_vc;
            m_vc=NULL;
        }
        if (m_mem!=NULL) {
            delete m_mem;
            m_mem=NULL;
        }
    }
    //提供工作的函式
    void work(){
        m_cpu->caculate();
        m_vc->display();
        m_mem->storage();
    }
private:
    CPU*m_cpu;//cpu的零件指標
    VideoCard*m_vc;//顯示卡零件指標
    Memory*m_mem;//記憶體條零件指標
};

class IntelCPU:public CPU{
  public:
    virtual void caculate(){
        cout<<"Intel的CPU開始計算了！"<<endl;
    }
};

class IntelVideoCard:public VideoCard{
  public:
    virtual void display(){
        cout<<"Intel的顯示卡開始顯示了！"<<endl;
    }
};

class IntelMemory:public Memory{
  public:
    virtual void storage(){
        cout<<"Intel的記憶體條開始儲存了！"<<endl;
    }
};

class LenovoCPU:public CPU{
  public:
    virtual void caculate(){
        cout<<"Lenovo的CPU開始計算了！"<<endl;
    }
};

class LenovoVideoCard:public VideoCard{
  public:
    virtual void display(){
        cout<<"Lenovo的顯示卡開始顯示了！"<<endl;
    }
};

class LenovoMemory:public Memory{
  public:
    virtual void storage(){
        cout<<"Lenovo的記憶體條開始儲存了！"<<endl;
    }
};


void test01(){
    //第一臺電腦零件
    CPU*intelCpu=new IntelCPU;
    VideoCard*intelCard=new IntelVideoCard;
    Memory*intelMem=new IntelMemory;
    
    //建立第一臺電腦
    Computer*computer1=new Computer(intelCpu,intelCard,intelMem);
    computer1->work();
    delete computer1;
    
    cout<<"--------------------"<<endl;
    
    //建立第二臺電腦
    Computer*computer2=new Computer(new LenovoCPU,new LenovoVideoCard,new LenovoMemory);
    computer2->work();
    delete computer2;
    
    //建立第三臺電腦
    cout<<"--------------------"<<endl;
    Computer*computer3=new Computer(new LenovoCPU,new IntelVideoCard,new LenovoMemory);
    computer3->work();
    delete computer3;
}

int main(){
    test01();
    return 0;
}