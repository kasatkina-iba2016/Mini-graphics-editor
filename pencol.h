#ifndef PENCOL_H
#define PENCOL_H
#include <QPainter>

class PenColor : public QPen
{
   //Q_OBJECT

public:
    QPen *pen;

    PenColor()
    {
       pen=new QPen;
    }

    void getcolorPen(QPen *_pen)
    {
         pen=_pen;
    }

    QPen setcolorPen()
    {
        return *pen;
    }
};

#endif // PENCOL_H

