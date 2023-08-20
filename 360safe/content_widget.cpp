#include "content_widget.h"

ContentWidget::ContentWidget(QWidget *parent)
	: QWidget(parent)
{
	main_splitter = new QSplitter();
	main_splitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	main_splitter->setOrientation(Qt::Horizontal);
	main_splitter->setHandleWidth(1);

	this->initLeft();
	this->initRight();
	this->initRightTop();
	this->initRightCenter();
	this->initRightCenterFunction();
	this->initRightBottom();

	right_splitter->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	right_splitter->setOrientation(Qt::Vertical);
	right_splitter->setHandleWidth(1);

	right_top_widget->setFixedSize(250, 130);
	right_center_widget->setFixedSize(250, 90);
	right_bottom_widget->setFixedSize(250, 30);
	right_splitter->addWidget(right_top_widget);
	right_splitter->addWidget(right_center_widget);
	right_splitter->addWidget(right_center_function_widget);
	right_splitter->addWidget(right_bottom_widget);

	main_splitter->addWidget(left_widget);
	main_splitter->addWidget(right_splitter);

	//½ûÖ¹ÍÏ¶¯
	for(int i = 0; i<right_splitter->count();i++) 
	{ 
		QSplitterHandle *handle = right_splitter->handle(i); 
		handle->setEnabled(false); 
	} 

	for(int i = 0; i<main_splitter->count();i++) 
	{ 
		QSplitterHandle *handle = main_splitter->handle(i); 
		handle->setEnabled(false); 
	}

	QHBoxLayout *main_layout = new QHBoxLayout();
	main_layout->addWidget(main_splitter);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(0, 0, 0, 0);

	this->setLayout(main_layout);
	this->translateLanguage();
}

void ContentWidget::initLeft()
{
	left_widget = new QWidget();
	label = new QLabel();
	suggest_label = new QLabel();
	system_safe_label = new QLabel();
	power_button = new QPushButton();

	left_widget->resize(650, 500);

	QPixmap label_pixmap(":/contentWidget/computer");
	label->setPixmap(label_pixmap);
	label->setFixedSize(label_pixmap.size());

	QFont suggest_font = suggest_label->font();
	suggest_font.setPointSize(12);
	suggest_font.setBold(true);
	suggest_label->setFont(suggest_font);
	suggest_label->setObjectName("grayLabel");

	QFont system_safe_font = system_safe_label->font();
	system_safe_font.setBold(true);
	system_safe_label->setFont(system_safe_font);
	system_safe_label->setObjectName("grayLabel");

	QPixmap pixmap(":/contentWidget/power");
	power_button->setIcon(pixmap);
	power_button->setIconSize(pixmap.size());
	power_button->setFixedSize(180, 70);
	power_button->setObjectName("greenButton");

	QFont power_font = power_button->font();
	power_font.setPointSize(16);
	power_button->setFont(power_font);

	QVBoxLayout *v_layout = new QVBoxLayout();
	v_layout->addWidget(suggest_label);
	v_layout->addWidget(system_safe_label);
	v_layout->addStretch();
	v_layout->setSpacing(15);
	v_layout->setContentsMargins(0, 20, 0, 0);

	QHBoxLayout *h_layout = new QHBoxLayout();
	h_layout->addWidget(label, 0, Qt::AlignTop);
	h_layout->addLayout(v_layout);
	h_layout->addStretch();
	h_layout->setSpacing(20);
	h_layout->setContentsMargins(30, 20, 0, 0);

	QVBoxLayout *main_layout = new QVBoxLayout();
	main_layout->addLayout(h_layout);
	main_layout->addWidget(power_button, 0, Qt::AlignCenter);
	main_layout->addStretch();
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(0, 0, 0, 0);

	left_widget->setLayout(main_layout);
}

void ContentWidget::initRight()
{
	right_splitter = new QSplitter();
}

