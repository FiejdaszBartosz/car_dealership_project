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

private:
    Ui::NewSportVehicleForm *ui;
};

#endif // NEWSPORTVEHICLEFORM_H
