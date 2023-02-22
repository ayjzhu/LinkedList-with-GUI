#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linkedlist.h"
#include <sstream>

using namespace std;

/**
 * @brief MainWindow::MainWindow
 *
 * Constructor: default construtor
 *
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * @brief MainWindow::~MainWindow
 *
 * Destructor
 */
MainWindow::~MainWindow()
{
    delete ui;
}


template <typename T>
/**
 * @brief MainWindow::print
 *
 * Accessor: print the list
 *
 * Parameter: v, the vector
 *            index, the index of list
 *
 * Return: print the list
 */
void MainWindow::print(vector<LinkedList<T> > v, int index){
    ui->textBrowser->setText(QString::fromStdString(v[index].display()));
}

template <typename T>
/**
 * @brief MainWindow::print_portion
 *
 * Accessor: print part of the list
 *
 * Parameter:
 * @param v  the vector
 * @param index the index of list
 * @param start the start of index of the list
 * @param end the end of index of the list
 *
 * Return: print the list
 */
void MainWindow::print_portion(vector<LinkedList<T> > v, int index, int start, int end){
    ui->textBrowser->setText(QString::fromStdString(v[index].display_portion(start, end)));
}

/**
 * @brief MainWindow::on_pb_generate_clicked
 *
 * Mutator: generate the list in the vector and update the combobox, then print
 *
 * Return: print the list
 */
