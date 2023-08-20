/*
    用户信息：包括用户图标、昵称、帐号、删除按钮等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef ACCOUNTITEM_H
#define ACCOUNTITEM_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMouseEvent>

class AccountItem: public QWidget
{
	Q_OBJECT

public:

	explicit AccountItem(QWidget *parent = 0);
	~AccountItem();
	void setAccountNumber(QString account_text);
	QString getAccountNumber();

protected:

	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

signals:

	void showAccount(QString account);
	void removeAccount(QString account_number_text);

private slots:

	void removeAccount();

private:

	QLabel *account_number;  //账号
	QPushButton *delede_button;  //删除账号按钮
	bool mouse_press;

};

#endif //ACCOUNTITEM_H
