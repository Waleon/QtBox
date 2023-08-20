/*
    新版特性：包括功能大全、Cookie清理、网购先陪、加速球等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef CHARACTERWIDGET_H
#define CHARACTERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QApplication>
#include "push_button.h"
#include "clabel.h"
#include "common.h"

class CharacterWidget : public QWidget
{
	Q_OBJECT

public:
	explicit CharacterWidget(QWidget *parent = 0);
	~CharacterWidget();
	void translateLanguage();

	enum EButtonMouseState
	{
		EButtonMouseDefault = 0,
		EButtonMouseEnter,
		EButtonMousePress,
		EButtonMouseNone
	};

protected:

	void mousePressEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *);

private slots:

	void changeCurrentPage(CLabel *);

private:

	void changeCurrentButton();
	void setLabelMove(bool);
	void moveCurrentPage(bool);

	QStringList name_list;
	QPoint m_mouseSrcPos;
	QPoint m_mouseDstPos;
	int current_pos_x;
	bool mouse_press;
	bool mouse_move;
	bool label_move;

	QLabel *background_label; //背景图片
	int current_index; //当前图片下标
	QLabel *total_label; //图片（结合体）
	CLabel *label_array[4]; //存储图片的数组
	PushButton *close_button; //关闭按钮
};

#endif //CHARACTERWIDGET_H
