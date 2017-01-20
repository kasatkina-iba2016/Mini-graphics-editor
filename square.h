#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Square : public Figure
{
    Q_OBJECT

    QColor FigureColor;
    int FigureWidth;
    QBrush FigureBrush;

public:
    explicit Square(QPointF point, QObject *parent = 0);
    ~Square();

    QColor penFigureColor() const;
    void setPenFigureColor(const QColor &myPenColor);
    int penFigureWidth() const;
    void setPenFigureWidth(const int &myPenWidth);
    QBrush brushFigureColor() const;
    void setBrushFigureColor(const QBrush &myBrushColor);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUARE_H
