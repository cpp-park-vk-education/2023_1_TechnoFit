#pragma once
#include <QMainWindow>
#include <QThread>
#include <QString>
#include <QTimer>
#include "Device.h"
#include "header.h"
#include "../UseCase/IMetricsUseCase.h"
#include "IMetricsUI.h"
#include "HorizontalScrollArea.h"
#include "dialog.h"
#include "../Sources/ui_dialog.h"
#include "../UseCase/MetricsUseCase.h"
#include "Metrics.h"
#include "DeviceCard.h"
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
    void UpdateResults(IDevice &result) override;
    void setUseCase(IMetricsUseCase* usecase);
    void setDialog(Dialog* dialog_);
    void startrefresh();
    void createDevice(State state, QString name, int age, float weight) override;
    void change_graph(int id, State type) override;
    void refresh_graph();
    void refresh_zone();
private slots:
    void on_add_device_btn_clicked();
public slots:
    void RefreshGUIdata();
private:
    Ui::MainWindow* ui;
    Dialog* dialog;
    IMetricsUseCase* usecase_;
    QGraphicsScene* scene_pulse;
    QGraphicsScene* scene_O2;
    QGraphicsScene* scene_temprature;
    QGraphicsScene* scene_ECG;
    QVector<DeviceCard*> devices;
    qreal time;
    QPen axis_pen;
    QPen pulse_graph_pen;
    QPen O2_graph_pen;
    QPen temprature_graph_pen;
    QPen grid_pen;
    int id;
    State type;
    int counter = 0;
    int element_counter = 0;
    bool builded = false;
    HorizontalScrollArea* layoutwidget;
};