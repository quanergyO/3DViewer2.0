#ifndef CPP4_3DVIEWER_V2_0_1_Facet_CC_
#define CPP4_3DVIEWER_V2_0_1_Facet_CC_

#include "Facet.h"

#include <iostream>

namespace s21 {

Facet::Facet(const std::vector<std::vector<size_t>> &polygons) {
  for (const auto &polygon : polygons) {
    for (size_t i = 1; i < polygon.size(); ++i) {
      polygons_.push_back(polygon[i - 1] - 1);
      polygons_.push_back(polygon[i] - 1);
    }
    polygons_.push_back(polygon.back() - 1);
    polygons_.push_back(polygon.front() - 1);
  }
}

std::vector<unsigned int> Facet::GetPolygons() const { return polygons_; }

size_t Facet::GetPolygonCount() const { return polygons_.size(); }

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_VERTEX_CC_
