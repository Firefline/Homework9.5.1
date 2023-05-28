#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent}
{
    tmr = new QTimer(this);
    tmr->setInterval(100);
    connect(tmr, &QTimer::timeout, this, &Stopwatch::setTimer);
}

Stopwatch::~Stopwatch()
{

}

void Stopwatch::ReceiveStartSignal()
{
    if (startCount == true)
    {
        emit Stopwatch::sig_SendStartSignal(startCount);
        startCount = false;

    } else if (startCount == false)
    {
        emit Stopwatch::sig_SendStartSignal(startCount);
        startCount = true;
    }
}

void Stopwatch::ReceiveCleanSignal()
{
    circleCount = 1;
    msec = 0;
    sec = 0;
    min = 0;
    msec_circle = 0;
    sec_circle = 0;
    min_circle = 0;
    emit Stopwatch::sig_SendCleanSignal();
}

void Stopwatch::ReceiveCircleSignal()
{
    emit Stopwatch::sig_SendCircleSignal("Круг " + QString::number(circleCount) + ", Время " + QString::number(min_circle) + " : " + QString::number(sec_circle) + " : " + QString::number(msec_circle));
    msec_circle = 0;
    sec_circle = 0;
    min_circle = 0;
    ++circleCount;
}

void Stopwatch::setTimer()
{
    if (startCount == false)
    {
        tmr->start();

    } else if (startCount == true)
    {
        tmr->stop();
    }

    ++msec;
    ++msec_circle;

    if (msec >= 10)
    {
        msec = 0;
        ++sec;
    }

    if (sec >= 60)
    {
        sec = 0;
        ++min;
    }
    if (msec_circle >= 10)
    {
        msec_circle = 0;
        ++sec_circle;
    }

    if (sec_circle >= 60)
    {
        sec_circle = 0;
        ++min_circle;
    }

    emit Stopwatch::sig_SendTimerSignal(QString::number(min) + " : " + QString::number(sec) + " : " + QString::number(msec));
}
