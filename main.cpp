#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.hpp"
using namespace std;

char newdeletebuff[128] = {0};

void FuncA(ConvertFunA opt)
{
    cout<<opt<<endl;
}
/*
void FuncA(ConvertFunB opt)
{
    cout<<opt<<endl;
}
*/
void FuncB(ConvertFunB opt)
{
    cout<<opt<<endl;
}
/*
void FuncB(ConvertFunA opt)
{
    cout<<opt<<endl;
}
*/
int main(void)
{
    printf("app version:%s\n",APP_VERSION);
    #if 0
    SelfIncSelfDec a;
    printf("a=%d,%d\n",a.GetA(),a.GetB());
    //++a;
    printf("a=%d,%d\n",(++a).GetA(),(++a).GetB());
    printf("a=%d,%d\n",a.GetA(),a.GetB());
    printf("\n");

    SelfIncSelfDec b(52,68);
    printf("b=%d,%d\n",b.GetA(),b.GetB());
    printf("b=%d,%d\n",(b--).GetA(),(b--).GetB());
    //b--;
    printf("b=%d,%d\n",b.GetA(),b.GetB());

    //a=b;
    //printf("a=%d,b=%d\n",a.GetA(),a.GetB());
    
    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;
    SelfIncSelfDec c;
    cin>>c;
    printf("c=%d,%d\n",c.GetA(),c.GetB());

    //(a + b) = c;//错误形式,a+b的结果是右值
    b = a + b + c;
    cout<<"b = a + b + c:"<<b<<endl;

    b=b+2;
    cout<<"b=b+2:"<<b<<endl;
    b=2+b;
    cout<<"b=2+b:"<<b<<endl;

    b=b*2;
    cout<<"b=b*2:"<<b<<endl;
    b=2*b;
    cout<<"b=2*b:"<<b<<endl;

    b=b/2;
    cout<<"b=b/2:"<<b<<endl;
    b=2256/b;
    cout<<"b=2256/b:"<<b<<endl;
    b/0;
    SelfIncSelfDec d;
    d=5;
    cout<<"d:"<<d<<endl;
    #endif
#if 0
    Subscript subscript("abcdefghijklmnopqrstuvwxyz");
    cout<<"please enter the index:"<<endl;
    unsigned int idx=0;
    cin>>idx;
    cout<<subscript[idx]<<endl;
    subscript[idx] = '8';
    cout<<subscript[idx]<<endl;
#endif

#if 0
    Dereference dereference;
    cout<<dereference.GetA()<<endl;
    *dereference = 5;
    cout<<dereference.GetA()<<endl;
#endif
#if 0
    ArrowA A;
    ArrowB B;
    ArrowC C;
    A->f();//调用重载的'->'
    ArrowA* pA = &A;
    pA->f();//调用内置的'->'
    B->f();
    C->f();
#endif
#if 0
    FunctionCallOperator sum;
    int a=0;
    int b=0;
    cout<<"please enter two namber:"<<endl;
    cin>>a;
    cin>>b;
    int result = sum(a,b);
    cout<<result<<endl;
#endif
#if 0
    ConvertFunA convertA;
    cout<<"please enter one namber for optA:"<<endl;
    cin>>convertA;
    cout<<convertA<<endl;
    if (convertA < 10)          cout<<"less than 10"<<endl;
    else if (convertA == 10)    cout<<"equ 10"<<endl;
    else if (convertA > 10)     cout<<"more than 10"<<endl;

    cout<<"please enter one namber for optB:"<<endl;
    ConvertFunB convertB;
    cin>>convertB;
    cout<<convertB<<endl;

    if (convertA < convertB)        cout<<"optA less than optB"<<endl;
    else if (convertA == convertB)  cout<<"optA equ to optB"<<endl;
    else if (convertA > convertB)   cout<<"optA more than optB"<<endl;

    FuncA(convertA);
    FuncA(convertB);//convertB转换为ConvertFunA类型

    //FuncB(convertA);
    FuncB(convertB);
#endif
#if 1
    NewDeleteA* pNewDeleteA = new NewDeleteA();
    NewDeleteA* pNewDeleteA2 = new NewDeleteA(1);
    delete pNewDeleteA;
    //delete pNewDeleteA2;
    NewDeleteA::operator delete(pNewDeleteA2);//只释放内存，不调用类的析构函数

    NewDeleteA* pNewDeleteA3 = (NewDeleteA*)NewDeleteA::operator new(sizeof(NewDeleteA),5);//显式调用(类内重载得)new需要指定参数以及返回值得强制类型转转
    delete pNewDeleteA3;

    NewDeleteB* pNewDeleteB = ::new NewDeleteB();//指定调用全局的new
    delete pNewDeleteB;

    NewDeleteC* pNewDeleteC = new NewDeleteC[5];
    if (pNewDeleteC != nullptr) delete [] pNewDeleteC;

    NewDeleteC* pNewDeleteC2 = new NewDeleteC[2];
    delete [] pNewDeleteC2;

#endif
    return 0;
}

