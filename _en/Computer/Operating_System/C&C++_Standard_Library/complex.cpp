/* complex.cpp
Author: BSS9395
Update: 2021-09-23T22:49:00+08@China-Guangdong-Shenzhen+08
Design: C++ Standard Library complex
*/

/*
Multiplication:
(a+b*i) * (c+d*i) = (a*c-b*d) + (a*d+b*c)*i

Division:
a+b*i   (a+b*i) * (c-d*i)   (a*c+b*d)+(b*c-a*d)*i   a*c+b*d   b*c-a*d
----- = ----------------- = --------------------- = ------- + -------*i
c+d*i   (c+d*i) * (c-d*i)   c^2+d^2                 c^2+d^2   c^2+d^2
*/

/*
#include<complex>

complex (const T& re = T(), const T& im = T());

complex (const complex& x);

template<class U>
complex (const complex<U>& x);
*/

#include <iostream>     
#include <complex>      

using namespace std;

int main(int argc, char *argv[]) {
    complex<double> plural(3.0, 4.0);
    double absolute = abs(plural);
    double angle = arg(plural);
    cout << plural << ": " << plural.real() << "+" << plural.imag() << "*i" << endl;
    cout << "abs(" << plural << ")=" << absolute << endl;
    cout << "arg(" << plural << ")=" << angle << endl;

    complex<double> rhs(4.0, 3.0);
    complex<double> multiplication = plural * rhs;
    complex<double> division = plural / rhs;
    cout << plural << "*" << rhs << "=" << multiplication << endl;
    cout << plural << "/" << rhs << "=" << division << endl;

    return 0;
}