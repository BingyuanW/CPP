
// Insertion Sort ，插入排序，正序（从小到大）

#include <iostream>
using namespace std;

int main()
{
    int a[11]  = {10,9,8,7,6,5,4,3,2,1,0};

    for(int i = 1; i< 11;i++)
    {
        int key = a[i] ;
        int j = i-1;

        while (a[j] > key && j >= 0 )
        {
            a[j+1] = a[j];
            j -= 1;
            a[j+1] =key ;
        }

    }

    for(int i : a)
    {
        cout << a[i] << " " ;

    }

    return 0 ;
}
