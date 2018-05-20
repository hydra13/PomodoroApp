#ifndef POMODOROAPP_H
#define POMODOROAPP_H

#include <QTimer>
#include <QWidget>
#include "rest30minstate.h"
#include "work25minstate.h"
#include "work5minstate.h"
#include "pausestate.h"
#include "stopstate.h"

namespace Ui {
class PomodoroApp;
}

class PomodoroApp : public QWidget
{
    Q_OBJECT

public:
    explicit PomodoroApp(QWidget *parent = 0);
    ~PomodoroApp();

private slots:
    void on_pb25MWork_clicked();
    void on_pb5MRest_clicked();
    void on_pb30MRest_clicked();
    void on_pbExit_clicked();
    void timeout();

    void on_pbStop_clicked();

private:
    Ui::PomodoroApp *ui;
    QTimer *m_timer;
    int m_period;
    const QString TEMPATE_TIME_STR = "%1:%2";
};

#endif // POMODOROAPP_H
