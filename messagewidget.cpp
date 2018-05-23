#include "messagewidget.h"
#include "ui_messagewidget.h"

MessageWidget::MessageWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageWidget),
    m_player(new QMediaPlayer)
{
    ui->setupUi(this);
    m_player->setMedia(QUrl("qrc:/sounds/sounds/super_alarm.mp3"));
    m_player->setVolume(50);
    m_player->play();
}

MessageWidget::~MessageWidget()
{
    m_player->deleteLater();
    delete ui;
}

void MessageWidget::on_pbStopAndClose_clicked()
{
    m_player->stop();
    close();
}