void ContentWidget::initRightTop()
{
	right_top_widget = new QWidget();
	login_button = new QPushButton();
	priv_label = new QLabel();
	info_label = new QLabel();
	privilege_label = new QLabel();
	register_button = new QPushButton();
	safe_button = new QPushButton();
	tab_button = new QPushButton();
	pet_button = new QPushButton();
	lottery_button = new QPushButton();
	cloud_five_button = new QPushButton();
	caipiao_button = new QPushButton();

	login_button->setFixedSize(240, 60);
	login_button->setObjectName("loginButton");
	QFont login_font = login_button->font();
	login_font.setBold(true);
	login_font.setPointSize(12);
	login_button->setFont(login_font);

	priv_label->setPixmap(QPixmap(":/contentWidget/priv"));
	QPixmap safe_pixmap(":/contentWidget/360");
	safe_button->setIcon(safe_pixmap);
	safe_button->setFixedSize(safe_pixmap.size());
	QPixmap tab_pixmap(":/contentWidget/tab");
	tab_button->setIcon(tab_pixmap);
	tab_button->setFixedSize(tab_pixmap.size());
	QPixmap pet_pixmap(":/contentWidget/pet");
	pet_button->setIcon(pet_pixmap);
	pet_button->setFixedSize(tab_pixmap.size());
	QPixmap lottery_pixmap(":/contentWidget/lottery");
	lottery_button->setIcon(lottery_pixmap);
	lottery_button->setFixedSize(lottery_pixmap.size());
	QPixmap cloud_five_pixmap(":/contentWidget/cloud_five");
	cloud_five_button->setIcon(cloud_five_pixmap);
	cloud_five_button->setFixedSize(cloud_five_pixmap.size());
	QPixmap caipiao_pixmap(":/contentWidget/caipiao");
	caipiao_button->setIcon(caipiao_pixmap);
	caipiao_button->setFixedSize(caipiao_pixmap.size());

	register_button->setCursor(Qt::PointingHandCursor);
	safe_button->setCursor(Qt::PointingHandCursor);
	tab_button->setCursor(Qt::PointingHandCursor);
	pet_button->setCursor(Qt::PointingHandCursor);
	lottery_button->setCursor(Qt::PointingHandCursor);
	cloud_five_button->setCursor(Qt::PointingHandCursor);
	caipiao_button->setCursor(Qt::PointingHandCursor);

	register_button->setObjectName("blueButton");
	safe_button->setObjectName("transparentButton");
	tab_button->setObjectName("transparentButton");
	pet_button->setObjectName("transparentButton");
	lottery_button->setObjectName("transparentButton");
	cloud_five_button->setObjectName("transparentButton");
	caipiao_button->setObjectName("transparentButton");

	QHBoxLayout *login_layout = new QHBoxLayout();
	login_layout->addWidget(login_button);
	login_layout->addStretch();
	login_layout->setContentsMargins(15, 0, 0, 0);

	QHBoxLayout *register_layout = new QHBoxLayout();
	register_layout->addStretch();
	register_layout->addWidget(priv_label);
	register_layout->addWidget(info_label);
	register_layout->addWidget(register_button);
	register_layout->addStretch();
	register_layout->setSpacing(5);
	register_layout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout *privilege_layout = new QHBoxLayout();
	privilege_layout->addStretch();
	privilege_layout->addWidget(privilege_label);
	privilege_layout->addWidget(safe_button);
	privilege_layout->addWidget(tab_button);
	privilege_layout->addWidget(pet_button);
	privilege_layout->addWidget(lottery_button);
	privilege_layout->addWidget(cloud_five_button);
	privilege_layout->addWidget(caipiao_button);
	privilege_layout->addStretch();
	privilege_layout->setSpacing(8);
	privilege_layout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout *main_layout = new QVBoxLayout();
	main_layout->addStretch();
	main_layout->addLayout(login_layout);
	main_layout->addLayout(register_layout);
	main_layout->addLayout(privilege_layout);
	main_layout->addStretch();
	main_layout->setSpacing(5);
	main_layout->setContentsMargins(10, 10, 10, 10);

	connect(login_button, SIGNAL(clicked()), this, SIGNAL(showLoginDialog()));
	connect(register_button, SIGNAL(clicked()), this, SIGNAL(showRegisterDialog()));

	right_top_widget->setLayout(main_layout);
}

