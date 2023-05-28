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

private slots:
    void ReceiveStartSignalFromStopwatch(bool);
    void ReceiveCleanSignalFromStopwatch();
    void ReceiveCircleSignalFromStopwatch(QString);
    void ReceiveTimerSignalFromStopwatch(QString);
};
#endif // MAINWINDOW_H
