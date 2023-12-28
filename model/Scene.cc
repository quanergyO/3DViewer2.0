#ifndef CPP4_3DVIEWER_V2_0_1_SCENE_CC_
#define CPP4_3DVIEWER_V2_0_1_SCENE_CC_

#include "Scene.h"

namespace s21 {
Scene::Scene(const Vertex &vertex, const Facet &facet)
    : vertex_(vertex), facet_(facet) {}

void Scene::MoveScene(double x, double y, double z) {
  vertex_.MoveVertex(x, y, z);
}

void Scene::ScaleScene(double scale) { vertex_.ScaleVertex(scale); }

void Scene::RotateSceneByX(double angle) { vertex_.TurnX(angle); }

void Scene::RotateSceneByY(double angle) { vertex_.TurnY(angle); }

void Scene::RotateSceneByZ(double angle) { vertex_.TurnZ(angle); }

std::vector<double> Scene::GetVertexArray() const {
  return vertex_.GetVertex();
}

std::vector<unsigned int> Scene::GetFacetArray() const {
  return facet_.GetPolygons();
}

size_t Scene::GetVertexCount() const { return vertex_.GetVertexCount(); }

size_t Scene::GetPolygonCount() const { return facet_.GetPolygonCount(); }

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SCENE_CC_