void ContentWidget::initRightCenter()
{
	right_center_widget = new QWidget();
	fireproof_button = new QToolButton();
	triggerman_button = new QToolButton();
	net_shop_button = new QToolButton();
	line_label_1 = new QLabel();
	line_label_2 = new QLabel();
	line_label_1->setFixedWidth(10);
	line_label_2->setFixedWidth(10);
	line_label_1->installEventFilter(this);
	line_label_2->installEventFilter(this);

	fireproof_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	triggerman_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	net_shop_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	QPixmap fireproof_pixmap(":/contentWidget/fireproof");
	fireproof_button->setIcon(fireproof_pixmap);
	fireproof_button->setIconSize(fireproof_pixmap.size());
	fireproof_button->setFixedSize(fireproof_pixmap.width()+25, fireproof_pixmap.height()+25);

	QPixmap triggerman_pixmap(":/contentWidget/triggerman");
	triggerman_button->setIcon(triggerman_pixmap);
	triggerman_button->setIconSize(triggerman_pixmap.size());
	triggerman_button->setFixedSize(triggerman_pixmap.width()+25, triggerman_pixmap.height()+25);

	QPixmap net_shop_pixmap(":/contentWidget/net_shop");
	net_shop_button->setIcon(net_shop_pixmap);
	net_shop_button->setIconSize(net_shop_pixmap.size());
	net_shop_button->setFixedSize(net_shop_pixmap.width()+25, net_shop_pixmap.height()+25);

	fireproof_button->setObjectName("transparentToolButton");
	triggerman_button->setObjectName("transparentToolButton");
	net_shop_button->setObjectName("transparentToolButton");

	QHBoxLayout *h_layout = new QHBoxLayout();
	h_layout->addWidget(fireproof_button);
	h_layout->addWidget(line_label_1);
	h_layout->addWidget(triggerman_button);
	h_layout->addWidget(line_label_2);
	h_layout->addWidget(net_shop_button);
	h_layout->setSpacing(0);
	h_layout->setContentsMargins(0, 0, 0, 0);

	right_center_widget->setLayout(h_layout);
}

void ContentWidget::initRightCenterFunction()
{
	right_center_function_widget = new QWidget();
	function_label = new QLabel();
	more_button = new QPushButton();

	QFont function_font = function_label->font();
	function_font.setBold(true);
	function_label->setFont(function_font);
	function_label->setObjectName("infoLabel");
	more_button->setFixedSize(50, 25);
	more_button->setObjectName("blueButton");
	more_button->setCursor(Qt::PointingHandCursor);

	QHBoxLayout *h_layout = new QHBoxLayout();
	h_layout->addWidget(function_label);
	h_layout->addStretch();
	h_layout->addWidget(more_button);
	h_layout->setSpacing(0);
	h_layout->setContentsMargins(10, 5, 0, 0);

	QStringList string_list;
	string_list<<":/contentWidget/recovery"<<":/contentWidget/mobile"<<":/contentWidget/game_box"<<":/contentWidget/desktop"
		<<":/contentWidget/net_repair"<<":/contentWidget/auto_run"<<":/contentWidget/net_speed"<<":/contentWidget/net_pretext"
		<<":/contentWidget/first_add";

	QGridLayout *grid_layout = new QGridLayout();
	for(int i=0; i<string_list.size(); i++)
	{
		QToolButton *tool_button = new QToolButton();
		tool_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
		QPixmap button_pixmap(string_list.at(i));
		tool_button->setIcon(button_pixmap);
		tool_button->setIconSize(button_pixmap.size());
		tool_button->setFixedSize(button_pixmap.width()+50, button_pixmap.height()+35);
		tool_button->setObjectName("functionButton");

		button_list.append(tool_button);
		grid_layout->addWidget(tool_button, i/3, i%3);
	}
	grid_layout->setSpacing(0);
	grid_layout->setContentsMargins(5, 0, 5, 5);

	QVBoxLayout *v_layout = new QVBoxLayout();
	v_layout->addLayout(h_layout);
	v_layout->addLayout(grid_layout);
	v_layout->addStretch();
	v_layout->setSpacing(10);
	v_layout->setContentsMargins(0, 0, 0, 0);

	right_center_function_widget->setLayout(v_layout);
}

