#include "../include/mainwindow.h"
#include "./ui_mainwindow.h"

/**
  * @brief constructor - creates ui
  * @param parent - ui parent
*/
MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

}

/**
  * @brief destructor - delete ui
*/
MainWindow::~MainWindow() {
  delete ui;
}

/**
  * @brief sets local vehicle manager
  * @param pVehicleManager - pointer to main manager
*/
void MainWindow::setManager(VehicleManager &rVehicleManager) {
  this->aVehicleMenager = rVehicleManager;
}

/**
  * @brief checks right, sets hatchback manager, opens new hatchback form
*/
void MainWindow::on_addButton_clicked() {
  if (pUser->getRightOnPosition(0)) {
	newHatchbackForm.setManager(&aVehicleMenager);
	newHatchbackForm.show();
  } else
	QMessageBox::critical(this, "Permission denied", "You are not allowed to do this action");
}

/**
  * @brief checks right, deletes vehicle form vector
*/
void MainWindow::on_deleteButton_clicked() {
  int i = -1;
  if (pUser->getRightOnPosition(5)) {
	if (ui->listWidget->count() != 0) {
	  i = ui->listWidget->currentRow();
	  if (i != -1) {
		qDeleteAll(ui->listWidget->selectedItems());
		this->aVehicleMenager.removeElemnt(i);
	  } else {
		QMessageBox::warning(this, "warning", "You haven't selected any item");
		throw MyException("warning",
						  "User hasn't selected any item",
						  "mainwindow.cpp",
						  "on_deleteButton_clicked",
						  "48");
	  }
	} else
	  QMessageBox::warning(this, "warning", "List is empty");
  } else
	QMessageBox::critical(this, "Permission denied", "You are not allowed to do this action");

}

/**
  * @brief checks right, shows vehicle properties form vector
*/
void MainWindow::on_showDetails_clicked() {
  int i = -1;
  if (pUser->getRightOnPosition(3)) {
	if (ui->listWidget->count() != 0) {
	  i = ui->listWidget->currentRow();
	  if (i != -1) {
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
						  "74");
	  }
	} else
	  QMessageBox::warning(this, "warning", "List is empty");
  } else {
	QMessageBox::critical(this, "Permission denied", "You are not allowed to do this action");
  }
}

/**
  * @brief checks right, saves vehicle to file
*/
void MainWindow::on_actionSave_triggered() {
  if (pUser->getRightOnPosition(7)) {
	std::string fileName = QFileDialog::getOpenFileName(this,
														"Load from database",
														aDefaultDatabse).toUtf8().constData();
	aVehicleMenager.saveAllVehicle(fileName);
  } else
	QMessageBox::critical(this, "Permission denied", "You are not allowed to do this action");
}

/**
  * @brief checks right, loads vehicle from file
*/
void MainWindow::on_actionLoad_triggered() {
  if (pUser->getRightOnPosition(6)) {
	ui->listWidget->clear();
	std::string fileName = QFileDialog::getOpenFileName(this,
														"Load from database",
														aDefaultDatabse).toUtf8().constData();
	aVehicleMenager.loadAllVehicle(fileName);
	listHandling();
  } else
	QMessageBox::critical(this, "Permission denied", "You are not allowed to do this action");
}

/**
  * @brief adds items to listWidget
*/
void MainWindow::listHandling() {
  int length = aVehicleMenager.getRegisterLenght();
  std::vector<Vehicle *> tempRegister = aVehicleMenager.getVehicleRegister();
  QString tempName;

  for (int i = 0; i < length; i++) {
	tempName = QString::fromUtf8(tempRegister.at(i)->getName());
	ui->listWidget->addItem(tempName);
  }
}

/**
  * @brief checks right, sets limousine manager, opens new limousine form
*/
void MainWindow::on_addLimousineButton_clicked() {
  if (pUser->getRightOnPosition(1)) {
	newLimousineForm.setManager(&aVehicleMenager);
	newLimousineForm.show();
  } else
	QMessageBox::critical(this, "Permission denied", "You are not allowed to do this action");
}

/**
  * @brief checks right, sets sport vehicle manager, opens new sport vehicle form
*/
void MainWindow::on_addSportVehicleButton_clicked() {
  if (pUser->getRightOnPosition(2)) {
	newSportVehicleForm.setManager(&aVehicleMenager);
	newSportVehicleForm.show();
  } else
	QMessageBox::critical(this, "Permission denied", "You are not allowed to do this action");
}

/**
  * @brief reloads listWidget
*/
void MainWindow::on_actionReload_triggered() {
  ui->listWidget->clear();
  listHandling();
}

/**
  * @brief sets account
  * @param pAccount - pointer to account
*/
void MainWindow::setUser(Account *pAccount) {
  this->pUser = pAccount;
}

/**
  * @brief checks right, opens newAddPackageForm after choosing sport vehicle
*/
void MainWindow::on_addPackageButton_clicked() {
  int i = -1;
  if (pUser->getRightOnPosition(4)) {
	if (ui->listWidget->count() != 0) {
	  i = ui->listWidget->currentRow();
	  if (i != -1) {
		if (aVehicleMenager.getVehicleRegister().at(i)->getType() == "sportVehicle") {
		  if (!aVehicleMenager.getVehicleRegister().at(i)->getIsPackageAdded()) {
			newAddPackageForm.setManager(&aVehicleMenager);
			newAddPackageForm.setVehiclePosition(i);
			try {
			  newAddPackageForm.setComboBox();
			} catch (const std::exception &exc) {
			  std::cerr << "During setting combo box\n";
			  std::cerr << exc.what();
			  QMessageBox::warning(this, "critical", "Invalid Vehicle");
			}
			newAddPackageForm.show();
		  } else
			QMessageBox::warning(this, "warning", "Package has already been added");
		} else
		  QMessageBox::warning(this, "warning", "You haven't selected sport vehicle");

	  } else {
		QMessageBox::warning(this, "warning", "You haven't selected any item");
		throw MyException("warning",
						  "User hasn't selected any item",
						  "mainwindow.cpp",
						  "on_addPackageButton_clicked",
						  "56");
	  }
	} else
	  QMessageBox::warning(this, "warning", "List is empty");
  } else
	QMessageBox::critical(this, "Permission denied", "You are not allowed to do this action");
}

