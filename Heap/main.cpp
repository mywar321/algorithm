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
void heapify(vector<int> &vi,size_t n,size_t i) { // n表示堆内数据数量
    size_t maxIndex = i;
    while (true) {
        if (2*i <= n && vi[i] < vi[2 * i])
            maxIndex = 2 * i;
        if (2*i+1 <= n && vi[maxIndex] < vi[2*i + 1])
            maxIndex = 2*i + 1;
        if (maxIndex == i)
            break;
        swap(vi[i], vi[maxIndex]);
        i = maxIndex;
    }
}
//堆排序
void build_heap(vector<int> &vi) {
    size_t n = vi.size()-1;
    for (size_t i=n/2;i>0;--i) { //从倒数第一个非叶子节点开始自上而下堆化
        heapify(vi, n, i);
    }
}

void heap_sort(vector<int> &vi) {
    build_heap(vi);    //首先以原数组建堆
    for (size_t i=vi.size()-1;i > 1;i--) { //将堆顶元素取出，堆容量-1，依次堆化剩余数组元素
        swap(vi[1],vi[i]);
        heapify(vi, i-1, 1);
    }
}
int main()
{
#if 0
    Heap heap(10);
    vector<int> vi = {6,4,5};
    for(auto it : vi)
        heap.insert(it);
    heap.insert(7);
    heap.insert(9);
    heap.insert(3);
    heap.remove_top();
    cout << heap.heapTop() << endl;
#endif

    vector<int> vi_sort = {0,3,5,67,23,10,1,2,9};
    heap_sort(vi_sort);
    for(auto it : vi_sort)
        cout << it << ",";


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
