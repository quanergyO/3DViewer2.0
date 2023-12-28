#ifndef CPP4_3DVIEWER_V2_0_1_FACADE_CC_
#define CPP4_3DVIEWER_V2_0_1_FACADE_CC_

#include "Facade.h"

namespace s21 {

void Facade::LoadScene(const std::string& path) {
  parser_.setFilePath(path);
  NormalizationParametrs parametrs;
  parser_.ParseFile(parametrs);
  parametrs.CalculateScale();
  Vertex vert(parser_.GetVertices());
  vert.Centering(parametrs);
  vert.ScaleVertex(parametrs.GetScale());
  Facet facet(parser_.GetPolygons());
  scene_ = Scene(vert, facet);
}

void Facade::RotateScene(char axis, double angle) {
  RotateProcessor processor;
  switch (axis) {
    case 'x': {
      RotateSceneByX strategyRotateX;
      processor.setCompressionStrategy(&strategyRotateX);
      break;
    }
    case 'y': {
      RotateSceneByY strategyRotateY;
      processor.setCompressionStrategy(&strategyRotateY);
      break;
    }
    case 'z': {
      RotateSceneByZ strategyRotateZ;
      processor.setCompressionStrategy(&strategyRotateZ);
      break;
    }
  }

  processor.processRotate(angle, scene_);
}

void Facade::MoveScene(double x, double y, double z) {
  scene_.MoveScene(x, y, z);
}

void Facade::ScaleScene(double scale) { scene_.ScaleScene(scale); }

std::vector<double> Facade::GetVertexArray() const {
  return scene_.GetVertexArray();
}

std::vector<unsigned int> Facade::GetFacetArray() const {
  return scene_.GetFacetArray();
}

size_t Facade::GetVertexCount() const { return scene_.GetVertexCount(); }

size_t Facade::GetFacetCount() const { return scene_.GetPolygonCount(); }

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_FACADE_CC_
