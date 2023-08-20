/*
    标题：包括最小化、关闭等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QSignalMapper>
#include <QVBoxLayout>
#include "push_button.h"
#include "tool_button.h"
#include "main_menu.h"

class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWidget(QWidget *parent = 0);
	void translateLanguage();

signals:

	void showSkin();
    void showMin();
	void showMainMenu();
	void closeWidget();
	void turnPage(int current_page);

public slots:

    void setPage(const QString &current_page);

private:

    QPoint press_point;//鼠标按下去的点
    bool is_move;

	QLabel *version_title; //标题
	PushButton *medal_button; //勋章墙
    PushButton *skin_button; //换肤
    PushButton *main_menu_button; //主菜单
    PushButton *min_button; //最小化
    PushButton *feedback_button; //反馈意见
    PushButton *close_button; //关闭

	QLabel *safe_360_label;  //360安全卫士
	QLabel *safe_label;  //360安全卫士

	QList<ToolButton *> button_list;
};

#endif // TITLEWIDGET_H
