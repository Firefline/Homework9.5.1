#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QTime>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();

private:
    Stopwatch *stopwatch;
    QTimer *tmr;

    bool startCount = true;
    int circleCount = 1;

    int msec = 0;
    int sec = 0;
    int min = 0;

    int msec_circle = 0;
    int sec_circle = 0;
    int min_circle = 0;

public slots:
    void ReceiveStartSignal();
    void ReceiveCleanSignal();
    void ReceiveCircleSignal();
    void setTimer();

signals:
    void sig_SendStartSignal(bool);
    void sig_SendCleanSignal();
    void sig_SendCircleSignal(QString);
    void sig_SendTimerSignal(QString);

};

#endif // STOPWATCH_H
