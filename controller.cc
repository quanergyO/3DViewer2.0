#ifndef CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_CC_
#define CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_CC_

#include "controller.h"

namespace s21 {

Controller& Controller::getInstance(Facade& facade) {
  static Controller instance(facade);
  return instance;
}

Controller::Controller(Facade& facade) : facade_(facade) {}

void Controller::OpenObj(const std::string& path) { facade_.LoadScene(path); }

void Controller::RotateObj(char axis, double angle) {
  facade_.RotateScene(axis, angle);
}

void Controller::ScaleObj(double scale) { facade_.ScaleScene(scale); }

void Controller::MoveObj(double x, double y, double z) {
  facade_.MoveScene(x, y, z);
}

std::vector<double> Controller::GetVertexArray() {
  return facade_.GetVertexArray();
}

std::vector<unsigned int> Controller::GetPolygonArray() {
  return facade_.GetFacetArray();
}

size_t Controller::GetVertexCount() { return facade_.GetVertexCount(); }

size_t Controller::GetPolygonCount() { return facade_.GetFacetCount(); }

}  // namespace s21

#endif  // CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_CC_
