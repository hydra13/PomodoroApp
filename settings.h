#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

class Settings
{
public:
    Settings();

    int getPeriodWork() const;
    void setPeriodWork(int value);

    int getPeriodShortRest() const;
    void setPeriodShortRest(int value);

    int getPeriodLongRest() const;
    void setPeriodLongRest(int value);

public slots:
    void loadSettings();
    void saveSettings();

private:
    int periodWork;
    int periodShortRest;
    int periodLongRest;
    const QString FILE_SETTINGS_NAME = "pomodoro.conf";
};

#endif // SETTINGS_H
