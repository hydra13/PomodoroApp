#ifndef POMODOROAPP_H
#define POMODOROAPP_H

#include <QTimer>
#include <QWidget>
#include "settingswidget.h"

namespace Ui {
class PomodoroApp;
}

class PomodoroApp : public QWidget
{
    Q_OBJECT

public:
    explicit PomodoroApp(QWidget *parent = 0);
    ~PomodoroApp();

    void startTimerSec(quint32 seconds);
    void startTimerMin(quint32 minutes);
    void stopTimer();

private slots:
    void on_pb25MWork_clicked();
    void on_pb5MRest_clicked();
    void on_pb30MRest_clicked();
    void on_pbExit_clicked();
    void on_pbStop_clicked();
    void on_pbSettings_clicked();
    void timeout();

private:
    QString convertToTimeStr(int period);
    Ui::PomodoroApp *ui;
    QTimer *m_timer;
    int m_period;
    Settings settings;
    const QString TEMPATE_TIME_STR = "%1:%2";
};

#endif // POMODOROAPP_H
