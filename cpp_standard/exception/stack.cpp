template <class T>
class Stack {
public:
    Stack();
    ~Stack();

private:
    T* v_;
    size_t vsize_;
    size_t vused_;
};