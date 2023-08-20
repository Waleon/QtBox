#include "setting_dialog.h"
#include "util.h"

Q_DECLARE_METATYPE(LANGUAGE)

SettingDialog::SettingDialog(QWidget *parent)
	: DropShadowWidget(parent)
{
	resize(560, 400);
	this->initTitle();
	this->initCenter();
	this->initTab1();
	this->initTab2();
	this->initTab3();
	this->initTab4();
	this->initTab5();
	this->initTab6();
	this->initBottom();

	QVBoxLayout *main_layout = new QVBoxLayout();
	main_layout->addLayout(title_layout);
	main_layout->addWidget(tab_widget);
	main_layout->addLayout(bottom_layout);
	main_layout->addStretch();
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

	setLayout(main_layout);
	this->translateLanguage();
}

void SettingDialog::initTitle()
{
	title_label = new QLabel();
	title_icon_label = new QLabel();
	close_button = new PushButton();
	close_button->setPicName(QString(":/sysButton/close"));

	title_label->setObjectName("whiteLabel");
	QPixmap pixmap(":/img/safe");
	title_icon_label->setPixmap(pixmap);
	title_icon_label->setFixedSize(16, 16);
	title_icon_label->setScaledContents(true);
	
	title_layout = new QHBoxLayout();
	title_layout->addWidget(title_icon_label, 0, Qt::AlignVCenter);
	title_layout->addWidget(title_label, 0, Qt::AlignVCenter);
	title_layout->addStretch();
	title_layout->addWidget(close_button, 0, Qt::AlignTop);
	title_layout->setSpacing(5);
	title_layout->setContentsMargins(10, 0, 5, 10);

	connect(close_button, SIGNAL(clicked()), this, SLOT(hide()));
}

void SettingDialog::initTab1()
{
	tab1_group_box = new QGroupBox();
	auto_rise_button = new QRadioButton();
	not_auto_rise_button = new QRadioButton();
	rise_mummy_check_box = new QCheckBox();
	game_check_box = new QCheckBox();
	g3_check_box = new QCheckBox();
	p2p_check_box = new QCheckBox();
	mummy_check_box = new QCheckBox();

	QFont group_box_font = tab1_group_box->font();
	group_box_font.setBold(true);
	tab1_group_box->setFont(group_box_font);
	tab1_group_box->setFixedSize(480, 250);
	
	QHBoxLayout *rise_mummy_layout = new QHBoxLayout();
	rise_mummy_layout->addWidget(rise_mummy_check_box);
	rise_mummy_layout->setSpacing(0);
	rise_mummy_layout->setContentsMargins(20, 0, 0, 0);

	QVBoxLayout *group_layout = new QVBoxLayout();
	group_layout->addWidget(auto_rise_button);
	group_layout->addWidget(not_auto_rise_button);
	group_layout->addLayout(rise_mummy_layout);
	group_layout->addWidget(game_check_box);
	group_layout->addWidget(g3_check_box);
	group_layout->addWidget(p2p_check_box);
	group_layout->addWidget(mummy_check_box);
	group_layout->setSpacing(0);
	group_layout->setContentsMargins(30, 0, 0, 0);
	tab1_group_box->setLayout(group_layout);

	QHBoxLayout *tab1_layout = new QHBoxLayout();
	tab1_layout->addWidget(tab1_group_box);
	tab1_layout->setSpacing(0);
	tab1_layout->setContentsMargins(0, 0, 0, 0);
	tab1->setLayout(tab1_layout);
}

