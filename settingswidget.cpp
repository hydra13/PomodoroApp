#include "settingswidget.h"
#include "ui_settingswidget.h"

SettingsWidget::SettingsWidget(Settings *settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWidget),
    settings(settings)
{
    ui->setupUi(this);
    ui->timeEditWork->setTime( QTime::fromMSecsSinceStartOfDay( settings->getPeriodWork() * 1000 ) );
    ui->timeEditShortRest->setTime( QTime::fromMSecsSinceStartOfDay( settings->getPeriodShortRest() * 1000 ) );
    ui->timeEditLongRest->setTime( QTime::fromMSecsSinceStartOfDay( settings->getPeriodLongRest() * 1000 ) );
}

SettingsWidget::~SettingsWidget()
{
    delete ui;
}

void SettingsWidget::on_pbCancel_clicked()
{
    close();
}

void SettingsWidget::on_pbSave_clicked()
{
    if (ui->timeEditWork->time().isValid()){
        settings->setPeriodWork( getResultSecsFromTime( ui->timeEditWork->time() ) );
    }
    if (ui->timeEditShortRest->time().isValid()){
        settings->setPeriodShortRest( getResultSecsFromTime( ui->timeEditShortRest->time() ) );
    }
    if (ui->timeEditLongRest->time().isValid()){
        settings->setPeriodLongRest( getResultSecsFromTime( ui->timeEditLongRest->time() ) );
    }
    settings->saveSettings();
    close();
}

int SettingsWidget::getResultSecsFromTime(const QTime &time)
{
    return (time.minute() * 60 + time.second());
}
