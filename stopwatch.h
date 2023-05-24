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

signals:
    void sig_SendStartSignal();
    void sig_SendCleanSignal();
    void sig_SendCircleSignal();
};

#endif // STOPWATCH_H
