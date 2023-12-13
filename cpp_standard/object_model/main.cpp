// #include <iostream>

class Base {
public:
    Base(){}
    ~Base(){}

    virtual void foo(int data){
        a = data;
    }

protected:
    int a;
};

class Derived : public Base {
public:
    Derived(int data) : b(data){}
    ~Derived(){}

    void foo(int data) override {
        a = 0;
        b = data;
    }

private:
    int b;
};

int main(int argc, char** argv) {
    int data = 123;
    Derived obj = Derived(data);
    // std::cout << sizeof(obj) << std::endl;
    (&obj)->foo(567);
    return 0;
}

// rax：通常用于存储函数调用返回值
// rsp：栈顶指针，指向栈的顶部
// rdi：第一个入参
// rsi：第二个入参
// rdx：第三个入参
// rcx：第四个入参
// r8：第五个入参
// r9：第六个入参
// rbx：数据存储，遵循Callee Save原则
// rbp：数据存储，遵循Callee Save原则
// r12~
// r15：数据存储，遵循Callee Save原则
// r10~
// r11：数据存储，遵循Calle
//  Save原则