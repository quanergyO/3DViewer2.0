#include "mainwindow.h"

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

#include "gif/gif.h"
//  #include "glwidget.h"
#include <iostream>

#include "ui_mainwindow.h"

MainWindow::MainWindow(s21::Controller *controller, QWidget *parent)
    : controller_(controller), QMainWindow(parent), ui(new Ui::MainWindow), settings_() {
  ui->setupUi(this);
  ui->GLwidget->SetController(controller_);
  settings_.LoadSettings();
  ui->GLwidget->SetSettings(settings_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonpath_clicked() {
  QString filter = "file(*.obj)";
  QString path = QFileDialog::getOpenFileName(this, "Open a file",
                                              QDir::homePath(), filter);
  if (path == "") {
    QMessageBox::information(this, "title", "Вы не выбрали файл");
    return;
  }
  ui->path_line->setText(path);
  controller_->OpenObj(path.toStdString());
  NumOfVert = controller_->GetVertexCount();
  NumOfRibs = controller_->GetPolygonCount();
  ui->GLwidget->SetVertices(controller_->GetVertexArray());
  ui->GLwidget->SetFacets(controller_->GetPolygonArray());
  ui->GLwidget->update();

  QString new_label;
  new_label = QString::number(NumOfVert, 'g', 15);
  ui->number_vert->setText(new_label);
  QString new_label1;
  new_label1 = QString::number(NumOfRibs, 'g', 15);
  ui->number_ribs->setText(new_label1);
}

void MainWindow::on_type_of_projection_activated(int index) {
  ui->GLwidget->SetProjectType(index);
  ui->GLwidget->update();
}

void MainWindow::on_background_color_button_clicked() {
  QColor color = QColorDialog::getColor(Qt::black, this, "Choose a color");
  red = color.redF();
  green = color.greenF();
  blue = color.blueF();
  if (color.isValid()) {
    ui->GLwidget->colors_RGB(red, green, blue, 0);
  }
}

void MainWindow::on_ribscolor_button_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose a color");
  red = color.redF();
  green = color.greenF();
  blue = color.blueF();
  if (color.isValid()) {
    ui->GLwidget->colors_RGB(red, green, blue, 1);
  }
}

void MainWindow::on_color_of_vert_button_clicked() {
  QColor color = QColorDialog::getColor(Qt::red, this, "Choose a color");
  red = color.redF();
  green = color.greenF();
  blue = color.blueF();
  if (color.isValid()) {
    ui->GLwidget->colors_RGB(red, green, blue, 2);
  }
  update();
}

void MainWindow::on_ribthick_valueChanged(double num) {
  ui->GLwidget->SetRibsThick(num);
  ui->GLwidget->update();
}

void MainWindow::on_ribstype_activated(int index) {
  ui->GLwidget->SetRibsType(index);
  ui->GLwidget->update();
}

void MainWindow::on_vertsize_valueChanged(int num) {
  ui->GLwidget->SetVertSize(num);
  ui->GLwidget->update();
}

void MainWindow::on_verttype_activated(int index) {
  ui->GLwidget->SetVertType(index);
  ui->GLwidget->update();
}

void MainWindow::on_x_trans_valueChanged(double num) {
  QString s_move_x = ui->label_x->text();
  double value_move_x = s_move_x.toDouble();
  num = num - value_move_x;
  ui->GLwidget->moveObjX(num);
  QString s = ui->x_trans->text();
  ui->label_x->setText(s);
}

void MainWindow::on_y_trans_valueChanged(double num) {
  QString s_move_x = ui->label_y->text();
  double value_move_x = s_move_x.toDouble();
  num = num - value_move_x;
  ui->GLwidget->moveObjY(num);
  QString s = ui->y_trans->text();
  ui->label_y->setText(s);
}

void MainWindow::on_z_trans_valueChanged(double num) {
  QString s_move_x = ui->label_z->text();
  double value_move_x = s_move_x.toDouble();
  num = num - value_move_x;
  ui->GLwidget->moveObjZ(num);
  QString s = ui->z_trans->text();
  ui->label_z->setText(s);
}

void MainWindow::on_x_rot_valueChanged(double num) {
  QString s_move_x = ui->label_x_r->text();
  double value_move_x = s_move_x.toDouble();
  num = num - value_move_x;
  ui->GLwidget->setXRotation(num);
  QString s = ui->x_rot->text();
  ui->label_x_r->setText(s);
}

void MainWindow::on_y_rot_valueChanged(double num) {
  QString s_move_x = ui->label_y_r->text();
  double value_move_x = s_move_x.toDouble();
  num = num - value_move_x;
  ui->GLwidget->setYRotation(num);
  QString s = ui->y_rot->text();
  ui->label_y_r->setText(s);
}

void MainWindow::on_z_rot_valueChanged(double num) {
  QString s_move_x = ui->label_z_r->text();
  double value_move_x = s_move_x.toDouble();
  num = num - value_move_x;
  ui->GLwidget->setZRotation(num);
  QString s = ui->z_rot->text();
  ui->label_z_r->setText(s);
}

void MainWindow::on_scale_value_valueChanged(double num) {
  QString s_move_x = ui->scale_label->text();
  double value_move_x = s_move_x.toDouble();
  num = num - value_move_x;
  ui->GLwidget->zoomObj(num);
  QString s = ui->scale_value->text();
  ui->scale_label->setText(s);
}

// -----------------------------------------------//

void MainWindow::on_btn_screen_bmp_clicked() {
  QDir *pathDir = new QDir();
  pathDir->mkdir(pathProject);
  pathDir->mkdir(pathProject + "/screenshots");
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  ui->btn_screen_bmp->setEnabled(false);
  ui->GLwidget->grab().save(pathProject + "screenshots/" + currentDateTime +
                            ".bmp");
  ui->btn_screen_bmp->setEnabled(true);
}

void MainWindow::on_btn_screen_jpg_clicked() {
  QDir *pathDir = new QDir();
  pathDir->mkdir(pathProject);
  pathDir->mkdir(pathProject + "/screenshots");
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  ui->btn_screen_jpg->setEnabled(false);
  ui->GLwidget->grab().save(pathProject + "screenshots/" + currentDateTime +
                            ".jpg");
  ui->btn_screen_bmp->setEnabled(true);
}

void MainWindow::on_btn_screen_gif_clicked() {
  QDir *pathDir = new QDir();
  pathDir->mkdir(pathProject);
  pathDir->mkdir(pathProject + "/screenshots");
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  ui->btn_screen_gif->setEnabled(false);
  pathDir->mkdir(pathProject + "/screenshots/gif_obj/");
  startTime = 0, tmpTime = 1000 / GifFps;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(oneGif()));
  timer->start(1000 / GifFps);
}

