/*
	登陆后加载界面 包括加载等待图标、账号、正在加载等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include <QWidget>
#include <QLabel>  
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include "util.h"

class LoadingWidget : public QWidget
{
	Q_OBJECT

public:

	explicit LoadingWidget(QWidget *parent = 0);
	~LoadingWidget();
	void translateLanguage();
	void start(bool is_start);
	void setAccount(QString account);

private slots:

	void updatePixmap();

private:

	QLabel *loading_label;  //加载等待图标
	QLabel *account_label;  //账号名称
	QLabel *waiting_label;  //正在加载
	QTimer *timer; //定时器，变化图标
	int index; //图标下标值
	QString account; //账号名
	
};

#endif //LOADINGWIDGET_H
