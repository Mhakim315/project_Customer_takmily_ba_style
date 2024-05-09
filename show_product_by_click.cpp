#include "show_product_by_click.h"
#include "ui_show_product_by_click.h"
#include "product_and_customer_class.h"
#include "QFile"
#include "QWidget"
#include "QLabel"
#include "QVBoxLayout"
#include "QTextStream"
#include "QFont"

show_product_by_click::show_product_by_click(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::show_product_by_click)
{
    ui->setupUi(this);
}

show_product_by_click::~show_product_by_click()
{
    delete ui;
}

void show_product_by_click::on_pushButton_clicked()
{
    QFile read_in_file("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    if(!read_in_file.open(QFile::ReadOnly | QFile::Text))
    {
        QWidget * window = new QWidget();
        window->setWindowTitle("Status of record information");
        QLabel *check = new QLabel("information was not recorded");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(check);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window, SLOT(close()));
        window->setLayout(layout);
        window->show();
        return;
    }
    QTextStream file_read_name (& read_in_file);
    QString name_with_lint_edit = ui->lineEdit->text();
    QString name_in_file, inventory, price;
    while(!file_read_name.atEnd())
    {
        name_in_file = file_read_name.readLine();
        if(file_read_name.atEnd())
            break;
        if(name_in_file == name_with_lint_edit)
        {
            inventory = file_read_name.readLine();
            price = file_read_name.readLine();
            QFont font("Arial", 10, QFont::Bold);
            QWidget * window_information = new QWidget();
            window_information->setWindowTitle("information product ");
            window_information->resize(400, 400);
            window_information->setStyleSheet("QWidget {background-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));}");
            //QLabel *name = new QLabel(name_in_file);
            QLabel *name_lbl = new QLabel("product name : " + name_in_file);
            name_lbl->setFont(font);
            //QLabel *inventory_ = new QLabel(inventory);
            QLabel *inventory_lbl = new QLabel("inventory product : " + inventory);
            inventory_lbl->setFont(font);
            //QLabel *price_ = new QLabel(price);
            QLabel *price_lbl = new QLabel("price product : " + price);
            price_lbl->setFont(font);
            //QLabel *fasele = new QLabel("******************************");
            //fasele->setFont(font);
            QVBoxLayout *layout = new QVBoxLayout();
            layout->addWidget(name_lbl);
            //layout->addWidget(name);
            layout->addWidget(inventory_lbl);
            //layout->addWidget(inventory_);
            layout->addWidget(price_lbl);
            //layout->addWidget(price_);
            QPushButton *button_ok = new QPushButton("OK");
            button_ok->setFont(font);
            button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_information, SLOT(close()));
            //layout->addWidget(fasele);
            layout->addWidget(button_ok);
            window_information->setLayout(layout);
            window_information->show();
            return;
        }
    }
    read_in_file.close();

    QWidget * window_show_not_found = new QWidget();
    window_show_not_found->setWindowTitle("Status of record information");
    QLabel *check = new QLabel("<b>product with name not found in the warehouse</b>");
    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *button_ok = new QPushButton("ok");
    layout->addWidget(check);
    layout->addWidget(button_ok);
    button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_show_not_found, SLOT(close()));
    window_show_not_found->setLayout(layout);
    window_show_not_found->show();
    return;
}

