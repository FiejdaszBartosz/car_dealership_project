#include "LogIn.h"
#include "ui_LogIn.h"


LogIn::LogIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
}

LogIn::~LogIn()
{
    delete ui;
}

Account LogIn::getUser() {
    return aUser;
}

void LogIn::on_pushButton_clicked()
{
    QString tempUsername, tempPassword;
    tempUsername = ui->usernameLineEdit->text();
    if(tempUsername != "")
        isUsername = true;
    tempPassword = ui->passwordLineEdit->text();
    if(tempPassword != "")
        isPassword = true;

    if(isUsername && isPassword){
        if(tempUsername == "admin" && tempPassword == "admin"){
            aUser.setAdmin();
            newMainWindow.setUser(&aUser);
            newMainWindow.show();
            this->close();
        }
        else if(tempUsername == "user" && tempPassword == "user"){
            aUser.setNormalUser();      
            newMainWindow.setUser(&aUser);
            newMainWindow.show();
            this->close();
        }
        else
            QMessageBox::warning(this, "Warning", "Unknown user");
    } else
        QMessageBox::warning(this, "Warning", "Input is empty");
}

