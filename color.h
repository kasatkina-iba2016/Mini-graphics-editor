#ifndef COLOR_H
#define COLOR_H

#include <QWidget>

class Color : public QWidget
{
    Q_OBJECT
public:
    explicit Color(QWidget *parent = 0);
    void setColor()
    {
        paint.setPen(QPen(Qt::red, 2));
    }
     QPainter paint;




signals:

public slots:
};

#endif // COLOR_H
