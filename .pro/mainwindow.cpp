#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter train(this);
    train.drawRect((rectangleX+60),235,8,15);
    train.drawRect((rectangleX+60),255,5,8);
    train.drawRect(rectangleX,250,80,20);
    train.drawEllipse(ellipseX,272,5,5);
    train.drawEllipse((ellipseX+11),272,5,5);
    train.drawEllipse((ellipseX+22),272,5,5);
    train.drawEllipse((ellipseX+33),272,5,5);
    train.drawEllipse((ellipseX+44),272,5,5);
    train.drawEllipse((ellipseX+55),272,5,5);
    train.drawEllipse((ellipseX+66),272,5,5);
    QPainter line(this);
      line.drawLine(0,279,1200,279);
    QPainter slower(this);
    slower.drawRect(400,281,60,10);
    if(((rectangleX+80)>=400)&&((rectangleX)<=460)) {currentSpeed-=slowSpeed;}
      rectangleX+=currentSpeed;
      ellipseX+=currentSpeed;
}
void MainWindow::onTimeout()
{
    if((20*currentSpeed*koef)>300){ui->label_5->setText("Too fast,resrart app"); flag=true;}
    else  ui->label_5->setText(QString::number(20*currentSpeed*koef));
    if(!flag){repaint();}

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label_3->setText(QString("1"));
    slowSpeed=2*slowSpeed;
    QTimer* timer = new QTimer(this);
       timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
       if(flag){
       timer->start(42);
       flag=false;
       }
       else {
           timer->stop();
       }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_3->setText(QString("2"));
    slowSpeed=2.5*slowSpeed;
    QTimer* timer = new QTimer(this);
       timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
       if(flag){
       timer->start(42);
       flag=false;
       }
       else {
           timer->stop();
       }
}

void MainWindow::on_pushButton_4_clicked()
{
    slowSpeed=3*slowSpeed;
    ui->label_3->setText(QString("3"));
    QTimer* timer = new QTimer(this);
       timer = new QTimer(this);
       connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
       if(flag){
       timer->start(42);
       flag=false;
       }
       else {
           timer->stop();
       }
}
void MainWindow::on_pushButton_5_clicked()
{
     flag=true;
     rectangleX=0;
     ellipseX=0;
     koef+=1;
     currentSpeed=defaultSpeed;
     slowSpeed=0.01;
     repaint();
}