//重载加运算符,形式：SelfIncSelfDec+SelfIncSelfDec
const SelfIncSelfDec operator+(const SelfIncSelfDec& opt1,const SelfIncSelfDec& opt2)
{
    SelfIncSelfDec tmp;
    tmp.a = opt1.a + opt2.a;
    tmp.b = opt1.b + opt2.b;
    return tmp;
}

//重载加运算符,形式：int+SelfIncSelfDec
const SelfIncSelfDec operator+(int i,const SelfIncSelfDec& opt)
{
    SelfIncSelfDec tmp;
    tmp.a = i + opt.a;
    tmp.b = i + opt.b;
    //tmp.SetA(i + opt.GetA());
    //tmp.SetB(i + opt.GetB());
    return tmp;
}

//重载加运算符,形式：SelfIncSelfDec+int
const SelfIncSelfDec operator+(const SelfIncSelfDec& opt,int i)
{
    SelfIncSelfDec tmp;
    tmp.a = opt.a + i;
    tmp.b = opt.b + i;
    //tmp.SetA(opt.GetA() + i);
    //tmp.SetB(opt.GetB() + i);
    return tmp;
}

//重载减运算符,形式：SelfIncSelfDec-SelfIncSelfDec
const SelfIncSelfDec operator-(const SelfIncSelfDec& opt1,const SelfIncSelfDec& opt2)
{
    SelfIncSelfDec tmp;
    tmp.a = opt1.a - opt2.a;
    tmp.b = opt1.b - opt2.b;
    return tmp;
}

//重载减运算符,形式：int-SelfIncSelfDec
const SelfIncSelfDec operator-(int i,const SelfIncSelfDec& opt)
{
    SelfIncSelfDec tmp;
    tmp.a = i - opt.a;
    tmp.b = i - opt.b;
    //tmp.SetA(i - opt.GetA());
    //tmp.SetB(i - opt.GetB());
    return tmp;
}

//重载减运算符,形式：SelfIncSelfDec-int
const SelfIncSelfDec operator-(const SelfIncSelfDec& opt,int i)
{
    SelfIncSelfDec tmp;
    tmp.a = opt.a - i;
    tmp.b = opt.b - i;
    //tmp.SetA(opt.GetA() - i);
    //tmp.SetB(opt.GetB() - i);
    return tmp;
}

//重载乘运算符,形式：SelfIncSelfDec*SelfIncSelfDec
const SelfIncSelfDec operator*(const SelfIncSelfDec& opt1,const SelfIncSelfDec& opt2)
{
    SelfIncSelfDec tmp;
    tmp.a = opt1.a * opt2.a;
    tmp.b = opt1.b * opt2.b;
    return tmp;
}

//重载乘运算符,形式：int*SelfIncSelfDec
const SelfIncSelfDec operator*(int i,const SelfIncSelfDec& opt)
{
    SelfIncSelfDec tmp;
    tmp.a = i * opt.a;
    tmp.b = i * opt.b;
    //tmp.SetA(i * opt.GetA());
    //tmp.SetB(i * opt.GetB());
    return tmp;
}

