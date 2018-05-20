#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "state.h"

class PauseState: public State
{
public:
    PauseState(Ui::PomodoroApp *ui, QTimer *m_timer, int *m_period);
    void start25MWork();
    void start5MRest();
    void start30MRest();
    void pause();
    void stop();
};

#endif // PAUSESTATE_H
