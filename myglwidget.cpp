// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>
#include <bits/stdc++.h>
#include "myglwidget.h"
using namespace std;
MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
}

MyGLWidget::~MyGLWidget()
{
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}
void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}
void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle){
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::initializeGL()
{
//    qglClearColor(Qt::black);

//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//    glShadeModel(GL_SMOOTH);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);

//    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
//    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}


void drawline(){
    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex3d(0,-1.5,0);
    glVertex3d(0.75,-1.5,0);
    glEnd();


    glColor3f(0,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex3d(0,-1.5,0);
    glVertex3d(0,-1.2,0);
    glEnd();
}
void drawtraingle(){
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
          glNormal3f(0,-1,0.707);
          glVertex3f(1.5,.9,1);
          glVertex3f(-.5,.9,1);
          glVertex3f(.4,1.5,0.6);
      glEnd();

      glBegin(GL_TRIANGLES);
          glNormal3f(1,0, 0.707);
          glVertex3f(-1,1,0);
          glVertex3f(1,1,0);
          glVertex3f(.4,1.5,0.6);
      glEnd();

      glBegin(GL_TRIANGLES);
          glNormal3f(0,1,0.707);
          glVertex3f(-1,1,0);
          glVertex3f(-.5,.9,1);
          glVertex3f(.4,1.5,0.6);
      glEnd();

      glBegin(GL_TRIANGLES);
          glNormal3f(-1,0,0.707);
          glVertex3f(1,1,0);
          glVertex3f(1.5,.9,1);
            glVertex3f(.4,1.5,0.6);
      glEnd();
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 1, 0, 0);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
//    glRotatef(xRot/16.0,1,0,0);
//    glRotatef(yRot/30.0,0,1,0);
//    glRotatef(zRot/16.0,0,0,1);
    drawHouse(0);
    drawHouse(1);
    drawtraingle();
    if(isOpenedDoor()){
        drawOpenedDoor();
    }else
        drawClosedDoor();
    if(isOpenedWindows()){
        drawOpenedWindows(0 , 0);
        drawOpenedWindows(0 , 1);
        drawOpenedWindows(1 , 1);
        drawOpenedWindows(1 , 0);

    }else{
        drawClosedWindows( 0 , 0);
        drawClosedWindows( 0 , 1);
        drawClosedWindows( 1 , 0);
        drawClosedWindows( 1 , 1);

    }
    glRotatef(xRot/16.0,1,0,0);
    glRotatef(yRot/30.0,0,1,0);
    glRotatef(zRot/16,0,.7,1);
    drawBicycle();
    drawline();

}


void drawCircle(double x1,double y1,double z1){
    float x2,y2,z2;
    float angle;
    double radius=0.1;

    glColor3f(0,0,0);

    glBegin(GL_POINTS);
    for (angle=1.0f;angle<361.0f;angle+=.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        z2 = z1+cos(angle)*radius;
        glVertex3f(x2,y2,z2);
    }
    glEnd();
}
void MyGLWidget::drawOpenedWindows(int tempX , int tempY){
    glBegin(GL_POLYGON);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(.32 + tempX,-.4 + tempY,1.2);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(.2 + tempX,-.4 + tempY,1);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(.2 + tempX,-.2 + tempY,1);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(.32 + tempX,-.2 + tempY,1.2);
     glEnd();

     //shabk shmal
   glBegin(GL_POLYGON);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3d(-.2 + tempX,-.4 + tempY,1); // 1
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3d(-.32 + tempX,-.4 + tempY,1.2);// 2
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3d(-.32 + tempX,-.2 + tempY,1.2); // 3
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3d(-.2 + tempX,-.2 + tempY,1);//glVertex3d(0,-.2,1); // 4
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3d(0 + tempX,-.4 + tempY,1);//glVertex3d(.2,-.4,1);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3d(.2 + tempX,-.4 + tempY,1);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3d(.2 + tempX,-.2 + tempY,1);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3d(0 + tempX,-.2 + tempY,1);//glVertex3d(.2,-.2,1);
     glEnd();

       //shabk shmal
     glBegin(GL_POLYGON);
         glColor3f(1.0f,0.0f,1.0f);
         glVertex3d(-.2 + tempX,-.4 + tempY,1);
         glColor3f(1.0f,0.0f,1.0f);
         glVertex3d(0 + tempX,-.4 + tempY,1);//glVertex3d(-.2,-.4,1);
         glColor3f(1.0f,0.0f,1.0f);
         glVertex3d(0 + tempX,-.2 + tempY,1);
         glColor3f(1.0f,0.0f,1.0f);
         glVertex3d(-.2 + tempX,-.2 + tempY,1);//glVertex3d(0,-.2,1);
      glEnd();
}
void MyGLWidget::drawClosedWindows(int tempX , int tempY){
    glBegin(GL_POLYGON);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(0 + tempX,-.4 + tempY,1);//glVertex3d(.2,-.4,1);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(.2 + tempX,-.4 + tempY,1);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(.2 + tempX,-.2 + tempY,1);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(0 + tempX,-.2 + tempY,1);//glVertex3d(.2,-.2,1);
     glEnd();

       //shabk shmal
     glBegin(GL_POLYGON);
         glColor3f(0.0f,0.0f,1.0f);
         glVertex3d(-.2 + tempX,-.4 + tempY,1);
         glColor3f(0.0f,0.0f,1.0f);
         glVertex3d(0 + tempX,-.4 + tempY,1);//glVertex3d(-.2,-.4,1);
         glColor3f(0.0f,0.0f,1.0f);
         glVertex3d(0 + tempX,-.2 + tempY,1);
         glColor3f(0.0f,0.0f,1.0f);
         glVertex3d(-.2 + tempX,-.2 + tempY,1);//glVertex3d(0,-.2,1);
      glEnd();
}
void MyGLWidget::drawOpenedDoor(){
    glBegin(GL_POLYGON);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(1.55,-.95,1.3); // 1
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(1.3,-.95,1); // 2
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(1.3,-.45,1); // 3
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(1.55,-.45,1.3); // 4
     glEnd();
     glBegin(GL_POLYGON);
         glColor3f(1.0f,0.0f,1.0f);
         glVertex3d(1,-.95,1); // 1
         glColor3f(1.0f,0.0f,1.0f);
         glVertex3d(1.3,-.95,1); // 2
         glColor3f(1.0f,0.0f,1.0f);
         glVertex3d(1.3,-.45,1); // 3
         glColor3f(1.0f,0.0f,1.0f);
         glVertex3d(1,-.45,1); // 4
      glEnd();
}
void MyGLWidget::drawClosedDoor(){
    glBegin(GL_POLYGON);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(1,-.95,1); // 1
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(1.3,-.95,1); // 2
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(1.3,-.45,1); // 3
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3d(1,-.45,1); // 4
     glEnd();
}
void MyGLWidget::drawHouse(int temp){
    /////////7eta gwa
 glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1,-1 + temp,0);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1,-1 + temp,0);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1,0 + temp,0);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1,0 + temp,0);
  glEnd();

    //////////// foo2
    glBegin(GL_POLYGON);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-0.5,-0.1 + temp,1);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(1.5,-0.1 + temp,1);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(1,0 + temp,0);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-1,0 + temp,0);
    glEnd();

    //////////////////////t7t
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-1.1 + temp,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1.5,-1.1 + temp,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1,-1 + temp,0);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-1,-1 + temp,0);
     glEnd();


     // el gnb el ymeen
     glBegin(GL_POLYGON);
         glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(-1,-1 + temp,0);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-1.1 + temp,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-0.1 + temp,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-1,0 + temp,0);
     glEnd();
        //el gnb el shmal
     glBegin(GL_POLYGON);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1,-1 + temp,0);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1.5,-1.1 + temp,1);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1.5,-0.1 + temp,1);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1,0 + temp,0);
      glEnd();

