//
// Created by bingyuan on 2021/2/26.
//
#include <iostream>
#include "even.h"
using namespace std ;

//中间函数
//接受一个生成偶数的函数作为参数
//返回一个奇数
int getOddNumber(int k, int (*getEvenNumber)(int )){  //函数指针
    return 1 + getEvenNumber(k) ;
}

int main(){
    int k =1 ;
    int i ;

    //当需要生成一个2k+1形式的奇数时
    i = getOddNumber(k, mydouble) ;
    cout <<  i << endl ;  //1 + 1*2 = 3

    //当需要一个4k+1形式的奇数时
    i = getOddNumber(k, myquadruple) ;
    cout << i << endl ;  //1 + 1*4 = 5

    //当需要一个4k+1形式的奇数时
    i = getOddNumber(k, [] (int x) -> int {return x*8;}) ; //lambda expression
    cout << i << endl ;  //1 + 1*8 = 9

    return 0 ;

}