void SettingDialog::initTab2()
{
	tab2_group_box1 = new QGroupBox();
	tab2_group_box2 = new QGroupBox();
	tab2_group_box3 = new QGroupBox();
	auto_start_check_box = new QCheckBox();
	remove_own_check_box = new QCheckBox();
	strong_remove_check_box = new QCheckBox();
	mummy_kill_check_box = new QCheckBox();
	display_count_check_box = new QCheckBox();

	QFont group_box_font = tab2_group_box1->font();
	group_box_font.setBold(true);
	tab2_group_box1->setFont(group_box_font);
	tab2_group_box2->setFont(group_box_font);
	tab2_group_box3->setFont(group_box_font);

	QHBoxLayout *group_box1_layout = new QHBoxLayout();
	group_box1_layout->addWidget(auto_start_check_box);
	group_box1_layout->setSpacing(0);
	group_box1_layout->setContentsMargins(30, 0, 0, 0);
	tab2_group_box1->setLayout(group_box1_layout);

	QVBoxLayout *group_box2_layout = new QVBoxLayout();
	group_box2_layout->addWidget(remove_own_check_box);
	group_box2_layout->addWidget(strong_remove_check_box);
	group_box2_layout->addWidget(mummy_kill_check_box);
	group_box2_layout->setSpacing(0);
	group_box2_layout->setContentsMargins(30, 0, 0, 0);
	tab2_group_box2->setLayout(group_box2_layout);

	QHBoxLayout *group_box3_layout = new QHBoxLayout();
	group_box3_layout->addWidget(display_count_check_box);
	group_box3_layout->setSpacing(0);
	group_box3_layout->setContentsMargins(30, 0, 0, 0);
	tab2_group_box3->setLayout(group_box3_layout);

	tab2_group_box1->setFixedSize(480, 60);
	tab2_group_box2->setFixedSize(480, 110);
	tab2_group_box3->setFixedSize(480, 60);

	QVBoxLayout *group_layout = new QVBoxLayout();
	group_layout->addWidget(tab2_group_box1, 0, Qt::AlignCenter);
	group_layout->addWidget(tab2_group_box2, 0, Qt::AlignCenter);
	group_layout->addWidget(tab2_group_box3, 0, Qt::AlignCenter);
	group_layout->addStretch();
	group_layout->setSpacing(10);
	group_layout->setContentsMargins(0, 20, 0, 0);
	tab2->setLayout(group_layout);
}

void SettingDialog::initTab3()
{
	tab3_group_box1 = new QGroupBox();
	tab3_group_box2 = new QGroupBox();
	auto_check_button = new QRadioButton();
	first_check_button = new QRadioButton();
	hand_check_button = new QRadioButton();
	select_quit_button = new QRadioButton();
	backstage_mode_button = new QRadioButton();
	immediacy_close_button = new QRadioButton();

	QFont group_box_font = tab3_group_box1->font();
	group_box_font.setBold(true);
	tab3_group_box1->setFont(group_box_font);
	tab3_group_box2->setFont(group_box_font);

	QVBoxLayout *group_box1_layout = new QVBoxLayout();
	group_box1_layout->addWidget(auto_check_button);
	group_box1_layout->addWidget(first_check_button);
	group_box1_layout->addWidget(hand_check_button);
	group_box1_layout->setSpacing(0);
	group_box1_layout->setContentsMargins(30, 0, 0, 0);
	tab3_group_box1->setLayout(group_box1_layout);

	QVBoxLayout *group_box2_layout = new QVBoxLayout();
	group_box2_layout->addWidget(select_quit_button);
	group_box2_layout->addWidget(backstage_mode_button);
	group_box2_layout->addWidget(immediacy_close_button);
	group_box2_layout->setSpacing(0);
	group_box2_layout->setContentsMargins(30, 0, 0, 0);
	tab3_group_box2->setLayout(group_box2_layout);

	tab3_group_box1->setFixedSize(480, 120);
	tab3_group_box2->setFixedSize(480, 120);

	QVBoxLayout *group_layout = new QVBoxLayout();
	group_layout->addWidget(tab3_group_box1, 0, Qt::AlignCenter);
	group_layout->addWidget(tab3_group_box2, 0, Qt::AlignCenter);
	group_layout->addStretch();
	group_layout->setSpacing(10);
	group_layout->setContentsMargins(0, 20, 0, 0);
	tab3->setLayout(group_layout);
}

void SettingDialog::initTab4()
{
	tab4_group_box = new QGroupBox();
	diaplay_experience_check_box = new QCheckBox();
	diaplay_login_check_box = new QCheckBox();
	tray_quit_check_box = new QCheckBox();
	new_character_check_box = new QCheckBox();
	rise_remind_check_box = new QCheckBox();
	language_label = new QLabel();
	language_combo_box = new QComboBox();

	language_combo_box->addItem("chinese", UI_ZH);
	language_combo_box->addItem("english", UI_EN);
	language_label->setBuddy(language_combo_box);
	language_combo_box->setFixedWidth(70);

	QHBoxLayout *language_layout = new QHBoxLayout();
	language_layout->addWidget(language_label);
	language_layout->addWidget(language_combo_box);
	language_layout->addStretch();

	QFont group_box_font = tab4_group_box->font();
	group_box_font.setBold(true);
	tab4_group_box->setFont(group_box_font);
	tab4_group_box->setFixedSize(480, 240);

	QVBoxLayout *group_layout = new QVBoxLayout();
	group_layout->addWidget(diaplay_experience_check_box);
	group_layout->addWidget(diaplay_login_check_box);
	group_layout->addWidget(tray_quit_check_box);
	group_layout->addWidget(new_character_check_box);
	group_layout->addWidget(rise_remind_check_box);
	group_layout->addLayout(language_layout);
	group_layout->setSpacing(0);
	group_layout->setContentsMargins(30, 0, 0, 0);
	tab4_group_box->setLayout(group_layout);

	QVBoxLayout *tab4_layout = new QVBoxLayout();
	tab4_layout->addWidget(tab4_group_box, 0 , Qt::AlignCenter);
	tab4_layout->addStretch()
;	tab4_layout->setSpacing(0);
	tab4_layout->setContentsMargins(0, 20, 0, 0);
	tab4->setLayout(tab4_layout);
}

