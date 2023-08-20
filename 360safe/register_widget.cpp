#include "register_widget.h"

RegisterWidget::RegisterWidget(QWidget *parent)
	: DropShadowWidget(parent)
{
	this->resize(370, 275);
	title_label = new QLabel();
	close_button = new PushButton();
	icon_label = new QLabel();
	register_label = new QLabel();
	privilege_label = new QLabel();
	email_label = new QLabel();
	password_label = new QLabel();
	confirm_password_label = new QLabel();
	email_line_edit = new QLineEdit();
	password_line_edit = new QLineEdit();
	confirm_line_edit = new QLineEdit();
	tip_email_label = new QLabel();
	tip_password_label = new QLabel();
	tip_confirm_label = new QLabel();
	remember_check_box = new QCheckBox();
	auto_login_check_box = new QCheckBox();
	account_label = new QLabel();
	login_button = new QPushButton();
	register_button = new QPushButton();
	
	title_label->setObjectName("whiteLabel");
	close_button->setPicName(QString(":/sysButton/close"));

	icon_label->setFixedSize(70, 70);
	icon_label->setPixmap(QPixmap(":/img/360safe"));
	icon_label->setScaledContents(true);

	email_line_edit->setFixedHeight(25);
	password_line_edit->setFixedHeight(25);
	confirm_line_edit->setFixedHeight(25);

	register_label->setAlignment(Qt::AlignRight | Qt::AlignBottom);
	privilege_label->setAlignment(Qt::AlignRight | Qt::AlignTop);
	QFont register_font = register_label->font();
	register_font.setPointSize(14);
	register_label->setFont(register_font);
	register_label->setObjectName("whiteLabel");
	privilege_label->setObjectName("whiteLabel");
	register_button->setFixedSize(60, 25);
	login_button->setObjectName("examineAuthorizeButton");
	register_button->setObjectName("loginGreenButton");

	password_line_edit->setEchoMode(QLineEdit::Password);
	confirm_line_edit->setEchoMode(QLineEdit::Password);

	login_button->setCursor(Qt::PointingHandCursor);

	email_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	password_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	confirm_password_label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	tip_email_label->setObjectName("grayLabel");
	tip_password_label->setObjectName("grayLabel");

	QHBoxLayout *title_layout = new QHBoxLayout();
	title_layout->addWidget(title_label);
	title_layout->addStretch();
	title_layout->addWidget(close_button);
	title_layout->setSpacing(0);
	title_layout->setContentsMargins(10, 0, 5, 10);

	QVBoxLayout *privilege_layout = new QVBoxLayout();
	privilege_layout->addWidget(register_label);
	privilege_layout->addWidget(privilege_label);
	privilege_layout->setSpacing(5);
	privilege_layout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout *icon_layout = new QHBoxLayout();
	icon_layout->addWidget(icon_label);
	icon_layout->addStretch();
	icon_layout->addLayout(privilege_layout);
	icon_layout->setSpacing(0);
	icon_layout->setContentsMargins(30, 0, 20, 0);

	QGridLayout *grid_layout = new QGridLayout();
	grid_layout->addWidget(email_label, 0, 0);
	grid_layout->addWidget(email_line_edit, 0, 1, 1, 2);
	grid_layout->addWidget(tip_email_label, 0, 3);
	grid_layout->addWidget(password_label, 1, 0);
	grid_layout->addWidget(password_line_edit, 1, 1, 1, 2);
	grid_layout->addWidget(tip_password_label, 1, 3);
	grid_layout->addWidget(confirm_password_label, 2, 0);
	grid_layout->addWidget(confirm_line_edit, 2, 1, 1, 2);
	grid_layout->addWidget(tip_confirm_label, 2, 3);
	grid_layout->addWidget(remember_check_box, 3, 1);
	grid_layout->addWidget(auto_login_check_box, 3, 2);
	grid_layout->setHorizontalSpacing(5);
	grid_layout->setVerticalSpacing(10);
	grid_layout->setContentsMargins(0, 10, 10, 10);

	QHBoxLayout *bottom_layout = new QHBoxLayout();
	bottom_layout->addWidget(account_label);
	bottom_layout->addWidget(login_button);
	bottom_layout->addStretch();
	bottom_layout->addWidget(register_button);
	bottom_layout->setSpacing(0);
	bottom_layout->setContentsMargins(20, 0, 10, 5);
    
	QVBoxLayout *main_layout = new QVBoxLayout();
	main_layout->addLayout(title_layout);
	main_layout->addLayout(icon_layout);
	main_layout->addLayout(grid_layout);
	main_layout->addLayout(bottom_layout);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

	connect(close_button, SIGNAL(clicked()), this, SLOT(hide()));

	this->setLayout(main_layout);
	this->translateLanguage();
}

RegisterWidget::~RegisterWidget()
{

}

void RegisterWidget::translateLanguage()
{
	title_label->setText(tr("360 register"));
	close_button->setToolTip(tr("close"));
	register_label->setText(tr("register 360 safe account"));
	privilege_label->setText(tr("privilege"));
	email_label->setText(tr("email"));
	password_label->setText(tr("password"));
	confirm_password_label->setText(tr("confirm password"));
	tip_email_label->setText(tr("forgot password"));
	tip_password_label->setText(tr("6-20 bytes"));
	remember_check_box->setText(tr("remember password"));
	auto_login_check_box->setText(tr("auto login"));
	account_label->setText(tr("account"));
	login_button->setText(tr("login"));
	register_button->setText(tr("register"));
}

void RegisterWidget::paintEvent(QPaintEvent *event)
{
	DropShadowWidget::paintEvent(event);
	QString skin_name = Util::getSkinName();
	int height = 95;
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
	painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(skin_name));
	painter.drawRect(QRect(SHADOW_WIDTH, height, this->width()-2*SHADOW_WIDTH, this->height()-height-SHADOW_WIDTH));
}