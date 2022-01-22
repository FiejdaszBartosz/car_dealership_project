#include "NewHatchbackForm.h"
#include "ui_NewHatchbackForm.h"

NewHatchbackForm::NewHatchbackForm(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::NewHatchbackForm) {
  ui->setupUi(this);
  apTempHatchback = new Hatchback;
  ui->fuelTypeComboBox_2->addItem("petrol");
  ui->fuelTypeComboBox_2->addItem("diesel");
  ui->fuelTypeComboBox_2->addItem("electric");
}

NewHatchbackForm::~NewHatchbackForm() {
  delete ui;
  delete apTempHatchback;
}

void NewHatchbackForm::setManager(VehicleManager *pVehicleManager) {
  this->apVehicleManager = pVehicleManager;
}

void NewHatchbackForm::setAllIs() {
  aIsEngine = false;
  aIsColor = false;
  aIsWheels = false;
  aIsInterior = false;
  aIsEquipment = false;
}

void NewHatchbackForm::on_addToRegisterButton_2_clicked() {
  int tempInt = 0, tempInt1 = 0, tempInt2 = 0;
  QString tempQString;
  std::string tempString;
  bool checkInput = true, add = false, add1 = false, add2 = false,
	  add3 = false, setIntersection = false, setUnion = false;

  tempQString = ui->nameLineEdit_2->text();                                           //name reading
  try {
	convertToString(tempQString, tempString);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During name reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect name");
  }
  apTempHatchback->setName(tempString);

  tempQString = ui->productionYearLineEdit_2->text();                                 //year reading
  try {
	convertToInt(tempQString, tempInt);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During year reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect year value");
  }
  try {
	validateYear(tempInt);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During year validation\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect year value");
  }
  apTempHatchback->setProductionYear(tempInt);                                        //lenght reading

  tempQString = ui->vehicleLenghtLineEdit_2->text();
  try {
	convertToInt(tempQString, tempInt);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During lenght reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect lenght value");
  }
  apTempHatchback->setVehicleLength(tempInt);

  tempQString = ui->hpLineEdit_2->text();                                             //engine reading
  try {
	convertToInt(tempQString, tempInt, aIsEngine, add);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During hp reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect hp value");
  }

  tempQString = ui->nmLineEdit_4->text();
  try {
	convertToInt(tempQString, tempInt1, aIsEngine, add1);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During nm reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect nm value");
  }

  tempQString = ui->fuelTypeComboBox_2->currentText();
  try {
	convertToString(tempQString, tempString, aIsEngine, add2);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During petrol type reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Unexpected error during petrol reading");
  }

  tempQString = ui->priceLineEdit_2->text();
  try {
	convertToInt(tempQString, tempInt2, aIsEngine, add3);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect price value");
  }

  setIntersection = (add && add1 && add3);
  setUnion = (add || add1 || add3);

  if (checkInput == true && setIntersection == true)
	apTempHatchback->addEngine(tempInt, tempInt1, tempString, tempInt2);
  if (setIntersection == false && setUnion == true) {
	QMessageBox::warning(this, "warning", "Incomplete engine");
	checkInput = false;
  }

  tempQString = ui->colorNameLineEdit_2->text();                                       //color reading
  try {
	convertToString(tempQString, tempString, aIsColor, add);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During color name reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect color name");
  }

  tempQString = ui->colorPriceLineEdit_8->text();
  try {
	convertToInt(tempQString, tempInt, aIsEngine, add1);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During color price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect color price value");
  }

  setIntersection = (add && add1);
  setUnion = (add || add1);

  if (checkInput == true && setIntersection == true)
	apTempHatchback->addColor(tempString, tempInt);
  if (setIntersection == false && setUnion == true) {
	QMessageBox::warning(this, "warning", "Incomplete color");
	checkInput = false;
  }

  tempQString = ui->wheelsSizeLineEdit_14->text();                                     //wheels reading
  try {
	convertToString(tempQString, tempString, aIsColor, add);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During wheels size reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect wheels size");
  }

  tempQString = ui->wheelsPriceLineEdit_15->text();
  try {
	convertToInt(tempQString, tempInt, aIsEngine, add1);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect wheels price value");
  }

  setIntersection = (add && add1);
  setUnion = (add || add1);

  if (checkInput == true && setIntersection == true)
	apTempHatchback->addWheels(tempString, tempInt);
  if (setIntersection == false && setUnion == true) {
	QMessageBox::warning(this, "warning", "Incomplete wheels");
	checkInput = false;
  }

  tempQString = ui->interioTrimLineEdit_2->text();                                     //interior reading
  try {
	convertToString(tempQString, tempString, aIsColor, add);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During interior trim reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect interior trim size");
  }

  tempQString = ui->interiorPriceLineEdit_2->text();
  try {
	convertToInt(tempQString, tempInt, aIsEngine, add1);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During interior trim price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect interior trim price value");
  }

  setIntersection = (add && add1);
  setUnion = (add || add1);

  if (checkInput == true && setIntersection == true)
	apTempHatchback->addInterior(tempString, tempInt);
  if (setIntersection == false && setUnion == true) {
	QMessageBox::warning(this, "warning", "Incomplete interior");
	checkInput = false;
  }

  tempQString = ui->equipmentLineEdit_2->text();                                     //additional equipment reading
  try {
	convertToString(tempQString, tempString, aIsColor, add);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During additional equipment reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect additional equipment name");
  }

  tempQString = ui->equipmentPriceLineEdit_2->text();
  try {
	convertToInt(tempQString, tempInt, aIsEngine, add1);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During additional equipment price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect additional equipment price value");
  }

  setIntersection = (add && add1);
  setUnion = (add || add1);

  if (checkInput == true && setIntersection == true)
	apTempHatchback->addAdditionalEquipment(tempString, tempInt);
  if (setIntersection == false && setUnion == true) {
	QMessageBox::warning(this, "warning", "Incomplete additional equipment");
	checkInput = false;
  }

  if (checkInput == true) {
	apVehicleMenager->addElemnt(apTempHatchback);
	setAllIs();
	ui->hpLineEdit_2->clear();
	ui->nmLineEdit_4->clear();
	ui->priceLineEdit_2->clear();
	ui->colorNameLineEdit_2->clear();
	ui->colorPriceLineEdit_8->clear();
	ui->wheelsSizeLineEdit_14->clear();
	ui->wheelsPriceLineEdit_15->clear();
	ui->equipmentLineEdit_2->clear();
	ui->equipmentPriceLineEdit_2->clear();
  }
}

