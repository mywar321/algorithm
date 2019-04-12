#include <iostream>

using namespace std;

/*动态数组实现顺序栈*/

template<class T>
class Stack{

public:
    T pop();
    void push(T elem);

    Stack(int n);
    ~Stack();
private:
    T *data = nullptr;
    int size = 0;
    int top = -1;
};



int main()
{
    Stack<int> stack(5);
    for (int i=0;i <20; i++) {
        stack.push(i);
    }
    for (int i=0;i <20; i++) {
        cout <<stack.pop()<<",";
    }
    cout << "Hello World!" << endl;
    return 0;
}







template<class T>
T Stack<T>::pop()
{
    if(top != -1)
        return data[top--];
    else
        throw out_of_range("empty stack can't pop");

}

template<class T>
void Stack<T>::push(T elem)
{
    top++;
    if (top >= size) {
        cout << "alloc new memory" <<endl;
        T* new_data = new T[size * 2];
        if(new_data == nullptr)
            throw new std::exception("alloc error");
        for (int i=0;i < size;i++) {
            new_data[i] = data[i];
        }
        new_data[top] = elem;
        delete[] data;
        data = new_data;
        size *= 2;
    }
    else {
        data[top] = elem;
    }
}

template<class T>
Stack<T>::Stack(int n):
    size(n)
{
    data = new T[size];
}

template<class T>
Stack<T>::~Stack()
{
    size = 0;
    delete []data;
    data = nullptr;
}


