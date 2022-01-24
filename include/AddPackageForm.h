#ifndef ADDPACKAGEFORM_H
#define ADDPACKAGEFORM_H

#include "VehicleManager.h"
#include "MyException.h"
#include <QWidget>
#include <QMessageBox>

namespace Ui {
class AddPackageForm;
}

class AddPackageForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddPackageForm(QWidget *parent = nullptr);
    ~AddPackageForm();
    void setManager(VehicleManager *pVehicleManager);
    void setVehiclePosition(int position);
    void setComboBox();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddPackageForm *ui;
    VehicleManager *apVehicleManager;
    int aVehiclePosition;
    int aSelectedPackage;
};

#endif // ADDPACKAGEFORM_H
