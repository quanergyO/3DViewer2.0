#ifndef CPP4_3DVIEWER_V2_0_1_NORMALIZATION_PARAMETRS_H_
#define CPP4_3DVIEWER_V2_0_1_NORMALIZATION_PARAMETRS_H_

#include <algorithm>
#include <limits>

namespace s21 {
/**
 * @brief Класс NormalizationParametrs представляет параметры нормализации
 * трехмерной модели.
 */
class NormalizationParametrs {
 public:
  /**
   * @brief Конструктор по умолчанию для класса NormalizationParametrs.
   */
  NormalizationParametrs();

  /**
   * @brief Проверяет координаты точки на соответствие параметрам нормализации.
   * @param x Координата X точки.
   * @param y Координата Y точки.
   * @param z Координата Z точки.
   */
  void CheckPoint(double x, double y, double z);

  /**
   * @brief Вычисляет коэффициент масштабирования для нормализации модели.
   */
  void CalculateScale();

  /**
   * @brief Получает коэффициент масштабирования.
   * @return Коэффициент масштабирования.
   */
  double GetScale() const;

 public:
  double minX_;   ///< Минимальная координата X.
  double maxX_;   ///< Максимальная координата X.
  double minY_;   ///< Минимальная координата Y.
  double maxY_;   ///< Максимальная координата Y.
  double minZ_;   ///< Минимальная координата Z.
  double maxZ_;   ///< Максимальная координата Z.
  double scale_;  ///< Коэффициент масштабирования.
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_NORMALIZATION_PARAMETRS_H_
