/*
    更换皮肤：包括皮肤、皮肤名称、下载次数、使用此皮肤按钮等

    作者：一去丶二三里
    博客地址：https://waleon.blog.csdn.net
    微信公众号：高效程序员
    QQ：550755606
    QQ 技术群：242790253
    微信技术群：加微信（iwaleon），邀请入群。

    注：请尊重原作者劳动成果，仅供学习使用！
*/

#ifndef CHANGESKINWIDGET_H
#define CHANGESKINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QPainter>
#include <QPen>

class ChangeSkinWidget : public QWidget
{
	Q_OBJECT

public:
	explicit ChangeSkinWidget(QWidget *parent = 0);
	~ChangeSkinWidget();
	void translateLanguage();
	QString getPixmapName();

protected:

	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);
	void paintEvent(QPaintEvent *event);

signals:

	void changeSkin();

public slots:

	void changeSkin(QString pixmap_name, QString skin_name, QString download_count);

private slots:

	void useSkin();

private:

	QLabel *skin_label; //显示皮肤
	QLabel *skin_name_label; //显示皮肤名称
	QLabel *download_count_label; //显示下载次数
	QPushButton *use_skin_button; //使用此皮肤按钮

	QString pixmap_name;
	bool mouse_press;
	bool mouse_enter;
};

#endif  //CHANGESKINWIDGET_H