void MainWindow::oneGif() {
  if (startTime == tmpTime) {
    ui->GLwidget->grab()
        .scaled(640, 480, Qt::IgnoreAspectRatio)
        .save(pathProject + "/screenshots/gif_obj/" + QString::number(counter) +
              ".bmp");
    counter++;
    tmpTime += 1000 / GifFps;
  }
  if (startTime == 1000 * GifLength) {
    createGif();
    timer->stop();
    counter = 1;
  }
  startTime += 1000 / GifFps;
}

void MainWindow::createGif() {
  QDir pathFile;
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  QString gif_name = pathProject + "/screenshots/" + currentDateTime + ".gif";
  QByteArray ga = gif_name.toLocal8Bit();
  GifWriter writer = {};
  int err = 0;
  if (GifBegin(&writer, ga.data(), 640, 480, 10, 8, false)) {
    for (int i = 1; i <= 50; i++) {
      if (err == 1) {
        break;
      }
      QImage img(pathProject + "/screenshots/gif_obj/" + QString::number(i) +
                 ".bmp");
      if (!img.isNull()) {
        if (GifWriteFrame(&writer,
                          img.convertToFormat(QImage::Format_Indexed8)
                              .convertToFormat(QImage::Format_RGBA8888)
                              .constBits(),
                          640, 480, 10, 8, false)) {
        } else {
          QMessageBox::critical(0, "Error", "Gif file can not be created!1");
          err = 1;
        }
      } else {
        QMessageBox::critical(0, "Error", "Gif file can not be created! 2");
        err = 1;
      }
    }
    if (err == 0) {
      GifEnd(&writer);
    }
  } else {
    err = 1;
    QMessageBox::critical(0, "Error", "Gif file can not be created! 3");
  }

  if (err == 1) {
    if (QFile::exists(gif_name)) {
      QFile::remove(gif_name);
    }
  }
  pathFile.setPath(pathProject + "/screenshots/gif_obj/");
  pathFile.removeRecursively();
  ui->btn_screen_gif->setEnabled(true);
}

void MainWindow::on_color_of_rebra_button_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose a color");
    red = color.redF();
    green = color.greenF();
    blue = color.blueF();
    if (color.isValid()) {
      ui->GLwidget->colors_RGB(red, green, blue, 1);
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
  ui->GLwidget->UpdateSettings(settings_);
  settings_.SaveSettings();
}

