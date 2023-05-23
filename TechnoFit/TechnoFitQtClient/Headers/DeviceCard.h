#pragma once
#include <QtWidgets>
#include "../UseCase/IMetricsUseCase.h"
#include "header.h"
#include <iostream>
class DeviceCard : public QWidget
{
public:
    DeviceCard(const QString& name, int id, State state, IMetricsUseCase* usecase, QWidget* parent = nullptr) : QWidget(parent)
    {
        this->state = state;
        this->id = id;
        this->usecase_ = usecase;
        QPointF first(0,70);
        pulse_points.append(first);
        O2_points.append(first);
        temprature_points.append(first);
        ECG_points.append(first);
        BloodPressure_points.append(first);
        name_btn = new QPushButton(name);
        QObject::connect(name_btn, &QPushButton::clicked, [=]() {
            this->usecase_->change_graph(this->id, this->state);
        });
        name_btn->setStyleSheet(
"QPushButton"
"{"
	"background-color: rgb(246, 245, 244);"
	"border: 1px solid rgb(246, 245, 244);"
	"border-radius: 10px;"
	"border-width: 5px;"
    "font: 20pt;"
"}"
"QPushButton:hover"
"{"
"	background-color: rgb(222, 221, 218);"
"	border: 1px solid rgb(222, 221, 218);"
"	border-radius: 10px;"
"}");
        pulselabel = new QLabel(": 0");
        O2label = new QLabel(": 0");
        tempraturelabel = new QLabel(": 0");
        ECGlabel = new QLabel(": 0");
        BloodPressurelabel = new QLabel(": 0");
        pulsepicture = new QLabel(); 
        O2picture = new QLabel();
        tempraturepicture = new QLabel();
        ECGpicture = new QLabel("test");
        BloodPressurepicture = new QLabel("test");
        QPixmap pix1(":/img/img/icons8-сердце-с-пульсом-48.png");
        int w = 40;
        int h = 40;
        pulsepicture->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pix2(":/img/img/icons8-кислород-64.png");
        O2picture->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pix3(":/img/img/icons8-температура-64.png");
        tempraturepicture->setPixmap(pix3.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pix4(":/img/img/icons8-ecg-64.png");
        ECGpicture->setPixmap(pix4.scaled(w,h,Qt::KeepAspectRatio));
        QPixmap pix5(":/img/img/icons8-tonometer-64.png");
        BloodPressurepicture->setPixmap(pix5.scaled(w,h,Qt::KeepAspectRatio));
        auto main_layout = new QVBoxLayout(this);
        auto field_temprature_layout = new QHBoxLayout(this);
        switch(state)
        {
        case Standard:
        {
            auto field_pulse_layout = new QHBoxLayout(this);
            auto field_O2_layout = new QHBoxLayout(this);
            main_layout->addWidget(name_btn);
            main_layout->addLayout(field_pulse_layout);
            main_layout->addLayout(field_O2_layout);
            main_layout->addLayout(field_temprature_layout);
            field_pulse_layout->addWidget(pulsepicture);
            field_pulse_layout->addWidget(pulselabel);
            field_O2_layout->addWidget(O2picture);
            field_O2_layout->addWidget(O2label);
            field_temprature_layout->addWidget(tempraturepicture);
            field_temprature_layout->addWidget(tempraturelabel);
            break;
        }
            
        case Intensive:
        {
            auto field_ECG_layout = new QHBoxLayout(this);
            main_layout->addWidget(name_btn);
            main_layout->addLayout(field_temprature_layout);
            main_layout->addLayout(field_ECG_layout);
            field_temprature_layout->addWidget(tempraturepicture);
            field_temprature_layout->addWidget(tempraturelabel);
            field_ECG_layout->addWidget(ECGpicture);
            field_ECG_layout->addWidget(ECGlabel);
            break;
        }
        case Premium:
        {
            auto field_pulse_layout = new QHBoxLayout(this);
            auto field_O2_layout = new QHBoxLayout(this);
            auto field_ECG_layout = new QHBoxLayout(this);
            auto field_BloodPressure_layout = new QHBoxLayout(this);
            main_layout->addWidget(name_btn);
            main_layout->addLayout(field_pulse_layout);
            main_layout->addLayout(field_O2_layout);
            main_layout->addLayout(field_temprature_layout);
            main_layout->addLayout(field_ECG_layout);
            main_layout->addLayout(field_BloodPressure_layout);
            field_pulse_layout->addWidget(pulsepicture);
            field_pulse_layout->addWidget(pulselabel);
            field_O2_layout->addWidget(O2picture);
            field_O2_layout->addWidget(O2label);
            field_temprature_layout->addWidget(tempraturepicture);
            field_temprature_layout->addWidget(tempraturelabel);
            field_ECG_layout->addWidget(ECGpicture);
            field_ECG_layout->addWidget(ECGlabel);
            field_BloodPressure_layout->addWidget(BloodPressurepicture);
            field_BloodPressure_layout->addWidget(BloodPressurelabel);
            break;
        }    
        }
    }
    void setUseCase(IMetricsUseCase* usecase)
    {
        usecase_ = usecase;
    }
private slots:
    void on_name_btn_clicked()
    {
        std::cout << "clicked" << this->id << " " << this->state << std::endl;
        this->usecase_->change_graph(this->id, this->state);
    }
public:
    IMetricsUseCase* usecase_;
    QPushButton* name_btn;
    QLabel* pulselabel;
    QLabel* O2label;
    QLabel* tempraturelabel;
    QLabel* ECGlabel;
    QLabel* BloodPressurelabel;
    QLabel* pulsepicture;
    QLabel* O2picture;
    QLabel* tempraturepicture;
    QLabel* ECGpicture;
    QLabel* BloodPressurepicture;
    QVector<QPointF> pulse_points;
    QVector<QPointF> O2_points;
    QVector<QPointF> temprature_points;
    QVector<QPointF> ECG_points;
    QVector<QPointF> BloodPressure_points;
    State state;
    int id;
private:

};