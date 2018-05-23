#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class MessageWidget;
}

class MessageWidget : public QDialog
{
    Q_OBJECT

public:
    explicit MessageWidget(QWidget *parent = 0);
    ~MessageWidget();

private slots:
    void on_pbStop_clicked();
    void on_pbStopAndClose_clicked();

private:
    Ui::MessageWidget *ui;
    QMediaPlayer *m_player;
};

#endif // MESSAGEWIDGET_H
