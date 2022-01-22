#ifndef NEWSPORTVEHICLEFORM_H
#define NEWSPORTVEHICLEFORM_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include "VehicleManager.h"
#include "lineEditFunctions.h"

namespace Ui {
class NewSportVehicleForm;
}

class NewSportVehicleForm : public QWidget {
 Q_OBJECT

 public:
  explicit NewSportVehicleForm(QWidget *parent = nullptr);
  ~NewSportVehicleForm();
  void setManager(VehicleManager *pVehicleManager);

 private slots:
  void on_addToRegisterButton_2_clicked();

  void on_addEngineButton_2_clicked();

  void on_addColorButton_2_clicked();

  void on_addInteriorButton_2_clicked();

  void on_addWheelsButton_2_clicked();

  void on_addAdditionalEquipment_2_clicked();

  void on_addEngineButton_3_clicked();

 private:
  void setAllIs();

 private:
  Ui::NewSportVehicleForm *ui;
  VehicleManager *apVehicleManager;
  SportVehicle *apTempSportVehicle;
  bool aIsEngine = false,
	  aIsColor = false,
	  aIsWheels = false,
	  aIsInterior = false,
	  aIsEquipment = false,
	  aIsUpgrade = false;
};

#endif // NEWSPORTVEHICLEFORM_H
