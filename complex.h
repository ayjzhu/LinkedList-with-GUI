#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

class Complex
{
public:
    double real;                        //IN/OUT - a double type number
    double imaginary;                   //IN/OUT - a double type number
public:
    /*****************
     ** CONSTRUCTOR **
     *****************/
    Complex(double re,           //constructor
            double imagny);
    Complex(double real_part);   //constructor
    Complex();                   //constructor

    /***************
     ** ACCESSORS **
     ***************/
    bool operator==(const Complex&);
    const Complex operator+(const Complex&);
    const Complex operator-(const Complex&);
    const Complex operator*(const Complex&);
    friend ostream& operator<<(ostream&out, const Complex& c);

    // overloaded operator for comparison
    inline bool operator >=(Complex rhs){
        if(real >= rhs.real && (real+ imaginary >= rhs.real + rhs.imaginary))
            return true;
        return false;
    }
    inline bool operator >(Complex rhs){
        if(real > rhs.real && (real+ imaginary > rhs.real + rhs.imaginary))
            return true;
        return false;
    }
    inline bool operator <(Complex rhs){
        if(real < rhs.real && (real+ imaginary < rhs.real + rhs.imaginary))
            return true;
        return false;
    }
    inline bool operator !=(Complex rhs){
        if(fabs(real-rhs.real) > real * 0.01
                && fabs(imaginary-rhs.imaginary) > real * 0.01)
            return true;
        return false;
    }

    inline bool operator ==(Complex rhs){
        double epsilon = 0.001;

          if((std::abs(real - rhs.real) < epsilon )
                  && (std::abs(imaginary - rhs.imaginary) < epsilon) )
              return true;
          return false;
    }


    /***************
     **  Mutator  **
     ***************/
    friend istream& operator>>(istream&in, Complex& c);
};
#endif // COMPLEX_H

/**************************************************************************
 * Complex Class
 *   This class will read in two double type number in a complex form of a+
 *   bi as the attribute.
 *************************************************************************/

/*****************
 ** CONSTRUCTOR **
 *****************/

/**************************************************************************
 * Complex(double re, double imagny);
 *      Constructor; initializes the value of real to re and imaginary to
 *          imagny
 *      Parameters: re: a double type number
 *                  imagny: a double type number
 *      Return: none
 *************************************************************************/

/**************************************************************************
 * Complex(double real_part);
 *      Constructor; initializes imaginary to zero and real to real_part.
 *      Parameters: real_part is a double type number
 *      Return: none
 *************************************************************************/

/**************************************************************************
 * Complex();
 *      Constructor; initializes class attributes to zeros.
 *      Parameters: none
 *      Return: none
 *************************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/**************************************************************************
 * bool operator==(const Complex&);
 *      Accessor: This method compares the the value of the object to the
 *                the parameter object.
 *      Parameters: Complex c: is an object of Complex type
 *      Return: a boolean
 *************************************************************************/

/**************************************************************************
 * const Complex operator+(const Complex&);
 *      Accessor: This method adds the value of two objects
 *      Parameters: Complex c: is an object of Complex type
 *      Return: the sum of the two objects
 *************************************************************************/

/**************************************************************************
 * const Complex operator-(const Complex&);
 *      Accessor: This method subtract the value of two objects
 *      Parameters: Complex c: is an object of Complex type
 *      Return: the difference of the two objects
 *************************************************************************/

/**************************************************************************
 * const Complex operator*(const Complex&);
 *      Accessor: This method multiplies the value of two objects
 *      Parameters: Complex c: is an object of Complex type
 *      Return: the product of the two objects
 *************************************************************************/

/**************************************************************************
 * friend ostream& operator<<(ostream&out, const Complex& c);
 *      Accessor: This method outputs the complex form
 *      Parameters: Complex c: is an object of Complex type
 *      Return: the operator out
 *************************************************************************/
/***************
 **  Mutator  **
 ***************/
/**************************************************************************
 * friend ostream& operator>>(ostream&in, const Complex& c);
 *      Accessor: This method inputs the complex form to the instances
 *      Parameters: Complex c: is an object of Complex type
 *      Return: the operator in
 *************************************************************************/
