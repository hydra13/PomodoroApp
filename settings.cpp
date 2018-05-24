#include "settings.h"

#include <QFile>
#include <QSettings>

Settings::Settings()
{
    loadSettings();
}

int Settings::getPeriodWork() const
{
    return periodWork;
}

void Settings::setPeriodWork(int value)
{
    periodWork = value;
}

int Settings::getPeriodShortRest() const
{
    return periodShortRest;
}

void Settings::setPeriodShortRest(int value)
{
    periodShortRest = value;
}

int Settings::getPeriodLongRest() const
{
    return periodLongRest;
}

void Settings::setPeriodLongRest(int value)
{
    periodLongRest = value;
}

void Settings::loadSettings()
{
    if (QFile::exists(FILE_SETTINGS_NAME)){
        QSettings settings(FILE_SETTINGS_NAME, QSettings::IniFormat);
        periodWork = settings.value("periods/work", 25 * 60).toInt();
        periodShortRest = settings.value("periods/short_rest", 5 * 60).toInt();
        periodLongRest = settings.value("periods/long_rest", 30 * 60).toInt();
    } else {
        periodWork = 25 * 60;
        periodShortRest = 5 * 60;
        periodLongRest = 30 * 60;
    }
}

void Settings::saveSettings()
{
    QSettings settings(FILE_SETTINGS_NAME, QSettings::IniFormat);
//    settings.clear();
    settings.setValue("periods/work", periodWork);
    settings.setValue("periods/short_rest", periodShortRest);
    settings.setValue("periods/long_rest", periodLongRest);
    settings.sync();
}
