#include <QPainter>
#include "line.h"

Line::Line(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Line::~Line()
{

}

QColor Line::penFigureColor() const
{
    return FigureColor;
}

void Line::setPenFigureColor(const QColor &myPenColor)
{
    FigureColor=myPenColor;
}

int Line::penFigureWidth() const
{
    return FigureWidth;
}

void Line::setPenFigureWidth(const int &myPenWidth)
{
    FigureWidth=myPenWidth;
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
      painter->setPen(QPen(FigureColor,FigureWidth));
      painter->drawLine(startPoint().x(),startPoint().y(),endPoint().x(),endPoint().y());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
