#ifndef CPP4_3DVIEWER_V2_0_1_VIEW_SETTINGS_CC_
#define CPP4_3DVIEWER_V2_0_1_VIEW_SETTINGS_CC_

#include "Settings.h"

namespace s21 {
Settings::Settings()
    : typeRib_(3),
      typeVert_(3),
      typeProject_(2),
      ribsThick_(1.0),
      vertSize_(1.0),
      colorWidget_(Qt::black),
      colorLines_(Qt::white),
      colorVertices_(Qt::blue) {}

void Settings::LoadSettings() {
  QFile file(static_cast<QDir>(QDir::homePath()).absolutePath() +
             "/Desktop/settings.json");
  if (file.open(QIODevice::ReadOnly)) {
    QJsonDocument json = QJsonDocument::fromJson(file.readAll());
    QJsonObject settings = json.object();

    colorLines_.setRed(settings.value("line_color_r").toInt());
    colorLines_.setGreen(settings.value("line_color_g").toInt());
    colorLines_.setBlue(settings.value("line_color_b").toInt());
    colorVertices_.setRed(settings.value("vertex_color_r").toInt());
    colorVertices_.setGreen(settings.value("vertex_color_g").toInt());
    colorVertices_.setBlue(settings.value("vertex_color_b").toInt());
    colorWidget_.setRed(settings.value("widget_color_r").toInt());
    colorWidget_.setGreen(settings.value("widget_color_g").toInt());
    colorWidget_.setBlue(settings.value("widget_color_b").toInt());
    vertSize_ = settings.value("vertex_size").toDouble();
    ribsThick_ = settings.value("rib_thickness").toDouble();
    typeRib_ = settings.value("rib_type").toInt();
    typeProject_ = settings.value("project_type").toInt();

    file.close();
  }
}

void Settings::SaveSettings() {
  QJsonObject settings;
  settings.insert("line_color_r", colorLines_.red());
  settings.insert("line_color_g", colorLines_.green());
  settings.insert("line_color_b", colorLines_.blue());
  settings.insert("vertex_color_r", colorVertices_.red());
  settings.insert("vertex_color_g", colorVertices_.green());
  settings.insert("vertex_color_b", colorVertices_.blue());
  settings.insert("widget_color_r", colorWidget_.red());
  settings.insert("widget_color_g", colorWidget_.green());
  settings.insert("widget_color_b", colorWidget_.blue());
  settings.insert("vertex_size", vertSize_);
  settings.insert("rib_thickness", ribsThick_);
  settings.insert("rib_type", typeRib_);
  settings.insert("project_type", typeProject_);
  QJsonDocument doc(settings);
  QFile file(static_cast<QDir>(QDir::homePath()).absolutePath() +
             "/Desktop/settings.json");
  if (file.open(QIODevice::WriteOnly)) {
    file.write(doc.toJson());
    file.close();
  }
}

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_VIEW_SETTINGS_CC_