void SettingDialog::initTab5()
{
	tab5_group_box = new QGroupBox();
	improve_plan_check_box = new QCheckBox();
	understand_detail_button = new QPushButton();

	QFont group_box_font = tab5_group_box->font();
	group_box_font.setBold(true);
	tab5_group_box->setFont(group_box_font);

	tab5_group_box->setFixedSize(480, 60);
	understand_detail_button->setFixedSize(80, 25);
	understand_detail_button->setCursor(Qt::PointingHandCursor);
	understand_detail_button->setObjectName("blueButton");

	QHBoxLayout *group_layout = new QHBoxLayout();
	group_layout->addWidget(improve_plan_check_box);
	group_layout->addStretch();
	group_layout->addWidget(understand_detail_button);
	group_layout->setSpacing(0);
	group_layout->setContentsMargins(30, 0, 30, 0);
	tab5_group_box->setLayout(group_layout);

	QVBoxLayout *tab5_layout = new QVBoxLayout();
	tab5_layout->addWidget(tab5_group_box, 0 , Qt::AlignCenter);
	tab5_layout->addStretch();
	tab5_layout->setSpacing(0);
	tab5_layout->setContentsMargins(0, 20, 0, 0);
	tab5->setLayout(tab5_layout);
}

void SettingDialog::initTab6()
{
	tab6_group_box1 = new QGroupBox();
	tab6_group_box2 = new QGroupBox();
	file_safe_label = new QLabel();
	internet_safe_label = new QLabel();
	file_safe_check_box = new QCheckBox();
	internet_safe_check_box = new QCheckBox();
	look_privacy_button = new QPushButton();

	QFont group_box_font = tab6_group_box1->font();
	group_box_font.setBold(true);
	tab6_group_box1->setFont(group_box_font);
	tab6_group_box2->setFont(group_box_font);
	look_privacy_button->setCursor(Qt::PointingHandCursor);

	look_privacy_button->setObjectName("blueButton");
	file_safe_label->setObjectName("grayLabel");
	internet_safe_label->setObjectName("grayLabel");
	file_safe_label->setFixedWidth(420);
	file_safe_label->resize(420, 25*3);
	file_safe_label->setWordWrap(true);
	internet_safe_label->setFixedWidth(420);
	internet_safe_label->resize(420, 25*3);
	internet_safe_label->setWordWrap(true);

	QHBoxLayout *group_box1_h_layout = new QHBoxLayout();
	group_box1_h_layout->addWidget(file_safe_check_box);
	group_box1_h_layout->addStretch();
	group_box1_h_layout->addWidget(look_privacy_button);
	group_box1_h_layout->setSpacing(0);
	group_box1_h_layout->setContentsMargins(0, 0, 30, 0);

	QVBoxLayout *group_box1_layout = new QVBoxLayout();
	group_box1_layout->addWidget(file_safe_label);
	group_box1_layout->addLayout(group_box1_h_layout);
	group_box1_layout->setSpacing(0);
	group_box1_layout->setContentsMargins(30, 0, 0, 10);
	tab6_group_box1->setLayout(group_box1_layout);

	QVBoxLayout *group_box2_layout = new QVBoxLayout();
	group_box2_layout->addWidget(internet_safe_label);
	group_box2_layout->addWidget(internet_safe_check_box);
	group_box2_layout->setSpacing(0);
	group_box2_layout->setContentsMargins(30, 0, 0, 10);
	tab6_group_box2->setLayout(group_box2_layout);

	tab6_group_box1->setFixedSize(480, 120);
	tab6_group_box2->setFixedSize(480, 120);

	QVBoxLayout *group_layout = new QVBoxLayout();
	group_layout->addWidget(tab6_group_box1, 0, Qt::AlignCenter);
	group_layout->addWidget(tab6_group_box2, 0, Qt::AlignCenter);
	group_layout->addStretch();
	group_layout->setSpacing(10);
	group_layout->setContentsMargins(0, 20, 0, 0);
	tab6->setLayout(group_layout);
}

void SettingDialog::initCenter()
{
	tab_widget = new QTabWidget();
	tab_widget->setFixedSize(this->width(), 320);
	tab1 = new QWidget();
	tab2 = new QWidget();
	tab3 = new QWidget();
	tab4 = new QWidget();
	tab5 = new QWidget();
	tab6 = new QWidget();
}

