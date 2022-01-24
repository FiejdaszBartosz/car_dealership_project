#include "LogIn.h"
#include "ui_LogIn.h"

/**
  * @brief constructor - creates ui
  * @param parent - ui parent
*/
LogIn::LogIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
}

/**
  * @brief destructor - delete ui
*/
LogIn::~LogIn()
{
    delete ui;
}

/**
  * @returns user Account object
*/
Account LogIn::getUser() {
    return aUser;
}

/**
  * @brief checks username and password after clicking push button
*/
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

