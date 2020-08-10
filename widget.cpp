#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 初始化自定义按钮
    MyButton *pBtnPos = new MyButton(false);
    MyButton *pBtnSize = new MyButton(false);
    MyButton *pBtnColor = new MyButton(true);
    pBtnPos->SetPaintText(QString::fromLocal8Bit("居中"));
    pBtnColor->SetBlockColor(QColor(196, 68, 21));
    pBtnSize->SetPaintText(QString::fromLocal8Bit("20px"));

    // 水平布局
    QHBoxLayout *pHLayoutMain = new QHBoxLayout(this);
    pHLayoutMain->addWidget(pBtnPos);
    pHLayoutMain->addWidget(pBtnColor);
    pHLayoutMain->addWidget(pBtnSize);

    // 连接信号槽
    connect(pBtnPos, SIGNAL(toggled()), this, SLOT(onToggled()));
    connect(pBtnColor, SIGNAL(toggled()), this, SLOT(onToggled()));
    connect(pBtnSize, SIGNAL(toggled()), this, SLOT(onToggled()));
}

Widget::~Widget()
{
    delete ui;
}

// 自定义按钮触发信号槽
void Widget::onToggled()
{
    qDebug() << "clicked";
}
