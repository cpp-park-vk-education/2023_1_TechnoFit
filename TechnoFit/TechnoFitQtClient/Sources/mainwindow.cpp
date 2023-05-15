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
	for (x_pix; x_pix < scene->width(); x_pix += scene->width()/10)
	{
		scene->addLine(x_pix, 0, x_pix, scene->height(), pen);
		QString _coord = QString::number((x_pix - origin.x()) * sx);
		QPointF sceneidvalue(x_pix + 2, 430);
		auto coordtext = scene->addText(_coord);
        coordtext->setPos(sceneidvalue.x(), sceneidvalue.y());
	}	
	for (x_pix; x_pix > 0; x_pix -= scene->width() / 10)
	{
		scene->addLine(x_pix, 0, x_pix, scene->height(), pen);
		QString _coord = QString::number((x_pix - origin.x()) * sx);
		QPointF sceneidvalue(x_pix + 2, 430);
        auto coordtext = scene->addText(_coord);
        coordtext->setPos(sceneidvalue.x(), sceneidvalue.y());
	}
	qreal y_pix = origin.y();
	for (y_pix; y_pix <= scene->height(); y_pix += scene->width() / 10)
	{
		scene->addLine(0, y_pix, scene->width(), y_pix, pen);
		QString _coord = QString::number((y_pix - origin.y()) * -sy);
		QPointF sceneidvalue(2, y_pix + 2);
        auto coordtext = scene->addText(_coord);
        coordtext->setPos(sceneidvalue.x(), sceneidvalue.y());
	}
	for (y_pix; y_pix > 0; y_pix -= scene->width() / 10)
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
    QPixmap pix1(":/img/img/icons8-сердце-с-пульсом-48.png");
    int w = ui->pic1_pulse->width() + 20;
    int h = ui->pic1_pulse->height() + 20;
    ui->pic1_pulse->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix2(":/img/img/icons8-кислород-64.png");
    w = ui->pic2_O2->width() + 20;
    h = ui->pic2_O2->height() + 20;
    ui->pic2_O2->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
    QPixmap pix3(":/img/img/icons8-температура-64.png");
    w = ui->pic3_Temprature->width() + 20;
    h = ui->pic3_Temprature->height() + 20;
    ui->pic3_Temprature->setPixmap(pix3.scaled(w,h,Qt::KeepAspectRatio));
    startrefresh();
    scene_pulse = new QGraphicsScene(0, 0, 710, 150, this);
    scene_O2 = new QGraphicsScene(0, 0, 710, 150, this);
    scene_temprature = new QGraphicsScene(0, 0, 710, 150, this);
    ui->graphicsView->setScene(scene_pulse);
    ui->graphicsView_2->setScene(scene_O2);
    ui->graphicsView_3->setScene(scene_temprature);
    scene_pulse->addRect(scene_pulse->sceneRect());
    scene_O2->addRect(scene_O2->sceneRect());
    scene_temprature->addRect(scene_temprature->sceneRect());
    axis_pen.setColor(Qt::black);
    grid_pen.setColor(Qt::gray);
    pulse_graph_pen.setColor(Qt::red);
    O2_graph_pen.setColor(Qt::blue);
    temprature_graph_pen.setColor(Qt::red);
    QPointF first(0,70);
    time = 0;
    pulse_points.append(first);
    O2_points.append(first);
    temprature_points.append(first);
    plot(scene_pulse, axis_pen, pulse_graph_pen, grid_pen, 60, 150, time - 20, time + 20, pulse_points, time, counter);
    plot(scene_O2, axis_pen, O2_graph_pen, grid_pen, 70, 130, time - 20, time + 20, O2_points, time, counter);
    plot(scene_temprature, axis_pen, temprature_graph_pen, grid_pen, 30, 45, time - 20, time + 20, temprature_points, time, counter);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUseCase(IMetricsUseCase* usecase)
{
    usecase_ = usecase;
}

void MainWindow::UpdateResults(Device &result)
{
    ui->pulse_label->setText(QString::number(result.get_pulse()));
    ui->O2_label->setText(QString::number(result.get_O2()));
    ui->Temprature_label->setText(QString::number(result.get_temprature()));
    ui->name_label->setText(result.get_name());
    if(time > 20)
    {
        time++;
        counter++;
    }
    else
    {
        time++;
    }
    QPointF new_pulsePoint(time, result.get_pulse());
    QPointF new_O2Point(time, result.get_O2());
    QPointF new_tempraturePoint(time, result.get_temprature());
    pulse_points.append(new_pulsePoint);
    O2_points.append(new_O2Point);
    temprature_points.append(new_tempraturePoint);
    plot(scene_pulse, axis_pen, pulse_graph_pen, grid_pen, 60, 150, time - 20, time + 20, pulse_points, time, counter);
    plot(scene_O2, axis_pen, O2_graph_pen, grid_pen, 70, 130, time - 20, time + 20, O2_points, time, counter);
    plot(scene_temprature, axis_pen, temprature_graph_pen, grid_pen, 30, 45, time - 20, time + 20, temprature_points, time, counter);
    show();
}

void MainWindow::RefreshGUIdata()
{
    usecase_->RefreshData(22);
}

void MainWindow::startrefresh()
{
    QTimer* timer = new QTimer(this);
    timer->setInterval(1000);
    connect (timer, SIGNAL(timeout()), this, SLOT(RefreshGUIdata()));
    timer->start(1000);
}


// будет кнопка которая делает запрос на создание новго девайса если он есть в бд
// то он будет создан в клиенте


// будет кнопка которая делает запрос на прогноз данных
// данные будут возвращены и отображены