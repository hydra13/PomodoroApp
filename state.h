#ifndef STATE_H
#define STATE_H

#include <QTimer>

namespace Ui {
    class PomodoroApp;
}

class State: public QObject
{
    Q_OBJECT
public:
    State(Ui::PomodoroApp *ui, QTimer *m_timer, int *m_period, QObject *parent){
        this->ui = ui;
        this->m_timer = m_timer;
        this->m_period = m_period;
    }
    virtual void start25MWork() = 0;
    virtual void start5MRest() = 0;
    virtual void start30MRest() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;

private:
    Ui::PomodoroApp *ui;
    QTimer *m_timer;
    int *m_period;
};

#endif // STATE_H
