/*
**各种排序算法的实现
**
**
*/
#include <iostream>

using namespace std;

/*冒泡排序*/
void bubble_sort(int array[], int size)
{
    for (int i=0;i<size;i++) {
        for (int j=0;j<size-i-1;j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }

    }
}





int main()
{
    int arr[] = {5,4,3,2,1,0};
    int size = sizeof (arr) / sizeof (int);
    bubble_sort(arr, size);
    for (int i=0;i<size;i++) {
        cout << arr[i] << ",";
    }
    cout << "Hello World!" << endl;
    return 0;
}