void MainWindow::on_pb_generate_clicked()
{
    // for int
    if (ui->rb_int->isChecked()){

        // create a temporary int vector
        LinkedList<int>* ll = new LinkedList<int>;

        // convert the data input to a string
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        int n;
        // read in and store the data one at a time
        while (is >> n){
            ll->push_back(n);
        }

        // store the int vector to the int list container
        MainWindow::v_int.push_back(*ll);

        // add the current vector to the combobox list
        ui->cb_list->addItem(QString::number(v_int.size()));
        // display the combobox list number
        ui->cb_list->setCurrentText(QString::number(v_int.size()));

        // display the current list to the text browser
        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }
    // for double
    else if(ui->rb_double->isChecked()){
        LinkedList<double>* ll = new LinkedList<double>;

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);
        is.precision(3);

        double n;

        while (is >> n){
            ll->push_back(n);
        }

        MainWindow::v_double.push_back(*ll);

        ui->cb_list->addItem(QString::number(v_double.size()));
        ui->cb_list->setCurrentText(QString::number(v_double.size()));

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    // for string
    else if (ui->rb_string->isChecked()){
        LinkedList<string>* ll = new LinkedList<string>;

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        string n;

        while (is >> n){
            ll->push_back(n);
        }

        MainWindow::v_string.push_back(*ll);

        ui->cb_list->addItem(QString::number(v_string.size()));
        ui->cb_list->setCurrentText(QString::number(v_string.size()));

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    // for Rational
    else if (ui->rb_rational->isChecked()){
        LinkedList<Rational>* ll = new LinkedList<Rational>;

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        int denom, numer;
        char dummy;

        while (is >> denom >> dummy >> numer){
            ll->push_back(Rational(denom, numer));
        }

        MainWindow::v_rational.push_back(*ll);

        ui->cb_list->addItem(QString::number(v_rational.size()));
        ui->cb_list->setCurrentText(QString::number(v_rational.size()));

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    // for Date
    else if (ui->rb_date->isChecked()){

        // create a temporary int vector
        LinkedList<Date>* ll = new LinkedList<Date>;

        // convert the data input to a string
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);  // store the string

        Date n;

        // extract the data
        is >> n;
        ll->push_back(n);

        // store the int vector to the int list container
        MainWindow::v_date.push_back(*ll);

        // add the current vector to the combobox list
        ui->cb_list->addItem(QString::number(v_date.size()));
        // display the combobox list number
        ui->cb_list->setCurrentText(QString::number(v_date.size()));

        // display the current list to the text browser
        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    // for complex
    else if (ui->rb_complex->isChecked()){

        // create a temporary int vector
        LinkedList<Complex>* ll = new LinkedList<Complex>;

        // convert the data input to a string
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);  // store the string

        Complex n;

        // extract the data
        is >> n;
        cout << n << endl;
        ll->push_back(n);

        // store the int vector to the int list container
        MainWindow::v_complex.push_back(*ll);

        // add the current vector to the combobox list
        ui->cb_list->addItem(QString::number(v_complex.size()));
        // display the combobox list number
        ui->cb_list->setCurrentText(QString::number(v_complex.size()));

        // display the current list to the text browser
        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }
}

/**
 * @brief MainWindow::on_pb_insert_clicked
 *
 * Mutator: insert sort a value in the list and print the list
 *
 * Return: print the list
 */
void MainWindow::on_pb_insert_clicked()
{
    if (ui->rb_int->isChecked()){

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        int n;

        while (is >> n){
            v_int[v_int.size() - 1].insert_sorted(n);
        }

        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }

    else if(ui->rb_double->isChecked()){
        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);
        is.precision(3);

        double n;

        while (is >> n){
            v_double[v_double.size() - 1].insert_sorted(n);
        }

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    else if (ui->rb_string->isChecked()){

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        string n;

        while (is >> n){
            v_string[v_string.size() - 1].insert_sorted(n);
        }

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    else if (ui->rb_rational->isChecked()){
        LinkedList<Rational>* ll = new LinkedList<Rational>;

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        int denom, numer;
        char dummy;

        while (is >> denom >> dummy >> numer){
            v_rational[v_rational.size() - 1].insert_sorted((Rational(denom, numer)));
        }

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    else if(ui->rb_date->isChecked()){
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        Date d;

        is >> d;
        v_date[MainWindow::v_date.size() - 1].insert_sorted(d);

        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    else if(ui->rb_complex->isChecked()){
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        Complex d;

        is >> d;
        v_complex[MainWindow::v_complex.size() - 1].insert_sorted(d);

        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }

}

void MainWindow::on_pb_insertAtPosition_clicked()
{
    int index = ui->le_position->text().toInt();
    ui->le_position->clear();

    if(ui->rb_int->isChecked()){

        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        int n;

        while (is >> n){
            v_int[v_int.size() - 1].insert_at_index(n,index);
        }

        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }
    else if(ui->rb_double->isChecked()){
        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);
        is.precision(3);

        double n;

        while (is >> n){
            v_double[v_double.size() - 1].insert_at_index(n,index);
        }

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    else if (ui->rb_string->isChecked()){

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        string n;

        while (is >> n){
            v_string[v_string.size() - 1].insert_at_index(n,index);
        }

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    else if (ui->rb_rational->isChecked()){
        LinkedList<Rational>* ll = new LinkedList<Rational>;

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        int denom, numer;
        char dummy;

        while (is >> denom >> dummy >> numer){
            v_rational[v_rational.size() - 1].insert_at_index(Rational(denom, numer),index);
        }

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    else if(ui->rb_date->isChecked()){
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        Date d;

        is >> d;
        v_date[MainWindow::v_date.size() - 1].insert_at_index(d,index);

        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    else if(ui->rb_complex->isChecked()){
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        Complex c;

        is >> c;
        v_complex[MainWindow::v_complex.size() - 1].insert_at_index(c,index);

        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }

}

/**
 * @brief MainWindow::on_pb_pushback_clicked
 *
 * Mutator: push back a value in the list and print the list
 *
 * Return: print the list
 */
void MainWindow::on_pb_pushback_clicked()
{
    // for int
    if (ui->rb_int->isChecked()){

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        int n;

        while (is >> n){
            v_int[v_int.size() - 1].push_back(n);
        }

        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }
    // for double
    else if(ui->rb_double->isChecked()){
        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);
        is.precision(3);

        double n;

        while (is >> n){
            v_double[v_double.size() - 1].push_back(n);
        }

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    // for string
    else if (ui->rb_string->isChecked()){

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        string n;

        while (is >> n){
            v_string[v_string.size() - 1].push_back(n);
        }

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    // for Rational
    else if (ui->rb_rational->isChecked()){

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        int denom, numer;
        char dummy;

        while (is >> denom >> dummy >> numer){
            v_rational[v_rational.size() - 1].push_back((Rational(denom, numer)));
        }

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    // for Date
    else if(ui->rb_date->isChecked()){
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        Date d;
        is >> d;
        v_date[MainWindow::v_date.size() - 1].push_back(d);

        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    // for Complex
    else if(ui->rb_complex->isChecked()){
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        Complex d;
        is >> d;
        v_complex[MainWindow::v_complex.size() - 1].push_back(d);

        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }
}

/**
 * @brief MainWindow::on_pb_pushfront_clicked
 *
 * Mutator: push front a value in the list
 *
 * Return: print the list
 */
void MainWindow::on_pb_pushfront_clicked()
{
    if (ui->rb_int->isChecked()){

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        int n;

        while (is >> n){
            v_int[v_int.size() - 1].push_front(n);
        }

        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }

    else if(ui->rb_double->isChecked()){
        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);
        is.precision(3);

        double n;

        while (is >> n){
            v_double[v_double.size() - 1].push_front(n);
        }

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    else if (ui->rb_string->isChecked()){

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        string n;

        while (is >> n){
            v_string[v_string.size() - 1].push_front(n);
        }

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    else if (ui->rb_rational->isChecked()){

        string str = ui->le_datainput->text().toStdString();

        istringstream is(str);

        int denom, numer;
        char dummy;

        while (is >> denom >> dummy >> numer){
            v_rational[v_rational.size() - 1].push_front((Rational(denom, numer)));
        }

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    else if(ui->rb_date->isChecked()){
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        Date d;

        is >> d;
        v_date[MainWindow::v_date.size() - 1].push_front(d);

        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    else if(ui->rb_complex->isChecked()){
        string str = ui->le_datainput->text().toStdString();
        istringstream is(str);

        Complex d;
        is >> d;
        v_complex[MainWindow::v_complex.size() - 1].push_front(d);

        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }
}

/**
 * @brief MainWindow::on_pb_sort_clicked
 *
 * Mutator: sort the list and print
 *
 * Return: print the list
 */
void MainWindow::on_pb_sort_clicked()
{
    if (ui->rb_int->isChecked()){

        v_int[v_int.size() - 1].select_sort();

        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }

    else if(ui->rb_double->isChecked()){
        v_double[v_double.size() - 1].select_sort();

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    else if (ui->rb_string->isChecked()){

        v_string[v_string.size() - 1].select_sort();

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    else if (ui->rb_rational->isChecked()){
        v_rational[v_rational.size() - 1].select_sort();

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    else if(ui->rb_date->isChecked()){
        v_date[MainWindow::v_date.size() - 1].select_sort();

        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    else if(ui->rb_complex->isChecked()){
        v_complex[MainWindow::v_complex.size() - 1].select_sort();

        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }
}

/**
 * @brief MainWindow::on_pb_rm_dp_clicked
 *
 * Mutator: remove duplicates in the list and print
 *
 * Return: print the list
 */
void MainWindow::on_pb_rm_dp_clicked()
{
    if (ui->rb_int->isChecked()){

        v_int[v_int.size() - 1].remove_duplicates();

        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }

    else if(ui->rb_double->isChecked()){
        v_double[v_double.size() - 1].remove_duplicates();

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    else if (ui->rb_string->isChecked()){

        v_string[v_string.size() - 1].remove_duplicates();

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    else if (ui->rb_rational->isChecked()){

        v_rational[v_rational.size() - 1].remove_duplicates();

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    else if(ui->rb_date->isChecked()){
        v_date[MainWindow::v_date.size() - 1].remove_duplicates();
        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    else if(ui->rb_complex->isChecked()){
        v_complex[MainWindow::v_complex.size() - 1].complex_remove_duplicates();
        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }
}

/**
 * @brief MainWindow::on_pb_pop_front_clicked
 *
 * Mutator: pop front the value in the list and print
 *
 * Return: print the list
 */
void MainWindow::on_pb_pop_front_clicked()
{
    if (ui->rb_int->isChecked()){

        v_int[v_int.size() - 1].pop_front();

        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }

    else if(ui->rb_double->isChecked()){
        v_double[v_double.size() - 1].pop_front();

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    else if (ui->rb_string->isChecked()){

        v_string[v_string.size() - 1].pop_front();

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    else if (ui->rb_rational->isChecked()){

        v_rational[v_rational.size() - 1].pop_front();

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    else if(ui->rb_date->isChecked()){
        v_date[MainWindow::v_date.size() - 1].pop_front();
        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    else if(ui->rb_complex->isChecked()){
        v_complex[MainWindow::v_complex.size() - 1].pop_front();
        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }
}

/**
 * @brief MainWindow::on_pb_copy_clicked
 *
 * Mutator: copy the list and update combobox
 *
 * Return: print the lsit
 */
void MainWindow::on_pb_copy_clicked()
{
    if (ui->rb_int->isChecked()){

        v_int.push_back(v_int[v_int.size() - 1]);

        ui->cb_list->addItem(QString::number(v_int.size()));
        ui->cb_list->setCurrentText(QString::number(v_int.size()));

        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }

    else if(ui->rb_double->isChecked()){
        v_double.push_back(v_double[v_double.size() - 1]);

        ui->cb_list->addItem(QString::number(v_double.size()));
        ui->cb_list->setCurrentText(QString::number(v_double.size()));

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    else if (ui->rb_string->isChecked()){

        v_string.push_back(v_string[v_string.size() - 1]);

        ui->cb_list->addItem(QString::number(v_string.size()));
        ui->cb_list->setCurrentText(QString::number(v_string.size()));

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    else if (ui->rb_rational->isChecked()){

        v_rational.push_back(v_rational[v_rational.size() - 1]);

        ui->cb_list->addItem(QString::number(v_rational.size()));
        ui->cb_list->setCurrentText(QString::number(v_rational.size()));

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    else if(ui->rb_date->isChecked()){

        v_date.push_back(v_date[v_date.size() - 1]);
        ui->cb_list->addItem(QString::number(v_date.size()));
        ui->cb_list->setCurrentText(QString::number(v_date.size()));
        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    else if(ui->rb_complex->isChecked()){

        v_complex.push_back(v_complex[v_complex.size() - 1]);
        ui->cb_list->addItem(QString::number(v_complex.size()));
        ui->cb_list->setCurrentText(QString::number(v_complex.size()));
        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }
}

/**
 * @brief MainWindow::on_cb_list_currentTextChanged
 *
 * Accessor: update the textbrowser
 *
 * Parameter
 * @param arg1 the combobox text
 *
 * Return: update the textbroser
 */
void MainWindow::on_cb_list_currentTextChanged(const QString &arg1)
{
    if (arg1.toInt()){
        if (ui->rb_int->isChecked()){

            print(MainWindow::v_int, arg1.toInt() - 1);
        }

        else if(ui->rb_double->isChecked()){

            print(MainWindow::v_double, arg1.toInt() - 1);
        }
        else if (ui->rb_string->isChecked()){

            print(MainWindow::v_string, arg1.toInt() - 1);
        }
        else if (ui->rb_rational->isChecked()){

            print(MainWindow::v_rational, arg1.toInt() - 1);

        }
        else if (ui->rb_date->isChecked()){

            print(MainWindow::v_date, arg1.toInt() - 1);

        }
        else if (ui->rb_complex->isChecked()){

            print(MainWindow::v_complex, arg1.toInt() - 1);

        }
    }

}

/**
 * @brief MainWindow::on_rb_int_clicked
 *
 * Mutator: update the lineedit and combobox
 */
void MainWindow::on_rb_int_clicked()
{
    ui->le_datainput->clear();

    if (ui->cb_list->count())
        ui->cb_list->clear();

    for (int i = 1; i <= MainWindow::v_int.size(); ++i)
        ui->cb_list->addItem(QString::number(i));
}

/**
 * @brief MainWindow::on_rb_double_clicked
 *
 * Mutator: update the lineeidt and comboxbox
 */
void MainWindow::on_rb_double_clicked()
{
    ui->le_datainput->clear();

    if (ui->cb_list->count())
        ui->cb_list->clear();

    for (int i = 1; i <= MainWindow::v_double.size(); ++i)
        ui->cb_list->addItem(QString::number(i));
}

/**
 * @brief MainWindow::on_rb_string_clicked
 *
 * Mutator: update the lineeidt and comboxbox
 */
void MainWindow::on_rb_string_clicked()
{
    ui->le_datainput->clear();

    if (ui->cb_list->count())
        ui->cb_list->clear();

    for (int i = 1; i <= MainWindow::v_string.size(); ++i)
        ui->cb_list->addItem(QString::number(i));
}

/**
 * @brief MainWindow::on_rb_rational_clicked
 *
 * Mutator: update the lineeidt and comboxbox
 */
void MainWindow::on_rb_rational_clicked()
{
    ui->le_datainput->clear();

    if (ui->cb_list->count())
        ui->cb_list->clear();

    for (int i = 1; i <= MainWindow::v_rational.size(); ++i)
        ui->cb_list->addItem(QString::number(i));

}

void MainWindow::on_rb_date_clicked()
{
    ui->le_datainput->clear();

    if (ui->cb_list->count())
        ui->cb_list->clear();

    for (int i = 1; i <= MainWindow::v_date.size(); ++i)
        ui->cb_list->addItem(QString::number(i));

}

void MainWindow::on_rb_complex_clicked()
{

    ui->le_datainput->clear();

    if (ui->cb_list->count())
        ui->cb_list->clear();

    for (int i = 1; i <= MainWindow::v_complex.size(); ++i)
        ui->cb_list->addItem(QString::number(i));
}

/**
 * @brief MainWindow::on_pb_showall_clicked
 *
 * Accessor: print the list
 *
 * Return: print the list
 */
void MainWindow::on_pb_showall_clicked()
{
    if (ui->rb_int->isChecked()){

        print(MainWindow::v_int, MainWindow::v_int.size() - 1);
    }

    else if(ui->rb_double->isChecked()){

        print(MainWindow::v_double, MainWindow::v_double.size() - 1);
    }
    else if (ui->rb_string->isChecked()){

        print(MainWindow::v_string, MainWindow::v_string.size() - 1);
    }
    else if (ui->rb_rational->isChecked()){

        print(MainWindow::v_rational, MainWindow::v_rational.size() - 1);
    }
    else if (ui->rb_date->isChecked()){

        print(MainWindow::v_date, MainWindow::v_date.size() - 1);
    }
    else if (ui->rb_complex->isChecked()){

        print(MainWindow::v_complex, MainWindow::v_complex.size() - 1);
    }
}

/**
 * @brief MainWindow::on_pb_show_portion_clicked
 *
 * Accessor: print part of list
 *
 * Return: print part of list
 */
void MainWindow::on_pb_show_portion_clicked()
{
    if (ui->rb_int->isChecked()){

        print_portion(MainWindow::v_int, MainWindow::v_int.size() - 1, ui->sb_from_index->value(), ui->sb_to_index->value());
    }

    else if(ui->rb_double->isChecked()){

        print_portion(MainWindow::v_double, MainWindow::v_double.size() - 1, ui->sb_from_index->value(), ui->sb_to_index->value());
    }
    else if (ui->rb_string->isChecked()){

        print_portion(MainWindow::v_string, MainWindow::v_string.size() - 1, ui->sb_from_index->value(), ui->sb_to_index->value());
    }
    else if (ui->rb_rational->isChecked()){

        print_portion(MainWindow::v_rational, MainWindow::v_rational.size() - 1, ui->sb_from_index->value(), ui->sb_to_index->value());
    }
    else if (ui->rb_date->isChecked()){

        print_portion(MainWindow::v_date, MainWindow::v_date.size() - 1, ui->sb_from_index->value(), ui->sb_to_index->value());
    }
    else if (ui->rb_date->isChecked()){

        print_portion(MainWindow::v_complex, MainWindow::v_complex.size() - 1, ui->sb_from_index->value(), ui->sb_to_index->value());
    }
}
