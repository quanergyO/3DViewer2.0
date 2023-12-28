#ifndef CPP4_3DVIEWER_V2_0_1_VIEW_SETTINGS_H_
#define CPP4_3DVIEWER_V2_0_1_VIEW_SETTINGS_H_

#include <QCloseEvent>
#include <QColorDialog>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

namespace s21 {
class Settings {
 public:
  Settings();
  void LoadSettings();
  void SaveSettings();

  int typeRib_;
  int typeVert_;
  int typeProject_;
  double ribsThick_;
  double vertSize_;
  QColor colorWidget_;
  QColor colorLines_;
  QColor colorVertices_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_VIEW_SETTINGS_H_
