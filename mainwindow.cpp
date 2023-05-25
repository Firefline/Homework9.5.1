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

    tmr = new QTimer(this);
    tmr->setInterval(100);

    connect(tmr, &QTimer::timeout, stopwatch, &Stopwatch::setTimer);

    connect(ui->startButton, &QPushButton::clicked, stopwatch, &Stopwatch::ReceiveStartSignal);

    connect(ui->cleanButton, &QPushButton::clicked, stopwatch, &Stopwatch::ReceiveCleanSignal);

    connect(ui->circleButton, &QPushButton::clicked, stopwatch, &Stopwatch::ReceiveCircleSignal);
}

MainWindow::~MainWindow()
{
    delete ui;
}
