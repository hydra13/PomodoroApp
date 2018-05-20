#include "pomodoroapp.h"
#include "ui_pomodoroapp.h"

PomodoroApp::PomodoroApp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PomodoroApp),
    m_period(0),
    m_timer(new QTimer)
{
    ui->setupUi(this);
    m_timer->setInterval(1000);
    m_state = new StopState(ui, m_timer, &m_period);
}

void PomodoroApp::setState(State *newState)
{
    m_state->deleteLater();
    m_state = newState;
}

PomodoroApp::~PomodoroApp()
{
    m_state->deleteLater();
    if (m_timer->isActive()){
        m_timer->stop();
    }
    m_timer->deleteLater();
    delete ui;
}

void PomodoroApp::start25MWork()
{
    m_state->start25MWork();
}

void PomodoroApp::start5MRest()
{
    m_state->start5MRest();
}

void PomodoroApp::start30MRest()
{
    m_state->start30MRest();
}

void PomodoroApp::stopTimer()
{
    m_state->stop();
}

void PomodoroApp::pauseTimer()
{
    m_state->pause();
}

int PomodoroApp::period() const
{
    return m_period;
}

void PomodoroApp::setPeriod(int period)
{
    m_period = period;
}

void PomodoroApp::decrementPeriod()
{
    if (m_period>0){
        m_period--;
    }
}
