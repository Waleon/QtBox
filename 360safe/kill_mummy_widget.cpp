#include "kill_mummy_widget.h"

KillMummyWidget::KillMummyWidget(QWidget *parent)
	: QWidget(parent)
{
	tip_icon_label = new QLabel();
	tip_info_label = new QLabel();
	tip_suggest_label = new QLabel();
	fast_scan_button = new QToolButton();
	full_scan_button = new QToolButton();
	custom_scan_button = new QToolButton();

	QPixmap pixmap(":/killMummyWidget/tip");
	tip_icon_label->setPixmap(pixmap);
	tip_icon_label->setScaledContents(true);
	tip_icon_label->setFixedSize(pixmap.size());

	QFont tip_font = tip_info_label->font();
	tip_font.setPointSize(12);
	tip_font.setBold(true);
	tip_info_label->setFont(tip_font);
	tip_info_label->setObjectName("grayLabel");
	tip_suggest_label->setObjectName("grayLabel");

	fast_scan_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	full_scan_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	custom_scan_button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	//ÉèÖÃÍ¼±ê
	QSize size(123, 115);
	QPixmap fast_scan_pixmap(":/killMummyWidget/fast_scan");
	fast_scan_button->setIcon(fast_scan_pixmap);
	fast_scan_button->setIconSize(size);
	fast_scan_button->setFixedSize(size.width()+25, size.height()+25);

	QFont scan_font = fast_scan_button->font();
	scan_font.setPointSize(12);
	scan_font.setBold(true);
	fast_scan_button->setFont(scan_font);
	full_scan_button->setFont(scan_font);
	custom_scan_button->setFont(scan_font);

	QPixmap full_scan_pixmap(":/killMummyWidget/full_scan");
	full_scan_button->setIcon(full_scan_pixmap);
	full_scan_button->setIconSize(size);
	full_scan_button->setFixedSize(size.width()+25, size.height()+25);

	QPixmap custom_scan_pixmap(":/killMummyWidget/custom_scan");
	custom_scan_button->setIcon(custom_scan_pixmap);
	custom_scan_button->setIconSize(size);
	custom_scan_button->setFixedSize(size.width()+25, size.height()+25);

	fast_scan_button->setObjectName("grayToolButton");
	full_scan_button->setObjectName("grayToolButton");
	custom_scan_button->setObjectName("grayToolButton");

	QVBoxLayout *info_layout = new QVBoxLayout();
	info_layout->addWidget(tip_info_label);
	info_layout->addWidget(tip_suggest_label);
	info_layout->setSpacing(5);
	info_layout->setContentsMargins(0, 0, 0, 0);

	QHBoxLayout *tip_layout = new QHBoxLayout();
	tip_layout->addWidget(tip_icon_label);
	tip_layout->addLayout(info_layout);
	tip_layout->setSpacing(10);
	tip_layout->setContentsMargins(20, 20, 0, 0);

	QHBoxLayout *scan_layout = new QHBoxLayout();
	scan_layout->addWidget(fast_scan_button);
	scan_layout->addWidget(full_scan_button);
	scan_layout->addWidget(custom_scan_button);
	scan_layout->setSpacing(0);
	scan_layout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout *main_layout = new QVBoxLayout();
	main_layout->addLayout(tip_layout);
	main_layout->addStretch();
	main_layout->addLayout(scan_layout);
	main_layout->addStretch();
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(0, 0, 0, 0);

	this->setLayout(main_layout);
	this->translateLanguage();
}

KillMummyWidget::~KillMummyWidget()
{

}

void KillMummyWidget::translateLanguage()
{
	tip_info_label->setText(tr("the last scanning") + QString::number(3, 10) + tr("no threat found"));
	tip_suggest_label->setText(tr("regular scanning"));
	fast_scan_button->setText(tr("fast scan"));
	full_scan_button->setText(tr("full scan"));
	custom_scan_button->setText(tr("custom scan"));
}