//    7eeta fe el wesh
     glBegin(GL_POLYGON);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-1.1 + temp,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1.5,-1.1 + temp,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1.5,-0.1 + temp,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-0.1 + temp,1);
      glEnd();


}

void MyGLWidget::drawBicycle(){
    drawCircle(0,-1.5,0);
    drawCircle(0.75,-1.5,0);

}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}


void MyGLWidget::setOpenDoor(bool z){
    openDoor = z;
}
void MyGLWidget::setOpenWindows(bool z){
    openWindows = z;
}
bool MyGLWidget::isOpenedWindows(){
    return openWindows;
}
bool MyGLWidget::isOpenedDoor(){
    return openDoor;
}
void MyGLWidget::keyPressEvent(QKeyEvent *event){
     if(event->key()==(int)'D'){
        yRot+=10;
    }
    else if(event->key()==(int)'A'){
        yRot-=10;
    }else if(event->key() == (int)'W' && isOpenedWindows()){
        setOpenWindows(false);
    }else if(event->key() == (int)'W'){
        setOpenWindows(true);
    }else if(event->key() == (int)'R' && isOpenedDoor()){
        setOpenDoor(false);
    }else if(event->key() == (int)'R'){
        setOpenDoor(true);
    }
    else if(event->key()==(int)'Z'){
        zRot+=10;
    }
    else if(event->key()==(int)'X'){
        zRot-=10;
    }

    updateGL();
}
