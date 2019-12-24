/*** 如果运行异常退出，是因为没在输出目录拷贝动态链接库(libmpv.dll.a和mpv-1.dll) ***/
#ifndef MPVPLAYER_H
#define MPVPLAYER_H

#include <QMainWindow>
#include <QDebug>
#include <client.h> // MPV库头文件

class MpvPlayer
{
public:
    MpvPlayer(QWidget *parent);
    ~MpvPlayer();

    void create_mvpPlayer(QWidget *videoWin); // 创建mvpPlayer
    void setProperty(const QString &name, const QString &value); // 设置mpv属性
    QString getProperty(const QString &name) const; // 获得mpv属性
    void play(QString filename); // 播放视频

private:
    mpv_handle *mpv;
};

#endif // MPVPLAYER_H
