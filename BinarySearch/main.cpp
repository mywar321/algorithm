#include <iostream>
#include <vector>
using namespace std;
static const double EPSINON = 0.000001;
#define TEST_(a,b) ((a) == (b) ? "pass" : "failed")

/*二分查找*/
int binary_search(const vector<int> &vi, int value)
{
    int mid = 0;
    int low = 0;
    int high = vi.size()-1;
    while (low <= high) {
        mid = low + (high-low)/2;
        if (value == vi.at(mid)) {
            return mid;
        }
        else if (value < vi.at(mid)) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
}

//二分法求平方根
double binary_sqrt(double num)
{
    if (num < 0)
        return -1;
    double low = 1, high= num;
    if (num < 1 ) {
        low = num;
        high = 1;
    }
    double mid = low + (high - low)/2.0;
    while (fabs(high - low) >= EPSINON) {
       double sqr_mid = mid * mid;
       if (fabs(sqr_mid - num) <= EPSINON)
           return mid;
       else if (sqr_mid < num) {
           low = mid;
       }
       else {
           high = mid;
       }
       mid = low + (high - low)/2.0;
    }
    return mid;
}
/***1.在一个顺序（升序）表(允许重复数字)中求第一个等于指定值的数*/
int bsearch_equal_first(const vector<int> &vi, int value)
{
    int low = 0, high=vi.size()-1;
    int mid;
    while (low <= high) {//将等于value的值看作大于value的，二分得出的结果必然是最后一个小于value的值，
                         //low+1就是第一个大于等于value的值
        mid = low + (high-low)/2;
        if (vi[mid] < value) {
            low = mid+1;
        }
        else if(vi[mid] >= value) {
            high = mid-1;
        }
    }
    if (low < vi.size() && vi[low] == value)  //注意边界处理，如果数组只有一个元素，且指定元素不存在，则low会超出界线。
        return low;
    return -1;
}

/***2.在一个顺序（升序）表(允许重复数字)中求第一个大于等于指定值的数*/
int bsearch_not_less_than_first(const vector<int> &vi, int value)
{
    int low = 0, high=vi.size()-1;
    int mid;
    while (low <= high) {
        mid = low + (high-low)/2;
        if (vi[mid] < value) {
            low = mid+1;
        }
        else if(vi[mid] >= value) {
            high = mid-1;
        }
    }
    if (low < vi.size() && vi[low] >= value)
        return low;
    return -1;
}

/***3.在一个顺序（升序）表(允许重复数字)中求倒数第一个等于指定值的数*/
int bsearch_equal_first_from_end(const vector<int> &vi, int value)
{
    int low = 0, high=vi.size()-1;
    int mid;
    while (low <= high) {
        mid = low + (high-low)/2;
        if (vi[mid] <= value) {
            low = mid+1;
        }
        else if(vi[mid] > value) {
            high = mid-1;
        }
    }
    if (high > 0 && vi[high] == value)
        return high;
    return -1;
}

/***4.在一个顺序（升序）表(允许重复数字)中求倒数第一个小于等于指定值的数*/
int bsearch_no_greater_than_first_from_end(const vector<int> &vi, int value)
{
    int low = 0, high=vi.size()-1;
    int mid;
    while (low <= high) {
        mid = low + (high-low)/2;
        if (vi[mid] <= value) {
            low = mid+1;
        }
        else if(vi[mid] > value) {
            high = mid-1;
        }
    }
    if (high > 0 && vi[high] <= value)
        return high;
    return -1;
}

//TODO: 循环数组的查询

int main()
{
#if 0
    vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
    cout << binary_search(vi, 11) << endl;
    cout << binary_sqrt(0.01) << endl;
    cout << binary_sqrt(8) << endl;
    cout << binary_sqrt(1) << endl;
    cout << binary_sqrt(1000000) << endl;
#endif

    vector<int> vi_2 = {1,1,2,4,4,4,4,8,9,10};
#if 0
    cout << bsearch_equal_first(vi_2, 4) <<endl;
    cout << bsearch_equal_first(vi_2, 2) <<endl;
    cout << bsearch_equal_first(vi_2, 9) <<endl;
#elif 0
    cout << TEST_(bsearch_not_less_than_first(vi_2, 5), 7) <<endl;
    cout << TEST_(bsearch_not_less_than_first(vi_2, 3), 3) <<endl;
    cout << TEST_(bsearch_not_less_than_first(vi_2, 1), 0) <<endl;
    cout << TEST_(bsearch_not_less_than_first(vi_2, 10), 9) <<endl;
    cout << TEST_(bsearch_not_less_than_first(vi_2, 11), -1) <<endl;
#elif 0
    cout << TEST_(bsearch_equal_first_from_end(vi_2, 5), -1) <<endl;
    cout << TEST_(bsearch_equal_first_from_end(vi_2, 4), 6) <<endl;
    cout << TEST_(bsearch_equal_first_from_end(vi_2, 2), 2) <<endl;
    cout << TEST_(bsearch_equal_first_from_end(vi_2, 1), 1) <<endl;
    cout << TEST_(bsearch_equal_first_from_end(vi_2, 10), 9) <<endl;
#elif 1
    cout << TEST_(bsearch_no_greater_than_first_from_end(vi_2, 0), -1) <<endl;
    cout << TEST_(bsearch_no_greater_than_first_from_end(vi_2, 5), 6) <<endl;
    cout << TEST_(bsearch_no_greater_than_first_from_end(vi_2, 3), 2) <<endl;
    cout << TEST_(bsearch_no_greater_than_first_from_end(vi_2, 1), 1) <<endl;
    cout << TEST_(bsearch_no_greater_than_first_from_end(vi_2, 12), 9) <<endl;
#endif

    return 0;
}
