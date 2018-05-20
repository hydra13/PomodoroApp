#ifndef STOPSTATE_H
#define STOPSTATE_H

#include "state.h"

class StopState: public State
{
public:
    StopState(Ui::PomodoroApp *ui, QTimer *m_timer, int *m_period);
    void start25MWork();
    void start5MRest();
    void start30MRest();
    void pause();
    void stop();
};

#endif // STOPSTATE_H
