
#include <QGridLayout>
#include <QResizeEvent>
#include <QScrollArea>
#include <QScrollBar>
#include <QSizePolicy>

class HorizontalScrollArea : public QWidget
{
    QHBoxLayout *layout;
public:
    HorizontalScrollArea(QWidget *parent = Q_NULLPTR)
        :QWidget(parent)
    {
        layout = new QHBoxLayout(this);
        layout->setSpacing(10);
        QSpacerItem *item = new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);
        layout->addSpacerItem(item);
    }
    void insertWidget(int count, QWidget* w){
        layout->insertWidget(count, w, 0, Qt::AlignLeft);


        //layout->setAlignment(w, Qt::AlignLeft);
        //layout->addWidget(w);
    }


private:
protected:
   
};
