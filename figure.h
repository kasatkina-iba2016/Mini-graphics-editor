#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QBrush>
#include <QDebug>
#include <QCursor>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    QPointF m_startPoint;
    QPointF m_endPoint;
    QRectF boundingRect() const;
public:
    explicit Figure(QPointF point,QObject *parent = 0);
    ~Figure();

    QPointF startPoint() const;
    QPointF endPoint() const;

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);

signals:
    void pointChanged();

public slots:
    void updateRomb();
};

#endif // FIGURE_H
