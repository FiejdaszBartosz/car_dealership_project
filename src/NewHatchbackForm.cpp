#include "NewHatchbackForm.h"
#include "ui_NewHatchbackForm.h"

NewHatchbackForm::NewHatchbackForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewHatchbackForm)
{
    ui->setupUi(this);
}

NewHatchbackForm::~NewHatchbackForm()
{
    delete ui;
}

void NewHatchbackForm::setMenager(VehicleManager &rVehicleMenager) {
    this->aVehicleMenager = rVehicleMenager;
}

void NewHatchbackForm::on_addToRegisterButton_2_clicked()
{
    int tempInt;
    QString tempQString;

    tempQString = ui->vehicleLenghtLineEdit_2->text();
    try{
        if(!convertToInt(tempQString, tempInt)) {}
    } catch(const std::exception &exc) {
        std::cerr << exc.what();
    }

}

