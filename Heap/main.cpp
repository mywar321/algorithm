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
//堆排序
void heapify(int array[],int n,int i) { // n表示堆内数据数量
    int maxIndex = i;
    while (true) {
        if (2*i <= n && array[i] < array[2 * i])
            maxIndex = 2 * i;
        if (2*i+1 <= n && array[maxIndex] < array[2*i + 1])
            maxIndex = 2*i + 1;
        if (maxIndex == i)
            break;
        swap(array[i], array[maxIndex]);
        i = maxIndex;
    }
}
void build_heap(int array[], int n) {

    for (int i=n/2;i>0;--i) { //从倒数第一个非叶子节点开始自上而下堆化
        heapify(array, n, i);
    }
}
void heap_sort(int array[], int n) {
    build_heap(array, n-1);    //首先以原数组建堆
    for (int i=n-1;i > 1;i--) { //将堆顶元素取出，堆容量-1，依次堆化剩余数组元素
        swap(array[1],array[i]);
        heapify(array, i-1, 1);
    }
}

/*
** 堆的应用：1.优先级队列，2.求TOP K，3.求中位数
*/

//2.求一组数据中前K大的数


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

    int a[100];
    a[0] = 0;
    for(int i=1;i<100;i++)
        a[i] = rand()%1000;
    int n = sizeof(a)/sizeof(int);
    heap_sort(a, n);
    for(int i=0;i<n;i++)
        cout << a[i] << ",";


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
