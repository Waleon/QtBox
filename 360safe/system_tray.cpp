#include "system_tray.h"

SystemTray::SystemTray(QWidget *parent)
    : QSystemTrayIcon(parent)
{
    this->createAction();
    this->createTopAction();
    this->createBottomAction();
    this->addActions();
    this->translateLanguage();
}

SystemTray::~SystemTray()
{

}

void SystemTray::translateLanguage()
{
    this->setToolTip(tr("360 safe"));

    protect_label->setText(tr("protect") + QString::number(3, 10) + tr("day"));
    open_button->setText(tr("firewall start"));
    enter_button->setText(tr("enter"));

    game_mode_button->setText(tr("game mode"));
    online_mode_button->setText(tr("online mode"));

    action_open->setText(tr("open"));
    action_help_center->setText(tr("help center"));
    action_kill_mummy->setText(tr("kill mummy"));
    action_clear->setText(tr("clear"));
    action_optimize->setText(tr("optimize"));
    action_fireproof->setText(tr("fireproof"));
    action_show_speed->setText(tr("show speed"));
    action_soft_manage->setText(tr("soft manage"));
    action_safe_notice->setText(tr("safe notice"));
    action_rise->setText(tr("rise"));
    action_login->setText(tr("login"));
    action_separate->setText(tr("separate"));
    action_logout->setText(tr("logout"));
}

void SystemTray::createTopAction()
{
    top_widget = new QWidget();
    top_widget_action = new QWidgetAction(tray_menu);
    protect_label = new QLabel();
    open_button = new QPushButton();
    enter_button = new QPushButton();

    protect_label->setObjectName("whiteLabel");
    open_button->setObjectName("trayButton");
    enter_button->setObjectName("trayButton");

    open_button->setCursor(Qt::PointingHandCursor);
    enter_button->setCursor(Qt::PointingHandCursor);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(open_button);
    layout->addStretch();
    layout->addWidget(enter_button);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *v_layout = new QVBoxLayout();
    v_layout->addWidget(protect_label);
    v_layout->addLayout(layout);
    v_layout->setSpacing(10);
    v_layout->setContentsMargins(10, 5, 10, 5);
    top_widget->setLayout(v_layout);
    top_widget_action->setDefaultWidget(top_widget);

    top_widget->installEventFilter(this);
}

void SystemTray::createBottomAction()
{
    bottom_widget = new QWidget();
    bottom_widget_action = new QWidgetAction(tray_menu);
    game_mode_button = new QPushButton();
    online_mode_button = new QPushButton();

    game_mode_button->setObjectName("trayButton");
    online_mode_button->setObjectName("trayButton");

    game_mode_button->setCursor(Qt::PointingHandCursor);
    online_mode_button->setCursor(Qt::PointingHandCursor);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(game_mode_button);
    layout->addStretch();
    layout->addWidget(online_mode_button);
    layout->setSpacing(0);
    layout->setContentsMargins(10, 5, 10, 5);

    bottom_widget->setLayout(layout);
    bottom_widget_action->setDefaultWidget(bottom_widget);

    bottom_widget->installEventFilter(this);
}

void SystemTray::createAction()
{
    this->setIcon(QIcon(":/img/safe"));

    tray_menu = new QMenu();
    action_open = new QAction(this);
    action_help_center = new QAction(this);
    action_kill_mummy = new QAction(this);
    action_clear = new QAction(this);
    action_optimize = new QAction(this);
    action_fireproof = new QAction(this);
    action_show_speed = new QAction(this);
    action_soft_manage = new QAction(this);
    action_safe_notice = new QAction(this);
    action_rise = new QAction(this);
    action_login = new QAction(this);
    action_separate = new QAction(this);
    action_logout = new QAction(this);

    tray_menu->setFixedWidth(250);

    connect(action_open, SIGNAL(triggered()), this, SIGNAL(showWidget()));
    connect(action_logout, SIGNAL(triggered()), qApp, SLOT(quit()));

    this->setContextMenu(tray_menu);
}

void SystemTray::addActions()
{
    tray_menu->addAction(top_widget_action);
    tray_menu->addAction(action_open);
    tray_menu->addAction(action_help_center);
    tray_menu->addSeparator();
    tray_menu->addAction(action_kill_mummy);
    tray_menu->addAction(action_clear);
    tray_menu->addSeparator();
    tray_menu->addAction(action_optimize);
    tray_menu->addAction(action_fireproof);
    tray_menu->addAction(action_show_speed);
    tray_menu->addAction(action_soft_manage);
    tray_menu->addSeparator();
    tray_menu->addAction(action_safe_notice);
    tray_menu->addAction(action_rise);
    tray_menu->addAction(action_login);
    tray_menu->addAction(action_separate);
    tray_menu->addAction(action_logout);
    tray_menu->addAction(bottom_widget_action);
}

bool SystemTray::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == top_widget || obj == bottom_widget)
    {
        if(event->type() == QEvent::Paint)
        {
            QPainter top_painter(top_widget);
            top_painter.setPen(Qt::NoPen);
            top_painter.setBrush(QColor(70, 180, 20));
            top_painter.drawRect(top_widget->rect());

            QPainter bottom_painter(bottom_widget);
            bottom_painter.setPen(Qt::NoPen);
            bottom_painter.setBrush(QColor(70, 180, 20));
            bottom_painter.drawRect(bottom_widget->rect());
        }
    }

    return QSystemTrayIcon::eventFilter(obj, event);
}
