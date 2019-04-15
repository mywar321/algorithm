#include <iostream>
#include <vector>
using namespace std;
static const double EPSINON = 0.000001;
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
int main()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
    cout << binary_search(vi, 11) << endl;
    cout << binary_sqrt(0.01) << endl;
    cout << binary_sqrt(8) << endl;
    cout << binary_sqrt(1) << endl;
    cout << binary_sqrt(1000000) << endl;
    cout << "Hello World!" << endl;
    return 0;
}
