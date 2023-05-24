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

    connect(tmr, &QTimer::timeout, this, [this] {
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
    });

    connect(ui->startButton, &QPushButton::clicked, this, [this] {
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
    });

    connect(ui->cleanButton, &QPushButton::clicked, this, [this] {
        ui->secText->setText("0 : 0 : 0");
        circleCount = 1;
        ms = 0;
        s = 0;
        m = 0;
        ms_circle = 0;
        s_circle = 0;
        m_circle = 0;
    });

    connect(ui->circleButton, &QPushButton::clicked, this, [this] {
        ui->circleText->append("Круг " + QString::number(circleCount) + ", Время " + QString::number(m_circle) + " : " + QString::number(s_circle) + " : " + QString::number(ms_circle));
        ++circleCount;
        m_circle = 0;
        s_circle = 0;
        ms_circle = 0;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
