#ifndef NEWHATCHBACKFORM_H
#define NEWHATCHBACKFORM_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include "VehicleManager.h"
#include "lineEditFunctions.h"

namespace Ui {
class NewHatchbackForm;
}

class NewHatchbackForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewHatchbackForm(QWidget *parent = nullptr);
    ~NewHatchbackForm();
    void setMenager(VehicleManager &rVehicleMenager);

private slots:
    void on_addToRegisterButton_2_clicked();

private:
    Ui::NewHatchbackForm *ui;
    VehicleManager aVehicleMenager;
    Hatchback *apTempHatchback;
    bool aIsEngine = false,
         aIsColor = false,
         aIsWheels = false,
         aIsInterior = false,
         aIsEquipment = false;
};

#endif // NEWHATCHBACKFORM_H
