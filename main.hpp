#ifndef _MAIN_HPP_
#define _MAIN_HPP_

#include <istream>
#include <ostream>
#include <iostream>
#include <stdio.h>

using namespace std;

#define APP_VERSION "1.11"

#define CLASS_MENBER (1)

class SelfIncSelfDec
{
    private:
    int a;
    int b;
    
    public:
    SelfIncSelfDec()
    {
        a = 0;
        b = 0;
    }
    SelfIncSelfDec(int i, int j)
    {
        a = i;
        b = j;
    }
    int GetA() {return a;}
    int GetB() {return b;}
    int SetA(int i) {a=i;return 0;}
    int SetB(int j) {b=j;return 0;}

    //+
    friend const SelfIncSelfDec operator+(const SelfIncSelfDec& opt1,const SelfIncSelfDec& opt2);
    friend const SelfIncSelfDec operator+(int i,const SelfIncSelfDec& opt);
    friend const SelfIncSelfDec operator+(const SelfIncSelfDec& opt,int i);

    //-
    friend const SelfIncSelfDec operator-(const SelfIncSelfDec& opt1,const SelfIncSelfDec& opt2);
    friend const SelfIncSelfDec operator-(int i,const SelfIncSelfDec& opt);
    friend const SelfIncSelfDec operator-(const SelfIncSelfDec& opt,int i);

    //*
    friend const SelfIncSelfDec operator*(const SelfIncSelfDec& opt1,const SelfIncSelfDec& opt2);
    friend const SelfIncSelfDec operator*(int i,const SelfIncSelfDec& opt);
    friend const SelfIncSelfDec operator*(const SelfIncSelfDec& opt,int i);

    ///
    friend const SelfIncSelfDec operator/(const SelfIncSelfDec& opt1,const SelfIncSelfDec& opt2);
    friend const SelfIncSelfDec operator/(int i,const SelfIncSelfDec& opt);
    friend const SelfIncSelfDec operator/(const SelfIncSelfDec& opt,int i);

#if (defined(CLASS_MENBER) && CLASS_MENBER)
    // 重载前缀自加运算符
    SelfIncSelfDec& operator++()
    {
        ++a;
        ++b;
        return (*this);
    }

    // 重载前缀自减运算符
    SelfIncSelfDec& operator--()
    {
        --a;
        --b;
        return (*this);
    }

    // 重载后缀自加运算符
    SelfIncSelfDec operator++(int i)
    {
        SelfIncSelfDec tmp(*this);
        a++;
        b++;
        return tmp;
    }

    // 重载后缀自减运算符
    SelfIncSelfDec operator--(int i)
    {
        SelfIncSelfDec tmp(*this);
        a--;
        b--;
        return tmp;
    }
#else
    friend SelfIncSelfDec& operator++(SelfIncSelfDec& opt);
    friend SelfIncSelfDec& operator--(SelfIncSelfDec& opt);
    friend SelfIncSelfDec  operator++(SelfIncSelfDec& opt,int i);
    friend SelfIncSelfDec  operator--(SelfIncSelfDec& opt,int i);
#endif
    // 重载赋值运算符
    SelfIncSelfDec& operator=(const SelfIncSelfDec& opt)
    {
        if (this == &opt) return (*this);
        this->a=opt.a;
        this->b=opt.b;

        return (*this);
    }
    // 重载赋值运算符
    SelfIncSelfDec& operator=(const int& opt)
    {
        this->a=opt;
        this->b=opt;

        return (*this);
    }

    // 输入输出流运算符重载函数的友元声明
    friend ostream& operator<<(ostream& out,SelfIncSelfDec& opt);
    friend istream& operator>>(istream& in,SelfIncSelfDec& opt);
};// end of class


class Subscript
{
    private:
    char *p;
    int index;
    public:
    Subscript(){p=NULL;index=0;}
    Subscript(const char* const s)
    {
        int len = strlen(s);
        if (len>0)
        {
            p=new char[len];
            strcpy(p,s);
            index = len;
        }
        else
        {
            p=NULL;
            index=0;
        }
    }
    char & operator[](const int i)
    {
        int len = strlen(p);
        if(i<len)
        {
            return p[i];
        }
        else{
            cout<<"error,index overflow"<<endl;
            return p[0];
        }
    }
};// end of class

class Dereference
{
    private:
    int a;
    public:
    Dereference()
    {a=0;}
    Dereference(int n)
    {a=n;}

    int GetA()
    {return a;}

    int& operator*()
    {
        return a;
    }
}; // end of Dereference class

class ArrowA;
class ArrowC
{
    private:
    int a;
    ArrowA* ma;
    public:
    ArrowC()
    {a=0;}
    ArrowC(int n)
    {a=n;}

    int GetA()
    {return a;}

    void f(){cout<<"ArrowC f()"<<endl;}

    int& operator*()
    {
        return a;
    }

    ArrowA* operator->()
    {
        return ma;
    }
}; // end of ArrowC class

class ArrowB
{
    private:
    int a;
    ArrowC mc;
    public:
    ArrowB()
    {a=0;}
    ArrowB(int n)
    {a=n;}