void ContentWidget::initRightBottom()
{
	right_bottom_widget = new QWidget();
	icon_label = new QLabel();
	connect_label = new QLabel();
	version_label = new QLabel();
	version_button = new QPushButton();

	QPixmap label_pixmap(":/contentWidget/cloud");
	icon_label->setPixmap(label_pixmap);
	icon_label->setFixedSize(label_pixmap.size());

	QPixmap pixmap(":/contentWidget/version");
	version_button->setIcon(pixmap);
	version_button->setIconSize(pixmap.size());
	version_button->setFixedSize(20, 20);
	version_button->setObjectName("transparentButton");

	QHBoxLayout *bottom_layout = new QHBoxLayout();
	bottom_layout->addWidget(icon_label);
	bottom_layout->addWidget(connect_label);
	bottom_layout->addStretch();
	bottom_layout->addWidget(version_label);
	bottom_layout->addWidget(version_button);
	bottom_layout->setSpacing(5);
	bottom_layout->setContentsMargins(10, 0, 10, 0);
	right_bottom_widget->setLayout(bottom_layout);
}

void ContentWidget::translateLanguage()
{
	suggest_label->setText(tr("suggest"));
	system_safe_label->setText(tr("system safe"));
	power_button->setText(tr("power"));

	login_button->setText(tr("login home"));
	info_label->setText(tr("show beautifull icon"));
	register_button->setText(tr("register"));
	privilege_label->setText(tr("privilege power"));

	fireproof_button->setText(tr("fireproof"));
	triggerman_button->setText(tr("triggerman"));
	net_shop_button->setText(tr("net shop"));

	function_label->setText(tr("function"));
	more_button->setText(tr("more"));
	button_list.at(0)->setText(tr("recovery"));
	button_list.at(1)->setText(tr("mobile"));
	button_list.at(2)->setText(tr("game box"));
	button_list.at(3)->setText(tr("desktop"));
	button_list.at(4)->setText(tr("net repair"));
	button_list.at(5)->setText(tr("auto run"));
	button_list.at(6)->setText(tr("net speed"));
	button_list.at(7)->setText(tr("net pretext"));
	button_list.at(8)->setText(tr("first add"));

	connect_label->setText(tr("connect success"));
	version_label->setText(tr("version"));
}

bool ContentWidget::eventFilter(QObject *obj, QEvent *event)
{
	if(obj == line_label_1 || obj == line_label_2)
	{
		if(event->type() == QEvent::Paint)
		{
			int label_height_1 = line_label_1->height();
			int label_width_1 = line_label_1->width();
			QPainter painter(line_label_1);
			painter.setPen(QPen(QColor(220, 220, 220), 1, Qt::DashLine));
			painter.drawLine(label_width_1/2, 0, label_width_1/2, label_height_1);	

			int label_height_2 = line_label_2->height();
			int label_width_2 = line_label_2->width();
			QPainter painter2(line_label_2);
			painter2.setPen(QPen(QColor(220, 220, 220), 1, Qt::DashLine));
			painter2.drawLine(label_width_2/2, 0, label_width_2/2, label_height_2);
		}
	}

	return QWidget::eventFilter(obj, event);
}
