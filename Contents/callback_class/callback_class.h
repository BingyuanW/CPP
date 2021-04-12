//
// Created by bingyuan on 2021/4/12.
//

#ifndef __CALLBACK_CLASS__
#define __CALLBACK_CLASS__

class mycallback
{
public:
   explicit mycallback(int x0 = 0): x(x0) {}
   int mydouble()  const {return x * 2 ;}
   int myquadruple()  const {return x * 4 ;}
private:
    int x ;
};



#endif //CALLBACK_CLASS_CALLBACK_CLASS_H
