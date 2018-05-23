#include "pomodoroapp.h"
#include "messagewidget.h"
#include "ui_pomodoroapp.h"

#include <QMessageBox>

PomodoroApp::PomodoroApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PomodoroApp),
    m_period(0),
    m_timer(new QTimer)
{
    ui->setupUi(this);
    m_timer->setInterval(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timeout()));
}

PomodoroApp::~PomodoroApp()
{
    if (m_timer->isActive()){
        m_timer->stop();
    }
    m_timer->deleteLater();
    delete ui;
}

void PomodoroApp::on_pb25MWork_clicked()
{
    startTimerMin(25);
}


void PomodoroApp::on_pb5MRest_clicked()
{
    startTimerMin(5);
}

void PomodoroApp::on_pb30MRest_clicked()
{
    startTimerMin(30);
}

void PomodoroApp::on_pbExit_clicked()
{
    close();
}

void PomodoroApp::startTimerSec(quint32 seconds)
{
    ui->pb5MRest->setEnabled(false);
    ui->pb25MWork->setEnabled(false);
    ui->pb30MRest->setEnabled(false);
    ui->pbStop->setEnabled(true);
    m_period = seconds;
    ui->pBar->setMaximum(seconds);
    ui->pBar->setValue(seconds);
    QString min = ((int)(m_period / 60) >= 10 ? "" : "0") + QString::number((int)(m_period / 60));
    QString sec = ((int)(m_period % 60) >= 10 ? "" : "0") + QString::number((int)(m_period % 60));
    ui->label->setText(TEMPATE_TIME_STR.arg(min, sec));
    m_timer->start();
}

void PomodoroApp::startTimerMin(quint32 minutes)
{
    startTimerSec(minutes * 60);
}

void PomodoroApp::stopTimer()
{
    m_timer->stop();
    ui->pb5MRest->setEnabled(true);
    ui->pb25MWork->setEnabled(true);
    ui->pb30MRest->setEnabled(true);
    ui->pbStop->setEnabled(false);
    m_period = 0;
    ui->pBar->setValue(0);
    ui->label->setText("00:00");
}

void PomodoroApp::timeout()
{
    m_period--;
    ui->pBar->setValue(m_period);
    QString min = ((int)(m_period / 60) >= 10 ? "" : "0") + QString::number((int)(m_period / 60));
    QString sec = ((int)(m_period % 60) >= 10 ? "" : "0") + QString::number((int)(m_period % 60));
    ui->label->setText(TEMPATE_TIME_STR.arg(min, sec));
    if (m_period == 0){
        stopTimer();
        MessageWidget *msg = new MessageWidget(this);
        msg->exec();
        msg->deleteLater();
    }
}

void PomodoroApp::on_pbStop_clicked()
{
    stopTimer();
}

void PomodoroApp::on_pbSettings_clicked()
{

}
