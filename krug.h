#ifndef KRUG_H
#define KRUG_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Krug : public Figure
{
    Q_OBJECT

    QColor FigureColor;
    QBrush FigureBrush;
    int FigureWidth;

public:
    explicit Krug(QPointF point,QObject *parent = 0);
    ~Krug();

    QColor penFigureColor() const;
    void setPenFigureColor(const QColor &myPenColor);
    int penFigureWidth() const;
    void setPenFigureWidth(const int &myPenWidth);
    QBrush brushFigureColor() const;
    void setBrushFigureColor(const QBrush &myBrushColor);


private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // KRUG_H