void SettingDialog::initBottom()
{
	ok_button = new QPushButton();
	cancel_button = new QPushButton();

	ok_button->setFixedSize(75, 25);
	cancel_button->setFixedSize(75, 25);
	ok_button->setObjectName("okButton");
	cancel_button->setObjectName("okButton");

	bottom_layout = new QHBoxLayout();
	bottom_layout->addStretch();
	bottom_layout->addWidget(ok_button);
	bottom_layout->addWidget(cancel_button);
	bottom_layout->setSpacing(20);
	bottom_layout->setContentsMargins(0, 10, 20, 20);

	connect(ok_button, SIGNAL(clicked()), this, SLOT(updateConfig()));
	connect(cancel_button, SIGNAL(clicked()), this, SLOT(hide()));
}

SettingDialog::~SettingDialog()
{

}

void SettingDialog::translateLanguage()
{
	QString space_str = QString("    ");
	title_label->setText(tr("360 safe setting"));
	close_button->setToolTip(tr("close"));

	tab_widget->addTab(tab1, tr("rise style"));
	tab_widget->addTab(tab2, tr("advanced setting"));
	tab_widget->addTab(tab3, tr("physical setting"));
	tab_widget->addTab(tab4, tr("user setting"));
	tab_widget->addTab(tab5, tr("improve program"));
	tab_widget->addTab(tab6, tr("cloud secure program"));

	tab1_group_box->setTitle(tr("rise style title"));
	auto_rise_button->setText(tr("auto rise"));
	not_auto_rise_button->setText(tr("not auto rise"));
	rise_mummy_check_box->setText(tr("rise mummy"));
	game_check_box->setText(tr("game"));
	g3_check_box->setText(tr("3g"));
	p2p_check_box->setText(tr("p2p"));
	mummy_check_box->setText(tr("mummy"));

	tab2_group_box1->setTitle(tr("mummy fireproof"));
	tab2_group_box2->setTitle(tr("context menu"));
	tab2_group_box3->setTitle(tr("software manager"));
	auto_start_check_box->setText(tr("auto start"));
	remove_own_check_box->setText(tr("remove own"));
	strong_remove_check_box->setText(tr("strong remove"));
	mummy_kill_check_box->setText(tr("mummy kill"));
	display_count_check_box->setText(tr("display count"));

	tab3_group_box1->setTitle(tr("frequency setting"));
	tab3_group_box2->setTitle(tr("quit style setting"));
	auto_check_button->setText(tr("auto check"));
	first_check_button->setText(tr("first check"));
	hand_check_button->setText(tr("hand check"));
	select_quit_button->setText(tr("select quit"));
	backstage_mode_button->setText(tr("backstage mode"));
	immediacy_close_button->setText(tr("immediacy close"));

	tab4_group_box->setTitle(tr("rate task setting"));
	diaplay_experience_check_box->setText(tr("diaplay experience"));
	diaplay_login_check_box->setText(tr("diaplay login"));
	tray_quit_check_box->setText(tr("tray quit"));
	new_character_check_box->setText(tr("new character"));
	rise_remind_check_box->setText(tr("rise remind"));
	language_label->setText(tr("language"));
	language_combo_box->setItemText(0, tr("chinese"));
	language_combo_box->setItemText(1, tr("english"));

	tab5_group_box->setTitle(tr("improve plan"));
	improve_plan_check_box->setText(tr("join improve plan"));
	understand_detail_button->setText(tr("understand detail"));

	tab6_group_box1->setTitle(tr("file safe plan"));
	tab6_group_box2->setTitle(tr("internet safe plan"));
	file_safe_label->setText(space_str + tr("file safe info"));
	internet_safe_label->setText(space_str + tr("internet safe info"));
	file_safe_check_box->setText(tr("file safe"));
	internet_safe_check_box->setText(tr("internet safe"));
	look_privacy_button->setText(tr("look privacy"));

	ok_button->setText(tr("ok"));
	cancel_button->setText(tr("cancel"));
}

void SettingDialog::paintEvent(QPaintEvent *event)
{
	DropShadowWidget::paintEvent(event);
	QString skin_name = Util::getSkinName();
	int height = 65;
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
	painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(skin_name));
	painter.drawRect(QRect(SHADOW_WIDTH, height, this->width()-2*SHADOW_WIDTH, this->height()-height-SHADOW_WIDTH));
}

void SettingDialog::updateConfig()
{
	int index = language_combo_box->currentIndex();
	LANGUAGE ui_language = (LANGUAGE)language_combo_box->itemData(index).toInt(); 
	emit changeLanguage(ui_language);

	this->hide();
}