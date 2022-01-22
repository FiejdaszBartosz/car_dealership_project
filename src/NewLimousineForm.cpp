#include "NewLimousineForm.h"
#include "ui_NewLimousineForm.h"

NewLimousineForm::NewLimousineForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewLimousineForm)
{
    ui->setupUi(this);
}

NewLimousineForm::~NewLimousineForm()
{
    delete ui;
}
