#include "date.h"

/**********************************************************
 *
 * Method Date: Class Date
 *_________________________________________________________
 * This method initialize class attributes,and default date
 *   -returns nothing.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      None
 *
 * POST-CONDITIONS
 *     This functiion will initilize the private member
 *     variables
***********************************************************/
Date::Date()
{
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}

/**********************************************************
 *
 * Method isLeap: Class Date
 *_________________________________________________________
 * This method receives y as a parameter to check whether a
 *   year is a leap year
 *   – returns a boolean.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      y: a integer value represents year
 *
 * POST-CONDITIONS
 *     This function will check if the argument consider to
 *     be a leap year, and return a bool type expression
***********************************************************/
bool Date::isLeap(unsigned y) const    //IN - a unsigned integer year
{
    if(y %4 == 0 && (y % 400 == 0 || y % 100 != 0))
        return true;
    else
        return false;
}

/**********************************************************
 *
 * Method daysPerMonth: Class Date
 *_________________________________________________________
 * This method will calculate the days in specific month in
 *   a year.
 *   -returns an unsigned integer.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      m: an unsigned integer month
 *      y: an unsinged integer year
 * POST-CONDITIONS
 *     This functiion will pass in the variable for month to
 *     compute days in that month. Meanwhile, if Feburary is
 *     the month, it will check to see whether the if is a
 *     leap year to determin the days in Feburary
***********************************************************/
unsigned Date::daysPerMonth(unsigned m,         // IN - month in integer
                            unsigned y)const    // IN - year in integer
{
    //if its leap year
    if(isLeap(y) && m == 2)
    {
        return 29;
    }
    else
    {
        switch(m)
        {
        case 1:
            return 31;
            break;
        case 2:
            return 28;  // 28 days incommon year
            break;
        case 3:
            return 31;
            break;
        case 4:
            return 30;
            break;
        case 5:
            return 31;
            break;
        case 6:
            return 30;
            break;
        case 7:
            return 31;
            break;
        case 8:
            return 31;
            break;
        case 9:
            return 30;
            break;
        case 10:
            return 31;
            break;
        case 11:
            return 30;
            break;
        case 12:
            return 31;
            break;
        }
    }
}

/**********************************************************
 *
 * Method name: Class Date
 *_________________________________________________________
 * This method will process the string name of the month
 *   returns a string of month
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      m: an unsigned integer of month
 *
 * POST-CONDITIONS
 *     This function will check the numeric value of month
 *     and return the corresponding string name of the month
***********************************************************/
string Date::name(unsigned m)const  // IN - month as integer
{
    switch(m)
    {
    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    default:
        if(m > 12)
        {
            return "December";
        }
        else if(m <= 0)
        {
            return "January";
        }
        break;
    }
}

/**********************************************************
 *
 * Method number: Class Date
 *_________________________________________________________
 * This method receives a string name of month and process
 *   to a corresponding numeric value
 *   – returns a numeric value of month.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      mn: a string name of month
 *
 * POST-CONDITIONS
 *     This function will check the name of the month and
 *     returns its corresponding numeric value
***********************************************************/
unsigned Date::number(const string &mn)const    //IN - month name in string
{
    //check upper and lowercase of month
    if(mn == "January" || mn == "january")
        return 1;
    else if(mn == "February" || mn == "february")
        return 2;
    else if(mn == "March" || mn == "march")
        return 3;
    else if(mn == "April" || mn == "april")
        return 4;
    else if(mn == "May" || mn == "may")
        return 5;
    else if(mn == "June" || mn == "june")
        return 6;
    else if(mn == "July" || mn == "july")
        return 7;
    else if(mn == "August" || mn == "august")
        return 8;
    else if(mn == "September" || mn == "september")
        return 9;
    else if(mn == "October" || mn == "october")
        return 10;
    else if(mn == "November" || mn == "november")
        return 11;
    else if(mn == "December"|| mn == "december")
        return 12;
    else
    {
        return 0;       //return default case
    }
}

/**********************************************************
 *
 * Method Date: Class Date
 *_________________________________________________________
 * This method initialize class attributes,and default date
 *   -returns nothing.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      m: an unsigned integer month
 *      d: an unsigned integer day
 *      y: an unsigned integer year
 *
 * POST-CONDITIONS
 *     This functiion will construct and assign values to
 *     the private member variables
***********************************************************/
Date::Date(unsigned m,  // IN - month in unsigned integer
           unsigned d,  // IN - day in unsigned integer
           unsigned y)  // IN - year in unsigned integer
{
    unsigned maxDay;
    maxDay = daysPerMonth(m,y);
    bool error = false;

    //validate day
    if(d > maxDay)
    {
        error = true;
        day = maxDay;
    }
    else if(d <= 0)
    {
        error = true;
        day = 1;
    }
    else
        day = d;

    //validate month
    if(m > 12)
    {
        error = true;
        month = 12;
    }
    else if(m <= 0)
    {
        error    = true;
        month = 1;
    }
    else
        month = m;

    //validate year
    if(y <= 0)
    {   error = true;
        year = 1;
    }
    else if(year != 2000)
        year = y;

    monthName = name(m);

    if(error)
        cout << "Invalid date values: Date corrected to "
             << month << "/" << day << "/" << year << ".\n";
}

