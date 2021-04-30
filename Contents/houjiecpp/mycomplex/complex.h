//
// Created by bingyuan on 2021/4/11.
//

#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__

class complex;
complex&
__doapl (complex* ths, const complex& r);
complex&
__doami (complex* ths, const complex& r);
complex&
__doaml (complex* ths, const complex& r);


class complex
{
public:
    complex (double r = 0, double i = 0): re (r), im (i) { }   //构造函数，创建对象时被自动调用的函数
    complex& operator += (const complex&);  //函数在此声明，未定义
    complex& operator -= (const complex&);
    complex& operator *= (const complex&);
    complex& operator /= (const complex&);
    double real () const { return re; }    //内联函数
    double imag () const { return im; }
private:
    double re, im;

    friend complex& __doapl (complex *, const complex&);  //返回引用
    friend complex& __doami (complex *, const complex&);
    friend complex& __doaml (complex *, const complex&);
};


inline complex&
__doapl (complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
complex::operator += (const complex& r)  //操作符重载，成员函数
{
    return __doapl ( this, r);
}

inline complex&
__doami (complex* ths, const complex& r)
{
    ths->re -= r.re;
    ths->im -= r.im;
    return *ths;
}

inline complex&
complex::operator -= (const complex& r)
{
    return __doami (this, r);
}

inline complex&
__doaml (complex* ths, const complex& r)
{
    double f = ths->re * r.re - ths->im * r.im;
    ths->im = ths->re * r.im + ths->im * r.re;
    ths->re = f;
    return *ths;
}

inline complex&
complex::operator *= (const complex& r)
{
    return __doaml (this, r);
}

inline double
imag (const complex& x)
{
    return x.imag ();
}

inline double
real (const complex& x)
{
    return x.real ();
}

inline complex // 返回的是local object, 不能 return by reference
operator + (const complex& x, const complex& y)
{
    return complex (real (x) + real (y), imag (x) + imag (y));
}

inline complex
operator + (const complex& x, double y)
{
    return complex (real (x) + y, imag (x));  //临时对象
}

inline complex
operator + (double x, const complex& y)
{
    return complex (x + real (y), imag (y));
}

inline complex
operator - (const complex& x, const complex& y)
{
    return complex (real (x) - real (y), imag (x) - imag (y));
}

inline complex
operator - (const complex& x, double y)
{
    return complex (real (x) - y, imag (x));
}

inline complex
operator - (double x, const complex& y)
{
    return complex (x - real (y), - imag (y));
}

inline complex
operator * (const complex& x, const complex& y)
{
    return complex (real (x) * real (y) - imag (x) * imag (y),
                    real (x) * imag (y) + imag (x) * real (y));
}

inline complex
operator * (const complex& x, double y)
{
    return complex (real (x) * y, imag (x) * y);
}

inline complex
operator * (double x, const complex& y)
{
    return complex (x * real (y), x * imag (y));
}

complex
operator / (const complex& x, double y)
{
    return complex (real (x) / y, imag (x) / y);
}

inline complex             //这里返回引用应该也是可以的
operator + (const complex& x)
{
    return x;
}

inline complex
operator - (const complex& x)
{
    return complex (-real (x), -imag (x));
}

inline bool
operator == (const complex& x, const complex& y)
{
    return real (x) == real (y) && imag (x) == imag (y);
}

inline bool
operator == (const complex& x, double y)
{
    return real (x) == y && imag (x) == 0;
}

inline bool
operator == (double x, const complex& y)
{
    return x == real (y) && imag (y) == 0;
}

inline bool
operator != (const complex& x, const complex& y)
{
    return real (x) != real (y) || imag (x) != imag (y);
}

inline bool
operator != (const complex& x, double y)
{
    return real (x) != y || imag (x) != 0;
}

inline bool
operator != (double x, const complex& y)
{
    return x != real (y) || imag (y) != 0;
}

#include <cmath>

inline complex
polar (double r, double t)
{
    return complex (r * cos (t), r * sin (t));
}

inline complex
conj (const complex& x)
{
    return complex (real (x), -imag (x));
}

inline double
norm (const complex& x)
{
    return real (x) * real (x) + imag (x) * imag (x);
}

#endif   //__MYCOMPLEX__




