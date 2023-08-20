#include "clabel.h"

CLabel::CLabel(QWidget *parent) :
    QWidget(parent)
{
    initVariable();
    initSetupUi();
}

CLabel::~CLabel()
{
    delete m_pLabelIcon;
    delete m_pLabelText;
    delete m_pHLayout;
}

void CLabel::setPixmap(const QPixmap &pixmap)
{
    m_pLabelIcon->setPixmap(pixmap.scaled(QSize(30, 30), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void CLabel::setText(const QString &text)
{
    m_pLabelText->setText(text);
}

void CLabel::setMouseEnterFlag(bool flag)
{
    m_mouseEnterFlag = flag;
    this->update();
}

void CLabel::setMousePressFlag(bool flag)
{
    m_mousePressFlag = flag;
    this->update();
}

void CLabel::enterEvent(QEvent *)
{
    if(!getMousePressFlag())
    {
        setMouseEnterFlag(true);
    }
    this->setCursor(Qt::PointingHandCursor);
}

void CLabel::leaveEvent(QEvent *)
{
    setMouseEnterFlag(false);
}

void CLabel::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        setMousePressFlag(true);
        emit signalLabelPress(this);
    }
}

void CLabel::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if(getMouseEnterFlag())
    {
        paintWidget(50, &painter);
    }
    else if(getMousePressFlag())
    {
        paintWidget(80, &painter);
    }

    QWidget::paintEvent(e);
}

void CLabel::initVariable()
{
    setMouseEnterFlag(false);
    setMousePressFlag(false);
}

void CLabel::initSetupUi()
{
    createFrame();
    createWidget();
    createLayout();
}

void CLabel::createFrame()
{
    this->setStyleSheet("QWidget {background:transparent;border:0px;color:white;font-weight:bold;font-size:16px;}");
}

void CLabel::createWidget()
{
    m_pLabelIcon = new QLabel(this);
    m_pLabelText = new QLabel(this);
}

void CLabel::createLayout()
{
    m_pHLayout = new QHBoxLayout;
    m_pHLayout->setSpacing(10);
    m_pHLayout->setContentsMargins(QMargins(5, 0, 5, 0));
    m_pHLayout->addWidget(m_pLabelIcon);
    m_pHLayout->addWidget(m_pLabelText);
	m_pHLayout->addStretch();

    this->setLayout(m_pHLayout);
}

void CLabel::paintWidget(int transparency, QPainter *device)
{
    QPen pen(Qt::NoBrush, 1);
    device->setPen(pen);
    QLinearGradient linear(this->rect().topLeft(), this->rect().bottomLeft());
    linear.setColorAt(0, QColor(255, 255, 255, transparency));

    QBrush brush(linear);
    device->setBrush(brush);
    device->drawRoundedRect(this->rect(), 2, 2);
}

inline bool CLabel::getMouseEnterFlag()
{
    return m_mouseEnterFlag;
}

inline bool CLabel::getMousePressFlag()
{
    return m_mousePressFlag;
}
