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
        if (vi[j] <= pivot) { //将未处理分区[j，up]中小于等于pivot的值替换到已处理分区[low，i]中
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
/************************************************************/

void insert_sort(vector<int> &vi)
{
    // 插入排序，a 表示数组，n 表示数组大小
    for (int i = 1; i < vi.size(); ++i) {
        int value = vi[i];
        int j = i - 1;
        // 查找插入的位置
        for (; j >= 0; --j) {
            if (vi[j] > value)
                vi[j+1] = vi[j];  // 数据移动
            else
                break;
        }
        vi[j+1] = value; // 插入数据
    }


}
/*归并排序*/
void merge_sort(vector<int> &vi)
{

}



int main()
{
    vector<int> vi = {1,2,4,6,3,5};
    //bubble_sort(vi);
    q_sort(vi,0,vi.size()-1);
    //insert_sort(vi);
    for (index_t i=0;i<vi.size();i++) {
        cout << vi[i] << ",";
    }


    cout << "Hello World!" << endl;
    return 0;
}

