#include "glwidget.h"

#include <QDebug>
#include <QMessageBox>
#include <QtOpenGL>
#include <QtWidgets>
#include <iostream> 

#include "../controller.h"
#include "mainwindow.h"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget{parent} {
  setGeometry(400, 200, 800, 600);
}

void GLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(colorWidget_.redF(), colorWidget_.greenF(), colorWidget_.blueF(), colorWidget_.alphaF());
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (typeProject_ == 1) {
    glFrustum(-(1), 1, -(1), 1, 1, 5);
    glTranslatef(0, 0, -3);
  } else {
    glOrtho(-(1), 1, -(1), 1, 1, 5);
    glTranslatef(0, 0, -2);
  }
  glVertexPointer(3, GL_DOUBLE, 0, vertices_.data());
  glEnableClientState(GL_VERTEX_ARRAY);
  Lines();
  Points();
  disableGL();
}

void GLWidget::disableGL()
{
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisable(GL_POINT_SMOOTH);
  glDisable(GL_POINT);
}

void GLWidget::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
}

void GLWidget::Points()
{
  glPointSize(vertSize_);
  glColor3d(colorVertices_.redF(), colorVertices_.greenF(), colorVertices_.blueF());
  if (typeVert_ == 1) {
    glEnable(GL_POINT);
    glDrawArrays(GL_POINTS, 0, vertices_.size() / 3);
  } else if (typeVert_ == 2) {
    glEnable(GL_POINT_SMOOTH);
    glDrawArrays(GL_POINTS, 0, vertices_.size() / 3);
  }
}

void GLWidget::Lines() 
{
  glLineWidth(ribsThick_);
  if (typeRib_ == 1) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x3333);
  } else  {
    glDisable(GL_LINE_STIPPLE);
  }
  glColor3d(colorLines_.redF(), colorLines_.greenF(), colorLines_.blueF());
  glDrawElements(GL_LINES, facets_.size(), GL_UNSIGNED_INT, facets_.data());
}

void GLWidget::SetRibsThick(double width) { ribsThick_ = width; }

void GLWidget::SetRibsType(int index) { typeRib_ = index; }

void GLWidget::SetVertSize(double width) { vertSize_ = width; }

void GLWidget::SetVertType(int index) { typeVert_ = index; }

void GLWidget::SetProjectType(int index) { typeProject_ = index; }

void GLWidget::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *mo) {
  yRot = 1 / M_PI * (mo->pos().y() - mPos.y());
  xRot = 1 / M_PI * (mo->pos().x() - mPos.x());
  setXRotation(xRot);
  setYRotation(yRot);
  update();
}

void GLWidget::SetController(s21::Controller *controller)
{
    controller_ = controller;
}

void GLWidget::SetVertices(const std::vector<double> &vertices) {
  this->vertices_ = vertices;
}

void GLWidget::SetFacets(const std::vector<unsigned int> &facets) {
  this->facets_ = facets;
}

void GLWidget::colors_RGB(float red, float green, float blue, int flag) {
  if (flag == 0) {
    colorWidget_.setRedF(red);
    colorWidget_.setGreenF(green);
    colorWidget_.setBlueF(blue);
  } else if (flag == 1) {
    colorLines_.setRedF(red);
    colorLines_.setGreenF(green);
    colorLines_.setBlueF(blue);
  } else if (flag == 2) {
    colorVertices_.setRedF(red);
    colorVertices_.setGreenF(green);
    colorVertices_.setBlueF(blue);
  }
  update();
}

void GLWidget::moveObjX(double val) {
  controller_->MoveObj(val, 0.0, 0.0);
  SetVertices(controller_->GetVertexArray());
  update();
}

void GLWidget::moveObjY(double val) {
  controller_->MoveObj(0.0, val, 0.0);
  SetVertices(controller_->GetVertexArray());
  update();
}

void GLWidget::moveObjZ(double val) {
  controller_->MoveObj(0.0, 0.0, val);
  SetVertices(controller_->GetVertexArray());
  update();
}

void GLWidget::setXRotation(double angle) {
  controller_->RotateObj('x', angle);
  SetVertices(controller_->GetVertexArray());
  update();
}

void GLWidget::setYRotation(double angle) {
  controller_->RotateObj('y', angle);
  SetVertices(controller_->GetVertexArray());
  update();
}

void GLWidget::setZRotation(double angle) {
  controller_->RotateObj('z', angle);
  SetVertices(controller_->GetVertexArray());
  update();
}

void GLWidget::zoomObj(double scale) {
  float zoomnum = 1.0 + scale * 0.01f;
  if (zoomnum < 0.1f) {
    zoomnum = 0.1f;
  }
  controller_->ScaleObj(zoomnum);
  SetVertices(controller_->GetVertexArray());
  update();
}


void GLWidget::wheelEvent(QWheelEvent *event) {
  if (event->angleDelta().y() > 0) {
    zoomObj(2);
  } else if (event->angleDelta().y() < 0) {
    zoomObj(-2);
  }
}

void GLWidget::SetSettings(const s21::Settings &settings) {
  ribsThick_ = settings.ribsThick_;
  vertSize_ = settings.vertSize_;
  colorWidget_ = settings.colorWidget_;
  colorLines_ = settings.colorLines_;
  colorVertices_ = settings.colorVertices_;
  typeRib_ = settings.typeRib_;
  typeVert_ = settings.typeVert_;
  typeProject_ = settings.typeProject_;
}

void GLWidget::UpdateSettings(s21::Settings &settings) const {
  settings.ribsThick_ = ribsThick_;
  settings.vertSize_ = vertSize_;
  settings.colorWidget_ = colorWidget_;
  settings.colorLines_ = colorLines_;
  settings.colorVertices_ = colorVertices_;
  settings.typeRib_ = typeRib_;
  settings.typeVert_ = typeVert_;
  settings.typeProject_ = typeProject_;
}
  
