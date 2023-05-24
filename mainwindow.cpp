#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->circleText->setReadOnly(true);
    ui->circleButton->setEnabled(false);

    stopwatch = new Stopwatch(this);

    tmr = new QTimer(this);
    tmr->setInterval(100);

    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));

    QObject::connect(stopwatch, &Stopwatch::sig_SendStartSignal, this, &MainWindow::ReceiveStartSignal, Qt::AutoConnection);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::SendStartSignal, Qt::AutoConnection);

    QObject::connect(stopwatch, &Stopwatch::sig_SendCleanSignal, this, &MainWindow::ReceiveCleanSignal, Qt::AutoConnection);
    connect(ui->cleanButton, &QPushButton::clicked, this, &MainWindow::SendCleanSignal, Qt::AutoConnection);

    QObject::connect(stopwatch, &Stopwatch::sig_SendCircleSignal, this, &MainWindow::ReceiveCircleSignal, Qt::AutoConnection);
    connect(ui->circleButton, &QPushButton::clicked, this, &MainWindow::SendCircleSignal, Qt::AutoConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete stopwatch;
    delete tmr;
}

void MainWindow::ReceiveStartSignal()
{
    if (startCount == true)
    {
        tmr->start();
        ui->startButton->setText("Стоп");
        ui->circleButton->setEnabled(true);
        startCount = false;
    } else if (startCount == false)
    {
        tmr->stop();
        ui->startButton->setText("Старт");
        ui->circleButton->setEnabled(false);
        startCount = true;
    }
}

void MainWindow::SendStartSignal()
{
    emit stopwatch->sig_SendStartSignal();
}

void MainWindow::ReceiveCleanSignal()
{
    ui->secText->setText("0 : 0 : 0");
    circleCount = 1;
    ms = 0;
    s = 0;
    m = 0;
    ms_circle = 0;
    s_circle = 0;
    m_circle = 0;

}

void MainWindow::SendCleanSignal()
{
    emit stopwatch->sig_SendCleanSignal();
}

void MainWindow::ReceiveCircleSignal()
{
    ui->circleText->append("Круг " + QString::number(circleCount) + ", Время " + QString::number(m_circle) + " : " + QString::number(s_circle) + " : " + QString::number(ms_circle));
    ++circleCount;
    m_circle = 0;
    s_circle = 0;
    ms_circle = 0;
}

void MainWindow::SendCircleSignal()
{
    emit stopwatch->sig_SendCircleSignal();
}

void MainWindow::updateTime()
{
    ++ms;
    if (ms >= 10)
    {
        ms = 0;
        ++s;
    }
    if (s >= 60)
    {
        s = 0;
        ++m;
    }
    ui->secText->setText(QString::number(m) + " : " + QString::number(s) + " : " + QString::number(ms));

    ++ms_circle;
    if (ms_circle >= 10)
    {
        ms_circle = 0;
        ++s_circle;
    }
    if (s_circle >= 60)
    {
        s_circle = 0;
        ++m_circle;
    }
}
