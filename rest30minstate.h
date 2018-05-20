#ifndef REST30MINSTATE_H
#define REST30MINSTATE_H

#include "state.h"

class Rest30MinState: public State
{
public:
    Rest30MinState(Ui::PomodoroApp *ui, QTimer *m_timer, int *m_period);
    void start25MWork();
    void start5MRest();
    void start30MRest();
    void pause();
    void stop();
};

#endif // REST30MINSTATE_H
