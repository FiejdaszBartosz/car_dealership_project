#ifndef NEWLIMOUSINEFORM_H
#define NEWLIMOUSINEFORM_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include "VehicleManager.h"
#include "lineEditFunctions.h"

namespace Ui {
class NewLimousineForm;
}

class NewLimousineForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewLimousineForm(QWidget *parent = nullptr);
    ~NewLimousineForm();
    void setMenager(VehicleManager &rVehicleMenager);

private slots:
    void on_addEngineButton_2_clicked();

    void on_addColorButton_2_clicked();

    void on_addInteriorButton_2_clicked();

    void on_addWheelsButton_2_clicked();

    void on_addAdditionalEquipment_2_clicked();

    void on_addToRegisterButton_2_clicked();

private:
    void setAllIs();

private:
    Ui::NewLimousineForm *ui;
    VehicleManager aVehicleMenager;
    Limousine *apTempLimousine;

    bool aIsEngine = false,
         aIsColor = false,
         aIsWheels = false,
         aIsInterior = false,
         aIsEquipment = false,
         aIsLongClicked = false;
};

#endif // NEWLIMOUSINEFORM_H
