
#ifndef REGISTERWIDGET_H
#define REGISTERWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include "push_button.h"
#include "util.h"
#include "drop_shadow_widget.h"

class RegisterWidget : public DropShadowWidget
{
	Q_OBJECT

public:

	explicit RegisterWidget(QWidget *parent = 0);
	~RegisterWidget();
	void translateLanguage();

protected:

	void paintEvent(QPaintEvent *event);

private:

	QLabel *title_label;
	PushButton *close_button;
	QLabel *icon_label;
	QLabel *register_label;
	QLabel *privilege_label;
	QLabel *email_label;
	QLabel *password_label;
	QLabel *confirm_password_label;
	QLineEdit *email_line_edit;
	QLineEdit *password_line_edit;
	QLineEdit *confirm_line_edit;
	QLabel *tip_email_label;
	QLabel *tip_password_label;
	QLabel *tip_confirm_label;
	QCheckBox *remember_check_box;
	QCheckBox *auto_login_check_box;
	QLabel *account_label;
	QPushButton *login_button;
	QPushButton *register_button;
};

#endif //REGISTERWIDGET_H
