#include <iostream>

class Base {
public:
    Base(){
        std::cout << "Base::" << __FUNCTION__ << std::endl;
    }
    virtual ~Base() {
        std::cout << "Base::" << __FUNCTION__ << std::endl;
    }

    void FunctionA(){
        std::cout << "Base::" << __FUNCTION__ << std::endl;
    }
    
    virtual void FunctionB(){
        std::cout << "Base::" << __FUNCTION__ << std::endl;
    }

    void FunctionC(){
        std::cout << "Base::" << __FUNCTION__ << std::endl;
    }
    
    virtual void FunctionD(){
        std::cout << "Base::" << __FUNCTION__ << std::endl;
    }

    void FunctionE(){
        std::cout << "Base::" << __FUNCTION__ << std::endl;
    }
};

class Derived : public Base {
public:
    Derived(){
        std::cout << "Derived::" << __FUNCTION__ << std::endl;
    }
    
    virtual ~Derived(){
        std::cout << "Derived::" << __FUNCTION__ << std::endl;
    }
    
    void FunctionA(){
        std::cout << "Derived::" << __FUNCTION__ << std::endl;
    }
    
    void FunctionB() override {
        std::cout << "Derived::" << __FUNCTION__ << std::endl;
    }
    
    void FunctionC(){
        std::cout << "Derived::" << __FUNCTION__ << std::endl;
    }
    
    virtual void FunctionD(){
        std::cout << "Derived::" << __FUNCTION__ << std::endl;
    }
    
    void FunctionE(){
        std::cout << "Derived::" << __FUNCTION__ << std::endl;
    }
};

int main() {
    Derived* dp = new Derived();
    Base* bp = dynamic_cast<Base*>(dp);
    dp->FunctionA();
    dp->FunctionB();
    dp->FunctionC();
    dp->FunctionD();
    dp->FunctionE();

    bp->FunctionA();
    bp->FunctionB();
    bp->FunctionC();
    bp->FunctionD();
    bp->FunctionE();
}