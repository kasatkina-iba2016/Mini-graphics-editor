#ifndef LINE_H
#define LINE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"


class Line: public Figure
{
    Q_OBJECT

    QColor FigureColor;
    int FigureWidth;

public:
    explicit Line(QPointF point, QObject *parent = 0);
    ~Line();

    QColor penFigureColor() const;
    void setPenFigureColor(const QColor &myPenColor);
    int penFigureWidth() const;
    void setPenFigureWidth(const int &myPenWidth);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LINE_H
