
//==================================================

//��������ص�ʵ�֣��������ǽ����������ļӼ��˳������

//ʹ�õı�������CodeBlocks

//������ԣ�C/C++

//�漰֪ʶ���ࡢ������������ص�

//==================================================

#include <iostream>

#include <stdlib.h>



//==================================================

//����һ��Rational�࣬���ж������������к���������˽�б�����һ��˽�к���

//==================================================

class Rational

{

public:

    Rational(int num,int denom);                   //ʵ������������ʽ"num/denom"



    Rational operator+(Rational rhs);              //�ӷ�����

    Rational operator-(Rational rhs);              //��������

    Rational operator*(Rational rhs);              //�˷�����

    Rational operator/(Rational rhs);              //��������



    void print();                                  //��ӡ������



private:

    void normalize();      //�Է����ļ򻯴���



    int numerator;         //����

    int denominator;       //��ĸ

};



Rational::Rational(int num,int denom)

{

    numerator = num;

    denominator = denom;



    normalize();

}



//==================================================

//�������������2/16���������������Ҫ����Ϊ1/8

//==================================================

void Rational::normalize()

{

    //ȷ����ĸΪ��

    if(denominator < 0)

    {

        numerator = -numerator;

        denominator = -denominator;

    }



    //ŷ������㷨

    int a = abs(numerator);

    int b = abs(denominator);



    while(b>0)

    {

        int t = a%b;

        a = b;

        b = t;

    }



    numerator/=a;

    denominator/=a;

}





Rational Rational::operator+(Rational rhs)

{

    int a = numerator;

    int b = denominator;

    int c = rhs.numerator;

    int d = rhs.denominator;



    int e = a*b +c*d;

    int f = b*d;



    return Rational(e,f);

}



Rational Rational::operator-(Rational rhs)

{

    rhs.numerator = -rhs.numerator;



    return operator+(rhs);

}



Rational Rational::operator*(Rational rhs)

{

    int a = numerator;

    int b = denominator;

    int c = rhs.numerator;

    int d = rhs.denominator;



    int e = a*c;

    int f = b*d;



    return Rational(e,f);

}



Rational Rational::operator/(Rational rhs)

{

    int t = rhs.numerator;

    rhs.numerator = rhs.denominator;

    rhs.denominator = t;



    return operator*(rhs);

}



void Rational::print()

{

    if(numerator%denominator == 0)

       std::cout<<numerator / denominator;

    else

       std::cout<<numerator <<"/"<<denominator;

}



int main()

{

    Rational f1(2,16);

    Rational f2(7,8);



    Rational res = f1+f2;

    f1.print();

    std::cout<<" + ";

    f2.print();

    std::cout<<" = ";

    res.print();

    std::cout<<"\n";





    res = f1 - f2;

    f1.print();

    std::cout<<" - ";

    f2.print();

    std::cout<<" = ";

    res.print();

    std::cout<<"\n";



    res = f1 * f2;

    f1.print();

    std::cout<<" * ";

    f2.print();

    std::cout<<" = ";

    res.print();

    std::cout<<"\n";



    res = f1 / f2;

    f1.print();

    std::cout<<" / ";

    f2.print();

    std::cout<<" = ";

    res.print();

    std::cout<<"\n";



    return 0;

}
