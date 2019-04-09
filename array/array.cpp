#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

class DynamicArray {
public:
    DynamicArray() {
       m_data  = new int[m_length];
    }
    ~DynamicArray() {
        delete []  m_data;
        m_data = nullptr;
    }

    int addData(int newNum);

    void output();

private:
    int m_length = 5;
    int *m_data;
    int m_size = 0;

};

int DynamicArray::addData(int newNum)
{
    if (m_size < m_length) { //如果存储数组内还有空间
        m_data[m_size] = newNum;
        m_size++;
    }
    else {
        int *new_data = new int[m_length*2];
        assert(new_data != nullptr);   //说明内存不足

        memcpy(new_data, m_data, sizeof(int) * static_cast<unsigned int>(m_length));

        new_data[m_size] = newNum;
        m_size++;
        delete [] m_data;
        m_data = new_data;

        m_length *= 2;  //扩容一倍
    }


    return 0;
}

void DynamicArray::output()
{
    for (int i=0; i< m_size;i++)
        cout<< m_data[i] <<",";
}

int main()
{
    DynamicArray array;
    for (int i = 0; i < 50; ++i) {
        array.addData(i);
    }
    array.output();
    return 0;
}


