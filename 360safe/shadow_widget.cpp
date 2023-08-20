#include "shadow_widget.h"

ShadowWidget::ShadowWidget(QWidget *parent)
    : QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);
}

ShadowWidget::~ShadowWidget()
{

}

void ShadowWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    this->drawWindowShadow(painter);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH));
}

void ShadowWidget::drawWindowShadow(QPainter &painter)
{
    QList<QPixmap> pixmaps;
    pixmaps.append(QPixmap(":/shadow/shadow_left"));
    pixmaps.append(QPixmap(":/shadow/shadow_right"));
    pixmaps.append(QPixmap(":/shadow/shadow_top"));
    pixmaps.append(QPixmap(":/shadow/shadow_bottom"));
    pixmaps.append(QPixmap(":/shadow/shadow_left_top"));
    pixmaps.append(QPixmap(":/shadow/shadow_right_top"));
    pixmaps.append(QPixmap(":/shadow/shadow_left_bottom"));
    pixmaps.append(QPixmap(":/shadow/shadow_right_bottom"));

    painter.drawPixmap(0, 0, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[4]);
    painter.drawPixmap(this->width()-SHADOW_WIDTH, 0, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[5]);
    painter.drawPixmap(0,this->height()-SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[6]);
    painter.drawPixmap(this->width()-SHADOW_WIDTH, this->height()-SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[7]);
    painter.drawPixmap(0, SHADOW_WIDTH, SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH, pixmaps[0].scaled(SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH));
    painter.drawPixmap(this->width()-SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH, pixmaps[1].scaled(SHADOW_WIDTH, this->height()- 2*SHADOW_WIDTH));
    painter.drawPixmap(SHADOW_WIDTH, 0, this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[2].scaled(this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH));
    painter.drawPixmap(SHADOW_WIDTH, this->height()-SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH, pixmaps[3].scaled(this->width()-2*SHADOW_WIDTH, SHADOW_WIDTH));
}