//重载乘运算符,形式：SelfIncSelfDec*int
const SelfIncSelfDec operator*(const SelfIncSelfDec& opt,int i)
{
    SelfIncSelfDec tmp;
    tmp.a = opt.a * i;
    tmp.b = opt.b * i;
    //tmp.SetA(opt.GetA() * i);
    //tmp.SetB(opt.GetB() * i);
    return tmp;
}

//重载除运算符,形式：SelfIncSelfDec/SelfIncSelfDec
const SelfIncSelfDec operator/(const SelfIncSelfDec& opt1,const SelfIncSelfDec& opt2)
{
    SelfIncSelfDec tmp;
    if (opt2.a == 0 || opt2.b == 0) {cout<<"error, Denominator cannot be 0!"<<endl;return tmp;}
    tmp.a = opt1.a / opt2.a;
    tmp.b = opt1.b / opt2.b;
    return tmp;
}

//重载除运算符,形式：int/SelfIncSelfDec
const SelfIncSelfDec operator/(int i,const SelfIncSelfDec& opt)
{
    SelfIncSelfDec tmp;
    if (opt.a == 0 || opt.b == 0) {cout<<"error, Denominator cannot be 0!"<<endl;return tmp;}
    tmp.a = i / opt.a;
    tmp.b = i / opt.b;
    //tmp.SetA(i / opt.GetA());
    //tmp.SetB(i / opt.GetB());
    return tmp;
}

//重载除运算符,形式：SelfIncSelfDec/int
const SelfIncSelfDec operator/(const SelfIncSelfDec& opt,int i)
{
    SelfIncSelfDec tmp;
    if (i == 0) {cout<<"error, Denominator cannot be 0!"<<endl;return tmp;}
    tmp.a = opt.a / i;
    tmp.b = opt.b / i;
    //tmp.SetA(opt.GetA() / i);
    //tmp.SetB(opt.GetB() / i);
    return tmp;
}


#if (defined(CLASS_MENBER) && CLASS_MENBER)
#else
// 重载前缀自加运算符
SelfIncSelfDec& operator++(SelfIncSelfDec& opt)
{
    opt.SetA(opt.GetA()+1);
    opt.SetB(opt.GetB()+1);

    return opt;
}

// 重载前缀自减运算符
SelfIncSelfDec& operator--(SelfIncSelfDec& opt)
{
    opt.SetA(opt.GetA()-1);
    opt.SetB(opt.GetB()-1);

    return opt;
}

// 重载后缀自加运算符
SelfIncSelfDec operator++(SelfIncSelfDec& opt,int i)
{
    SelfIncSelfDec tmp(opt);
    opt.SetA(opt.GetA()+1);
    opt.SetB(opt.GetB()+1);

    return tmp;
}

// 重载后缀自减运算符
SelfIncSelfDec operator--(SelfIncSelfDec& opt,int i)
{
    SelfIncSelfDec tmp(opt);
    opt.SetA(opt.GetA()-1);
    opt.SetB(opt.GetB()-1);

    return tmp;
}
#endif


//重载输出流
ostream& operator<<(ostream& out,SelfIncSelfDec& opt)
{
    out<<opt.GetA()<<","<<opt.GetB();//未在SelfIncSelfDec类中声明为友元时,需要调用GetA()/GetB()成员函数来取得私有成员数据a/b , 否则可以直接访问私有成员数据a/b
    return out;
}

//重载输入流
istream& operator>>(istream& in,SelfIncSelfDec& opt)
{
    int i,j;
    in>>i>>j;
    //未在SelfIncSelfDec类中声明为友元时,需要调用GetA()/GetB()成员函数来取得私有成员数据a/b , 否则可以直接访问私有成员数据a/b
    opt.SetA(i);
    opt.SetB(j);
    return in;
}

ostream& operator<<(ostream& out,ConvertFunA& opt)
{
    cout<<"ConvertFunA:"<<opt.i;
    return out;
}

istream& operator>>(istream& in,ConvertFunA& opt)
{
    cin>>opt.i;
    return in;
}

ostream& operator<<(ostream& out,ConvertFunB& opt)
{
    cout<<"ConvertFunB:"<<opt.i;
    return out;
}

istream& operator>>(istream& in,ConvertFunB& opt)
{
    cin>>opt.i;
    return in;
}