void NewHatchbackForm::on_addEngineButton_2_clicked() {
  int tempInt = 0, tempInt1 = 0, tempInt2 = 0;
  QString tempQString;
  std::string tempString;
  bool checkInput = true;

  tempQString = ui->hpLineEdit_2->text();
  try {
	convertToInt(tempQString, tempInt, aIsEngine);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During hp reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect hp value");
  }

  tempQString = ui->nmLineEdit_4->text();
  try {
	convertToInt(tempQString, tempInt1, aIsEngine);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During nm reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect nm value");
  }

  tempQString = ui->fuelTypeComboBox_2->currentText();
  try {
	convertToString(tempQString, tempString, aIsEngine);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During petrol type reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Unexpected error during petrol reading");
  }

  tempQString = ui->priceLineEdit_2->text();
  try {
	convertToInt(tempQString, tempInt2, aIsEngine);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During engine price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect engine price value");
  }

  if (checkInput == true)
	apTempHatchback->addEngine(tempInt, tempInt1, tempString, tempInt2);

  ui->hpLineEdit_2->clear();
  ui->nmLineEdit_4->clear();
  ui->priceLineEdit_2->clear();

  aIsEngine = true;
}

void NewHatchbackForm::on_addColorButton_2_clicked() {
  int tempInt = 0;
  QString tempQString;
  std::string tempString;
  bool checkInput = true;

  tempQString = ui->colorNameLineEdit_2->text();

  try {
	convertToString(tempQString, tempString, aIsColor);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During color reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect color value");
  }

  tempQString = ui->colorPriceLineEdit_8->text();
  try {
	convertToInt(tempQString, tempInt, aIsColor);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During color price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect color price value");
  }

  if (checkInput == true)
	apTempHatchback->addColor(tempString, tempInt);

  ui->colorNameLineEdit_2->clear();
  ui->colorPriceLineEdit_8->clear();

  aIsColor = true;
}

void NewHatchbackForm::on_addWheelsButton_2_clicked() {
  int tempInt = 0;
  QString tempQString;
  std::string tempString;
  bool checkInput = true;

  tempQString = ui->wheelsSizeLineEdit_14->text();

  try {
	convertToString(tempQString, tempString, aIsWheels);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During wheels size reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect wheels size value");
  }

  tempQString = ui->wheelsPriceLineEdit_15->text();
  try {
	convertToInt(tempQString, tempInt, aIsWheels);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During wheels price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect wheels price value");
  }

  if (checkInput == true)
	apTempHatchback->addWheels(tempString, tempInt);

  ui->wheelsSizeLineEdit_14->clear();
  ui->wheelsPriceLineEdit_15->clear();

  aIsWheels = true;
}

void NewHatchbackForm::on_addInteriorButton_2_clicked() {
  int tempInt = 0;
  QString tempQString;
  std::string tempString;
  bool checkInput = true;

  tempQString = ui->interioTrimLineEdit_2->text();

  try {
	convertToString(tempQString, tempString, aIsInterior);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During interior trim reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect interior trim value");
  }

  tempQString = ui->interiorPriceLineEdit_2->text();
  try {
	convertToInt(tempQString, tempInt, aIsInterior);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During interior price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect interior price value");
  }

  if (checkInput == true)
	apTempHatchback->addInterior(tempString, tempInt);

  ui->interioTrimLineEdit_2->clear();
  ui->interiorPriceLabel_2->clear();

  aIsInterior = true;
}

void NewHatchbackForm::on_addAdditionalEquipment_2_clicked() {
  int tempInt = 0;
  QString tempQString;
  std::string tempString;
  bool checkInput = true;

  tempQString = ui->equipmentLineEdit_2->text();

  try {
	convertToString(tempQString, tempString, aIsEquipment);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During additional equipment reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect additional equipment value");
  }

  tempQString = ui->equipmentPriceLineEdit_2->text();
  try {
	convertToInt(tempQString, tempInt, aIsEquipment);
  } catch (const std::exception &exc) {
	checkInput = false;
	std::cerr << "During additional equipment price reading\n";
	std::cerr << exc.what();
	QMessageBox::warning(this, "warning", "Incorect additional equipment price value");
  }

  if (checkInput == true)
	apTempHatchback->addAdditionalEquipment(tempString, tempInt);

  ui->equipmentLineEdit_2->clear();
  ui->equipmentPriceLineEdit_2->clear();

  aIsEquipment = true;
}

