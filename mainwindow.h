#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

#include <QTimer>
#include <QTime>

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
    Stopwatch *stopwatch;

    bool startCount = true;
    int circleCount = 1;
    int ms_circle = 0;
    int s_circle = 0;
    int m_circle = 0;

    int ms = 0;
    int s = 0;
    int m = 0;

    QTimer *tmr;
};
#endif // MAINWINDOW_H
