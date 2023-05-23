#pragma once
#include <QDialog>
#include <iostream>
#include "header.h"
#include "../Sources/ui_dialog.h"
#include "../UseCase/IMetricsUseCase.h"



QT_BEGIN_NAMESPACE
namespace Ui 
{
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QWidget* parent = nullptr);
    ~Dialog();
    void setUseCase(IMetricsUseCase* usecase)
    {
        usecase_ = usecase;
    }
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Dialog* ui;
    IMetricsUseCase* usecase_;
};