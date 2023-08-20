/*
	登陆界面 包括360、新浪、人人登录

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QStackedLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QListWidgetItem>
#include <QListWidget>
#include <QGridLayout>
#include "push_button.h"
#include "msg_box.h"
#include "loading_widget.h"
#include "common.h"
#include "drop_shadow_widget.h"

class LoginDialog : public DropShadowWidget
{	
	Q_OBJECT

public:

	explicit LoginDialog(QWidget *parent = 0);
	~LoginDialog();
	void translateLanguage();

protected:

	void paintEvent(QPaintEvent *event);

private slots:

	void turnSina();
	void turnRenRen();
	void showAccount(QString account);
	void removeAccount(QString account);
	void verify();

private:

	void initSafeWidget();
	void initRenRenWidget();
	void initSinaWidget();
	void initLoginCenter();
	void changeTitle();
	void turnWidget();

private:

	QStackedLayout *main_stacked_layout; //新浪、360、人人网界面
	QStackedLayout *stacked_layout; //360、人人网界面
	QStackedLayout *login_stacked_layout; //360、登录验证界面
	QWidget *safe_renren_center_widget;

	QWidget *safe_renren_widget; //安全卫士界面
	QWidget *safe_widget;
	QLabel *icon_label;
	QLabel *safe_label;
	QLabel *protect_label;

	QWidget *renren_widget; //人人界面
	QLabel *renren_icon_label;
	QLabel *renren_info_label;
	QLabel *renren_net_label;
	QLabel *renren_login_label;

	QWidget *sina_widget; //新浪界面
	QLabel *sina_icon_label; //新浪图标
	QLabel *sina_info_label; //新浪微博
	QLabel *sina_net_label; //sina.com
	QPushButton *sina_register_button; //新浪注册按钮
	QLineEdit *sina_account_line_edit; //新浪帐号
	QLineEdit *sina_password_line_edit; //新浪密码
	QPushButton *examine_authorize_button; //查看授权信息
	QPushButton *authorize_button; //授权按钮
	QCheckBox *sina_login_check_box; //自动登录
	QCheckBox *safe_attention_check_box; //关注360安全卫士

	QLabel *title_label;
	QLabel *account_label;
	QLabel *password_label;
	QLabel *other_account_label;
	PushButton *close_button;
	QPushButton *sina_button;
	QPushButton *renren_button;
	QLineEdit *password_line_edit;
	QPushButton *register_button;
	QPushButton *forgot_button;
	QPushButton *login_button;
	QCheckBox *remember_check_box;
	QCheckBox *auto_login_check_box;
	QComboBox *account_combo_box;
	QListWidget *list_widget;

	LOGIN login; //登录显示的界面
	LOGIN sina_login; //新浪按钮表示的界面

	MsgBox *msg_box; //删除用户提示界面
	LoadingWidget *loading_widget; //等待界面，正在登录

};

#endif //LOGINDIALOG_H
