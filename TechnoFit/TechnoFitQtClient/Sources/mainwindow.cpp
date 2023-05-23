#include <QPixmap>
#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"


void plot_axis(QGraphicsScene* scene, QPen& pen, QPointF origin)
{
    qInfo() << origin.x() << origin.y();
	scene->addLine(0, origin.y(), scene->width() - 1, origin.y(), pen);
	scene->addLine(origin.x(), 0, origin.x(), scene->height() - 1, pen);
    QString axis = "x";
	auto xtext = scene->addText(axis);
    xtext->setPos(scene->width() - 15, 290);
	axis = "y";
	auto ytext = scene->addText(axis);
    ytext->setPos(5, scene->height() - 300);
    axis = "origin";
    auto origintext = scene->addText(axis);
    origintext->setPos(origin.x(), origin.y());
}

void plot_grid(QGraphicsScene* scene, QPointF origin, qreal sx, qreal sy, QPen& pen)
{
    qreal x_pix = origin.x();
	for (; x_pix < scene->width(); x_pix += scene->width()/10)
	{
		scene->addLine(x_pix, 0, x_pix, scene->height(), pen);
		QString _coord = QString::number((x_pix - origin.x()) * sx);
		QPointF sceneidvalue(x_pix + 2, 430);
		auto coordtext = scene->addText(_coord);
        coordtext->setPos(sceneidvalue.x(), sceneidvalue.y());
	}	
	for (; x_pix > 0; x_pix -= scene->width() / 10)
	{
		scene->addLine(x_pix, 0, x_pix, scene->height(), pen);
		QString _coord = QString::number((x_pix - origin.x()) * sx);
		QPointF sceneidvalue(x_pix + 2, 430);
        auto coordtext = scene->addText(_coord);
        coordtext->setPos(sceneidvalue.x(), sceneidvalue.y());
	}
	qreal y_pix = origin.y();
	for (; y_pix <= scene->height(); y_pix += scene->width() / 10)
	{
		scene->addLine(0, y_pix, scene->width(), y_pix, pen);
		QString _coord = QString::number((y_pix - origin.y()) * -sy);
		QPointF sceneidvalue(2, y_pix + 2);
        auto coordtext = scene->addText(_coord);
        coordtext->setPos(sceneidvalue.x(), sceneidvalue.y());
	}
	for (; y_pix > 0; y_pix -= scene->width() / 10)
	{
		scene->addLine(0, y_pix, scene->width(), y_pix, pen);
		QString _coord = QString::number((y_pix - origin.y()) * -sy);
		QPointF sceneidvalue(2 , y_pix + 2);
        auto coordtext = scene->addText(_coord);
        coordtext->setPos(sceneidvalue.x(), sceneidvalue.y());
	}	
}

