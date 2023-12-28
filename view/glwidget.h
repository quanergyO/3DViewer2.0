#ifndef GLWIDGET_H
#define GLWIDGET_H
#define GL_SILENCE_DEPRECATION

#include <QMessageBox>
#include <QMouseEvent>
#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QTimer>
#include <QWidget>
#include <QtOpenGL>

#include "../controller.h"
#include "Settings.h"
#include "mainwindow.h"

class GLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  GLWidget(QWidget *parent = nullptr);
  void SetController(s21::Controller *controller);
  void SetVertices(const std::vector<double> &vertices);
  void SetFacets(const std::vector<unsigned int> &facets);
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void wheelEvent(QWheelEvent *event) override;
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int width, int height) override;
  void draw();
  void Lines();
  void Points();
  void disableGL();

  void SetRibsThick(double width);
  void SetRibsType(int index);
  void SetVertSize(double width);
  void SetVertType(int index);
  void SetProjectType(int index);
  void SetSettings(const s21::Settings &settings);
  void UpdateSettings(s21::Settings &settings) const;

  void setXRotation(double angle);
  void setYRotation(double angle);
  void setZRotation(double angle);
  void zoomObj(double scale);
  void moveObjX(double val);
  void moveObjY(double val);
  void moveObjZ(double val);
  void colors_RGB(float red, float green, float blue, int flag);

 private:
  int typeRib_ = 3;
  int typeVert_ = 3;
  int typeProject_ = 2;
  float xRot = 1.0;
  float yRot = 1.0;
  float zRot = 1.0;
  double ribsThick_ = 1.0;
  double vertSize_ = 1.0;
  s21::Controller *controller_;
  QColor colorWidget_;
  QColor colorLines_;
  QColor colorVertices_;
  QPoint mPos;
  QTimer tmr;
  std::vector<unsigned int> facets_;
  std::vector<double> vertices_;
};

#endif  // GLWIDGET_H
