#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDebug>
#include "MyButton.h"
#include "ui_widget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onToggled(); // 自定义按钮触发信号槽

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
