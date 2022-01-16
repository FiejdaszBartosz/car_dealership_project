#include "NewHatchbackForm.h"
#include "ui_NewHatchbackForm.h"

NewHatchbackForm::NewHatchbackForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewHatchbackForm)
{
    ui->setupUi(this);
    apTempHatchback = new Hatchback;
}

NewHatchbackForm::~NewHatchbackForm()
{
    delete ui;
    delete apTempHatchback;
}

void NewHatchbackForm::setMenager(VehicleManager &rVehicleMenager) {
    this->aVehicleMenager = rVehicleMenager;
}

void NewHatchbackForm::on_addToRegisterButton_2_clicked()
{
    int tempInt = 0;
    QString tempQString;
    std::string tempString;
    bool checkInput;

    tempQString = ui->nameLineEdit_2->text();                               //name reading
    try{
        convertToString(tempQString, tempString);
    } catch(const std::exception &exc) {
        std::cerr << "During name reading\n";
        std::cerr << exc.what();
        QMessageBox::warning(this, "warning", "Incorect name value");
    }
    apTempHatchback->setName(tempString);

    tempQString = ui->productionYearLineEdit_2->text();
    try{
        convertToInt(tempQString, tempInt);                                //year reading
    } catch(const std::exception &exc) {
        std::cerr << "During year reading\n";
        std::cerr << exc.what();
        QMessageBox::warning(this, "warning", "Incorect year value");
    }
    try{
        validateYear(tempInt);
    } catch(const std::exception &exc) {
        std::cerr << "During year validation\n";
        std::cerr << exc.what();
        QMessageBox::warning(this, "warning", "Incorect year value");
    }
    apTempHatchback->setProductionYear(tempInt);

    tempQString = ui->vehicleLenghtLineEdit_2->text();
    try{
        convertToInt(tempQString, tempInt);
    } catch(const std::exception &exc) {
        std::cerr << "During lenght reading\n";
        std::cerr << exc.what();
        QMessageBox::warning(this, "warning", "Incorect lenght value");
    }
    apTempHatchback->setVehicleLength(tempInt);
}

