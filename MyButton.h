#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>

class MyButton : public QWidget
{
    Q_OBJECT

public:
    explicit MyButton(const bool& bType = false, QWidget *parent = 0);
    void SetPaintText(const QString& sText); // 设置绘制文本
    void SetBlockColor(const QColor& color); // 设置色块颜色
    QString GetPaintText(); // 获得绘制文本
    QColor GetBlockColor(); // 获得色块颜色

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE; // 绘制事件
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE; // 鼠标按下事件
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE; // 鼠标释放事件

signals:
    // 状态改变时，发射信号
    void toggled();

private:
    bool m_bChecked;         // 是否选中
    QColor m_checkColor;   // 选中颜色
    QString m_sText; // 绘制文本

    bool m_bType; // 为0则显示文本，为1则显示色块
};

#endif // MYBUTTON_H
