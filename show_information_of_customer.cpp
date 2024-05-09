#include "show_information_of_customer.h"
#include "ui_show_information_of_customer.h"
#include "QWidget"
#include "QFile"
#include "QLabel"
#include "QPushButton"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QTextStream"
#include "QFont"


show_information_of_customer::show_information_of_customer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::show_information_of_customer)
{
    ui->setupUi(this);
}

show_information_of_customer::~show_information_of_customer()
{
    delete ui;
}

void show_information_of_customer::on_pushButton_clicked()
{
    QString name_customer_for_show_information  = ui->lineEdit->text();
    QString lastname_customer_for_show_information = ui->lineEdit_2->text();
    QString name_search_in_file;
    QString family_search_in_file;
    QString phone_number_in_file ;
    QString product_name_in_file;
    QString year_in_file, month_in_file, day_in_file;//type  int
    QString number_product_in_file, final_price_in_file;//type long
    QFile information_customer_in_file("C:/Users/ModernSystem/Desktop/Qtcreator2.txt");
    if(!information_customer_in_file.open(QFile::ReadOnly | QFile::Text))
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status record information customer");
        QLabel *error = new QLabel("Error openning file To read information customer To show invoic");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(error);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_error, SLOT(close()));
        window_error->setLayout(layout);
        window_error->show();
        return;
    }
    bool check_exit_customer_with_name_in_file = false;
    QTextStream file_information_of_customer(& information_customer_in_file);
    while(!file_information_of_customer.atEnd())
    {
        name_search_in_file = file_information_of_customer.readLine();
        family_search_in_file = file_information_of_customer.readLine();
        if(file_information_of_customer.atEnd())
            break;
        if(name_search_in_file == name_customer_for_show_information && family_search_in_file == lastname_customer_for_show_information)
        {
            check_exit_customer_with_name_in_file = true;
            phone_number_in_file = file_information_of_customer.readLine();
            year_in_file = file_information_of_customer.readLine();
            month_in_file = file_information_of_customer.readLine();
            day_in_file = file_information_of_customer.readLine();
            product_name_in_file = file_information_of_customer.readLine();
            number_product_in_file = file_information_of_customer.readLine();
            final_price_in_file = file_information_of_customer.readLine();
            QFont font("Arial", 10, QFont::Bold);
            QWidget *window_show_information_of_customer = new QWidget();
            window_show_information_of_customer->setWindowTitle("information of customer");
            window_show_information_of_customer->setStyleSheet("QWidget {background-color : qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));}");
            QLabel *name = new QLabel("Customer name : " + name_search_in_file);
            name->setFont(font);
            //QLabel *Customer_name = new QLabel(name_search_in_file);
            QLabel *family = new QLabel("Customer last name : " + family_search_in_file);
            family->setFont(font);
            //QLabel *Customer_lastname = new QLabel(family_search_in_file);
            QLabel *phone= new QLabel("Customer phone number : " + phone_number_in_file);
            phone->setFont(font);
            //QLabel *Costomer_phone_number = new QLabel(phone_number_in_file);
            QLabel *Date = new QLabel("Date of order : " + year_in_file + "/" + month_in_file + "/"+ day_in_file);
            Date->setFont(font);
            //QLabel *Customer_date_order = new QLabel(year_in_file + "/" + month_in_file + "/"+ day_in_file);
            QLabel *product = new QLabel("Custom product name : " + product_name_in_file);
            product->setFont(font);
            //QLabel *Custom_product_name = new QLabel(product_name_in_file);
            QLabel *number = new QLabel("Custom product number : " + number_product_in_file);
            number->setFont(font);
            //QLabel *number_product = new QLabel(number_product_in_file);
            QLabel *final = new QLabel("final price Custom product : " + final_price_in_file);
            final->setFont(font);
            //QHBoxLayout *hlayout = new QHBoxLayout();
            QLabel *fasele = new QLabel("**********************************");
            fasele->setFont(font);
            QVBoxLayout *vlayout = new QVBoxLayout();
            QPushButton *button_ok = new QPushButton("Ok");
            button_ok->setFont(font);
            button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_show_information_of_customer, SLOT(close()));

            vlayout->addWidget(name);
            vlayout->addWidget(family);
            vlayout->addWidget(phone);
            vlayout->addWidget(Date);
            vlayout->addWidget(product);
            vlayout->addWidget(number);
            vlayout->addWidget(final);
            vlayout->addWidget(fasele);
            vlayout->addWidget(button_ok);

            window_show_information_of_customer->setLayout(vlayout);
            window_show_information_of_customer->show();
            information_customer_in_file.close();
            return;
        }
        else
        {
            phone_number_in_file = file_information_of_customer.readLine();
            year_in_file = file_information_of_customer.readLine();
            month_in_file = file_information_of_customer.readLine();
            day_in_file = file_information_of_customer.readLine();
            product_name_in_file = file_information_of_customer.readLine();
            number_product_in_file = file_information_of_customer.readLine();
            final_price_in_file = file_information_of_customer.readLine();

        }
    }
    information_customer_in_file.close();
    if(check_exit_customer_with_name_in_file == false)
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status record information customer");
        QLabel *error = new QLabel("product not found with this name");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(error);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_error, SLOT(close()));
        window_error->setLayout(layout);
        window_error->show();
        return;
    }

    
}

