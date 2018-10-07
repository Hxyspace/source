#include <iostream>
#include <climits>

class Factorial
{
public:
    Factorial (unsigned short num);
    unsigned long getFactorial();
    bool inRange();

private:
    unsigned short a;
};
Factorial::Factorial(unsigned short num)
{
    this->a = num;
}

unsigned long Factorial::getFactorial()
{
    unsigned long sum = 1;
    for(int i=1; i<=a; i++)
    {
        sum *= i;
    }
    return sum;
}
bool Factorial::inRange()
{
    unsigned long max = ULONG_MAX;
    for( int i = a ;i >= 1; --i)
    {
        max /= i;
    }
    if ( max < 1)
        return false;
    else
        return true;
}

int main()
{
    while (1)
    {
    unsigned short sum = 0;
    std::cout << "������һ��������";
    std::cin >> sum;
    Factorial fac(sum);
    if ( fac.inRange())
    {
        std::cout << sum <<"�Ľ׳�Ϊ��"<<fac.getFactorial();
    }
    else
        std::cout << "����������Χ\n";
    }
    return 0;
}
