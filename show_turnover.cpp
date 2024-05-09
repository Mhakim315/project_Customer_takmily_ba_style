#include "show_turnover.h"
#include "ui_show_turnover.h"
#include "QWidget"
#include "QLabel"
#include "QPushButton"
#include "QVBoxLayout"
#include "QFile"
#include "QTextStream"
#include "ctime"
#include "time.h"
#include "QFont"

show_turnover::show_turnover(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::show_turnover)
{
    ui->setupUi(this);
}

show_turnover::~show_turnover()
{
    delete ui;
}

void show_turnover::on_pushButton_2_clicked()
{
    //dar inja gardesh malyye 1 mah akeer neshan dade mishavad

    QFile file_turnover("C:/Users/ModernSystem/Desktop/Qtcreator2.txt");
    if(!file_turnover.open(QFile::ReadOnly  | QFile::Text))
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status record information customer");
        QLabel *error = new QLabel("Error openning file To read information customer");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(error);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_error, SLOT(close()));
        window_error->setLayout(layout);
        window_error->show();
        return;
    }

    //tarikh hal system ra estekhraj mi konim

    time_t now = time(0);
    tm *ltm = localtime(& now);

    int year_system = ltm->tm_year + 1970;
    int month_system = ltm->tm_mon + 1;
    int day_system = ltm->tm_mday;
    //qDebug () << year_system << " "<<month_system<< " "<< day_system;

    QString Customer_name_in_file;
    QString Customer_lastname_in_file;
    QString Customer_phone_number_in_file;
    QString year_in_file, month_in_file, day_in_file;
    QString product_name_in_file, number_product_in_file;
    QString final_price_in_file;

    int year_check, month_check, day_check;
    long final_price_long = 0;
    QTextStream turnover_file_for_show_invoce (& file_turnover);
    QWidget *window_show_turnover = new QWidget();
    window_show_turnover->setWindowTitle("The turnover of a recent month");
    window_show_turnover->resize(500, 500);
    window_show_turnover->setStyleSheet("QWidget {background-color : qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");
    QFont font("Arial", 10, QFont::Bold);
    QVBoxLayout *layout2 = new QVBoxLayout();
    while(!turnover_file_for_show_invoce.atEnd())
    {
        Customer_name_in_file = turnover_file_for_show_invoce.readLine();
        if(turnover_file_for_show_invoce.atEnd())
            break;
        Customer_lastname_in_file = turnover_file_for_show_invoce.readLine();
        Customer_phone_number_in_file = turnover_file_for_show_invoce.readLine();
        year_in_file = turnover_file_for_show_invoce.readLine();
        month_in_file = turnover_file_for_show_invoce.readLine();
        day_in_file = turnover_file_for_show_invoce.readLine();
        year_check = year_in_file.toInt();
        month_check = month_in_file.toInt();
        day_check = day_in_file.toInt();
        product_name_in_file = turnover_file_for_show_invoce.readLine();
        number_product_in_file = turnover_file_for_show_invoce.readLine();
        final_price_in_file = turnover_file_for_show_invoce.readLine();

        if((year_check == year_system && month_check == month_system -1 && day_check == day_system) | (year_check == year_system && month_check == month_system && day_system - day_check  <= 30) | (year_check == year_system && month_check + 1 == month_system && ((30 - day_check) + day_system ) <= 30 )   )
        {
            final_price_long += final_price_in_file.toLong();
            QLabel *Customer_name = new QLabel("Customer name : " + Customer_name_in_file);
            Customer_name->setFont(font);
            QLabel *Customer_lastname = new QLabel("Customer last name : "+ Customer_lastname_in_file);
            Customer_lastname->setFont(font);
            QLabel *Customer_phone_number = new QLabel("Customer phone number : "+ Customer_phone_number_in_file);
            Customer_phone_number->setFont(font);
            QLabel *Customer_Date_order = new QLabel("Date order : "+ year_in_file + "/" + month_in_file + "/" + day_in_file);
            Customer_Date_order->setFont(font);
            QLabel *Customer_order_product = new QLabel("product name : "+ product_name_in_file);
            Customer_order_product->setFont(font);
            QLabel *Customer_number_product = new QLabel("product number To order : "+ number_product_in_file);
            Customer_number_product->setFont(font);
            QLabel *final_price_Customer = new QLabel("final price To order product : "+ final_price_in_file);
            final_price_Customer->setFont(font);
            QLabel *fasele_ba_setare = new QLabel("********************************");

            fasele_ba_setare->setFont(font);
            layout2->addWidget(Customer_name);
            layout2->addWidget(Customer_lastname);
            layout2->addWidget(Customer_phone_number);
            layout2->addWidget(Customer_Date_order);
            layout2->addWidget(Customer_order_product);
            layout2->addWidget(Customer_number_product);
            layout2->addWidget(final_price_Customer);
            layout2->addWidget(fasele_ba_setare);
        }
        // else
        // {
        //     product_name_in_file = turnover_file_for_show_invoce.readLine();
        //     number_product_in_file = turnover_file_for_show_invoce.readLine();
        //     final_price_in_file = turnover_file_for_show_invoce.readLine();
        // }
    }
    file_turnover.close();
    QString final_price_To_show = QString::number(final_price_long);
    QLabel *Customer_final_price = new QLabel("turnover in the recent month : "+ final_price_To_show);
    Customer_final_price->setFont(font);

    if(final_price_long == 0)
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status record information customer");
        QLabel *error = new QLabel("<b>NO purchases have been made in the last month</b>");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(error);
        layout->addWidget(Customer_final_price);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_error, SLOT(close()));
        window_error->setLayout(layout);
        window_error->show();
        return;
    }
    QPushButton *button_ok = new QPushButton("OK");
    button_ok->setFont(font);
    button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_show_turnover, SLOT(close()));
    layout2->addWidget(Customer_final_price);
    layout2->addWidget(button_ok);
    window_show_turnover->setLayout(layout2);
    window_show_turnover->show();
    return;
}


