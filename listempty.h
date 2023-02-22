#ifndef LISTEMPTY_H
#define LISTEMPTY_H

#include <string>

using namespace std;

class ListEmpty{

public:

    /*****************
     ** CONSTRUCTOR **
     *****************/
    ListEmpty(){
        message = "";
    }

    ListEmpty(string message){
        this->message = message;
    }

    /***************
     ** Accessor  **
     ***************/
    string what(){
        return message;
    }

private:
    string message;  // IN/OUT - error message
};

/**************************************************************************
 * ListEmpty Class
 *   This class will contain the information of the error message
 *************************************************************************/

/**************************************************************************
 * ListEmpty()
 *      Constructor; initialize the message to empty
 *      Parameters: none
 *      Return: none
 *************************************************************************/

/**************************************************************************
 * ListEmpty(string message)
 *      Constructor; initialize the message with the given message
 *      Parameters: message: a string text
 *      Return: none
 *************************************************************************/

/**************************************************************************
 * what()
 *      Accessor; gets the message
 *      Parameters: none
 *      Return: a string of message
 *************************************************************************/

#endif // LISTEMPTY_H
