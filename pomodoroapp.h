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
    void setState(State *newState);
    ~PomodoroApp();

    int period() const;
    void setPeriod(int period);
    void decrementPeriod();

private slots:
    void start25MWork();
    void start5MRest();
    void start30MRest();
    void stopTimer();
    void pauseTimer();

private:
    Ui::PomodoroApp *ui;
    QTimer *m_timer;
    int m_period;
    State *m_state;
};

#endif // POMODOROAPP_H
