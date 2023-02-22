#include "complex.h"

/**************************************************************************
 *
 * Method Complex: Class Complex
 *_________________________________________________________________________
 * This method assign class attributes of real to re and imaginary to
 *   imagny
 *   -returns nothing.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      None
 *
 * POST-CONDITIONS
 *     This functiion will assign the value to the class attributes
**************************************************************************/
Complex::Complex(double re,         // IN - real part of the number
                 double imagny)     // IN - imaginary part of the number
{
    real = re;
    imaginary = imagny;
}

/**************************************************************************
 *
 * Method Complex: Class Complex
 *_________________________________________________________________________
 * This method assign class attributes of real to re
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      None
 *
 * POST-CONDITIONS
 *     This functiion will assign the value to the class attributes
**************************************************************************/
Complex::Complex(double real_part)  // IN - real part of the number
{
    imaginary = 0;
    real = real_part;
}

/**************************************************************************
 *
 * Method Complex: Class Complex
 *_________________________________________________________________________
 * This method initialize class attributes,and default date
 *   -returns nothing.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      None
 *
 * POST-CONDITIONS
 *     This functiion will initilize the private member variables
**************************************************************************/
Complex::Complex()
{
    real = 0;
    imaginary = 0;
}

/**************************************************************************
 *
 * Method operator==: Class Complex
 *_________________________________________________________________________
 * This method compares the the value of the object to the
 *   the parameter object.
 *   -returns a boolean.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      Complex c: is an object of Complex type
 *
 * POST-CONDITIONS
 *     This functiion will compare the objects and return a boolean
**************************************************************************/
bool Complex::operator==(const Complex& c)  // IN - a complex number
{
    if(real == c.real)
    {
        if(imaginary == c.imaginary)
        {
            return true;
        }
    }
    return false;
}

/**************************************************************************
 *
 * Method operator+: Class Complex
 *_________________________________________________________________________
 * This method adds the value of two objects
 *   -returns the sum of the two objects.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      Complex c: is an object of Complex type
 *
 * POST-CONDITIONS
 *     This function will add the objects and return the sum
**************************************************************************/
const Complex Complex::operator +(const Complex& c) // IN - a complex number
{
    Complex temp;
    temp.real = real + c.real;
    temp.imaginary = imaginary + c.imaginary;
    return temp;
}

/**************************************************************************
 *
 * Method operator-: Class Complex
 *_________________________________________________________________________
 * This method subtracts the value of two objects
 *   -returns the difference of the two objects.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      Complex c: is an object of Complex type
 *
 * POST-CONDITIONS
 *     This function will subtract the objects and return the difference
**************************************************************************/
const Complex Complex::operator -(const Complex& c) // IN - a complex number
{
    Complex temp;
    temp.real = real - c.real;
    temp.imaginary = imaginary - c.imaginary;
    return temp;
}

/**************************************************************************
 *
 * Method operator*: Class Complex
 *_________________________________________________________________________
 * This method multiplies the value of two objects
 *   -returns the product of the two objects.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      Complex c: is an object of Complex type
 *
 * POST-CONDITIONS
 *     This function will multiplies the objects and return the product
**************************************************************************/
const Complex Complex::operator *(const Complex & c)    // IN - a complex number
{
    Complex temp;
    temp.real = (real * c.real) - (imaginary * c.imaginary);
    temp.imaginary = (real * c.imaginary) + (imaginary * c.real);
    return temp;
}

/**************************************************************************
 *
 * Method operator<<: Class Complex
 *_________________________________________________________________________
 * This method outputs the complex form
 *   -returns the operator out.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      Complex c: is an object of Complex type
 *
 * POST-CONDITIONS
 *     This function will output the objects and return the out operator
**************************************************************************/
ostream& operator<<(ostream& out, const Complex& c) // IN - a complex number
{
    if(c.real == 0)
    {
        if(c.imaginary >= 0)
            out << c.real << "+" << c.imaginary << "i";
        else
            out << c.real << c.imaginary << "i";
    }
    else
    {
        if(c.imaginary >0)
            out << c.real << "+" << c.imaginary << "i";
        else if (c.imaginary < 0)
            out << c.real << c.imaginary << "i";
        else
            out << c.real << "+" << c.imaginary << "i";
    }
    return out;
}

/**************************************************************************
 *
 * Method operator<<: Class Complex
 *_________________________________________________________________________
 * This method inputs the complex form
 *   -returns the operator out.
 *_________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      Complex c: is an object of Complex type
 *
 * POST-CONDITIONS
 *     This function will input the objects and return the out operator
**************************************************************************/
istream& operator>>(istream& in, Complex& c)    // IN - a complex number
{
    string text;
    getline(in,text);
    stringstream ss(text);
    if (text[text.size() - 1] != 'i') // no imaginary i

    {
        ss >> c.real;
        c.imaginary = 0;
        return in;

    }
    else if (text[0] == 'i') //only imaginary i
    {
        c.real = 0;
        c.imaginary = 1;
        return in;

    }
    else if (text[0] == '-') // only -i
    {
        if (text[1] == 'i')
        {
            c.real = 0;
            c.imaginary = -1;
            return in;
        }
    }

    for (int i = 0; i < text.size(); ++i)
    {
        if (text[i] == '-')
        {
            if (text[i + 1] == 'i')
            {
                stringstream ss_temp1(text);
                ss_temp1 >> c.real;
                c.imaginary = -1;
            }
        }
        if (text[i] == '+')
        {
            if (text[i + 1] == 'i')
            {
                stringstream ss_temp1(text);
                ss_temp1 >> c.real;
                c.imaginary = 1;
            }
        }
    }

    char c_temp;
    double d_temp=0;
    double d_temp2=0;
    ss >> d_temp >> c_temp;
    if (c_temp == 'i')
    {
        c.imaginary = d_temp;
        return in;
    }
    stringstream ss2(text);
    ss2 >> d_temp >> d_temp2 >> c_temp;
    if (c_temp == 'i')
    {
        c.real = d_temp;
        c.imaginary = d_temp2;
        return in;
    }

    return in;
}
