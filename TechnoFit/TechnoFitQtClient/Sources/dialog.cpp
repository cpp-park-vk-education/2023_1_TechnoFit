#include "../Headers/dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    State state;
    if(ui->radioButton->isChecked())
    {
        state = Standard;
        std::cout << "Standard" << std::endl;
    }
        
    if(ui->radioButton_2->isChecked())
    {
        state = Intensive;
        std::cout << "Intensive" << std::endl;   
    }
    if(ui->radioButton_3->isChecked())
    {
        state = Premium;
        std::cout << "Premium" << std::endl;
    }
    auto name = ui->name_textbox->text();
    int age = (ui->age_textbox->text()).toInt();
    float weight = (ui->weight_textbox->text()).toFloat();
    usecase_->createDevice(state, name, age, weight);
    close();
}

void Dialog::on_buttonBox_rejected()
{
    close();
}