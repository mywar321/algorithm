/*
**堆和堆排序,以及堆的应用
**
*/
#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
//最大堆
class Heap {
public:
    Heap() =default;
    Heap(size_t n);
    ~Heap();

    bool insert(int value);
    void remove_top();
    int heapTop();
private:
    int *arr = nullptr;
    size_t size = 0;
    size_t count = 0;
};

int main()
{
    Heap heap(10);
    vector<int> vi = {6,4,5};
    for(auto it : vi)
        heap.insert(it);
    heap.insert(7);
    heap.insert(9);
    heap.insert(3);
    heap.remove_top();
    cout << heap.heapTop() << endl;
    cout << "Hello World!" << endl;
    return 0;
}

Heap::Heap(size_t n):
    size(n)
{
    arr = new int[size];
}

Heap::~Heap()
{
    delete[] arr;
    arr = nullptr;
}

bool Heap::insert(int value)
{
    ++count;
    if (count >= size)
        return false;

    size_t index = count;
    arr[index] = value;

    while (index > 1 && arr[index/2] < arr[index]) {
        swap(arr[index/2], arr[index]);
        index /= 2;
    }
    return true;
}

void Heap::remove_top()
{
    if (count <1)
        return;
    swap(arr[1], arr[count]); //交换最后一个节点和堆顶节点
    count--;

    size_t index = 1;
    size_t maxIndex = index;
    while (true) {  //将当前节点和它的最小子节点交换 (自上而下调整)
       if (index*2 <= count && arr[index] < arr[2*index])
           maxIndex = 2 * index;
       if (index*2+1 <= count && arr[maxIndex] < arr[2*index+1])  //这两个if是求三个节点中最大节点索引
           maxIndex = 2*index + 1;
       if (maxIndex == index)
           break;
       swap(arr[index], arr[maxIndex]);
       index = maxIndex;
    }
}

int Heap::heapTop()
{
    if (count > 0)
        return arr[1];

    throw out_of_range("empty heap");
}
