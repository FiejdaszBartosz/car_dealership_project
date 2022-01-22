#ifndef NEWLIMOUSINEFORM_H
#define NEWLIMOUSINEFORM_H

#include <QWidget>

namespace Ui {
class NewLimousineForm;
}

class NewLimousineForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewLimousineForm(QWidget *parent = nullptr);
    ~NewLimousineForm();

private:
    Ui::NewLimousineForm *ui;
};

#endif // NEWLIMOUSINEFORM_H
