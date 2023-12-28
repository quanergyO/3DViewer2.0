#ifndef CPP4_3DVIEWER_V2_0_1_FACADE_H_
#define CPP4_3DVIEWER_V2_0_1_FACADE_H_

#include <vector>

#include "NormalizationParametrs.h"
#include "Parser.h"
#include "Scene.h"
#include "Strategy.h"

namespace s21 {

/**
 * @brief Класс Facade предоставляет унифицированный интерфейс для
 * взаимодействия с компонентами системы, обеспечивающими загрузку, манипуляции
 * и предоставление данных трехмерной сцены.
 */
class Facade {
 public:
  /**
   * @brief Конструктор класса Facade.
   */
  Facade() = default;

  /**
   * @brief Загружает трехмерную сцену из файла по указанному пути.
   * @param path Путь к файлу с трехмерной сценой.
   */
  void LoadScene(const std::string& path);

  /**
   * @brief Выполняет перемещение трехмерной сцены в пространстве.
   * @param x Компонента X вектора перемещения.
   * @param y Компонента Y вектора перемещения.
   * @param z Компонента Z вектора перемещения.
   */
  void MoveScene(double x, double y, double z);

  /**
   * @brief Выполняет масштабирование трехмерной сцены.
   * @param scale Коэффициент масштабирования.
   */
  void ScaleScene(double scale);

  /**
   * @brief Выполняет вращение трехмерной сцены вокруг указанной оси.
   * @param axis Ось вращения ('x', 'y' или 'z').
   * @param angle Угол вращения в градусах.
   */
  void RotateScene(char axis, double angle);

  /**
   * @brief Возвращает массив координат вершин трехмерной сцены.
   * @return Массив координат вершин.
   */
  std::vector<double> GetVertexArray() const;

  /**
   * @brief Возвращает массив вершин трехмерной сцены.
   * @return Массив вершин.
   */
  std::vector<unsigned int> GetFacetArray() const;

  /**
   * @brief Возвращает количество вершин трехмерной сцены.
   * @return Количество вершин.
   */
  size_t GetVertexCount() const;

  /**
   * @brief Возвращает количество граней трехмерной сцены.
   * @return Количество граней.
   */
  size_t GetFacetCount() const;

 private:
  Parser parser_;  ///< Парсер для загрузки данных трехмерной сцены.
  Scene scene_;  ///< Объект для хранения и манипуляций трехмерной сцены.
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_FACADE_H_