/**********************************************************
 *
 * Method Date: Class Date
 *_________________________________________________________
 * This method initialize class attributes,and default date
 *   -returns nothing.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      mn: an string name month
 *      d: an unsigned integer day
 *      y: an unsigned integer year
 *
 * POST-CONDITIONS
 *     This functiion will construct and assign values to
 *     the private member variables
***********************************************************/
Date::Date(const string &mn,    // IN - month in string
           unsigned d,          // IN - day in unsigned integer
           unsigned y)          // IN - year in unsigned integer
{
    bool error = false;
    month = number(mn);
    unsigned maxDay;
    maxDay = daysPerMonth(month,y);

    //validate day
    if(d > maxDay)
    {
        error = true;
        day = maxDay;
    }
    else if(d <= 0)
    {
        error = true;
        day = 1;
    }
    else
        day = d;

    //validate year
    if(y <= 0)
        year = 1;
    else if(year != 2000)
        year = y;

    monthName = name(month);

    if(month == 0)
    {
        cout << "Invalid month name: the Date was set to 1/1/2000.\n";
        month = 1;
        day = 1;
        year = 2000;    //default values
    }

    if(error)
        cout << "Invalid date values: Date corrected to "
             << month << "/" << day << "/" << year << ".\n";

}

/**********************************************************
 *
 * Method printNumeric: Class Date
 *_________________________________________________________
 * This method will display the date in numeric format
 *   -returns nothing.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *     This functiion will output the values of month, day
 *     and year.
***********************************************************/
void Date::printNumeric() const
{
    cout << month << "/" << day << "/" << year;
}

/**********************************************************
 *
 * Method printAlpha: Class Date
 *_________________________________________________________
 * This method will display the date in alpha format
 *   -returns nothing.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      none
 *
 * POST-CONDITIONS
 *     This functiion will output the values of month, day
 *     and year.
***********************************************************/
void Date::printAlpha() const
{
    cout << monthName << " " << day << ", " << year;
}

/**********************************************************
 *
 * Method addDays: Class Date
 *_________________________________________________________
 * This method will adds the given days to the current date
 *  and update to a new date
 *   -returns the new date
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *      int d: the days to add
 *
 * POST-CONDITIONS
 *     This functiion will get the date that is added with
 *       the given days
***********************************************************/
Date Date::addDays(int d) const{ // IN - day as integer
    // create a temporary date object
    Date temp(month, day, year);

    // if the days given are positive
    if (d > 0){
        // increment year by given days
        while (d > 365){
            if (isLeap(temp.year))
                d -= 366;
            else
                d -= 365;

            temp.year++;
        }

        // increment month according to the given days
        while (d > daysPerMonth(temp.month, temp.year)){
            d -= daysPerMonth(temp.month, temp.year);
            temp.month++;
            // increment a year if month is over 12
            if (temp.month > 12){
                temp.month = 1;
                temp.year++;
            }
        }
        // increment day according to the given days
        if (temp.day + d > daysPerMonth(temp.month, temp.year)){
            // increment month if the sum of days is over days in a valid month
            temp.month++;
            temp.day = temp.day + d - daysPerMonth(temp.month, temp.year);
        }
        else{  // increment the days for any excess given days
            temp.day += d;
        }
    }
    // if the days given is negative, decrement the days from the current date
    else{
        while (-d > daysPerMonth(temp.month, temp.year)){
            // decrement months from the given days
            temp.month--;

            // if month is less than 1 then decrement a year
            if (temp.month < 1){
                temp.month = 12;
                temp.year--;
            }
            d += daysPerMonth(temp.month, temp.year);

        }
        // if the give days has more than the days in the valid month then
        //   decrement a month
        if (-d > temp.day){
            temp.month--;
            temp.day = daysPerMonth(temp.month, temp.year) - (-d - temp.day);
        }
        else{
            temp.day -= -d;
        }
    }

    temp.monthName = name(temp.month);
    return temp;
}

istream& operator>>(istream& ins, Date& d){

    string dateStr;
    getline(ins,dateStr);
    stringstream ss(dateStr);
    vector<int> date;
    string s;

    while(getline(ss, s , '/')){
        date.push_back(stoi(s));
    }

    // assign member attributes
    d.month = date[0];
    d.day = date[1];
    d.year = date[2];
    d.monthName = d.name(d.month);

    return ins;
}

ostream& operator<<(ostream& outs, const Date &d){
    outs << d.display();
//    outs << d.month << "/" <<  d.day <<  "/" << d.year;
    return outs;
}

string Date::display() const{
    std::ostringstream outstr;
    outstr << month << "/" <<  day <<  "/" << year;
    return outstr.str();
}
