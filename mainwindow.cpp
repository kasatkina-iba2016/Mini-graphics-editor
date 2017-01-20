#include "mainwindow.h"
#include <QCommonStyle>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    view=new QGraphicsView();
    scene = new PaintScene();
    InstrumentGroup=new QActionGroup(this);
    ColorGroup=new QActionGroup(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    this->setWindowIcon(QIcon(":/network-64.png"));
    setWindowTitle("Новый-WordRed");

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);

    menuBar()->setStyleSheet("background:#f0f0f0;");
    fileMenu=menuBar()->addMenu(tr("&File"));

    newAction= new QAction(tr("&New"),this);
    newAction->setShortcuts(QKeySequence::New);
    newAction->setIcon(QIcon(":/new.png"));
    newAction->setIconVisibleInMenu(true);
    connect(newAction,SIGNAL(triggered(bool)),this,SLOT(slotNew()));
    fileMenu->addAction(newAction);

    openAction= new QAction(tr("&Open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setIcon(QIcon(":/open.png"));
    openAction->setIconVisibleInMenu(true);
    connect(openAction,SIGNAL(triggered(bool)),this,SLOT(slotOpen()));
    fileMenu->addAction(openAction);

    saveAction= new QAction(tr("&Save"),this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setIcon(QIcon(":/save.png"));
    saveAction->setIconVisibleInMenu(true);
    connect(saveAction,SIGNAL(triggered(bool)),this,SLOT(slotSave()));
    fileMenu->addAction(saveAction);

    saveAsAction= new QAction(tr("Sa&ve as..."),this);
    saveAsAction->setShortcuts(QKeySequence::SaveAs);
    saveAsAction->setIcon(QIcon(":/saveAs.png"));
    saveAsAction->setIconVisibleInMenu(true);
    connect(saveAsAction,SIGNAL(triggered(bool)),this,SLOT(slotSaveAs()));
    fileMenu->addAction(saveAsAction);

    fileMenu->addSeparator();

    exitAction= new QAction(tr("&Exit"),this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setIcon(QIcon(":/exit.png"));
    exitAction->setIconVisibleInMenu(true);
    connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(close()));
    fileMenu->addAction(exitAction);

    instrumentMenu=menuBar()->addMenu(tr("&Instruments"));

    QAction *lasticAct= new QAction(tr("Lastic"), this);
    instrumentMenu->addAction(lasticAct);
    lasticAct->setCheckable(true);
    lasticAct->setIcon(QIcon(":/lastic.png"));
    connect(lasticAct, SIGNAL(triggered(bool)), this, SLOT(on_btnLastic()));

    QAction *penAct= new QAction(tr("Pen"), this);
    instrumentMenu->addAction(penAct);
    penAct->setCheckable(true);
    penAct->setIcon(QIcon(":/pencil.png"));
    connect(penAct, SIGNAL(triggered(bool)), this, SLOT(on_btnPen()));

    QMenu *brushMenu=new QMenu;
    brushMenu->setIcon(QIcon(":/fill.png"));

    QAction *noneBrush=new QAction(tr("None"), this);
    brushMenu->addAction(noneBrush);
    connect(noneBrush, SIGNAL(triggered()), this, SLOT(slotNoneBrush()));

    QAction *greenBrush=new QAction(tr(""), this);
    brushMenu->addAction(greenBrush);
    greenBrush->setIcon(QIcon(":/green.png"));
    greenBrush->setIconVisibleInMenu(true);
    connect(greenBrush, SIGNAL(triggered()), this, SLOT(slotGreenBrush()));

    QAction *yellowBrush=new QAction(tr(""), this);
    brushMenu->addAction(yellowBrush);
    yellowBrush->setIcon(QIcon(":/yellow.png"));
    yellowBrush->setIconVisibleInMenu(true);
    connect(yellowBrush, SIGNAL(triggered()), this, SLOT(slotYellowBrush()));

    QAction *redBrush=new QAction(tr(""), this);
    brushMenu->addAction(redBrush);
    redBrush->setIcon(QIcon(":/new_red.png"));
    redBrush->setIconVisibleInMenu(true);
    connect(redBrush, SIGNAL(triggered()), this, SLOT(slotRedBrush()));

    QAction *blueBrush=new QAction(tr(""), this);
    brushMenu->addAction(blueBrush);
    blueBrush->setIcon(QIcon(":/blue.png"));
    blueBrush->setIconVisibleInMenu(true);
    connect(blueBrush, SIGNAL(triggered()), this, SLOT(slotBlueBrush()));

    QAction *magentaBrush=new QAction(tr(""), this);
    brushMenu->addAction(magentaBrush);
    magentaBrush->setIcon(QIcon(":/magenta.png"));
    magentaBrush->setIconVisibleInMenu(true);
    connect(magentaBrush, SIGNAL(triggered()), this, SLOT(magentaBrush()));

    QAction *blackBrush=new QAction(tr(""), this);
    brushMenu->addAction(blackBrush);
    blackBrush->setIcon(QIcon(":/black.png"));
    blackBrush->setIconVisibleInMenu(true);
    connect(blackBrush, SIGNAL(triggered()), this, SLOT(slotBlackBrush()));

    QAction *whiteBrush=new QAction(tr(""), this);
    brushMenu->addAction(whiteBrush);
    whiteBrush->setIcon(QIcon(":/white1.png"));
    whiteBrush->setIconVisibleInMenu(true);
    connect(whiteBrush, SIGNAL(triggered()), this, SLOT(slotWhiteBrush()));

    combo=new QComboBox;
    combo->setStyleSheet("QComboBox::drop-down{image:url(:/fill.png);}");

    combo->addItem(QIcon(""),"None");
    combo->addItem(QIcon(":/black.png"),"");
    combo->addItem(QIcon(":/blue.png"),"");
    combo->addItem(QIcon(":/new_red.png"),"");
    combo->addItem(QIcon(":/yellow.png"),"");
    combo->addItem(QIcon(":/magenta.png"),"");
    combo->addItem(QIcon(":/green.png"),"");
    combo->addItem(QIcon(":/gray.png"),"");
    combo->addItem(QIcon(":/white1.png"),"");
    connect(combo,SIGNAL(activated(int)),this,SLOT(slotBrush(int)));

    combo->setEditable(true);
    instrumentMenu->addMenu(brushMenu);

    QAction *recAct= new QAction(tr("Rectangle"), this);
    instrumentMenu->addAction(recAct);
    recAct->setCheckable(true);
    recAct->setIcon(QIcon(":/rectangle.png"));
    connect(recAct, SIGNAL(triggered(bool)), this, SLOT(on_btnKvadr()));

    QAction *trAct= new QAction(tr("Triangle"), this);
    instrumentMenu->addAction(trAct);
    trAct->setCheckable(true);
    trAct->setIcon(QIcon(":/trian.png"));
    connect(trAct, SIGNAL(triggered(bool)), this, SLOT(on_btnTreug()));

    QAction *rombAct= new QAction(tr("Romb"), this);
    instrumentMenu->addAction(rombAct);
    rombAct->setCheckable(true);
    rombAct->setIcon(QIcon(":/romb.png"));
    connect(rombAct, SIGNAL(triggered(bool)), this, SLOT(on_btnRomb()));

    QAction *ellAct= new QAction(tr("Ellipse"), this);
    instrumentMenu->addAction(ellAct);
    ellAct->setCheckable(true);
    ellAct->setIcon(QIcon(":/ellipse.png"));
    connect(ellAct, SIGNAL(triggered(bool)), this, SLOT(on_btnKrug()));

    QAction *strangeAct=new QAction(tr("Line"), this);
    instrumentMenu->addAction(strangeAct);
    strangeAct->setCheckable(true);
    strangeAct->setIcon(QIcon(":/line.png"));
    connect(strangeAct, SIGNAL(triggered(bool)), this, SLOT(on_btnLine()));

    QAction *blueAction=new QAction(tr("Blue"), this);
    blueAction->setCheckable(true);
    blueAction->setIcon(QIcon(":/blue.png"));
    blueAction->setIconVisibleInMenu(true);
    connect(blueAction, SIGNAL(triggered()), this, SLOT(slotBlue()));

    QAction *redAction=new QAction(tr("Red"), this);
    redAction->setCheckable(true);
    redAction->setIcon(QIcon(":/new_red.png"));
    redAction->setIconVisibleInMenu(true);
    connect(redAction, SIGNAL(triggered()), this, SLOT(slotRed()));

    QAction *greenAction=new QAction(tr("Green"), this);
    greenAction->setCheckable(true);
    greenAction->setIcon(QIcon(":/green.png"));
    greenAction->setIconVisibleInMenu(true);
    connect(greenAction, SIGNAL(triggered()), this, SLOT(slotGreen()));

    QAction *yellowAction=new QAction(tr("Yellow"), this);
    yellowAction->setCheckable(true);
    yellowAction->setIcon(QIcon(":/yellow.png"));
    yellowAction->setIconVisibleInMenu(true);
    connect(yellowAction, SIGNAL(triggered()), this, SLOT(slotYellow()));

    QAction *blackAction=new QAction(tr("Black"), this);
    blackAction->setCheckable(true);
    blackAction->setIcon(QIcon(":/black.png"));
    blackAction->setIconVisibleInMenu(true);
    connect(blackAction, SIGNAL(triggered()), this, SLOT(slotBlack()));

    QAction *magentaAction=new QAction(tr("Magenta"), this);
    magentaAction->setCheckable(true);
    magentaAction->setIcon(QIcon(":/magenta.png"));
    magentaAction->setIconVisibleInMenu(true);
    connect(magentaAction, SIGNAL(triggered()), this, SLOT(slotMagenta()));

    QAction *greyAction=new QAction(tr("Gray"), this);
    greyAction->setCheckable(true);
    greyAction->setIcon(QIcon(":/gray.png"));
    greyAction->setIconVisibleInMenu(true);
    connect(greyAction, SIGNAL(triggered()), this, SLOT(slotGray()));

    QAction *whiteAction=new QAction(tr("White"), this);
    whiteAction->setCheckable(true);
    whiteAction->setIcon(QIcon(":/white1.png"));
    whiteAction->setIconVisibleInMenu(true);
    connect(whiteAction, SIGNAL(triggered()), this, SLOT(slotWhite()));

    ColorGroup->addAction(magentaAction);
    ColorGroup->addAction(yellowAction);
    ColorGroup->addAction(blackAction);
    ColorGroup->addAction(greenAction);
    ColorGroup->addAction(redAction);
    ColorGroup->addAction(blueAction);
    ColorGroup->addAction(greyAction);
    ColorGroup->addAction(whiteAction);


    InstrumentGroup->addAction(strangeAct);
    InstrumentGroup->addAction(ellAct);
    InstrumentGroup->addAction(rombAct);
    InstrumentGroup->addAction(trAct);
    InstrumentGroup->addAction(recAct);
    InstrumentGroup->addAction(lasticAct);
    InstrumentGroup->addAction(penAct);

    resize(700,700);

    widthSlider=new QSlider(Qt::Vertical);
    widthSlider->setValue(3);
    widthSlider->setStyleSheet("QSlider::groove:vertical {"
                           "border: 1px solid #999999;"
                           "height: 150px;"
                           "background: palette(midlight);"
                           "width: 5px;"
                           "margin: 0px 10px;"

                                                  "}"
                           "QSlider::handle:vertical {"
                               "background: palette(window);"
                               "border: 1px solid #999999;"
                               "height: 10px;"
                               "margin: 0px -8px;"
                               "border-radius: 3px;"
                       "}");
    lbl1=new QLabel("3");
    lbl1->setAlignment(Qt::AlignRight);
    lbl1->setFixedHeight(20);
    QFont font = lbl1->font();
    font.setPointSize(13);
    lbl1->setFont(font);
    lbl1->setFixedSize(20,20);
    widthSlider->setRange(0,20);
    widthSlider->setTickInterval(2);
    widthSlider->setTickPosition(QSlider::TicksLeft);

    toolBar=new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);

    toolBar->addAction(recAct);
    toolBar->addAction(ellAct);
    toolBar->addAction(strangeAct);
    toolBar->addAction(trAct);
    toolBar->addAction(rombAct);
    toolBar->addSeparator();
    toolBar->addAction(lasticAct);
    toolBar->addAction(penAct);
    toolBar->addWidget(combo);
    toolBar->addSeparator();
    toolBar->addWidget(lbl1);
    toolBar->addWidget(widthSlider);

    connect(widthSlider,SIGNAL(valueChanged(int)),lbl1,SLOT(setNum(int)));
    connect (widthSlider,SIGNAL(valueChanged(int)),this,SLOT(slotWidth()));

    toolBar2=new QToolBar(this);
    addToolBar(Qt::TopToolBarArea, toolBar2);

    toolBar2->addAction(newAction);
    toolBar2->addAction(openAction);
    toolBar2->addAction(saveAction);
    toolBar2->addAction(saveAsAction);

    toolBar3=new QToolBar(this);
    addToolBar(Qt::RightToolBarArea, toolBar3);

    toolBar3->addAction(blueAction);
    toolBar3->addAction(greenAction);
    toolBar3->addAction(blackAction);
    toolBar3->addAction(redAction);
    toolBar3->addAction(magentaAction);
    toolBar3->addAction(yellowAction);
    toolBar3->addAction(greyAction);
    toolBar3->addAction(whiteAction);

    toolBar3->addSeparator();

    toolBar3->setStyleSheet("QToolBar{ background: qlineargradient(x1:0, y1:0, x2:1, y2:0,stop:0 white, stop: 0.4 #968e86, stop:1 white);"
                            "color: white; size: 15px; weight: bold;}" );
    toolBar->setStyleSheet("QToolBar{ background: qlineargradient(x1:0, y1:0, x2:1, y2:0,stop:0 white, stop: 0.4 #968e86, stop:1 white);"
                            "color: white; size: 15px; weight: bold;}" );
    toolBar2->setStyleSheet("QToolBar{ background: qlineargradient(x1:0, y1:0, x2:1, y2:0,stop:0 white, stop: 0.4 #968e86, stop:1 white);"
                            "color: white; size: 15px; weight: bold;}" );

  setCentralWidget(view);
  resize(500,500);
}

MainWindow::~MainWindow()
{

}

void MainWindow::slotTimer()
{
    timer->stop();
    scene->setSceneRect(0,0,view->width() - 30,view->height() - 30);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_btnRomb()
{
    scene->setTypeFigure(PaintScene::RombType);
    setCursor(Qt::CrossCursor);
}

void MainWindow::on_btnKvadr()
{
    scene->setTypeFigure(PaintScene::SquareType);
    setCursor(Qt::CrossCursor);
}

void MainWindow::on_btnTreug()
{
    scene->setTypeFigure(PaintScene::TriangleType);
    setCursor(Qt::CrossCursor);
}

void MainWindow::on_btnKrug()
{
    scene->setTypeFigure(PaintScene::EllipseType);
    setCursor(Qt::CrossCursor);
}

void MainWindow::on_btnLine()
{
    scene->setTypeFigure(PaintScene::LineType);
    setCursor(Qt::CrossCursor);
}

void MainWindow::slotWidth()
{
    QString strValue=lbl1->text();
    int value=strValue.toInt();
    scene->setPenWidth(value);
}

void MainWindow::on_btnPen()
{
     scene->setTypeFigure(PaintScene::PenType);
     setCursor(QPixmap(":/pencil.png"));
}

void MainWindow::on_btnLastic()
{
    scene->setPenColor(Qt::white);
    scene->setTypeFigure(PaintScene::LasticType);
    setCursor(QPixmap(":/lastic.png"));
}

void MainWindow::slotBrush(int ind)
{
    switch (ind) {
    case 0:
       slotNoneBrush();
       break;
    case 1:
       slotBlackBrush();
       break;
    case 2:
       slotBlueBrush();
        break;
    case 3:
       slotRedBrush();
        break;
    case 4:
       slotYellowBrush();
       break;
    case 5:
       slotMagentaBrush();
       break;
    case 6:
       slotGreenBrush();
        break;
    case 7:
       slotGrayBrush();
        break;
    case 8:
       slotWhiteBrush();
        break;
    default:
        slotNoneBrush();
        break;
    }
}

void MainWindow::slotNoneBrush()
{
    scene->setBrushColor(Qt::NoBrush);
}

void MainWindow::slotBlue()
{
    scene->setPenColor(Qt::blue);
}

void MainWindow::slotBlueBrush()
{
     scene->setBrushColor(Qt::blue);
}

void MainWindow::slotRed()
{
    scene->setPenColor(Qt::red);
}

void MainWindow::slotRedBrush()
{
    scene->setBrushColor(Qt::red);
}

void MainWindow::slotGreen()
{
    scene->setPenColor(Qt::green);
}

void MainWindow::slotGreenBrush()
{
    scene->setBrushColor(Qt::green);
}

void MainWindow::slotYellow()
{
    scene->setPenColor(Qt::yellow);
}

void MainWindow::slotYellowBrush()
{
    scene->setBrushColor(Qt::yellow);
}

void MainWindow::slotMagenta()
{
    scene->setPenColor(Qt::magenta);
}

void MainWindow::slotMagentaBrush()
{
    scene->setBrushColor(Qt::magenta);
}

void MainWindow::slotBlack()
{
    scene->setPenColor(Qt::black);
}

void MainWindow::slotBlackBrush()
{
    scene->setBrushColor(Qt::black);
}

void MainWindow::slotGray()
{
    scene->setPenColor(Qt::gray);
}

void MainWindow::slotGrayBrush()
{
    scene->setBrushColor(Qt::gray);
}

void MainWindow::slotWhite()
{
    scene->setPenColor(Qt::white);
}

void MainWindow::slotWhiteBrush()
{
    scene->setBrushColor(Qt::white);
}


bool MainWindow::maybeSave()
{
    if (view->isTransformed())
    {
       QMessageBox::StandardButton ret;
       ret = QMessageBox::warning(this, tr("WordRed"),
       tr("The image has been modified.\nDo you want to save your changes?"),
       QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);
       if (ret == QMessageBox::Save)
        {
           slotSaveAs();
        }
       else if (ret == QMessageBox::Cancel)
        {
            return false;
        }
    }
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
       if (maybeSave()) event->accept();
       else event->ignore();
}

void MainWindow::slotNew()
{
    if (view->isTransformed())
    {
       QMessageBox::StandardButton ret;
       ret = QMessageBox::warning(this, tr("WordRed"),
       tr("The image has been modified.\nDo you want to save your changes?"),
       QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);
       if (ret == QMessageBox::Save)
        {
           slotSaveAs();
           view->clearFocus();
           setWindowTitle("Новый-WordRed");
        }
     else
       {
           view->clearFocus();
           setWindowTitle("Новый-WordRed");
       }
    }
}

void MainWindow::slotOpen()
{
    fileName=QFileDialog::getOpenFileName
    (this,"Открыть...",QDir::homePath(),"PNG files(*.png )");
    QFileInfo fi(fileName);
    QString base=fi.baseName();
    QFile Myfile(fileName);
      if ( Myfile.open ( QIODevice::ReadOnly) )
        {
            QPixmap * pix = new QPixmap();
            pix->load(fileName);
            scene->addPixmap(*pix);
            view->setScene(scene);
            Myfile.close();
            setWindowTitle(base+"-WordRed");
            setWindowModified(false);
        }
}

void MainWindow::slotSave()
{
    if (!windowTitle().startsWith("Новый"))
    {

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    scene->render(&painter);
    image.save(fileName);
    file.close();
    setWindowModified(false);
    }
    else slotSaveAs();
}

void MainWindow::slotSaveAs()
{
      fileName=QFileDialog::getSaveFileName(this,"Сохранить как...",QDir::homePath(),"PNG files( *.png )");

        QFile Myfile(fileName);
        if (Myfile.open(QIODevice::WriteOnly))
        {
            QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
            QPainter painter(&image);
            scene->render(&painter);
            image.save(fileName);
            Myfile.close();
            setWindowModified(false);
         }
}

