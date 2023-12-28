#ifndef CPP4_3DVIEWER_V2_0_1_VERTEX_CC_
#define CPP4_3DVIEWER_V2_0_1_VERTEX_CC_

#include "Vertex.h"

#include <iostream>

namespace s21 {

Vertex::Vertex(const std::vector<double> &vertecies) : vertecies_(vertecies) {}

void Vertex::MoveVertex(double x, double y, double z) {
  for (size_t i = 0; i < vertecies_.size(); i += 3) {
    vertecies_[i] += x;
    vertecies_[i + 1] += y;
    vertecies_[i + 2] += z;
  }
}

void Vertex::ScaleVertex(double scale) {
  for (size_t i = 0; i < vertecies_.size(); i += 3) {
    vertecies_[i] *= scale;
    vertecies_[i + 1] *= scale;
    vertecies_[i + 2] *= scale;
  }
}

void Vertex::TurnX(double angle) {
  if (angle == 0.0) return;
  const double RAD_TO_GRAD = 0.01745329251994;
  angle *= RAD_TO_GRAD;
  for (size_t i = 0; i < vertecies_.size(); i += 3) {
    double x = vertecies_[i];
    double y = vertecies_[i + 1] * cos(angle) + vertecies_[i + 2] * sin(angle);
    double z = -vertecies_[i + 1] * sin(angle) + vertecies_[i + 2] * cos(angle);
    vertecies_[i] = x;
    vertecies_[i + 1] = y;
    vertecies_[i + 2] = z;
  }
}

void Vertex::TurnY(double angle) {
  if (angle == 0.0) return;
  const double RAD_TO_GRAD = 0.01745329251994;
  angle *= RAD_TO_GRAD;
  for (size_t i = 0; i < vertecies_.size(); i += 3) {
    double x = vertecies_[i] * cos(angle) - vertecies_[i + 2] * sin(angle);
    double y = vertecies_[i + 1];
    double z = vertecies_[i] * sin(angle) + vertecies_[i + 2] * cos(angle);
    vertecies_[i] = x;
    vertecies_[i + 1] = y;
    vertecies_[i + 2] = z;
  }
}

void Vertex::TurnZ(double angle) {
  if (angle == 0.0) return;
  const double RAD_TO_GRAD = 0.01745329251994;
  angle *= RAD_TO_GRAD;
  for (size_t i = 0; i < vertecies_.size(); i += 3) {
    double x = vertecies_[i] * cos(angle) + vertecies_[i + 1] * sin(angle);
    double y = -vertecies_[i] * sin(angle) + vertecies_[i + 1] * cos(angle);
    double z = vertecies_[i + 2];
    vertecies_[i] = x;
    vertecies_[i + 1] = y;
    vertecies_[i + 2] = z;
  }
}

void Vertex::Centering(const NormalizationParametrs &parametrs) {
  double centerX = parametrs.minX_ + (parametrs.maxX_ - parametrs.minX_) / 2;
  double centerY = parametrs.minY_ + (parametrs.maxY_ - parametrs.minY_) / 2;
  double centerZ = parametrs.minZ_ + (parametrs.maxZ_ - parametrs.minZ_) / 2;
  for (size_t i = 0; i < vertecies_.size(); i += 3) {
    vertecies_[i] -= centerX;
    vertecies_[i + 1] -= centerY;
    vertecies_[i + 2] -= centerZ;
  }
}

std::vector<double> Vertex::GetVertex() const { return vertecies_; }

size_t Vertex::GetVertexCount() const { return vertecies_.size(); }

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_VERTEX_CC_
