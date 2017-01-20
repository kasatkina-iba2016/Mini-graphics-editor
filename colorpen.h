#ifndef COLORPEN_H
#define COLORPEN_H
#include <QColor>
#include <QPainter>

class colorClass:public QPainter
{
    Q_OBJECT
    QColor myPenColor;

 public:
      colorClass();
     ~colorClass();

      void setPenColor(const QColor &newColor)
      {
          myPenColor = newColor;
      }

      QColor penColor() const {return myPenColor;}
};
#endif // COLORPEN_H
