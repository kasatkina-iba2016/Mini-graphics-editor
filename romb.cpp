#include "romb.h"
#include <QPainter>

Romb::Romb(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Romb::~Romb()
{

}

QColor Romb::penFigureColor() const
{
    return FigureColor;
}

void Romb::setPenFigureColor(const QColor &myPenColor)
{
    FigureColor=myPenColor;
}

int Romb::penFigureWidth() const
{
    return FigureWidth;
}

void Romb::setPenFigureWidth(const int &myPenWidth)
{
    FigureWidth=myPenWidth;
}

QBrush Romb::brushFigureColor() const
{
    return FigureBrush;
}

void Romb::setBrushFigureColor(const QBrush &myBrushColor)
{
    FigureBrush=myBrushColor;
}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->setPen(QPen(FigureColor,FigureWidth));
   painter->setBrush(FigureBrush);
   QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), startPoint().y())
                << QPointF(endPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                           abs((endPoint().y() - startPoint().y())/2))
                << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), endPoint().y())
                << QPointF(startPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                           abs((endPoint().y() - startPoint().y())/2));

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
