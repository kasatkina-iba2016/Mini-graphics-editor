#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtWidgets>
#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include <QGraphicsView>
#include <QtWidgets>
#include <QFile>
#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QUndoGroup>
#include <QAction>
#include <QMenu>
#include <QShortcut>
#include <QToolBar>
#include "paintscene.h"
#include "colorpen.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGraphicsView *view;
    PaintScene *scene;
    QTimer *timer;
    QStatusBar *statusBar;
    QToolBar *toolBar,*toolBar2,*toolBar3;
    QMenu *fileMenu,*editMenu,*instrumentMenu,*effectMenu, *brushMenu;
    QAction *newAction,*openAction,*saveAction,*saveAsAction,*closeAction,*exitAction,
            *undoAction,*redoAction,*copyAction,*pasteAction,*cutAction,*blueAction,
            *greenAction,*blackAction;
    QString fileName;
    QComboBox *combo;
    QCursor *curs;
    QSlider *widthSlider;
    QLabel *lbl1;
    QActionGroup *InstrumentGroup, *ColorGroup;

private:

    void resizeEvent(QResizeEvent * event);
    bool maybeSave();

private slots:

    void slotTimer();
    void on_btnKvadr();
    void on_btnRomb();
    void on_btnTreug();
    void on_btnKrug();
    void on_btnLine();
    void on_btnPen();
    void on_btnLastic();
    void slotBrush(int ind);
    void slotNoneBrush();
    void slotBlue();
    void slotBlueBrush();
    void slotRed();
    void slotRedBrush();
    void slotGreen();
    void slotGreenBrush();
    void slotYellow();
    void slotYellowBrush();
    void slotMagenta();
    void slotMagentaBrush();
    void slotBlack();
    void slotBlackBrush();
    void slotGray();
    void slotGrayBrush();
    void slotWhite();
    void slotWhiteBrush();
    void slotNew();
    void slotOpen();
    void slotSave();
    void slotSaveAs();
    void slotWidth();
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
