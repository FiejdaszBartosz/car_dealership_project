#include "../include/mainwindow.h"
#include "../include/Vehicle.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  timer = new QTimer(this);

}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::setMenager(VehicleManager &rVehicleMenager) {
    this->aVehicleMenager = rVehicleMenager;
}

void MainWindow::on_addButton_clicked()
{
    QMessageBox::information(this,"information", "Clicked on add");
}


void MainWindow::on_changeButton_clicked()
{
    QMessageBox::information(this,"information", "Clicked on change");
}


void MainWindow::on_deleteButton_clicked()
{
    QMessageBox::information(this,"information", "Clicked on delete");
}


void MainWindow::on_showDetails_clicked()
{
    QMessageBox::information(this,"information", "Clicked on showDetails");
}


void MainWindow::on_actionSave_triggered()
{
    aVehicleMenager.saveAllVehicle(aDefaultDatabse.toStdString());
}


void MainWindow::on_actionLoad_triggered()
{
    std::string fileName = QFileDialog::getOpenFileName(this,
                                                    "Load from database",
                                                     aDefaultDatabse).toStdString();
    aVehicleMenager.loadAllVehicle(fileName);
    listHandling();
}

void MainWindow::listHandling(){
    int lenght = aVehicleMenager.getRegisterLenght();
    std::vector<Vehicle *> tempRegister = aVehicleMenager.getVehicleRegister();
    QString tempName;

    for(int i = 0; i < lenght; i++){
      tempName = QString::fromUtf8(tempRegister.at(i)->getName());
      ui->listWidget->addItem(tempName);
    }
}
