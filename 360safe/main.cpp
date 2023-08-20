#include "main_widget.h"
#include <QApplication>
#include <QTranslator>
#include <QSharedMemory>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator_zh;
    translator_zh.load(QString(":/translations/360safe_zh.qm"));
    app.installTranslator(&translator_zh);

    QFile qss(":/qss/360safe");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    QSharedMemory shared_memory;
    shared_memory.setKey(QString("main_window"));

    if(shared_memory.attach())
    {
        return 0;
    }

    if(shared_memory.create(1))
    {
        MainWidget main_widget;
        main_widget.setTranslator(&translator_zh);
        main_widget.showWidget();

        return app.exec();
    }
}
