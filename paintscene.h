#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    QColor myPenColor;
    QBrush myBrushColor;
    int myPenWidth;
    Figure *tempFigure;
    int m_typeFigure;
    QPointF previousPoint;

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

    int typeFigure() const;
    void setTypeFigure(const int type);

    void setPenColor(const QColor &newColor);
    QColor penColor() const;
    void setPenWidth(const int &newWidth);
    int penWidth() const;
    void setBrushColor(const QBrush &newBrushColor);
    QBrush brushColor() const;

    enum FigureTypes {
        SquareType,
        RombType,
        TriangleType,
        EllipseType,
        LineType,
        PenType,
        LasticType
    };

signals:
    void typeFigureChanged();

private:

    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
