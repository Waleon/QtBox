/*
    提示界面：删除账号时，给与提示

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef MSGBOX_H
#define MSGBOX_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "common.h"
#include "push_button.h"
#include "drop_shadow_widget.h"

class MsgBox : public DropShadowWidget
{
	Q_OBJECT

public:

	explicit MsgBox(QWidget *parent = 0);
	~MsgBox();
	void translateLanguage();
	void setInfo(QString title_info, QString info, QPixmap pixmap, bool is_ok_hidden);

signals:

	void okMessageHidden(bool is_checked);
	void msgChecked(bool is_checked, bool is_ok);
	
private slots:

	void okOperate();
	void cancelOperate();

protected:

	void paintEvent(QPaintEvent *event);

private:

	QLabel *title_label;
	QLabel *title_icon_label;
	QLabel *msg_label; //提示图片
	QLabel *ask_label; //提示信息
	PushButton *close_button; //提示框上的关闭按钮
	QPushButton *ok_button; //下载按钮
	QPushButton *cancel_button; //取消按钮

	QString ok_text;
	QString cancel_text;

};

#endif  //MSGBOX_H
