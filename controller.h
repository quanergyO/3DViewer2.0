#ifndef CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_H_
#define CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/Facade.h"

namespace s21 {

/**
 * @brief Класс Controller управляет взаимодействием между пользовательским
 *        интерфейсом и моделью для отображения и редактирования трехмерных
 * объектов.
 */
class Controller {
 public:
  /**
   * @brief Получает единственный экземпляр Controller.
   * @param facade Ссылка на объект Facade, предоставляющий функциональность
   * модели.
   * @return Ссылка на единственный экземпляр Controller.
   */
  static Controller& getInstance(Facade& facade);

  /**
   * @brief Открывает трехмерный объект из файла.
   * @param file_name Путь к файлу с трехмерным объектом.
   */
  void OpenObj(const std::string& file_name);

  /**
   * @brief Вращает трехмерный объект вокруг указанной оси на заданное значение.
   * @param axis Ось вращения ('x', 'y' или 'z').
   * @param value Значение угла вращения.
   */
  void RotateObj(char axis, double value);

  /**
   * @brief Масштабирует трехмерный объект на указанное значение.
   * @param value Значение масштабирования.
   */
  void ScaleObj(double value);

  /**
   * @brief Перемещает трехмерный объект в пространстве.
   * @param x Координата X нового положения объекта.
   * @param y Координата Y нового положения объекта.
   * @param z Координата Z нового положения объекта.
   */
  void MoveObj(double x, double y, double z);

  /**
   * @brief Возвращает массив координат вершин трехмерного объекта.
   * @return Массив координат вершин.
   */
  std::vector<double> GetVertexArray();

  /**
   * @brief Возвращает массив вершин трехмерного объекта.
   * @return Массив вершин.
   */
  std::vector<unsigned int> GetPolygonArray();

  /**
   * @brief Возвращает количество вершин трехмерного объекта.
   * @return Количество вершин.
   */
  size_t GetVertexCount();

  /**
   * @brief Возвращает количество полигонов трехмерного объекта.
   * @return Количество полигонов.
   */
  size_t GetPolygonCount();

 private:
  /**
   * @brief Конструктор Controller.
   * @param facade Ссылка на объект Facade, предоставляющий функциональность
   * модели.
   */
  Controller(Facade& facade);

  Controller(const Controller&) = delete;
  Controller(Controller&&) = delete;
  ~Controller() = default;
  Controller& operator=(const Controller&) = delete;
  Controller& operator=(Controller&&) = delete;

 private:
  Facade& facade_;
};

}  // namespace s21

#endif  // CPP_S21_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_H_
