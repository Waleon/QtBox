#include "main_menu.h"

MainMenu::MainMenu(QWidget *widget)
    : QMenu(widget)
{
    this->createActions();
    this->translateActions();

    this->setObjectName("menu");
}

void MainMenu::createActions()
{
    action_setting = new QAction(this);
    action_new_character = new QAction(this);
    action_check_update = new QAction(this);
    action_change_company = new QAction(this);
    action_help_online = new QAction(this);
    action_platform_help = new QAction(this);
    action_login_home = new QAction(this);
    action_protect = new QAction(this);
    action_about_us = new QAction(this);

    this->addAction(action_setting);
    this->addAction(action_new_character);
    this->addAction(action_check_update);
    this->addAction(action_change_company);
    this->addSeparator();
    this->addAction(action_help_online);
    this->addAction(action_platform_help);
    this->addAction(action_login_home);
    this->addAction(action_protect);
    this->addAction(action_about_us);

    action_help_online->setObjectName(QString::number(HELP_ONLINE, 10));
    action_platform_help->setObjectName(QString::number(PLATFORM_HELP, 10));
    action_login_home->setObjectName(QString::number(LOGIN_HOME, 10));
    action_protect->setObjectName(QString::number(PROTECT, 10));

    connect(action_setting, SIGNAL(triggered()), this, SIGNAL(showSettingDialog()));
    connect(action_new_character, SIGNAL(triggered()), this, SIGNAL(showNewCharacter()));
    connect(action_about_us, SIGNAL(triggered()), this, SIGNAL(showAboutUs()));
    connect(action_help_online, SIGNAL(triggered()), this, SLOT(showPage()));
    connect(action_platform_help, SIGNAL(triggered()), this, SLOT(showPage()));
    connect(action_login_home, SIGNAL(triggered()), this, SLOT(showPage()));
    connect(action_protect, SIGNAL(triggered()), this, SLOT(showPage()));
}

void MainMenu::translateActions()
{
    action_setting->setText(tr("setting"));
    action_new_character->setText(tr("new character"));
    action_check_update->setText(tr("check update"));
    action_change_company->setText(tr("change company"));
    action_help_online->setText(tr("help online"));
    action_platform_help->setText(tr("platform help"));
    action_login_home->setText(tr("login home"));
    action_protect->setText(tr("protect"));
    action_about_us->setText(tr("about us"));
}

void MainMenu::showPage()
{
    QObject *object = QObject::sender();
    QAction *action = qobject_cast<QAction *>(object);
    QString object_name = action->objectName();
    int index = object_name.toInt();
    QString page;
    switch(index)
    {
    case HELP_ONLINE:
        page = QString("http://bbs.360.cn/cms/guide.html");
        break;

    case PLATFORM_HELP:
        page = QString("http://bbs.360safe.com/forum.php?mod=forumdisplay&fid=100");
        break;

    case LOGIN_HOME:
        page = QString("http://www.360.cn/");
        break;

    case PROTECT:
        page = QString("http://www.360.cn/privacy/v2/index.html");
        break;

    default:
        break;
    }

    QUrl url(page);
    QDesktopServices::openUrl(url);
}
