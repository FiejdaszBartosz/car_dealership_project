#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include "Account.h"
#include "mainwindow.h"

namespace Ui {
class LogIn;
}

class LogIn : public QWidget
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();
    Account getUser();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LogIn *ui;
    Account aUser;
    MainWindow newMainWindow;
    bool isUsername = false, isPassword = false;
};

#endif // LOGIN_H
