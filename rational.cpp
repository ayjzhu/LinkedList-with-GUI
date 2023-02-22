#include <iostream>
#include <sstream>
#include "rational.h"

using namespace std;

Rational::Rational()
{
    numer = 0;
    denom = 1;
}

Rational::Rational(int num){
    numer = num;
    denom = 1;
}

Rational::Rational(int num, int den){
    numer = num;
    denom = den;
}


const Rational Rational::add(const Rational &rn) const{
    Rational temp;
    temp.numer = numer * rn.denom + denom * rn.numer;
    temp.denom = denom * rn.denom;
    return temp;
}

const Rational Rational::subtract(const Rational &rn) const{
    Rational temp;
    temp.numer = numer * rn.denom - denom * rn.numer;
    temp.denom = denom * rn.denom;
    return temp;
}

const Rational Rational::multiply(const Rational &rn) const{
    Rational temp;
    temp.numer = numer * rn.numer;
    temp.denom = denom * rn.denom;
    return temp;
}

const Rational Rational::divide(const Rational &rn) const{
    Rational temp;
    temp.numer = numer * rn.denom;
    temp.denom = denom * rn.numer;
    return temp;
}

string Rational::display() const{
    std::ostringstream outstr;
    outstr << numer << "/" << denom;
    return outstr.str();
}

Rational Rational::operator++(){
    numer += denom;

    return *this;
}

Rational Rational::operator++(int u){
    Rational temp = *this;
    numer += denom;

    return temp;
}

ostream& operator<<(ostream& os, const Rational &r)
{
    os << r.numer << "/" << r.denom;
    return os;
}
