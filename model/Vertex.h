#ifndef CPP4_3DVIEWER_V2_0_1_VERTEX_H_
#define CPP4_3DVIEWER_V2_0_1_VERTEX_H_

#include <cmath>
#include <cstddef>
#include <vector>

#include "NormalizationParametrs.h"

namespace s21 {

/**
 * @brief Класс Vertex представляет вершину в трехмерном пространстве.
 */
class Vertex {
 public:
  /**
   * @brief Конструктор по умолчанию для класса Vertex.
   */
  Vertex() = default;

  /**
   * @brief Конструктор с параметрами для класса Vertex.
   * @param vertecies Координаты вершины в виде вектора.
   */
  Vertex(const std::vector<double> &vertecies);

  /**
   * @brief Перемещает вершину по заданным координатам.
   * @param x Координата по оси X.
   * @param y Координата по оси Y.
   * @param z Координата по оси Z.
   */
  void MoveVertex(double x, double y, double z);

  /**
   * @brief Масштабирует вершину относительно начала координат.
   * @param scale Коэффициент масштабирования.
   */
  void ScaleVertex(double scale);

  /**
   * @brief Центрирует вершину в соответствии с параметрами нормализации.
   * @param parametrs Параметры нормализации.
   */
  void Centering(const NormalizationParametrs &parametrs);

  /**
   * @brief Поворачивает вершину вокруг оси X на заданный угол.
   * @param angle Угол поворота.
   */
  void TurnX(double angle);

  /**
   * @brief Поворачивает вершину вокруг оси Y на заданный угол.
   * @param angle Угол поворота.
   */
  void TurnY(double angle);

  /**
   * @brief Поворачивает вершину вокруг оси Z на заданный угол.
   * @param angle Угол поворота.
   */
  void TurnZ(double angle);

  /**
   * @brief Возвращает координаты вершины в виде вектора.
   * @return Вектор с координатами вершины.
   */
  std::vector<double> GetVertex() const;

  /**
   * @brief Возвращает количество координат вершины.
   * @return Количество координат вершины.
   */
  size_t GetVertexCount() const;

 private:
  std::vector<double> vertecies_;  ///< Вектор с координатами вершины.
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_VERTEX_H_
