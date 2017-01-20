#include "triangle.h"
#include <QPainter>

Triangle::Triangle(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Triangle::~Triangle()
{

}

QColor Triangle::penFigureColor() const
{
    return FigureColor;
}

void Triangle::setPenFigureColor(const QColor &myPenColor)
{
    FigureColor=myPenColor;
}

int Triangle::penFigureWidth() const
{
    return FigureWidth;
}

void Triangle::setPenFigureWidth(const int &myPenWidth)
{
    FigureWidth=myPenWidth;
}

QBrush Triangle::brushFigureColor() const
{
    return FigureBrush;
}

void Triangle::setBrushFigureColor(const QBrush &myBrushColor)
{
    FigureBrush=myBrushColor;
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(FigureColor,FigureWidth));

    QPolygonF polygon;
    painter->setBrush(FigureBrush);
    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), startPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? endPoint().x() : startPoint().x(),
                           endPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? startPoint().x() : endPoint().x(),
                           endPoint().y());

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
