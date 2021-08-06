#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QPainter>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);
    void DrawTrain();
    double rectangleX=0,ellipseX=0;
    bool flag=true;
    double defaultSpeed=3,stopSpeed=0,currentSpeed=3;
    double slowSpeed=0.01;
    double checkSpeed=0;
    int koef=1;
private:
    Ui::MainWindow *ui;
public slots:
   void onTimeout();
private slots:
   void on_pushButton_clicked();
   void on_pushButton_2_clicked();
   void on_pushButton_4_clicked();
   void on_pushButton_3_clicked();
   void on_pushButton_5_clicked();
};
#endif // MAINWINDOW_H
