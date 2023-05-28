#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->circleText->setReadOnly(true);
    ui->circleButton->setEnabled(false);

    Stopwatch *stopwatch = new Stopwatch(this);

    connect(ui->startButton, &QPushButton::clicked, stopwatch, &Stopwatch::ReceiveStartSignal);
    connect(stopwatch, &Stopwatch::sig_SendStartSignal, this, &MainWindow::ReceiveStartSignalFromStopwatch);

    connect(ui->cleanButton, &QPushButton::clicked, stopwatch, &Stopwatch::ReceiveCleanSignal);
    connect(stopwatch, &Stopwatch::sig_SendCleanSignal, this, &MainWindow::ReceiveCleanSignalFromStopwatch);

    connect(ui->circleButton, &QPushButton::clicked, stopwatch, &Stopwatch::ReceiveCircleSignal);
    connect(stopwatch, &Stopwatch::sig_SendCircleSignal, this, &MainWindow::ReceiveCircleSignalFromStopwatch);

    connect(ui->startButton, &QPushButton::clicked, stopwatch, &Stopwatch::setTimer);
    connect(stopwatch, &Stopwatch::sig_SendTimerSignal, this, &MainWindow::ReceiveTimerSignalFromStopwatch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ReceiveStartSignalFromStopwatch(bool counter)
{
    if (counter == true)
    {
        ui->startButton->setText("Стоп");
        ui->circleButton->setEnabled(true);
    } else if (counter == false)
    {
        ui->startButton->setText("Старт");
        ui->circleButton->setEnabled(false);
    }
}

void MainWindow::ReceiveCleanSignalFromStopwatch()
{
    ui->secText->setText("0 : 0 : 0");
}

void MainWindow::ReceiveCircleSignalFromStopwatch(QString str)
{
    ui->circleText->append(str);
}

void MainWindow::ReceiveTimerSignalFromStopwatch(QString str)
{
    ui->secText->setText(str);
}
