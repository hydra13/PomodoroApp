#ifndef WORK5MINSTATE_H
#define WORK5MINSTATE_H

#include "state.h"

class Work5MinState: public State
{
public:
    Work5MinState(Ui::PomodoroApp *ui, QTimer *m_timer, int *m_period);
    void start25MWork();
    void start5MRest();
    void start30MRest();
    void pause();
    void stop();
};

#endif // WORK5MINSTATE_H
