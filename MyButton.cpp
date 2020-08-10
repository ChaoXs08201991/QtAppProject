#include "MyButton.h"

MyButton::MyButton(const bool& bType, QWidget *parent)
    : QWidget(parent)
{
    // 鼠标滑过光标形状 - 手型
    setCursor(Qt::PointingHandCursor);

    m_checkColor = QColor(0, 150, 136);
    m_bChecked = false;
    m_bType = bType;

    this->setFixedSize(128, 60);
}

// 绘制开关
void MyButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // 根据按钮状态，设置绘制颜色
    QColor paintColor;
    if (isEnabled()) { // 判断按钮是否可用
        // 可用状态
        if (m_bChecked)
            paintColor = QColor(73, 143, 248);
        else
            paintColor = QColor(112, 112, 112);
    } else {
        // 不可用状态
        paintColor = QColor(190, 190, 190, 0.26);
    }

    QPainter painter(this);
    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 设置画笔颜色
    QPen pen;
    pen.setWidth(3);
    pen.setColor(paintColor);
    painter.setPen(pen);
    // 绘制边框
    painter.drawRoundRect(0, 0, 128, 60, 8);
    // 绘制多边形-倒三角形箭头
    const QPointF points[4] = {QPointF(84, 20), QPointF(106, 20), QPointF(95, 40), QPointF(84, 20)};
    painter.setBrush(paintColor);
    painter.drawPolygon(points, 4);

    if (!m_bType) {
        // 绘制文本
        QFont font;
        font.setFamily("Microsoft YaHei");
        font.setPointSize(20);
        painter.setFont(font);
        painter.drawText(QRect(14, 11, 128, 60), m_sText);
    } else {
        // 绘制色块
        if (m_checkColor.red() == 255) {
            painter.setPen(QPen(QColor(191, 191, 191), 1)); // 设置边框颜色
            painter.setBrush(m_checkColor);
            painter.drawRoundRect(12, 10, 41, 41, 5, 5);
        } else {
            painter.setPen(m_checkColor);
            painter.setBrush(m_checkColor);
            painter.drawRoundRect(12, 10, 41, 41, 5, 5);
        }
    }
}

// 鼠标按下事件
void MyButton::mousePressEvent(QMouseEvent *event)
{
    if (isEnabled()) {
        if (event->buttons() & Qt::LeftButton) {
            m_bChecked = true;
            this->update();
        }
    }
}

// 鼠标释放事件 - 切换开关状态、发射toggled()信号
void MyButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (isEnabled()) {
        if ((event->type() == QMouseEvent::MouseButtonRelease) \
                && (event->button() == Qt::LeftButton)) {
            event->accept();
            emit toggled();
            m_bChecked = false;
            this->update();
        }
    }
}

// 设置绘制文本
void MyButton::SetPaintText(const QString& sText)
{
    m_sText = sText;
    this->update();
}

// 设置色块颜色
void MyButton::SetBlockColor(const QColor& color)
{
    m_checkColor = color;
}

// 获得绘制文本
QString MyButton::GetPaintText()
{
    return m_sText;
}

// 获得色块颜色
QColor MyButton::GetBlockColor()
{
    return m_checkColor;
}
