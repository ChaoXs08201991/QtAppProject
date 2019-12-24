#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mpvplayer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();    

private slots:
    void on_playPushButton_clicked(); // 播放视频
    void on_pausePushButton_clicked(); // 暂停/恢复视频

private:
    Ui::MainWindow *ui;

    MpvPlayer *mpvPlayer;
};

#endif // MAINWINDOW_H
