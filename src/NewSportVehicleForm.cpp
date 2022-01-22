#include "NewSportVehicleForm.h"
#include "ui_NewSportVehicleForm.h"

NewSportVehicleForm::NewSportVehicleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewSportVehicleForm)
{
    ui->setupUi(this);
}

NewSportVehicleForm::~NewSportVehicleForm()
{
    delete ui;
}
