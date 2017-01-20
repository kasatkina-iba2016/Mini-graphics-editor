#include "square.h"
#include <QPainter>

Square::Square(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Square::~Square()
{

}

QColor Square::penFigureColor() const
{
    return FigureColor;
}

void Square::setPenFigureColor(const QColor &myPenColor)
{
    FigureColor=myPenColor;
}

int Square::penFigureWidth() const
{
   return FigureWidth;
}

void Square::setPenFigureWidth(const int &myPenWidth)
{
    FigureWidth=myPenWidth;
}

QBrush Square::brushFigureColor() const
{
    return FigureBrush;
}

void Square::setBrushFigureColor(const QBrush &myBrushColor)
{
    FigureBrush=myBrushColor;
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(FigureColor,FigureWidth));
    painter->setBrush(FigureBrush);

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));

    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

