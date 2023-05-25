#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

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

public slots:
    void ReceiveStartSignal();
    void ReceiveCleanSignal();
    void ReceiveCircleSignal();
    void setTimer();
};

#endif // STOPWATCH_H
