/*
    设置界面：设置配置参数、信息

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef SETTINGDIALOG_H 
#define SETTINGDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QDialog>
#include <QCheckBox>
#include <QComboBox>
#include <QTabWidget>
#include <QHBoxLayout>
#include "common.h"
#include "push_button.h"
#include "drop_shadow_widget.h"

class SettingDialog : public DropShadowWidget
{
	Q_OBJECT

public:

	explicit SettingDialog(QWidget *parent = 0);
	~SettingDialog();
	void translateLanguage();

protected:

	void paintEvent(QPaintEvent *event);

private:

	void initTitle();
	void initCenter();
	void initBottom();
	void initTab1();
	void initTab2();
	void initTab3();
	void initTab4();
	void initTab5();
	void initTab6();

signals:

	void changeLanguage(LANGUAGE ui_language);

private slots:

	void updateConfig();

private:

	QHBoxLayout *title_layout; //标题布局
	QLabel *title_icon_label; //标题图标
	QLabel *title_label; //标题
	PushButton *close_button; //关闭按钮

	QHBoxLayout *bottom_layout; //底部布局
	QPushButton *ok_button; //确定按钮
	QPushButton *cancel_button; //取消按钮

	QTabWidget *tab_widget; 

	QWidget *tab1; //升级方式
	QGroupBox *tab1_group_box;
	QRadioButton *auto_rise_button; //自动升级
	QRadioButton *not_auto_rise_button; //不自动升级
	QCheckBox *rise_mummy_check_box; //不升级但备用木马库
	QCheckBox *game_check_box; //游戏时不升级
	QCheckBox *g3_check_box; //3G上网时不升级
	QCheckBox *p2p_check_box; //使用p2p/p2s技术为升级程序加速
	QCheckBox *mummy_check_box; //备用木马库升级完成后右下角提示

	QWidget *tab2; //高级设置
	QGroupBox *tab2_group_box1;
	QGroupBox *tab2_group_box2;
	QGroupBox *tab2_group_box3;
	QCheckBox *auto_start_check_box; //开机自启动
	QCheckBox *remove_own_check_box; //解除占有
	QCheckBox *strong_remove_check_box; //强力删除
	QCheckBox *mummy_kill_check_box; //木马云查杀
	QCheckBox *display_count_check_box; //显示软件升级数

	QWidget *tab3; //体验设置
	QGroupBox *tab3_group_box1;
	QGroupBox *tab3_group_box2;
	QRadioButton *auto_check_button; //每次启动自动体检
	QRadioButton *first_check_button; //首次开启体检
	QRadioButton *hand_check_button; //手动进行体检
	QRadioButton *select_quit_button; //选择退出方式
	QRadioButton *backstage_mode_button; //后台模式
	QRadioButton *immediacy_close_button; //直接关闭

	QWidget *tab4; //用户设置
	QGroupBox *tab4_group_box;
	QCheckBox *diaplay_experience_check_box; //完成任务显示获取经验值的动态提醒
	QCheckBox *diaplay_login_check_box; //自动登录后显示登录提示窗口
	QCheckBox *tray_quit_check_box; //托盘退出登录后显示提示窗口
	QCheckBox *new_character_check_box; //有新特权时显示通知窗口
	QCheckBox *rise_remind_check_box; //升级提醒通知窗口
	QLabel *language_label; //语言标签
	QComboBox *language_combo_box; //语言下拉框
	
	QWidget *tab5; //改善计划
	QGroupBox *tab5_group_box;
	QCheckBox *improve_plan_check_box;  //参加“360用户体检改善计划”
	QPushButton *understand_detail_button; //了解详情

	QWidget *tab6; //云安全计划
	QGroupBox *tab6_group_box1;
	QGroupBox *tab6_group_box2;
	QLabel *file_safe_label; //文件安全承诺
	QLabel *internet_safe_label; //网址安全承诺
	QCheckBox *file_safe_check_box; //加入360“文件云安全计划”
	QCheckBox *internet_safe_check_box; //加入360“网址云安全计划”
	QPushButton *look_privacy_button; //查看360用户隐私保护承诺

};

#endif SETTINGDIALOG_H
