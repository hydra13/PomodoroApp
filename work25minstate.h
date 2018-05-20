#ifndef WORK25MINSTATE_H
#define WORK25MINSTATE_H

#include "state.h"

class Work25MinState: public State
{
public:
    Work25MinState(Ui::PomodoroApp *ui, QTimer *m_timer, int *m_period);
    void start25MWork();
    void start5MRest();
    void start30MRest();
    void pause();
    void stop();
};

#endif // WORK25MINSTATE_H
