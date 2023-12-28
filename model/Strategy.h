#ifndef CPP4_3DVIEWER_V2_0_1_MODEL_STRATEGY_H_
#define CPP4_3DVIEWER_V2_0_1_MODEL_STRATEGY_H_

#include "Scene.h"

namespace s21 {

/**
 * @brief Абстрактный класс CompressionStrategy представляет стратегию сжатия
 * для модели сцены.
 */
class CompressionStrategy {
 public:
  /**
   * @brief Виртуальная функция для вращения сцены по заданному углу.
   * @param angle Угол вращения.
   * @param scene Сцена, которую необходимо вращать.
   */
  virtual void Rotate(double angle, Scene &scene) = 0;

  /**
   * @brief Виртуальный деструктор для класса CompressionStrategy.
   */
  virtual ~CompressionStrategy() = default;
};

/**
 * @brief Класс RotateSceneByX представляет стратегию вращения сцены вокруг оси
 * X.
 */
class RotateSceneByX : public CompressionStrategy {
 public:
  /**
   * @brief Реализация вращения сцены вокруг оси X.
   * @param angle Угол вращения.
   * @param scene Сцена, которую необходимо вращать.
   */
  void Rotate(double angle, Scene &scene) override;
};

/**
 * @brief Класс RotateSceneByY представляет стратегию вращения сцены вокруг оси
 * Y.
 */
class RotateSceneByY : public CompressionStrategy {
 public:
  /**
   * @brief Реализация вращения сцены вокруг оси Y.
   * @param angle Угол вращения.
   * @param scene Сцена, которую необходимо вращать.
   */
  void Rotate(double angle, Scene &scene) override;
};

/**
 * @brief Класс RotateSceneByZ представляет стратегию вращения сцены вокруг оси
 * Z.
 */
class RotateSceneByZ : public CompressionStrategy {
 public:
  /**
   * @brief Реализация вращения сцены вокруг оси Z.
   * @param angle Угол вращения.
   * @param scene Сцена, которую необходимо вращать.
   */
  void Rotate(double angle, Scene &scene) override;
};

/**
 * @brief Класс RotateProcessor представляет обработчик вращения сцены.
 */
class RotateProcessor {
 public:
  /**
   * @brief Конструктор по умолчанию для класса RotateProcessor.
   */
  RotateProcessor();

  /**
   * @brief Конструктор с параметрами для класса RotateProcessor.
   * @param strategy Стратегия вращения сцены.
   */
  RotateProcessor(CompressionStrategy *strategy);

  /**
   * @brief Устанавливает стратегию вращения сцены.
   * @param strategy Стратегия вращения сцены.
   */
  void setCompressionStrategy(CompressionStrategy *strategy);

  /**
   * @brief Выполняет процесс вращения сцены в соответствии с установленной
   * стратегией.
   * @param angle Угол вращения.
   * @param scene Сцена, которую необходимо вращать.
   */
  void processRotate(double angle, Scene &scene);

 private:
  CompressionStrategy
      *compressionStrategy_;  ///< Указатель на стратегию вращения сцены.
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_MODEL_STRATEGY_H_
