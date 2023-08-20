#include "title_widget.h"
#include "tool_button.h"

TitleWidget::TitleWidget(QWidget *parent)
    : QWidget(parent)
{
    version_title = new QLabel();
    skin_button = new PushButton();
    main_menu_button = new PushButton();
    min_button = new PushButton();
    feedback_button = new PushButton();
    close_button = new PushButton();
    medal_button = new PushButton();

    version_title->setObjectName("whiteLabel");

    medal_button->setPicName(QString(":/sysButton/medal"));
    skin_button->setPicName(QString(":/sysButton/skin"));
    min_button->setPicName(QString(":/sysButton/min"));
    close_button->setPicName(QString(":/sysButton/close"));
    main_menu_button->setPicName(QString(":/sysButton/menu"));
    feedback_button->setPicName(QString(":/sysButton/feedback"));

    connect(skin_button, SIGNAL(clicked()), this, SIGNAL(showSkin()));
    connect(main_menu_button, SIGNAL(clicked()), this, SIGNAL(showMainMenu()));
    connect(min_button, SIGNAL(clicked()), this, SIGNAL(showMin()));
    connect(close_button, SIGNAL(clicked()), this, SIGNAL(closeWidget()));

    QHBoxLayout *title_layout = new QHBoxLayout();
    title_layout->addWidget(version_title,0,Qt::AlignVCenter);
    title_layout->addStretch();
    title_layout->addWidget(medal_button, 0, Qt::AlignTop);
    title_layout->addWidget(skin_button, 0, Qt::AlignTop);
    title_layout->addWidget(feedback_button, 0, Qt::AlignTop);
    title_layout->addWidget(main_menu_button, 0, Qt::AlignTop);
    title_layout->addWidget(min_button, 0, Qt::AlignTop);
    title_layout->addWidget(close_button, 0, Qt::AlignTop);
    title_layout->setSpacing(0);
    title_layout->setContentsMargins(0, 0, 5, 0);
    version_title->setContentsMargins(15, 0, 0, 0);
    skin_button->setContentsMargins(0, 0, 10, 0);

    QStringList string_list;
    string_list<<":/toolWidget/tiJian"<<":/toolWidget/muMa"<<":/toolWidget/repair"<<":/toolWidget/qingLi"
                <<":/toolWidget/jiaSu"<<":/toolWidget/expert"<<":/toolWidget/menZhen"<<":/toolWidget/gongNeng";

    QHBoxLayout *button_layout = new QHBoxLayout();

    QSignalMapper *signal_mapper = new QSignalMapper(this);
    for(int i=0; i<string_list.size(); i++)
    {
        ToolButton *tool_button = new ToolButton(string_list.at(i));
        button_list.append(tool_button);
        connect(tool_button, SIGNAL(clicked()), signal_mapper, SLOT(map()));
        signal_mapper->setMapping(tool_button, QString::number(i, 10));

        button_layout->addWidget(tool_button, 0, Qt::AlignBottom);
    }
    connect(signal_mapper, &QSignalMapper::mappedString, this, &TitleWidget::setPage);

    safe_360_label = new QLabel();
    safe_label = new QLabel();

    QVBoxLayout *safe_layout = new QVBoxLayout();
    safe_layout->addWidget(safe_360_label);
    safe_layout->addWidget(safe_label);
    safe_layout->setSpacing(5);
    safe_layout->setContentsMargins(0, 0, 0, 0);

    QLabel *logo_label = new QLabel();
    QPixmap pixmap(":/img/safe");
    logo_label->setPixmap(pixmap);
    logo_label->setFixedSize(pixmap.size());

    safe_360_label->setObjectName("whiteLabel");
    safe_label->setObjectName("whiteLabel");
    QFont safe_360_font = safe_360_label->font();
    safe_360_font.setPointSize(18);
    safe_360_font.setBold(true);
    safe_360_label->setFont(safe_360_font);

    safe_360_label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    safe_label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QFont safe_font = safe_label->font();
    safe_font.setPointSize(14);
    safe_font.setBold(true);
    safe_label->setFont(safe_font);

    button_layout->addStretch();
    button_layout->addLayout(safe_layout);
    button_layout->addWidget(logo_label);
    button_layout->setSpacing(8);
    button_layout->setContentsMargins(15, 0, 15, 0);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addLayout(title_layout);
    main_layout->addLayout(button_layout);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(0, 0, 0, 0);

    this->translateLanguage();

    setLayout(main_layout);
    setFixedHeight(110);
    is_move = false;
}

void TitleWidget::translateLanguage()
{
    version_title->setText(tr("title") + QString("9.2"));
    skin_button->setToolTip(tr("change skin"));
    main_menu_button->setToolTip(tr("main menu"));
    min_button->setToolTip(tr("minimize"));
    feedback_button->setToolTip(tr("feedback"));
    close_button->setToolTip(tr("close"));

    button_list.at(0)->setText(tr("power"));
    button_list.at(1)->setText(tr("mummy"));
    button_list.at(2)->setText(tr("repair"));
    button_list.at(3)->setText(tr("clear"));
    button_list.at(4)->setText(tr("optimize"));
    button_list.at(5)->setText(tr("expert"));
    button_list.at(6)->setText(tr("hole"));
    button_list.at(7)->setText(tr("software"));

    safe_360_label->setText(tr("360"));
    safe_label->setText(tr("safe"));
}

void TitleWidget::setPage(const QString &current_page)
{
    bool ok;
    int current_index = current_page.toInt(&ok, 10);

    for(int i=0; i<button_list.count(); i++)
    {
        ToolButton *tool_button = button_list.at(i);
        if(current_index == i)
        {
            tool_button->setMousePress(true);
        }
        else
        {
            tool_button->setMousePress(false);
        }
    }

    emit turnPage(current_index);
}
