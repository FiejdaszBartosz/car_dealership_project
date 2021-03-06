#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "Account.h"
#include "VehicleManager.h"
#include "Vehicle.h"
#include "NewHatchbackForm.h"
#include "NewLimousineForm.h"
#include "NewSportVehicleForm.h"
#include "AddPackageForm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  friend VehicleManager;
  void setManager(VehicleManager &rVehicleManager);
  void setUser(Account *pAccount);

 public:
  Account *pUser;

 private slots:
  void on_addButton_clicked();

  void on_deleteButton_clicked();

  void on_showDetails_clicked();

  void on_actionSave_triggered();

  void on_actionLoad_triggered();

  void listHandling();

  void on_addLimousineButton_clicked();

  void on_addSportVehicleButton_clicked();

  void on_actionReload_triggered();

  void on_addPackageButton_clicked();

private:
  Ui::MainWindow *ui;
  NewHatchbackForm newHatchbackForm;
  NewLimousineForm newLimousineForm;
  NewSportVehicleForm newSportVehicleForm;
  VehicleManager aVehicleMenager;
  AddPackageForm newAddPackageForm;
  QString aDefaultDatabse = "D:\build-jipp_project-Desktop_Qt_6_2_2_MinGW_64_bit-Debug";
};
#endif // MAINWINDOW_H
