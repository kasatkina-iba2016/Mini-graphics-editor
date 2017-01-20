#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Triangle : public Figure
{
    Q_OBJECT

    QColor FigureColor;
    int FigureWidth;
    QBrush FigureBrush;

public:
    explicit Triangle(QPointF point, QObject *parent = 0);
    ~Triangle();

    QColor penFigureColor() const;
    void setPenFigureColor(const QColor &myPenColor);
    int penFigureWidth() const;
    void setPenFigureWidth(const int &myPenWidth);
    QBrush brushFigureColor() const;
    void setBrushFigureColor(const QBrush &myBrushColor);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TRIANGLE_H
