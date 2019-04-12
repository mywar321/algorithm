#include <iostream>

using namespace std;

/*基于数组的循环队列*/
template<class T>
class Queue{
public:
    Queue(int n);
    ~Queue();

    T dequeue();
    void enqueue(T data);

    bool isEmpty();
    bool isFull();

private:
    T *array = nullptr;
    int head = 0;
    int tail = 0;
    int size = 0;
};

int main()
{
    Queue<int> queue(6);


    for (int j=0;j<100;j++) {
        for (int i=0;i <5;i++) {
            queue.enqueue(i);
        }
        for (int i=0;i <5;i++) {
            cout << queue.dequeue() << ",";
        }
    }




    cout << "Hello World!" << endl;
    return 0;
}

template<class T>
Queue<T>::Queue(int n):
    size(n)
{
    if(n<=0)
        throw new exception("parameter error");
    array = new T[size];
}

template<class T>
Queue<T>::~Queue()
{
    delete array;
    array = nullptr;
}

template<class T>
T Queue<T>::dequeue()
{
    if (this->isEmpty()) {
        throw out_of_range("can not dequeue an empty queue");
    }
    else {
        int temp = head;
        head = (head+1)%size;
        return array[temp];
    }

}

template<class T>
void Queue<T>::enqueue(T data)
{
    if (this->isFull())
        throw out_of_range("can not enqueue an full queue");
    else {
        int temp = tail;
        tail = (tail+1)%size;
        array[temp] = data;
    }
}

template<class T>
bool Queue<T>::isEmpty()
{
    return head == tail;
}

template<class T>
bool Queue<T>::isFull()
{
    return (tail+1)%size == head;
}
