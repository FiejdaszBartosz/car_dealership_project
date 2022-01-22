#ifndef NEWSPORTVEHICLEFORM_H
#define NEWSPORTVEHICLEFORM_H

#include <QWidget>

namespace Ui {
class NewSportVehicleForm;
}

class NewSportVehicleForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewSportVehicleForm(QWidget *parent = nullptr);
    ~NewSportVehicleForm();

private slots:
    void on_addToRegisterButton_2_clicked();

    void on_addEngineButton_2_clicked();

    void on_addColorButton_2_clicked();

    void on_addInteriorButton_2_clicked();

    void on_addWheelsButton_2_clicked();

    void on_addAdditionalEquipment_2_clicked();

private:
    Ui::NewSportVehicleForm *ui;
};

#endif // NEWSPORTVEHICLEFORM_H
