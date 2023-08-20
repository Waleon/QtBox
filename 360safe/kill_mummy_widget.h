/*
	木马查杀 包括快速扫描、全盘扫描、自定义扫描等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef  KILLMUMMYWIDGET_H
#define  KILLMUMMYWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QToolButton>
#include <QHBoxLayout>

class KillMummyWidget : public QWidget
{
	Q_OBJECT

public:

	explicit KillMummyWidget(QWidget *parent = 0);
	~KillMummyWidget();
	void translateLanguage();

private:

	QLabel *tip_icon_label;  //提示图标
	QLabel *tip_info_label;  //提示信息
	QLabel *tip_suggest_label;  //建议信息
	QToolButton *fast_scan_button; //快速扫描
	QToolButton *full_scan_button; //全盘扫描
	QToolButton *custom_scan_button; //自定义扫描
};

#endif  KILLMUMMYWIDGET_H