    int GetA()
    {return a;}

    void f(){cout<<"ArrowB f()"<<endl;}

    int& operator*()
    {
        return a;
    }
    
    ArrowC* operator->()
    {
        return &mc;
    }
}; // end of ArrowB class

class ArrowA
{
    private:
    int a;
    ArrowB mb;
    public:
    ArrowA()
    {a=0;}
    ArrowA(int n)
    {a=n;}

    int GetA()
    {return a;}

    void f(){cout<<"ArrowA f()"<<endl;}

    int& operator*()
    {
        return a;
    }

    ArrowB& operator->()
    {
        return mb;
    }
}; // end of ArrowA class

class FunctionCallOperator
{
    public:
    FunctionCallOperator(){}
    
    int operator()(int a,int b)
    {
        return a+b;
    }
}; // end of class

class ConvertFunA
{
    public:
    int i;
    ConvertFunA(){i=0;}
    ConvertFunA(int n){i=n;}

    operator int()
    {
        return i;
    }

    // 输入输出流运算符重载函数的友元声明
    friend ostream& operator<<(ostream& out,ConvertFunA& opt);
    friend istream& operator>>(istream& in,ConvertFunA& opt);
}; // end of class ConvertFunA

class ConvertFunB
{
    public:
    int i;
    ConvertFunB(){i=0;}
    ConvertFunB(int n){i=n;}

    operator int()// Convert to int
    {
        return i;
    }

    operator ConvertFunA()// Convert to class ConvertFunA
    {
        return i;
    }

    // 输入输出流运算符重载函数的友元声明
    friend ostream& operator<<(ostream& out,ConvertFunB& opt);
    friend istream& operator>>(istream& in,ConvertFunB& opt);
}; // end of class ConvertFunB

extern char newdeletebuff[128];
class NewDeleteA
{
    public:
    int i;
    NewDeleteA(){i=0;cout<<"NewDeleteA1"<<endl;}
    NewDeleteA(int n){i=n;cout<<"NewDeleteA2"<<endl;}

    ~NewDeleteA()
    {
        cout<<"~NewDeleteA:"<<endl;
    }

    void* operator new(size_t size)
    {
        cout<<"size:"<<size<<endl;
        return newdeletebuff;
    }

    void* operator new(size_t size,int i)
    {
        cout<<"size:"<<size<<",i:"<<i<<endl;
        return newdeletebuff;
    }

    void operator delete(void *)
    {
        cout<<"operator delete"<<endl;
    }
    // 输入输出流运算符重载函数的友元声明
    //friend ostream& operator<<(ostream& out,ConvertFunA& opt);
    //friend istream& operator>>(istream& in,ConvertFunA& opt);
}; // end of class NewDeleteA


class NewDeleteB
{
    public:
    int i;
    NewDeleteB(){i=0;cout<<"NewDeleteB1"<<endl;}
    NewDeleteB(int n){i=n;cout<<"NewDeleteB2"<<endl;}

    ~NewDeleteB()
    {
        cout<<"~NewDeleteB:"<<endl;
    }
/*
    void* operator new(size_t size)
    {
        cout<<"size:"<<size<<endl;
        return newdeletebuff;
    }
*/
    void* operator new(size_t size,int i)
    {
        cout<<"size:"<<size<<",i:"<<i<<endl;
        return newdeletebuff;
    }

    void operator delete(void *)
    {
        cout<<"operator delete"<<endl;
    }
    // 输入输出流运算符重载函数的友元声明
    //friend ostream& operator<<(ostream& out,ConvertFunA& opt);
    //friend istream& operator>>(istream& in,ConvertFunA& opt);
}; // end of class NewDeleteB

class NewDeleteC
{
    public:
    int i;
    NewDeleteC(){i=0;cout<<"NewDeleteC1"<<endl;}
    NewDeleteC(int n){i=n;cout<<"NewDeleteC2"<<endl;}

    ~NewDeleteC()
    {
        cout<<"~NewDeleteC"<<endl;
    }

    void* operator new(size_t size)
    {
        cout<<"NewDeleteC size:"<<size<<endl;
        return newdeletebuff;
    }

    void* operator new(size_t size,int i)
    {
        cout<<"NewDeleteC size:"<<size<<",i:"<<i<<endl;
        return newdeletebuff;
    }

    void operator delete(void *)
    {
        cout<<"NewDeleteC operator delete"<<endl;
    }

    void* operator new[](size_t size)
    {
        cout<<"NewDeleteC operator new[] size:"<<size<<endl;
        //if (size>sizeof(newdeletebuff)) return nullptr;
        return newdeletebuff;
    }

    void operator delete[](void*p)
    {
        cout<<"NewDeleteC operator delete[]"<<endl;
    }
    // 输入输出流运算符重载函数的友元声明
    //friend ostream& operator<<(ostream& out,ConvertFunA& opt);
    //friend istream& operator>>(istream& in,ConvertFunA& opt);
}; // end of class NewDeleteC

#endif // _MAIN_HPP_
