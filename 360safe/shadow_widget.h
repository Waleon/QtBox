/*
	阴影边框

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef SHADOWWIDGET_H
#define SHADOWWIDGET_H

#include <QDialog>
#include <QPainter>
#include "common.h"

class ShadowWidget : public QDialog
{
	Q_OBJECT

public:

	explicit ShadowWidget(QWidget *parent = 0);
	~ShadowWidget();

protected:

	virtual void paintEvent(QPaintEvent *event);

private:

	void drawWindowShadow(QPainter &painter);

};


#endif //SHADOWWIDGET_H
