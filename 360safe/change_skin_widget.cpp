#include "change_skin_widget.h"
#include <QPainter>

ChangeSkinWidget::ChangeSkinWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(140, 160);
    mouse_press = false;
    mouse_enter = false;

    skin_label = new QLabel();
    skin_name_label = new QLabel();
    download_count_label = new QLabel();
    use_skin_button = new QPushButton();
    this->setCursor(Qt::PointingHandCursor);

    use_skin_button->setObjectName("skinButton");
    skin_label->setScaledContents(true);
    skin_label->setFixedSize(100, 65);
    use_skin_button->setFixedSize(85, 25);

    QVBoxLayout *background_layout = new QVBoxLayout();
    background_layout->addWidget(skin_label, 0, Qt::AlignCenter);
    background_layout->addWidget(skin_name_label, 0, Qt::AlignCenter);
    background_layout->addWidget(download_count_label, 0, Qt::AlignCenter);
    background_layout->addWidget(use_skin_button, 0, Qt::AlignCenter);
    background_layout->setSpacing(5);
    background_layout->setContentsMargins(0, 10, 0, 10);

    connect(use_skin_button, &QPushButton::clicked, this, &ChangeSkinWidget::useSkin);

    this->setLayout(background_layout);
    this->translateLanguage();
}

void ChangeSkinWidget::translateLanguage()
{
    use_skin_button->setText(tr("use skin"));
}

ChangeSkinWidget::~ChangeSkinWidget()
{

}

void ChangeSkinWidget::changeSkin(QString pixmap_name, QString skin_name, QString download_count)
{
    QString background_name = pixmap_name + "_big";
    this->pixmap_name = background_name;

    QPixmap pixmap(background_name);
    skin_label->setPixmap(pixmap);

    skin_name_label->setText(skin_name);

    download_count_label->setText(tr("download count:") + download_count);
}

void ChangeSkinWidget::useSkin()
{
    emit changeSkin();
}

QString ChangeSkinWidget::getPixmapName()
{
    return pixmap_name;
}

void ChangeSkinWidget::paintEvent(QPaintEvent *)
{
    if(mouse_enter)
    {
        QPainter painter(this);
        QPen pen(QColor(210, 225, 230));
        painter.setPen(pen);
        painter.drawRoundedRect(0, 0, this->width()-1, this->height()-1, 5, 5);
    }
}

void ChangeSkinWidget::mousePressEvent(QMouseEvent * event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;
    }
}

void ChangeSkinWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(mouse_press && (this->rect()).contains(event->pos()))
    {
        emit changeSkin();
    }
    mouse_press = false;
}

void ChangeSkinWidget::enterEvent(QEvent *)
{
    mouse_enter = true;
    update();
}

void ChangeSkinWidget::leaveEvent(QEvent *)
{
    mouse_enter = false;
    update();
}
