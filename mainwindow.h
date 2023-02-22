#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linkedlist.h"
#include "rational.h"
#include "date.h"
#include "complex.h"
#include "tvector.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // default constructor
    explicit MainWindow(QWidget *parent = nullptr);

    // destructor
    ~MainWindow();

    // print the linkedlist in the vector
    template<typename T>
    void print(vector<LinkedList<T> > v, int index);

    // print part of the linkedlist
    template<typename T>
    void print_portion(vector<LinkedList<T> > v, int index, int start, int end);

//    void update();

private slots:
    // generate a linkedlist into vector
    void on_pb_generate_clicked();

    // insert a value into linkedlist
    void on_pb_insert_clicked();

    // push back a value into linkedlist
    void on_pb_pushback_clicked();

    // push front a value into linkedlist
    void on_pb_pushfront_clicked();

    // sort the linkedlist
    void on_pb_sort_clicked();

    // remove duplicates in the list
    void on_pb_rm_dp_clicked();

    // pop front the value in the list
    void on_pb_pop_front_clicked();

    // copy the list
    void on_pb_copy_clicked();

    // change textbrowser content if combobox text changed
    void on_cb_list_currentTextChanged(const QString &arg1);

    // selected int vector and update combobox list
    void on_rb_int_clicked();

    // selected double vector and update combobox list
    void on_rb_double_clicked();

    // selected string vector and update combobox list
    void on_rb_string_clicked();

    // selected rational vector update combobox list
    void on_rb_rational_clicked();

    // show all contents in the list
    void on_pb_showall_clicked();

    // show part of list
    void on_pb_show_portion_clicked();

    // selected Date vector and update combobox list
    void on_rb_date_clicked();

    // selected Complex vector and update combobox list
    void on_rb_complex_clicked();

    // insert a value in a given position
    void on_pb_insertAtPosition_clicked();

private:
    Ui::MainWindow *ui;

    vector<LinkedList<int> > v_int;  // IN/OUT - int vector
    vector<LinkedList<double> > v_double;  // IN/OUT - double vector
    vector<LinkedList<string> > v_string;  // IN/OUT - string vector
    vector<LinkedList<Rational> > v_rational;  // IN/OUT - rational vector
    vector<LinkedList<Date> > v_date;       // IN/OUT - Date vector
    vector<LinkedList<Complex> > v_complex; // IN/OUT - Complex Vector
};

/*
    Mainwindow class
     This is the base class.
     It manages five attributes, *ui, v_int, v_double, v_string, v_rational.
*/

/*
 * explicit MainWindow(QWidget *parent = nullptr);
 * Constructor: default
 * Parameter: *parent
 * Return: none
*/

/*
 * ~MainWindow();
 * Destructor
*/

/*
 * void print(vector<LinkedList<T> > v, int index);
 * Accessor: print the list
 * Parameter: v, index
 * Return: print the list
*/

/*
 * void print_portion(vector<LinkedList<T> > v, int index, int start, int end);
 * Accessor: print part of list
 * Parameter: v, index, start, end
 * Return: print part of list
*/

/*
 * void on_pb_generate_clicked();
 * Mutator: generate a list
*/

/*
 * void on_pb_insert_clicked();
 * Mutator: insert a value into list
*/

/*
 * void on_pb_pushback_clicked();
 * Mutator: push back a value into list
*/

/*
 * void on_pb_pushfront_clicked();
 * Mutator: push front a value into list
*/

/*
 * void on_pb_sort_clicked();
 * Mutator: sort the list
*/

/*
 * void on_pb_rm_dp_clicked();
 * Mutator: remove duplicates in the list
*/

/*
 * void on_pb_pop_front_clicked();
 * Mutator: pop front the list
*/

/*
 * void on_pb_copy_clicked();
 * Mutator: copy the list
*/

/*
 * void on_cb_list_currentTextChanged(const QString &arg1);
 * Mutator: update the TextBrowser
 * Parameter: arg1
 * Return: update the TextBrowser
*/

/*
 * void on_rb_int_clicked();
 * Mutator: select int vector and update combobox list
*/

/*
 * void on_rb_double_clicked();
 * Mutator: select double vector and update combobox list
*/

/*
 * void on_rb_string_clicked();
 * Mutator: selected string vector and update combobox list
*/

/*
 * void on_rb_rational_clicked();
 * Mutator: selected rational vector update combobox list
*/

/*
 * void on_pb_showall_clicked();
 * Accessor: show all contents in the list
 * Return: print out the list
*/

/*
 * void on_pb_show_portion_clicked();
 * Accessor: print part of the list
 * Return: print part of list
*/
#endif // MAINWINDOW_H