void show_turnover::on_pushButton_clicked()
{
    // dar inja ham ardesh maly namaesh dade mishavad ba in tafavot ke range tareekhy dade mishavad

    // QString year_begin_line_edit = ui->line_edit_year_begin->text();
    // QString month_begin_line_edit = ui->line_edit_month_begin->text();
    // QString day_begin_line_edit = ui->line_edit_day_begin->text();
    // QString year_end_line_edit = ui->line_edit_year_end->text();
    // QString month_end_line_edit = ui->line_edit_month_end->text();
    // QString day_end_line_edit = ui->line_edit_day_end->text();

    int year_begin_int = (ui->line_edit_year_begin->text()).toInt();
    int month_begin_int = (ui->line_edit_month_begin->text()).toInt();
    int day_begin_int = (ui->line_edit_day_begin->text()).toInt();
    int year_end_int = (ui->line_edit_year_end->text()).toInt();
    int month_end_int = (ui->line_edit_month_end->text()).toInt();
    int day_end_int = (ui->line_edit_day_end->text()).toInt();

    QFile file_information_Customer("C:/Users/ModernSystem/Desktop/Qtcreator2.txt");
    if(!file_information_Customer.open(QFile::ReadOnly | QFile::Text))
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status record information customer");
        window_error->resize(500, 500);
        QLabel *error = new QLabel("Error openning file To read information customer");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(error);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_error, SLOT(close()));
        window_error->setLayout(layout);
        window_error->show();
        return;

    }

    QString Customer_name_search;
    QString Customer_lastname_search;
    QString Customer_phone_number_search;
    QString year_search, month_search, day_search;
    QString product_name_search;
    QString number_product_search;
    QString final_price_search;

    long final_price_To_show_turnover = 0;
    int year_int, month_int, day_int;

    QWidget *window_of_show_turnover_in_range = new QWidget();
    window_of_show_turnover_in_range->setWindowTitle("The turnover in range ");
    window_of_show_turnover_in_range->setStyleSheet("QWidget {background-color : qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");
    window_of_show_turnover_in_range->resize(500, 500);
    QFont font("Arial", 10, QFont::Bold);
    QVBoxLayout *layout3 = new QVBoxLayout();

    bool check_exit_turnover_in_the_range = false;

    QTextStream information_Customer_in_file (& file_information_Customer);
    while(!information_Customer_in_file.atEnd())
    {
        Customer_name_search = information_Customer_in_file.readLine();
        if(information_Customer_in_file.atEnd())
            break;
        Customer_lastname_search = information_Customer_in_file.readLine();
        Customer_phone_number_search = information_Customer_in_file.readLine();
        year_search = information_Customer_in_file.readLine();
        year_int = year_search.toInt();
        month_search = information_Customer_in_file.readLine();
        month_int = month_search.toInt();
        day_search = information_Customer_in_file.readLine();
        day_int = day_search.toInt();
        product_name_search = information_Customer_in_file.readLine();
        number_product_search = information_Customer_in_file.readLine();
        final_price_search = information_Customer_in_file.readLine();
        if((year_end_int > year_int && year_begin_int < year_int) | (year_begin_int == year_end_int && month_end_int > month_int && month_begin_int < month_int) | (year_begin_int == year_end_int && month_begin_int == month_end_int && day_end_int > day_int && day_begin_int < day_int))
        {
            check_exit_turnover_in_the_range = true;
            final_price_To_show_turnover += final_price_search.toLong();

            QLabel *Customer_name_label = new QLabel("Customer name : " + Customer_name_search);
            Customer_name_label->setFont(font);
            QLabel *Customer_lastname_label = new QLabel("Customer last name : " + Customer_lastname_search);
            Customer_lastname_label->setFont(font);
            QLabel *Customer_phone_number_label = new QLabel("Customer phone number : " + Customer_phone_number_search);
            Customer_phone_number_label->setFont(font);
            QLabel *Customer_Date_label = new QLabel("Customer Date order : " + year_search + "/" + month_search + "/" + day_search);
            Customer_Date_label->setFont(font);
            QLabel *Customer_product_name_order_label = new QLabel("Customer product name To order : " + product_name_search);
            Customer_product_name_order_label->setFont(font);
            QLabel *Customer_product_number_label = new QLabel("number of product record : " + number_product_search);
            Customer_product_number_label->setFont(font);
            QLabel *Customer_final_price_label = new QLabel("final price To order : " + final_price_search);
            Customer_final_price_label->setFont(font);
            QLabel *fasele_label = new QLabel("*************************");
            fasele_label->setFont(font);

            layout3->addWidget(Customer_name_label);
            layout3->addWidget(Customer_lastname_label);
            layout3->addWidget(Customer_phone_number_label);
            layout3->addWidget(Customer_Date_label);
            layout3->addWidget(Customer_product_name_order_label);
            layout3->addWidget(Customer_product_number_label);
            layout3->addWidget(Customer_final_price_label);
            layout3->addWidget(fasele_label);
        }
    }
    if(check_exit_turnover_in_the_range == false)
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status record information customer");
        QLabel *error = new QLabel("<b>not found turnover in the range date</b>");
        QLabel *final_price_label = new QLabel("turnover in the range date : 0" );
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(error);
        layout->addWidget(final_price_label);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_error, SLOT(close()));
        window_error->setLayout(layout);
        window_error->show();
        return;
    }

    file_information_Customer.close();
    QString final_price_string = QString::number(final_price_To_show_turnover);
    QLabel *final_price_show_turnover_label = new QLabel ("turnover with range date : " + final_price_string);
    layout3->addWidget(final_price_show_turnover_label);
    QPushButton *button_ok = new QPushButton("OK");
    button_ok->setFont(font);
    button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_of_show_turnover_in_range, SLOT(close()));

    layout3->addWidget(button_ok);
    window_of_show_turnover_in_range->setLayout(layout3);
    window_of_show_turnover_in_range->show();
    return;


}

