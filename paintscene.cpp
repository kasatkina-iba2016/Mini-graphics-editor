#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "krug.h"
#include "line.h"
#include "pen.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{
    myPenColor=Qt::white;
    myBrushColor=Qt::NoBrush;
    myPenWidth=3;
}

PaintScene::~PaintScene()
{

}

int PaintScene::typeFigure() const
{
    return m_typeFigure;
}

void PaintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void PaintScene::setPenWidth(const int &newWidth)
{
    myPenWidth=newWidth;
}

void PaintScene::setPenColor(const QColor &newColor)
{
    myPenColor = newColor;
}

QColor PaintScene::penColor() const
{
    return myPenColor;
}

int PaintScene::penWidth() const
{
    return myPenWidth;
}

void PaintScene::setBrushColor(const QBrush &newBrushColor)
{
    myBrushColor = newBrushColor;
}

QBrush PaintScene::brushColor() const
{
    return myBrushColor;
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_typeFigure==LasticType){
    addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::white,myPenWidth,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
    }

    else if(m_typeFigure==PenType){
    addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(myPenColor,myPenWidth,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
    }

    else
    {
    tempFigure->setEndPoint(event->scenePos());
    this->update(QRectF(0,0,this->width(), this->height()));
    }
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {

    case LasticType: {
         addEllipse(event->scenePos().x() - 5,event->scenePos().y() - 5,myPenWidth,myPenWidth,QPen(Qt::white),QBrush(Qt::white));
         previousPoint = event->scenePos();
    }
    case PenType: {
         addEllipse(event->scenePos().x() - 5,event->scenePos().y() - 5,myPenWidth,myPenWidth,QPen(Qt::NoPen),QBrush(myPenColor));
         previousPoint = event->scenePos();
    }
    case SquareType: {

        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        item->setPenFigureColor(myPenColor);
        item->setPenFigureWidth(myPenWidth);
        item->setBrushFigureColor(myBrushColor);
        tempFigure = item;
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        item->setPenFigureColor(myPenColor);
        item->setPenFigureWidth(myPenWidth);
        item->setBrushFigureColor(myBrushColor);
        tempFigure = item;
        break;
    }
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        item->setPenFigureColor(myPenColor);
        item->setPenFigureWidth(myPenWidth);
        item->setBrushFigureColor(myBrushColor);
        tempFigure = item;
        break;
    }
    case EllipseType: {
        Krug *item = new Krug(event->scenePos());
        item->setPos(event->pos());
        item->setPenFigureColor(myPenColor);
        item->setPenFigureWidth(myPenWidth);
        item->setBrushFigureColor(myBrushColor);
        tempFigure = item;
        break;
    }
    case LineType: {
        Line *item = new Line(event->scenePos());
        item->setPos(event->pos());
        item->setPenFigureColor(myPenColor);
        item->setPenFigureWidth(myPenWidth);

        tempFigure = item;
        break;
    }
    default:{

        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        item->setPenFigureColor(myPenColor);
        item->setPenFigureWidth(myPenWidth);
        item->setBrushFigureColor(myBrushColor);
        tempFigure = item;
        break;
    }
    }
    this->addItem(tempFigure);
}