void plot(QGraphicsScene* scene, QPen& axis_pen, QPen& graph_pen, QPen& grid_pen, qreal y_min, qreal y_max, qreal x_min, qreal x_max, QVector<QPointF>& points, qreal time, int counter)
{
    scene->clear();
    qreal width = scene->width();
	qreal height = scene->height();
    qInfo() <<  scene->height() << scene->width();
	qreal sx = (x_max - x_min) / width;
	qreal sy = (y_max - y_min) / height;
    QPointF origin(-x_min / sx, y_max / sy);
	plot_axis(scene, axis_pen, origin);
    plot_grid(scene, origin, sx, sy, grid_pen);
    if(points.size() == 0)
    {

    }
    else
    {
        for(auto it = points.constBegin() + 1; it != points.constEnd(); it++)
        {
            if((*it).x() < time - 20)
            {

            }
            else
            {
                if(time > 20)
                {
                    QPointF prev = *(it - 1);
                    qreal y_pix = (y_max - prev.y()) / sy;
                    qreal y_pix1 = (y_max - (*it).y()) / sy;
                    qInfo() << (*it).x()/sx << y_pix1;
                    scene->addLine((prev.x() - counter)/sx, y_pix, ((*it).x() - counter)/sx, y_pix1, graph_pen);
                }
                else
                {
                    QPointF prev = *(it - 1);
                    qreal y_pix = (y_max - prev.y()) / sy;
                    qreal y_pix1 = (y_max - (*it).y()) / sy;
                    qInfo() << (*it).x()/sx << y_pix1;
                    scene->addLine(prev.x()/sx, y_pix, (*it).x()/sx, y_pix1, graph_pen);
                }
                
            }
        }
    }
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    startrefresh();
    QPixmap pix1(":/img/img/icons8-сердце-с-пульсом-48.png");
    int w = 40;
    int h = 40;
    ui->pulse_pic->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix2(":/img/img/icons8-кислород-64.png");
    ui->O2_pic->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix3(":/img/img/icons8-температура-64.png");
    ui->temprature_pic->setPixmap(pix3.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix4(":/img/img/icons8-ecg-64.png");
    ui->ECG_pic->setPixmap(pix4.scaled(w,h,Qt::KeepAspectRatio));
    scene_pulse = new QGraphicsScene(0, 0, 485, 155, this);
    scene_O2 = new QGraphicsScene(0, 0, 485, 155, this);
    scene_temprature = new QGraphicsScene(0, 0, 485, 155, this);
    scene_ECG = new QGraphicsScene(0, 0, 485, 155, this);
    ui->graphicsView->setScene(scene_pulse);
    ui->graphicsView_2->setScene(scene_O2);
    ui->graphicsView_3->setScene(scene_temprature);
    ui->graphicsView_4->setScene(scene_ECG);
    scene_pulse->addRect(scene_pulse->sceneRect());
    scene_O2->addRect(scene_O2->sceneRect());
    scene_temprature->addRect(scene_temprature->sceneRect());
    scene_ECG->addRect(scene_ECG->sceneRect());
    axis_pen.setColor(Qt::black);
    grid_pen.setColor(Qt::gray);
    pulse_graph_pen.setColor(Qt::red);
    O2_graph_pen.setColor(Qt::blue);
    temprature_graph_pen.setColor(Qt::red);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUseCase(IMetricsUseCase* usecase)
{
    usecase_ = usecase;
}

void MainWindow::setDialog(Dialog* dialog_)
{
    dialog = dialog_;
}

void MainWindow::UpdateResults(IDevice &result)
{
    std::cout << "we came to update results" << std::endl;
    if(time > 20)
    {
        time++;
        counter++;
    }
    else
    {
        time++;
    }
    switch(result.get_type())
    {
    case Standard:
    {
        devices[result.get_id()]->pulselabel->setText(QString::number(result.get_pulse()));
        devices[result.get_id()]->O2label->setText(QString::number(result.get_O2()));
        devices[result.get_id()]->tempraturelabel->setText(QString::number(result.get_temprature()));
        QPointF new_pulsePoint(time, result.get_pulse());
        QPointF new_O2Point(time, result.get_O2());
        QPointF new_tempraturePoint(time, result.get_temprature());
        devices[result.get_id()]->pulse_points.append(new_pulsePoint);
        devices[result.get_id()]->O2_points.append(new_O2Point);
        devices[result.get_id()]->temprature_points.append(new_tempraturePoint);
        break;
    }
        
    case Intensive:
    {
        devices[result.get_id()]->tempraturelabel->setText(QString::number(result.get_temprature()));
        devices[result.get_id()]->ECGlabel->setText(QString::number(result.get_ECG()));
        QPointF new_tempraturePoint(time, result.get_temprature());
        QPointF new_BloodPressurePoint(time, result.get_BloodPressure());
        devices[result.get_id()]->temprature_points.append(new_tempraturePoint);
        devices[result.get_id()]->BloodPressure_points.append(new_BloodPressurePoint);
        break;
    }
        
    case Premium:
    {
        devices[result.get_id()]->pulselabel->setText(QString::number(result.get_pulse()));
        devices[result.get_id()]->O2label->setText(QString::number(result.get_O2()));
        devices[result.get_id()]->tempraturelabel->setText(QString::number(result.get_temprature()));
        devices[result.get_id()]->ECGlabel->setText(QString::number(result.get_ECG()));
        devices[result.get_id()]->BloodPressurelabel->setText(QString::number(result.get_BloodPressure()));
        QPointF new_pulsePoint(time, result.get_pulse());
        QPointF new_O2Point(time, result.get_O2());
        QPointF new_tempraturePoint(time, result.get_temprature());
        QPointF new_ECGPoint(time, result.get_ECG());
        QPointF new_BloodPressurePoint(time, result.get_BloodPressure());
        devices[result.get_id()]->pulse_points.append(new_pulsePoint);
        devices[result.get_id()]->O2_points.append(new_O2Point);
        devices[result.get_id()]->temprature_points.append(new_tempraturePoint);
        devices[result.get_id()]->ECG_points.append(new_ECGPoint);
        devices[result.get_id()]->BloodPressure_points.append(new_BloodPressurePoint);
        break;
    }   
        
    }
    show();
}

void MainWindow::RefreshGUIdata()
{
    if(builded)
        refresh_graph();
    for(int i = 0; i < devices.size(); i++)
        usecase_->RefreshData(i, devices[i]->state); // 
}

void MainWindow::startrefresh()
{
    QTimer* timer = new QTimer(this);
    timer->setInterval(1000);
    connect (timer, SIGNAL(timeout()), this, SLOT(RefreshGUIdata()));
    timer->start(1000);
}

void MainWindow::on_add_device_btn_clicked()
{   
    dialog->show();
}

void MainWindow::createDevice(State state)
{
    switch(state)
    {
    case Standard:
    {
        auto widget = new DeviceCard("test", element_counter, state, usecase_, this);
        widget->setFixedSize(200,250);
        ui->add_layout->insertWidget(element_counter, widget);
        devices.push_back(widget);
        show();
        break;
    }
    case Intensive:
    {
        auto widget = new DeviceCard("test", element_counter, state, usecase_, this);
        widget->setFixedSize(200,250);
        ui->add_layout->insertWidget(element_counter, widget);
        devices.push_back(widget);
        show();
        break;
    }
    case Premium:
    {
        auto widget = new DeviceCard("test", element_counter, state, usecase_, this);
        widget->setFixedSize(200,250);
        ui->add_layout->insertWidget(element_counter, widget);
        devices.push_back(widget);
        show();
        break;
    } 
    }
    element_counter++;
}

void MainWindow::refresh_graph()
{
    switch(type)
    {
    case Standard:
        plot(scene_pulse, axis_pen, pulse_graph_pen, grid_pen, 60, 150, time - 20, time + 20, devices[id]->pulse_points, time, counter);
        plot(scene_O2, axis_pen, O2_graph_pen, grid_pen, 70, 130, time - 20, time + 20, devices[id]->O2_points, time, counter);
        plot(scene_temprature, axis_pen, temprature_graph_pen, grid_pen, 30, 45, time - 20, time + 20, devices[id]->temprature_points, time, counter);
        scene_ECG->clear();
        ui->ECG_pic->setVisible(false);
        ui->pulse_pic->setVisible(true);
        ui->O2_pic->setVisible(true);
        break;
    case Intensive:
        plot(scene_temprature, axis_pen, temprature_graph_pen, grid_pen, 30, 45, time - 20, time + 20, devices[id]->temprature_points, time, counter);
        plot(scene_ECG, axis_pen, temprature_graph_pen, grid_pen, 30, 45, time - 20, time + 20, devices[id]->ECG_points, time, counter);
        scene_pulse->clear();
        scene_O2->clear();
        ui->pulse_pic->setVisible(false);
        ui->O2_pic->setVisible(false);
        ui->ECG_pic->setVisible(true);
        break;
    case Premium:
        plot(scene_pulse, axis_pen, pulse_graph_pen, grid_pen, 60, 150, time - 20, time + 20, devices[id]->pulse_points, time, counter);
        plot(scene_O2, axis_pen, O2_graph_pen, grid_pen, 70, 130, time - 20, time + 20, devices[id]->O2_points, time, counter);
        plot(scene_temprature, axis_pen, temprature_graph_pen, grid_pen, 30, 45, time - 20, time + 20, devices[id]->temprature_points, time, counter);
        plot(scene_ECG, axis_pen, temprature_graph_pen, grid_pen, 0, 45, time - 20, time + 20, devices[id]->ECG_points, time, counter);
        ui->ECG_pic->setVisible(true);
        ui->pulse_pic->setVisible(true);
        ui->O2_pic->setVisible(true);
        break;
    }
}


void MainWindow::change_graph(int id, State type)
{
    this->id = id;
    this->type = type;
    this->builded = true;
    refresh_graph();
}