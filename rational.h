#ifndef RATIONAL_H
#define RATIONAL_H

#include <string>
#include <iostream>

class Rational
{
    private:
        int numer;
        int denom;
    public:
        Rational();
        Rational(int);
        Rational(int, int);
        const Rational add(const Rational &) const;
        const Rational subtract(const Rational &) const;
        const Rational multiply(const Rational &) const;
        const Rational divide(const Rational &) const;
        std::string display() const;
        Rational operator++();

        Rational operator++(int u);

        inline bool operator>=(Rational r){
            if ((numer * r.denom - denom * r.numer) >= 0)
                return true;
            return false;
        }

        inline bool operator<(Rational r){
            if ((numer * r.denom - denom * r.numer) < 0)
                return true;
            return false;
        }

        inline bool operator>(Rational r){
            if ((numer * r.denom - denom * r.numer) > 0)
                return true;
            return false;
        }

        inline bool operator!=(Rational r){
            if ((numer * r.denom - denom * r.numer) == 0)
                return false;
            return true;
        }

        inline bool operator==(Rational r){
            if ((numer * r.denom - denom * r.numer) == 0)
                return true;
            return false;
        }

        friend std::ostream& operator<<(std::ostream& os, const Rational &r);

};

#endif // RATIONAL_H
