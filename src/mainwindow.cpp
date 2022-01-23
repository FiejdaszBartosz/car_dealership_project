#include "../include/mainwindow.h"
#include "../include/Vehicle.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::setManager(VehicleManager &rVehicleManager) {
  this->aVehicleMenager = rVehicleManager;
}

void MainWindow::on_addButton_clicked() {
  newHatchbackForm.setManager(&aVehicleMenager);
  newHatchbackForm.show();
}

void MainWindow::on_changeButton_clicked() {
  QMessageBox::information(this, "information", "Clicked on change");
}

void MainWindow::on_deleteButton_clicked() {
  int i = -1;
  i = ui->listWidget->currentRow();
  if(i != -1){
      qDeleteAll(ui->listWidget->selectedItems());
      this->aVehicleMenager.removeElemnt(i);
  } else {
      QMessageBox::warning(this, "warning", "You haven't selected any item");
      throw MyException("warning",
                        "User hasn't selected any item",
                        "mainwindow.cpp",
                        "on_deleteButton_clicked",
                        "35");
  }


}

void MainWindow::on_showDetails_clicked() {
  int i = -1;
  i = ui->listWidget->currentRow();
  if(i != -1) {
  std::vector<Vehicle *> tempRegister;
  tempRegister = aVehicleMenager.getVehicleRegister();
  std::string informationText = tempRegister.at(i)->showInformation();
  QMessageBox::information(this, "details", QString::fromUtf8(informationText));
  } else {
      QMessageBox::warning(this, "warning", "You haven't selected any item");
      throw MyException("warning",
                        "User hasn't selected any item",
                        "mainwindow.cpp",
                        "on_showDetails_clicked",
                        "56");
  }
}

void MainWindow::on_actionSave_triggered() {
  aVehicleMenager.saveAllVehicle(aDefaultDatabse.toUtf8().constData());
}

void MainWindow::on_actionLoad_triggered() {
  ui->listWidget->clear();
  std::string fileName = QFileDialog::getOpenFileName(this,
													  "Load from database",
													  aDefaultDatabse).toUtf8().constData();
  aVehicleMenager.loadAllVehicle(fileName);
  listHandling();
}

void MainWindow::listHandling() {
  int lenght = aVehicleMenager.getRegisterLenght();
  std::vector<Vehicle *> tempRegister = aVehicleMenager.getVehicleRegister();
  QString tempName;

  for (int i = 0; i < lenght; i++) {
	tempName = QString::fromUtf8(tempRegister.at(i)->getName());
	ui->listWidget->addItem(tempName);
  }
}

void MainWindow::on_addLimousineButton_clicked() {
  newLimousineForm.setManager(&aVehicleMenager);
  newLimousineForm.show();
}

void MainWindow::on_addSportVehicleButton_clicked() {
  newSportVehicleForm.setManager(&aVehicleMenager);
  newSportVehicleForm.show();
}

void MainWindow::on_actionReload_triggered() {
  ui->listWidget->clear();
  listHandling();
}

void MainWindow::setUser(Account *pAccount) {
    this->pUser = pAccount;
}
