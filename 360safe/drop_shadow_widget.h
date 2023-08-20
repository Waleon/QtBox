/*
	设置阴影边框

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/


#ifndef DROPSHADOWWIDGET_H
#define DROPSHADOWWIDGET_H

#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>

class DropShadowWidget : public QDialog
{
	Q_OBJECT

public:

	explicit DropShadowWidget(QWidget *parent = 0);
	~DropShadowWidget();

protected:

	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);

private:

	QPoint move_point; //移动的距离
	bool mouse_press; //按下鼠标左键

};

#endif //DROPSHADOWWIDGET_H
