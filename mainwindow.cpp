#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mpvPlayer = new MpvPlayer(ui->playerWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 播放视频
void MainWindow::on_playPushButton_clicked()
{
    QString videoName = "../mpvDemoModify/test.mp4";
    //QString videoName = "rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov";

    mpvPlayer->play(videoName);
}

// 暂停/恢复视频
void MainWindow::on_pausePushButton_clicked()
{
    // 获得mpv播放器的"暂停"状态
    QString pasued = mpvPlayer->getProperty("pause");

    // 根据"暂停"状态来选择暂停还是播放
    if(pasued == "no")
    {
        mpvPlayer->setProperty("pause", "yes");
        ui->pausePushButton->setText("恢复");
    }
    else if(pasued == "yes")
    {
        mpvPlayer->setProperty("pause", "no");
        ui->pausePushButton->setText("暂停");
    }
}
