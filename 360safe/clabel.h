/*
	新版特性时使用

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef CLABEL_H
#define CLABEL_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>

class CLabel : public QWidget
{
    Q_OBJECT

public:

    explicit CLabel(QWidget *parent = 0);
    ~CLabel();

    void setPixmap(const QPixmap &);
    void setText(const QString &);
    void setMouseEnterFlag(bool);
    void setMousePressFlag(bool);

protected:

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

signals:

    void signalLabelPress(CLabel *);

private:

    void initVariable();
    void initSetupUi();
    void createFrame();
    void createWidget();
    void createLayout();
    void paintWidget(int, QPainter *);
    bool getMouseEnterFlag();
    bool getMousePressFlag();

    bool m_mouseEnterFlag;
    bool m_mousePressFlag;

    QHBoxLayout *m_pHLayout;
    QLabel *m_pLabelIcon;
    QLabel *m_pLabelText;
};

#endif //CLABEL_H
