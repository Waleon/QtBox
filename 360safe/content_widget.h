/*
    电脑体检：包括开始体检、登录360、注册、防火墙、功能大全等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>
#include <QSplitter>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QPainter>
#include <QPen>
#include <QHBoxLayout>
#include <QEvent>
#include <QVBoxLayout>

class ContentWidget : public QWidget
{
    Q_OBJECT

public:

    explicit ContentWidget(QWidget *parent = 0);
	void translateLanguage();

private:

	void initLeft();
	void initRightTop();
	void initRightCenter();
	void initRightCenterFunction();
	void initRightBottom();
	void initRight();

protected:

	bool eventFilter(QObject *obj, QEvent *event);

signals:

	void showLoginDialog();
	void showRegisterDialog();

private:

	QSplitter *main_splitter;

	QWidget *left_widget;
	QLabel *label;
	QLabel *suggest_label;
	QLabel *system_safe_label;
	QPushButton *power_button; //立即体检按钮

	QSplitter *right_splitter;
	QWidget *right_widget;
	QWidget *right_top_widget;

	QPushButton *login_button; //登录我的360帐号
	QLabel *priv_label; //皇砖图标
	QLabel *info_label; //开启炫动卫视图标
	QLabel *privilege_label; //转享特权
	QPushButton *register_button; //10秒免费注册
	QPushButton *safe_button; //特权领360炫动logo
	QPushButton *tab_button;  //领取炫动导航功能图标
	QPushButton *pet_button;  //宠物安仔精灵
	QPushButton *lottery_button;  //按在抱枕大派送
	QPushButton *cloud_five_button;  //5G云盘
	QPushButton *caipiao_button;  //彩票

	QWidget *right_center_widget;
	QToolButton *fireproof_button; //360防火墙
	QToolButton *triggerman_button; //360保镖
	QToolButton *net_shop_button; //网购先赔
	QLabel *line_label_1; //虚线
	QLabel *line_label_2; //虚线

	QWidget *right_center_function_widget;
	QLabel *function_label; //功能大全
	QPushButton *more_button; //更多
	QList<QToolButton *> button_list;  //按钮容器

	QWidget *right_bottom_widget;
	QLabel *icon_label; //云图标
	QLabel *connect_label; //成功连接云安全
	QLabel *version_label; //版本号
	QPushButton *version_button; //版本升级

};

#endif // CONTENTWIDGET_H
