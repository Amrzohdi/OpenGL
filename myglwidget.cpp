// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>

#include "myglwidget.h"

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

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    draw();
//    draw2();
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


void drawCircle(double x1,double y1,double z1){
    float x2,y2,z2;
    float angle;
    double radius=0.1;

    glColor3f(1.0,1.0,0.6);

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

void MyGLWidget::draw()
{

    /////////7eta gwa
 glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1,-1,0);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1,-1,0);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1,0,0);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1,0,0);
  glEnd();

    //////////// foo2
    glBegin(GL_POLYGON);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-0.5,-0.1,1);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(1.5,-0.1,1);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(1,0,0);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-1,0,0);
    glEnd();

    //////////////////////t7t
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1,-1,0);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-1,-1,0);
     glEnd();


     // el gnb el ymeen
     glBegin(GL_POLYGON);
         glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(-1,-1,0);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-0.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-1,0,0);
     glEnd();
        //el gnb el shmal
     glBegin(GL_POLYGON);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1,-1,0);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1.5,-1.1,1);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1.5,-0.1,1);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1,0,0);
      glEnd();

//    7eeta fe el wesh
     glBegin(GL_POLYGON);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1.5,-0.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-0.1,1);
      glEnd();

    // bab
      glBegin(GL_POLYGON);
          glColor3f(0.0f,0.0f,1.0f);
          glVertex3d(1,-.95,0);
         // glVertex3d(1.3,-.95,1);
          glColor3f(0.0f,0.0f,1.0f);
          glVertex3d(1.3,-.95,0);
          glColor3f(0.0f,0.0f,1.0f);
          glVertex3d(1.3,-.45,0);
          glColor3f(0.0f,0.0f,1.0f);
          glVertex3d(1,-.45,0);
          //glVertex3d(1.3,-.45,1);
       glEnd();

       // shbak ymeen
         glBegin(GL_POLYGON);
             glColor3f(0.0f,0.0f,1.0f);
             glVertex3d(0,-.4,0);//glVertex3d(.2,-.4,1);
             glColor3f(0.0f,0.0f,1.0f);
             glVertex3d(.2,-.4,0);
             glColor3f(0.0f,0.0f,1.0f);
             glVertex3d(.2,-.2,0);
             glColor3f(0.0f,0.0f,1.0f);
             glVertex3d(0,-.2,0);//glVertex3d(.2,-.2,1);
          glEnd();

            //shabk shmal
          glBegin(GL_POLYGON);
              glColor3f(0.0f,0.0f,1.0f);
              glVertex3d(-.2,-.4,0);
              glColor3f(0.0f,0.0f,1.0f);
              glVertex3d(0,-.4,0);//glVertex3d(-.2,-.4,1);
              glColor3f(0.0f,0.0f,1.0f);
              glVertex3d(0,-.2,0);
              glColor3f(0.0f,0.0f,1.0f);
              glVertex3d(-.2,-.2,0);//glVertex3d(0,-.2,1);
           glEnd();
//    drawCircle(1,1,1);
    drawCircle(0,-1.5,2);
    drawCircle(0,-1.5,2.2);
}
void MyGLWidget::draw2()
{

    /////////7eta gwa
 glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1,-1,0);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1,-1,0);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(1,0,0);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1,0,0);
  glEnd();

    //////////// foo2
    glBegin(GL_POLYGON);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-0.5,-0.1,1);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(1.5,-0.1,1);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(1,0,0);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex3f(-1,0,0);
    glEnd();

    //////////////////////t7t
    glBegin(GL_POLYGON);
    glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1,-1,0);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-1,-1,0);
     glEnd();


     // el gnb el ymeen
     glBegin(GL_POLYGON);
         glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(-1,-1,0);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-0.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-1,0,0);
     glEnd();
        //el gnb el shmal
     glBegin(GL_POLYGON);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1,-1,0);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1.5,-1.1,1);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1.5,-0.1,1);
          glColor3f(1.0f,1.0f,1.0f);
          glVertex3f(1,0,0);
      glEnd();

//    7eeta fe el wesh
     glBegin(GL_POLYGON);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1.5,-1.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(1.5,-0.1,1);
         glColor3f(1.0f,1.0f,1.0f);
         glVertex3f(-0.5,-0.1,1);
      glEnd();

    // bab
      glBegin(GL_POLYGON);
          glColor3f(0.0f,0.0f,1.0f);
          glVertex3d(1,-.95,0);
         // glVertex3d(1.3,-.95,1);
          glColor3f(0.0f,0.0f,1.0f);
          glVertex3d(1.3,-.95,0);
          glColor3f(0.0f,0.0f,1.0f);
          glVertex3d(1.3,-.45,0);
          glColor3f(0.0f,0.0f,1.0f);
          glVertex3d(1,-.45,0);
          //glVertex3d(1.3,-.45,1);
       glEnd();

       // shbak ymeen
         glBegin(GL_POLYGON);
             glColor3f(0.0f,0.0f,1.0f);
             glVertex3d(.2,-.4,1);
             glColor3f(0.0f,0.0f,1.0f);
             glVertex3d(.2,-.4,0);
             glColor3f(0.0f,0.0f,1.0f);
             glVertex3d(.2,-.2,0);
             glColor3f(0.0f,0.0f,1.0f);
            glVertex3d(.2,-.2,1);
          glEnd();

            //shabk shmal
          glBegin(GL_POLYGON);
              glColor3f(0.0f,0.0f,1.0f);
              glVertex3d(-.2,-.4,0);
              glColor3f(0.0f,0.0f,1.0f);
              glVertex3d(-.2,-.4,1);
              glColor3f(0.0f,0.0f,1.0f);
              glVertex3d(0,-.2,0);
              glColor3f(0.0f,0.0f,1.0f);
              glVertex3d(0,-.2,1);
           glEnd();



}
