#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *timer;    // 타이머 인스턴스를 저장할 변수
    int tick;         // 타이머 틱 변수

private slots:
    int timer_update(); // 20ms마다 수행 되어지는 call back funtion
    void on_pushButton_start_clicked();
    void on_pushButton_end_clicked();
};

#endif // MAINWINDOW_H
