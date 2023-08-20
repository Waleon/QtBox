/**
	主菜单：包括关于我们、新版特性等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMenu>
#include <QDesktopServices>
#include <QUrl>
#include "common.h"

class MainMenu : public QMenu
{
	Q_OBJECT

public:

	explicit MainMenu(QWidget *parent = 0);
	void translateActions();

signals:

	void showSettingDialog();
	void showNewCharacter();
	void showAboutUs();

private slots:

	void showPage();

private:
	
	void createActions();

private:

	QAction *action_setting; //设置
	QAction *action_new_character; //新版特性
	QAction *action_check_update; //检查更新
	QAction *action_change_company; //切换为企业版
	QAction *action_help_online; //在线帮助
	QAction *action_platform_help; //论坛求助
	QAction *action_login_home; //360网站
	QAction *action_protect; //隐私保护
	QAction *action_about_us; //关于我们

};

#endif //MAINMENU_H
