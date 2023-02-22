#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Date
{
private:
    unsigned day;                   //IN/OUT - number of days
    unsigned month;                 //IN/OUT - number of months
    string monthName;               //IN/OUT - string name of  month
    unsigned year;                  //IN/OUT - number of years
    bool isLeap(unsigned) const;
    unsigned daysPerMonth(unsigned m, unsigned y)const;
    string name(unsigned m)const;
    unsigned number(const string & mn) const;
public:
    /*****************
     ** CONSTRUCTOR **
     *****************/

    Date();                     //constructor
    Date(unsigned m,
         unsigned d,
         unsigned y);
    Date(const string &mn,
         unsigned d,
         unsigned y);

    /***************
     ** ACCESSORS **
     ***************/
    void printNumeric() const;
    void printAlpha() const;
    string display() const;
    friend ostream& operator<<(ostream& outs, const Date &d);

    // overloaded operator for comparison
    inline bool operator>=(Date rhs){
        if((year + month + day) >= (rhs.year + rhs.month + rhs.day))
            return true;
        return false;
    }

    inline bool operator <(Date rhs){
        if((year + month + day) < (rhs.year + rhs.month + rhs.day))
            return true;
        return false;
    }

    inline bool operator >(Date rhs){
        if((year + month + day) > (rhs.year + rhs.month + rhs.day))
            return true;
        return false;
    }

    inline bool operator !=(Date rhs){
        if((year + month + day) != (rhs.year + rhs.month + rhs.day))
            return true;
        return false;
    }

    inline bool operator ==(Date rhs){
        if((year + month + day) == (rhs.year + rhs.month + rhs.day))
            return true;
        return false;
    }

    /***************
     **  MUTATORS **
     ***************/
    Date addDays(int) const;
    friend istream& operator>>(istream& ins, Date& d);
};

#endif // DATE_H
/****************************************************************
 * Date Class
 *   This class will read in a date with three arguments: day,
 *   month, year and then display the result
 ***************************************************************/

/*****************
 ** CONSTRUCTOR **
 *****************/

/****************************************************************
 * Date ();
 *   Constructor; Initialize class attributes
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * Date(unsigned m, unsigned d, unsigned y)
 *   Constructor; Initialize class attributes
 *   Parameters: unsinged integer m, d, and y
 *   Return: none
 ***************************************************************/

/****************************************************************
 * Date(const string &mn, unsigned d, unsigned y)
 *   Constructor; Initialize class attributes
 *   Parameters: string variable mn, unsinged integer d, and y
 *   Return: none
 ***************************************************************/

/***************
 ** ACCESSORS **
 ***************/

/****************************************************************
 * void printNumeric() const;
 *
 *   Accessor; This method will display the date in numeric form
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void printAlpha() const;
 *
 *   Accessor; This method will display the date in alpha format
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/***************
 **  MUTATORS **
 ***************/

/****************************************************************
 * Date addDays(int) const;
 *
 *   Mutator; This method will adds the days to the current date
 *     and return the new date
 * --------------------------------------------------------------
 *   Parameters:
 *      int d: the given days to add
 * --------------------------------------------------------------
 *   Return: the new date object
 ***************************************************************/
