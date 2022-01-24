#include "AddPackageForm.h"
#include "ui_AddPackageForm.h"

/**
  * @brief constructor - creates ui, sets default attributes value
  * @param parent - ui parent
*/
AddPackageForm::AddPackageForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::AddPackageForm) {
  ui->setupUi(this);

  apVehicleManager = nullptr;
  aVehiclePosition = -1;
  aSelectedPackage = -1;
}

/**
  * @brief destructor - delete ui
*/
AddPackageForm::~AddPackageForm() {
  delete ui;
}

/**
  * @brief sets local vehicle manager
  * @param pVehicleManager - pointer to main manager
*/
void AddPackageForm::setManager(VehicleManager *pVehicleManager) {
  this->apVehicleManager = pVehicleManager;
}

/**
  * @brief sets local vehicle manager
  * @param position - position of vehicle in manager
*/
void AddPackageForm::setVehiclePosition(int position) {
  aVehiclePosition = position;
}

/**
  * @brief sets combo box form class attributes
*/
void AddPackageForm::setComboBox() {
  if (aVehiclePosition == -1 && apVehicleManager == nullptr)
	throw MyException("critical",
					  "Position or vehicle manager weren't set",
					  "AddPackageForm.cpp",
					  "setComboBox",
					  "45");
  else {
	if (apVehicleManager->getVehicleRegister().at(aVehiclePosition)->showPackage(aVehiclePosition) == "error")
	  throw MyException("critical",
						"The chosen vehicle isn't sport vehicle",
						"AddPackageForm.cpp",
						"setComboBox",
						"52");
	else if (apVehicleManager->getVehicleRegister().at(aVehiclePosition)->showPackage(aVehiclePosition)
		== "sport vehicle") {
	  std::vector<engineProperties>
		  tempPackage = apVehicleManager->getVehicleRegister().at(aVehiclePosition)->getEnginePackage();
	  for (auto i = tempPackage.begin(); i < tempPackage.end(); ++i) {
		QString tempQString;
		std::string tempString;

		tempString += "HP = ";
		tempString += std::to_string(i->hp);
		tempString += " Nm = ";
		tempString += std::to_string(i->nm);
		tempQString = QString::fromStdString(tempString);
		ui->comboBox->addItem(tempQString);
	  }
	} else {
	  throw MyException("critical",
						"Unknown vehicle type",
						"AddPackageForm.cpp",
						"setComboBox",
						"58");
	}
  }
}

/**
  * @brief adds engine package to engine and sets it as a new engine
*/
void AddPackageForm::on_pushButton_clicked() {
  std::vector<engineProperties> temp = apVehicleManager->getVehicleRegister().at(aVehiclePosition)->getEngine();
  engineProperties tempEnginePackage =
	  apVehicleManager->getVehicleRegister().at(aVehiclePosition)->getEnginePackage().at(ui->comboBox->currentIndex());
  for (auto &var : temp)
	var += tempEnginePackage;

  apVehicleManager->getVehicleRegister().at(aVehiclePosition)->setEngine(temp);
  apVehicleManager->getVehicleRegister().at(aVehiclePosition)->setIsPackageAdded();
  QMessageBox::information(this, "Information", "Package set");
  this->close();
}

