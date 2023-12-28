#ifndef CPP4_3DVIEWER_V2_0_1_PARSER_H_
#define CPP4_3DVIEWER_V2_0_1_PARSER_H_

#include <string>
#include <vector>

#include "Facet.h"
#include "NormalizationParametrs.h"
#include "Vertex.h"

namespace s21 {

/**
 * @brief Класс Parser представляет парсер для чтения трехмерных моделей из
 * файлов.
 */
class Parser {
 public:
  /**
   * @brief Конструктор по умолчанию для класса Parser.
   */
  Parser() = default;

  /**
   * @brief Конструктор с параметром для класса Parser.
   * @param filePath Путь к файлу модели.
   */
  Parser(const std::string &filePath);

  /**
   * @brief Выполняет парсинг файла трехмерной модели.
   * @param parametrs Параметры нормализации модели.
   */
  void ParseFile(NormalizationParametrs &parametrs);

  /**
   * @brief Получает координаты вершин модели.
   * @return Вектор координат вершин модели.
   */
  std::vector<double> GetVertices() const;

  /**
   * @brief Получает описание полигонов модели.
   * @return Вектор, описывающий полигоны модели.
   */
  std::vector<std::vector<size_t>> GetPolygons() const;

  /**
   * @brief Устанавливает путь к файлу модели.
   * @param filePath Путь к файлу модели.
   */
  void setFilePath(const std::string &filePath);

 private:
  std::vector<double> vertices_;  ///< Координаты вершин модели.
  std::vector<std::vector<size_t>> polygons_;  ///< Описание полигонов модели.
  std::string filePath_;  ///< Путь к файлу модели.
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_PARSER_H_
