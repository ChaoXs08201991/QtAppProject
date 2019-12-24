#include "mpvplayer.h"

MpvPlayer::MpvPlayer(QWidget *parent)
{
    // 创建mvpPlayer
    create_mvpPlayer(parent);
}

MpvPlayer::~MpvPlayer()
{
    if (mpv)
        mpv_terminate_destroy(mpv);
}

// 创建mvpPlayer
void MpvPlayer::create_mvpPlayer(QWidget *videoWin)
{
    // 创建mpv实例
    mpv = mpv_create();
    if (!mpv)
        throw std::runtime_error("can't create mpv instance");

    // 将视频子窗口的窗口ID传递给mpv wid选项
    int64_t wid = videoWin->winId();
    mpv_set_option(mpv, "wid", MPV_FORMAT_INT64, &wid);

    // 播放的同时录制视频
    mpv_set_option_string(mpv, "stream-record", "./out.mp4");

    // 判断mpv实例是否成功初始化
    if (mpv_initialize(mpv) < 0)
        throw std::runtime_error("mpv failed to initialize");
}

// 设置mpv属性
void MpvPlayer::setProperty(const QString &name, const QString &value)
{
    mpv_set_option_string(mpv, name.toLatin1().data(), value.toLatin1().data());
}

// 获得mpv属性
QString MpvPlayer::getProperty(const QString &name) const
{
    return (QString)mpv_get_property_string(mpv, name.toLatin1().data());
}

// 播放视频
void MpvPlayer::play(QString filename)
{
    if (mpv)
    {
        const QByteArray c_filename = filename.toUtf8();
        const char *args[] = {"loadfile", c_filename.data(), NULL};
        // 与mpv_command相同，但异步运行命令来避免阻塞，直到进程终止
        mpv_command_async(mpv, 0, args);
    }
}
