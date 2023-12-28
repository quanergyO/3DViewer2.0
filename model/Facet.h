#ifndef CPP4_3DVIEWER_V2_0_1_Facet_H_
#define CPP4_3DVIEWER_V2_0_1_Facet_H_

#include "Vertex.h"

namespace s21 {

/**
 * @brief Класс Facet представляет грань в трехмерной модели.
 */
class Facet {
 public:
  /**
   * @brief Конструктор по умолчанию для класса Facet.
   */
  Facet() = default;

  /**
   * @brief Конструктор класса Facet.
   * @param polygons Вектор векторов индексов вершин, определяющих полигоны
   * грани.
   */
  Facet(const std::vector<std::vector<size_t>> &polygons);

  /**
   * @brief Получает вектор индексов вершин, определяющих полигоны грани.
   * @return Вектор индексов вершин.
   */
  std::vector<unsigned int> GetPolygons() const;

  /**
   * @brief Получает количество полигонов в грани.
   * @return Количество полигонов.
   */
  size_t GetPolygonCount() const;

 private:
  std::vector<unsigned int>
      polygons_;  ///< Вектор индексов вершин, определяющих полигоны грани.
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_Facet_H_
