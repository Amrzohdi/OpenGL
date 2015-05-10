// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
    void keyPressEvent(QKeyEvent *event);
    void drawHouse(int);
    void drawBicycle();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void setOpenWindows(bool);
    bool isOpenedWindows();
    void setOpenDoor(bool);
    bool isOpenedDoor();
public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);
private:
//    void drawHouse();
//    void draw2();
    void drawOpenedWindows(int , int);
    void drawClosedWindows(int , int);
    void drawOpenedDoor();
    void drawClosedDoor();
    int xRot;
    int yRot;
    int zRot;
    bool openWindows;
    bool openDoor;
    QPoint lastPos;
    bool rotatedbyc;
};

#endif // MYGLWIDGET_H

