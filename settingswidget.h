#ifndef SETTINGSWIDGET_H
#define SETTINGSWIDGET_H

#include <QDialog>
#include <settings.h>

namespace Ui {
class SettingsWidget;
}

class SettingsWidget : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWidget(Settings *settings, QWidget *parent = 0);
    ~SettingsWidget();
    Settings *settings;

private slots:
    void on_pbCancel_clicked();
    void on_pbSave_clicked();

private:
    Ui::SettingsWidget *ui;
    int getResultSecsFromTime(const QTime &time);
};

#endif // SETTINGSWIDGET_H
