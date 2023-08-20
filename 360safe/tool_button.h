/*
    功能按钮：包括体检、查杀木马等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef TOOlBUTTON_H
#define TOOlBUTTON_H

#include <QToolButton>
#include <QMouseEvent>
#include <QPainter>

class ToolButton : public QToolButton
{

public:

	explicit ToolButton(QString pic_name, QWidget *parent = 0);
	~ToolButton();
	void setMousePress(bool mouse_press);

protected:

	void enterEvent(QEvent *);
	void leaveEvent(QEvent *);
	void mousePressEvent(QMouseEvent *event);
	void paintEvent(QPaintEvent *event);
	void painterInfo(int top_color, int middle_color, int bottom_color);

public:

	bool mouse_over; //鼠标是否移过
	bool mouse_press; //鼠标是否按下
};

#endif //TOOlBUTTON_H
