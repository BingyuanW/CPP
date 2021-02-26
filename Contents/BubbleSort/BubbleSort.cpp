
// Bubble Sort , 冒泡排序， 正序（从小到大）

#include <iostream>
using namespace std;

int main()
{
    int a[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    for(int i = 0; i<11; i++)
    {
        /*
        int j = i + 1;
        int key;

        while(j <11)
        {
            if(a[i]>a[j])
            {
                key = a[i];
                a[i] = a[j];
                a[j] = key;
            }
            j += 1;
        }
         */

         for(int j=i+1, key; j<11; j++)
        {
            if(a[i]>a[j])
            {
                key = a[i];
                a[i] = a[j];
                a[j] = key;
            }
        }
    }

    for(int i:a)
    {
        cout << a[i] << " " ;

    }

    return 0;
}