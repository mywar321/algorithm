/*
**各种排序算法的实现
**
**
*/
#include <iostream>
#include <vector>

using namespace std;

using index_t = std::vector<int>::size_type;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
/*冒泡排序*/
void bubble_sort(vector<int> &vi)
{
    for (index_t i=0;i<vi.size();i++) {
        for (index_t j=0;j<vi.size()-i-1;j++) {
            if (vi[j] > vi[j+1]) {
                swap(vi[j], vi[j+1]);
            }
        }

    }
}
/*快速排序*/
//分治
int partition(vector<int> &vi, int low, int up)
{
    int pivot = vi[up]; //确立标准值
    int i = low-1;
    for (int j=low;j<up;j++) {
        if (vi[j] <= pivot) {
            i++;
            swap(vi[i],vi[j]);
        }
    }
    swap(vi[i+1],vi[up]);
    return i+1;   //返回pivot的索引
}

void q_sort(vector<int> &vi, int low, int up)
{
    if (low < up) {
        int mid = partition(vi, low, up);
        q_sort(vi, low, mid-1);
        q_sort(vi, mid+1, up);
    }
}





int main()
{
    vector<int> vi = {6,5,4,3,2,1};
    //bubble_sort(vi);
    q_sort(vi,0,vi.size()-1);
    for (index_t i=0;i<vi.size();i++) {
        cout << vi[i] << ",";
    }


    cout << "Hello World!" << endl;
    return 0;
}

