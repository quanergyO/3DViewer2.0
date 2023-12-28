#ifndef CPP4_3DVIEWER_V2_0_1_SCENE_H_
#define CPP4_3DVIEWER_V2_0_1_SCENE_H_

#include "Facet.h"
#include "Vertex.h"

namespace s21 {

/**
 * @brief Класс Scene представляет трехмерную сцену, содержащую вершину и
 * полигон.
 */
class Scene {
 public:
  /**
   * @brief Конструктор по умолчанию для класса Scene.
   */
  Scene() = default;

  /**
   * @brief Конструктор с параметрами для класса Scene.
   * @param vertex Вершина сцены.
   * @param facet Полигон сцены.
   */
  Scene(const Vertex &vertex, const Facet &facet);

  /**
   * @brief Выполняет перемещение сцены в трехмерном пространстве.
   * @param x Смещение по оси X.
   * @param y Смещение по оси Y.
   * @param z Смещение по оси Z.
   */
  void MoveScene(double x, double y, double z);

  /**
   * @brief Выполняет масштабирование сцены.
   * @param scale Масштабный коэффициент.
   */
  void ScaleScene(double scale);

  /**
   * @brief Выполняет вращение сцены вокруг оси X.
   * @param angle Угол вращения.
   */
  void RotateSceneByX(double angle);

  /**
   * @brief Выполняет вращение сцены вокруг оси Y.
   * @param angle Угол вращения.
   */
  void RotateSceneByY(double angle);

  /**
   * @brief Выполняет вращение сцены вокруг оси Z.
   * @param angle Угол вращения.
   */
  void RotateSceneByZ(double angle);

  /**
   * @brief Получает координаты вершин сцены.
   * @return Вектор координат вершин сцены.
   */
  std::vector<double> GetVertexArray() const;

  /**
   * @brief Получает описание полигонов сцены.
   * @return Вектор, описывающий полигоны сцены.
   */
  std::vector<unsigned int> GetFacetArray() const;

  /**
   * @brief Получает количество вершин сцены.
   * @return Количество вершин.
   */
  size_t GetVertexCount() const;

  /**
   * @brief Получает количество полигонов сцены.
   * @return Количество полигонов.
   */
  size_t GetPolygonCount() const;

 private:
  Vertex vertex_;  ///< Вершина сцены.
  Facet facet_;    ///< Полигон сцены.
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SCENE_H_
