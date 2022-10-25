#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>   // 타이머 라이브러리


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);  // 타이머라는 인스턴스 생성 후 저장
    connect(timer, SIGNAL(timeout()),this,SLOT(timer_update()));    // 타이머 맵핑
    tick = 0; // 타이머 연결
//    timer -> start(20); // 20ms마다 timer 가동
//    timer -> stop();    // 타이머 중지

}

int MainWindow::timer_update()
{
    if (tick >= 100)
    {
        ui -> label -> setText("Loading Complete !!!");

    }
    else if (tick < 100)
    {
        tick++;
        ui -> label -> setText("Loading....");
    }
    ui -> progressBar -> setValue(tick);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_start_clicked()
{
    timer -> start(20);
}

void MainWindow::on_pushButton_end_clicked()
{
    timer -> stop();
}
