#include "main_widget.h"
#include "util.h"
#include <QFile>

MainWidget::MainWidget(QWidget *parent)
    : DropShadowWidget(parent)
{
    initLocalConnection();
    setMinimumSize(900, 600);
    setWindowIcon(QIcon(":/img/safe"));

    statked_widget = new QStackedWidget();
    title_widget = new TitleWidget();
    content_widget = new ContentWidget();
    kill_mummy_widget = new KillMummyWidget();
    main_menu = new MainMenu();
    character_widget = new CharacterWidget();
    about_us_dialog = new AboutUsDialog(this);
    setting_dialog = new SettingDialog(this);
    login_dialog = new LoginDialog(this);
    register_widget = new RegisterWidget(this);
    skin_widget = new SkinWidget(this);
    system_tray = new SystemTray(this);

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(Qt::white));
    statked_widget->setPalette(palette);
    statked_widget->setAutoFillBackground(true);

    statked_widget->addWidget(content_widget);
    statked_widget->addWidget(kill_mummy_widget);

    QVBoxLayout *center_layout = new QVBoxLayout();
    center_layout->addWidget(statked_widget);
    center_layout->setSpacing(0);
    center_layout->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addWidget(title_widget);
    main_layout->addLayout(center_layout);
    main_layout->setSpacing(0);
    main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);

    setLayout(main_layout);

    connect(title_widget, SIGNAL(showSkin()), this, SLOT(showSkinWidget()));
    connect(title_widget, SIGNAL(showMainMenu()), this, SLOT(showMainMenu()));
    connect(title_widget, SIGNAL(showMin()), this, SLOT(showMinimized()));
    connect(title_widget, SIGNAL(closeWidget()), this, SLOT(hide()));
    connect(title_widget, SIGNAL(turnPage(int)), this, SLOT(turnPage(int)));

    connect(main_menu, SIGNAL(showSettingDialog()), this, SLOT(showSettingDialog()));
    connect(main_menu, SIGNAL(showNewCharacter()), this, SLOT(showNewCharacter()));
    connect(main_menu, SIGNAL(showAboutUs()), this, SLOT(showAboutUs()));

    connect(content_widget, SIGNAL(showLoginDialog()), this, SLOT(showLoginDialog()));
    connect(content_widget, SIGNAL(showRegisterDialog()), this, SLOT(showRegisterDialog()));

    connect(setting_dialog, SIGNAL(changeLanguage(LANGUAGE)), this, SLOT(changeLanguage(LANGUAGE)));

    connect(skin_widget, SIGNAL(changeSkin(QString)), this, SLOT(changeSkin(QString)));

    connect(system_tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));
    connect(system_tray, SIGNAL(showWidget()), this, SLOT(showWidget()));

    system_tray->show();

    title_widget->setPage("0");

    skin_name = Util::getSkinName();
    if( QString::compare(skin_name, QString("")) == 0)
    {
        this->changeSkin(DEFAULT_SKIN);
    }
}

MainWidget::~MainWidget()
{

}

void MainWidget::turnPage(int current_page)
{
    if(current_page == 0)
    {
        statked_widget->setCurrentWidget(content_widget);
    }
    else if(current_page == 1)
    {
        statked_widget->setCurrentWidget(kill_mummy_widget);
    }
}

void MainWidget::initLocalConnection()
{
    is_running = false;
    QCoreApplication::setApplicationName("localserver");
    QString serverName=QCoreApplication::applicationName();

    QLocalSocket socket;
    socket.connectToServer(serverName);

    if(socket.waitForConnected(500))
    {
        is_running =true;

        return;
    }

    server = new QLocalServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newLocalConnection()));
    if(server->listen(serverName))
    {
        if(server->serverError() == QAbstractSocket::AddressInUseError && QFile::exists(server->serverName()))
        {
            QFile::remove(server->serverName());
            server->listen(serverName);
        }
    }
}

void MainWidget::newLocalConnection()
{
    QLocalSocket *socket = server->nextPendingConnection();
    if(!socket)
        return;

    socket->waitForReadyRead(1000);

    delete socket;
}


bool MainWidget::isRunning()
{
    return is_running;
}

void MainWidget::paintEvent(QPaintEvent *event)
{
    DropShadowWidget::paintEvent(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap(skin_name));
}

void MainWidget::showSkinWidget()
{
    skin_widget->show();
}

void MainWidget::showMainMenu()
{
    QPoint p = rect().topRight();
    p.setX(p.x() - 90);
    p.setY(p.y() + 25);
    main_menu->exec(this->mapToGlobal(p));
}

void MainWidget::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
    {
        showWidget();
        break;
    }
    case QSystemTrayIcon::DoubleClick:
    {
        showWidget();
        break;
    }
    default:
        break;
    }
}

void MainWidget::showWidget()
{
    this->showNormal();
    this->raise();
    this->activateWindow();
}

void MainWidget::showAboutUs()
{
    about_us_dialog->exec();
}

void MainWidget::showNewCharacter()
{
    character_widget->show();
}

void MainWidget::showSettingDialog()
{
    setting_dialog->exec();
}

void MainWidget::showLoginDialog()
{
    login_dialog->exec();
}

void MainWidget::showRegisterDialog()
{
    register_widget->exec();
}

void MainWidget::changeSkin(QString skin_name)
{
    Util::writeInit(QString("./user.ini"), QString("skin"), skin_name);
    this->skin_name = skin_name;
    update();
}

void MainWidget::setTranslator(QTranslator* translator)
{
    this->translator = translator;
}

void MainWidget::changeLanguage(LANGUAGE language)
{
    if(current_language == language)
    {
        return;
    }
    current_language = language;

    switch(language)
    {
    case UI_EN:
        translator->load(QString(":/translations/360safe_en.qm"));
        break;
    case UI_ZH:
        translator->load(QString(":/translations/360safe_zh.qm"));
        break;
    default:
        translator->load(QString(":/translations/360safe_zh.qm"));
        break;
    }

    title_widget->translateLanguage();
    content_widget->translateLanguage();
    kill_mummy_widget->translateLanguage();
    main_menu->translateActions();
    character_widget->translateLanguage();
    login_dialog->translateLanguage();
    register_widget->translateLanguage();
    character_widget->translateLanguage();
    about_us_dialog->translateLanguage();
    setting_dialog->translateLanguage();
    skin_widget->translateLanguage();
    system_tray->translateLanguage();
}

