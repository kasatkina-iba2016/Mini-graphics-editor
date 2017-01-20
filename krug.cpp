#include "krug.h"
#include <QPainter>

Krug::Krug(QPointF point,QObject *parent):
    Figure(point,parent)
{
   Q_UNUSED(point)
}

Krug::~Krug()
{

}

QColor Krug::penFigureColor() const
{
    return FigureColor;
}

void Krug::setPenFigureColor(const QColor &myPenColor)
{
    FigureColor=myPenColor;
}

int Krug::penFigureWidth() const
{
    return FigureWidth;
}

void Krug::setPenFigureWidth(const int &myPenWidth)
{
    FigureWidth=myPenWidth;
}

QBrush Krug::brushFigureColor() const
{
    return FigureBrush;
}

void Krug::setBrushFigureColor(const QBrush &myBrushColor)
{
    FigureBrush=myBrushColor;
}

void Krug::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(FigureColor,FigureWidth));
    painter->setBrush(FigureBrush);
    QRect rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));

    painter->drawEllipse(rect);


    Q_UNUSED(option)
    Q_UNUSED(widget)
}

