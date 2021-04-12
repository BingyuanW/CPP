

#include <iostream>
#include "callback_class.h"
using namespace std ;

//中间函数
//接受一个生成偶数的函数作为参数
//返回一个奇数

//template <class mycallback>
int getOddNumber( mycallback *cal, int (mycallback::*getEvenNumber)() const){  //函数指针
    return 1 + (cal ->*getEvenNumber)() ;
}

int main(){

    int i ;

    mycallback c(1) ;   //x=1
    mycallback *cal = &c;  //创建指向class mycallback的指针

    int (mycallback::  *fpDouble)() const;   //声明为class mycallback 中的成员函数指针
    int (mycallback::*fpquadruple)() const;
    fpDouble = &mycallback::mydouble;
    fpquadruple =&mycallback::myquadruple;

    //当需要生成一个2k+1形式的奇数时
    i = getOddNumber( cal,fpDouble) ;
    cout <<  i << endl ;  //1 + 1*2 = 3

    //当需要一个4k+1形式的奇数时
    i = getOddNumber(cal, fpquadruple) ;
    cout << i << endl ;  //1 + 1*4 = 5

    //当需要一个8k+1形式的奇数时
   // i = getOddNumber(k, [] (int x) -> int {return x*8;}) ; //lambda expression
    //cout << i << endl ;  //1 + 1*8 = 9

    return 0 ;

}