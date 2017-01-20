/*#ifndef PEN_H
#define PEN_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

class Pen : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit Pen(QObject *parent = 0);
    ~Pen();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PEN_H
*/
