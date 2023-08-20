#include "loading_widget.h"

LoadingWidget::LoadingWidget(QWidget *parent)
    : QWidget(parent)
{
    index = 1;
    loading_label = new QLabel();
    account_label = new QLabel();
    waiting_label = new QLabel();

    QPixmap pixmap(QString(":/loginDialog/") + QString::number(index, 10));
    loading_label->setFixedSize(pixmap.size());
    loading_label->setPixmap(pixmap);
    loading_label->setScaledContents(true);

    QVBoxLayout *v_layout = new QVBoxLayout();
    v_layout->addWidget(account_label);
    v_layout->addWidget(waiting_label);
    v_layout->setSpacing(15);
    v_layout->setContentsMargins(0, 0, 0, 0);

    QHBoxLayout *h_layout = new QHBoxLayout();
    h_layout->addStretch();
    h_layout->addWidget(loading_label);
    h_layout->addLayout(v_layout);
    h_layout->addStretch();
    h_layout->setSpacing(20);
    h_layout->setContentsMargins(0, 0, 0, 30);

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &LoadingWidget::updatePixmap);

    this->setLayout(h_layout);

    this->translateLanguage();
}

LoadingWidget::~LoadingWidget()
{

}

void LoadingWidget::translateLanguage()
{
    waiting_label->setText(tr("waiting"));
}

void LoadingWidget::setAccount(QString account)
{
    this->account = account;
}

void LoadingWidget::start(bool is_start)
{
    if(is_start)
    {
        QString elided_text;
        bool is_elided = Util::updateText(account, 200, elided_text);
        if(!is_elided)
        {
            elided_text = account;
        }

        account_label->setText(tr("hi") + elided_text);
        timer->start();
    }
    else
    {
        timer->stop();
        index = 1;
        loading_label->setPixmap(QPixmap(QString(":/loginDialog/") + QString::number(index, 10)));
    }
}

void LoadingWidget::updatePixmap()
{
    index++;
    if(index > 8)
    {
        index = 1;
    }
    QPixmap pixmap(":/loginDialog/" + QString::number(index, 10));
    loading_label->setPixmap(pixmap);
}
