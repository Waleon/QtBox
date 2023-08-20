/*
    主界面：包括体检、查杀木马等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTranslator>
#include <QLocalSocket>
#include <QLocalServer>
#include "shadow_widget.h"
#include "title_widget.h"
#include "content_widget.h"
#include "system_tray.h"
#include "about_us.h"
#include "main_menu.h"
#include "character_widget.h"
#include "setting_dialog.h"
#include "skin_widget.h"
#include "login_dialog.h"
#include "register_widget.h"
#include "drop_shadow_widget.h"
#include "kill_mummy_widget.h"
#include <QStackedWidget>

class MainWidget : public DropShadowWidget
{
    Q_OBJECT

public:

    MainWidget(QWidget *parent = 0);
    ~MainWidget();
	void setTranslator(QTranslator* translator);
	bool isRunning(); 

protected:

    virtual void paintEvent(QPaintEvent *event);

public slots:

	void showWidget();

private slots:

	void newLocalConnection();  

	void showSkinWidget();
	void showMainMenu();
	void showSettingDialog();
	void showAboutUs();
	void showNewCharacter();
	void showLoginDialog();
	void showRegisterDialog();
	void changeSkin(QString skin_name);
	void iconIsActived(QSystemTrayIcon::ActivationReason reason);
	void changeLanguage(LANGUAGE language);

	void turnPage(int current_page);

private:

	void initLocalConnection();

private:

	QStackedWidget *statked_widget;
	TitleWidget *title_widget; //标题栏
	ContentWidget *content_widget; //主界面内容
	KillMummyWidget *kill_mummy_widget;  //查杀木马界面
	SystemTray *system_tray; //托盘项
	SettingDialog *setting_dialog; //设置界面
	CharacterWidget *character_widget; //新版特性界面
	AboutUsDialog *about_us_dialog; //关于我们界面
	LoginDialog *login_dialog; //登录界面
	RegisterWidget *register_widget; //注册界面
    QString skin_name;//主窗口背景图片的名称
	MainMenu *main_menu; //主菜单
	SkinWidget *skin_widget; //显示皮肤界面

	QTranslator* translator; //翻译器
	LANGUAGE current_language; //当前语言

	QLocalServer *server;  
    bool is_running;

};

#endif // MAINWIDGET_H
