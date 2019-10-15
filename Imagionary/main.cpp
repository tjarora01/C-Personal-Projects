#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Complex {

    double re, im;

public:
    //Complex();


    Complex(const double r = 0.0, const double i = 0.0);

    void operator=(Complex *rhs);

    Complex operator+(Complex *rhs);

    void operator+=(Complex *rhs);

    Complex operator- (const Complex& rhs) const;
    void operator-=(Complex *rhs);

    Complex operator*(Complex *rhs);

    void operator*=(Complex *rhs);

    Complex operator/(const Complex& rhs) const;

    Complex&  operator/= (const Complex& rhs);

    double getRe(){
        return re;
    }

    double getIm(){
        return im;
    }
};

// define constructor
Complex::Complex( const double r, const double i )
{
    re = r; im = i;
}

Complex Complex::operator- (const Complex& rhs) const
{
    Complex finalComplex;
    finalComplex.re = this->re - rhs.re;
    finalComplex.im = this->im - rhs.im;
    return finalComplex;
}

Complex Complex::operator/ (const Complex& rhs) const
{
    Complex finalComplex;

    double divisor = (rhs.re * rhs.re) + (rhs.im * rhs.im);
    double num_re = (this->re * rhs.re) + (this->im * rhs.im);
    double num_img = (this->im * rhs.re) - (this->re * rhs.im);

    finalComplex.re = num_re/divisor;
    finalComplex.im = num_img/divisor;
    return finalComplex;
}

Complex& Complex::operator/= (const Complex& rhs) {
    Complex finalComplex;

    double divisor = (rhs.re * rhs.re) + (rhs.im * rhs.im);
    double num_re = (this->re * rhs.re) + (this->im * rhs.im);
    double num_img = (this->im * rhs.re) - (this->re * rhs.im);

    this->re = num_re/divisor;
    this->im = num_img/divisor;
    return finalComplex;
}

Complex exp(Complex c) {
    double x;
    x = (double) c;


}



int main() {

    Complex c(25.0,50.0);
    Complex d(4.0,3.0);

    Complex g = c - d;

    cout << "--- subtraction---" << endl;
    cout << g.getRe() << endl;
    cout << g.getIm() << endl;

    cout << "--- division / ---" << endl;
    g = c / d;

    cout << g.getRe() << endl;
    cout << g.getIm() << endl;

    cout << "--- division /= ---" << endl;

    c /= d;

    cout << c.getRe() << endl;
    cout << c.getIm() << endl;

    return 0;
}