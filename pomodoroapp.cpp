#include "messagewidget.h"
#include "pomodoroapp.h"
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
    ui->pb5MRest->setEnabled(false);
    ui->pb25MWork->setEnabled(false);
    ui->pb30MRest->setEnabled(false);
    ui->pbStop->setEnabled(true);
    m_period = 25 * 60;
    ui->pBar->setMaximum(25 * 60);
    ui->pBar->setValue(25 * 60);
    ui->label->setText(TEMPATE_TIME_STR.arg("25", "00"));
    m_timer->start();
}

void PomodoroApp::on_pb5MRest_clicked()
{
    ui->pb5MRest->setEnabled(false);
    ui->pb25MWork->setEnabled(false);
    ui->pb30MRest->setEnabled(false);
    ui->pbStop->setEnabled(true);
    m_period = 5;// * 60;
    ui->pBar->setMaximum(5);// * 60);
    ui->pBar->setValue(5);// * 60);
    ui->label->setText(TEMPATE_TIME_STR.arg("00", "05"));
    m_timer->start();
}

void PomodoroApp::on_pb30MRest_clicked()
{
    ui->pb5MRest->setEnabled(false);
    ui->pb25MWork->setEnabled(false);
    ui->pb30MRest->setEnabled(false);
    ui->pbStop->setEnabled(true);
    m_period = 30 * 60;
    ui->pBar->setMaximum(30 * 60);
    ui->pBar->setValue(30 * 60);
    ui->label->setText(TEMPATE_TIME_STR.arg("30", "00"));
    m_timer->start();
}

void PomodoroApp::on_pbExit_clicked()
{
    close();
}

void PomodoroApp::timeout()
{
    m_period--;
    ui->pBar->setValue(m_period);
    QString min = ((int)(m_period / 60) >= 10 ? "" : "0") + QString::number((int)(m_period / 60));
    QString sec = ((int)(m_period % 60) >= 10 ? "" : "0") + QString::number((int)(m_period % 60));
    ui->label->setText(TEMPATE_TIME_STR.arg(min, sec));
    if (m_period == 0){
//        QMessageBox::information(this, "PomodoroApp", "Time now!!!");
        ui->pb5MRest->setEnabled(true);
        ui->pb25MWork->setEnabled(true);
        ui->pb30MRest->setEnabled(true);
        ui->label->setText("00:00");
        ui->pBar->setValue(0);
        ui->pbStop->setEnabled(false);
        m_timer->stop();
        MessageWidget *msg = new MessageWidget(this);
        msg->exec();
        msg->deleteLater();
    }
}

void PomodoroApp::on_pbStop_clicked()
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

void PomodoroApp::on_pbSettings_clicked()
{

}
