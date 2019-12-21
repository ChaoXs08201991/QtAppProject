#ifndef QTEXAMPLE_H
#define QTEXAMPLE_H

#include <QMainWindow>

#include <client.h> // MVP库头文件

class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_file_open(); // 打开文件
    void on_new_window(); // 新建窗口
    void on_mpv_events(); // 这个槽函数由 wakeup()调用（通过mpv_events信号）

signals:
    void mpv_events();

private:
    QWidget *mpv_container;
    mpv_handle *mpv;
    QTextEdit *log;

    void create_mvpPlayer(); // 创建mvpPlayer
    void handle_mpv_event(mpv_event *event); // 处理mpv事件

    void append_log(const QString &text); // 附加log
};

#endif // QTEXAMPLE_H
