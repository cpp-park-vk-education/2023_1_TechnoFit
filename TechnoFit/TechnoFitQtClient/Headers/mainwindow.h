#pragma once
#include <QMainWindow>
#include <QThread>
#include <QString>
#include <QTimer>
#include "Device.h"
#include "../UseCase/IMetricsUseCase.h"
#include "IMetricsUI.h"
#include "../UseCase/MetricsUseCase.h"
#include <memory>
#include <QPainter>
#include <QPoint>
#include <QGraphicsItem>
#include <QVector>
#include <QPen>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui 
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public IMetricsUI
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void UpdateResults(Device &result) override;
    void setUseCase(IMetricsUseCase* usecase);
    void startrefresh();
public slots:
    void RefreshGUIdata();
private:
    Ui::MainWindow* ui;
    QThread refresherThread;
    IMetricsUseCase* usecase_;
    QGraphicsScene* scene_pulse;
    QGraphicsScene* scene_O2;
    QGraphicsScene* scene_temprature;
    QVector<QPointF> pulse_points;
    QVector<QPointF> O2_points;
    QVector<QPointF> temprature_points;
    qreal time;
    QPen axis_pen;
    QPen pulse_graph_pen;
    QPen O2_graph_pen;
    QPen temprature_graph_pen;
    QPen grid_pen;
    int counter = 0;
};