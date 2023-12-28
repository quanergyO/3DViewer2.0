#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>
#include <QDir>
#include <QImage>
#include <QMainWindow>
#include <QPainter>
#include <QSettings>
#include <QTimer>
#include <QVector>

#include "../controller.h"
#include "Settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(s21::Controller *contorller, QWidget *parent = nullptr);
  ~MainWindow();
  float red = 0, green = 0, blue = 0;
  int NumOfVert = 0;
  int NumOfRibs = 0;

 private slots:
  void on_pushButtonpath_clicked();
  void on_type_of_projection_activated(int index);
  void on_background_color_button_clicked();
  void on_color_of_vert_button_clicked();
  void on_ribscolor_button_clicked();
  void on_ribthick_valueChanged(double num);
  void on_ribstype_activated(int index);
  void on_vertsize_valueChanged(int num);
  void on_verttype_activated(int index);
  void on_x_trans_valueChanged(double num);
  void on_y_trans_valueChanged(double num);
  void on_z_trans_valueChanged(double num);
  void on_x_rot_valueChanged(double num);
  void on_y_rot_valueChanged(double num);
  void on_z_rot_valueChanged(double num);
  void on_scale_value_valueChanged(double num);

  void oneGif();
  void createGif();
  void on_btn_screen_bmp_clicked();
  void on_btn_screen_jpg_clicked();
  void on_btn_screen_gif_clicked();
  void on_color_of_rebra_button_clicked();
  void closeEvent(QCloseEvent *event) override;

 private:
  Ui::MainWindow *ui;
  QList<QImage> jiff;
  int counter_im;
  int screenshotcounter;
  QString pathProject = QDir::homePath() + "/3dViewer2/";
  QTimer *timer;
  int startTime;
  int tmpTime;
  const int GifFps = 10, GifLength = 5;
  int counter = 1;
  s21::Settings settings_;
  s21::Controller *controller_;
};
#endif  // MAINWINDOW_H
