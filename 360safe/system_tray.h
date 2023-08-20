/*
    系统托盘：包括打开360、求救中心等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef SYSYTEMTRAY_H
#define SYSYTEMTRAY_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QWidgetAction>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QPainter>

class SystemTray : public QSystemTrayIcon
{
	Q_OBJECT

public:

	explicit SystemTray(QWidget *parent = 0);
	~SystemTray();
	void translateLanguage();

protected:

	bool eventFilter(QObject *obj, QEvent *event);

signals:

	void showWidget();

private:

	void createTopAction();
	void createBottomAction();
	void createAction();
	void addActions();

private:

	QMenu *tray_menu; //托盘菜单

	QWidget *top_widget;  //顶部菜单项
	QWidgetAction *top_widget_action;  //播放模式：上一首、播放/暂停、下一首
	QLabel *protect_label;  //360已保护电脑...天
    QPushButton *open_button;  //木马防火墙已经开启
    QPushButton *enter_button;  //进入
	
	QWidget *bottom_widget;  //底部菜单项
	QWidgetAction *bottom_widget_action;  //播放模式：上一首、播放/暂停、下一首
    QPushButton *game_mode_button;  //进入游戏模式
    QPushButton *online_mode_button;  //进入网购模式

	QAction *action_open; //打开360安全卫士
	QAction *action_help_center; //求助中心
	QAction *action_kill_mummy; //查杀木马
	QAction *action_clear; //清理垃圾
	QAction *action_optimize; //一键优化
	QAction *action_fireproof; //检查更新
	QAction *action_show_speed; //显示加速球
	QAction *action_soft_manage; //软件管家
	QAction *action_safe_notice; //安全通知
	QAction *action_rise; //升级
	QAction *action_login; //360用户登录
	QAction *action_separate; //隔离沙箱
	QAction *action_logout; //退出

};

#endif //SYSYTEMTRAY_H
