#ifndef CPP4_3DVIEWER_V2_0_1_FACADEOPERATIONRESULT_H_
#define CPP4_3DVIEWER_V2_0_1_FACADEOPERATIONRESULT_H_

#include <string>

namespace s21 {

/**
 * @brief Класс FacadeOperationResult представляет результат выполнения
 *        операции в классе Facade.
 */
class FacadeOperationResult {
public:

  /**
   * @brief Конструктор класса FacadeOperationResult.
   * @param errorMessage Сообщение об ошибке (пустая строка в случае успеха).
   * @param isSuccess Флаг успешного выполнения операции (true в случае успеха).
   */
  FacadeOperationResult(const std::string &errorMessage, bool isSuccess);

  /**
   * @brief Получает сообщение об ошибке.
   * @return Строка с сообщением об ошибке (пустая строка в случае успеха).
   */
  std::string GetErrorMessage() const;

  /**
   * @brief Проверяет, была ли операция успешной.
   * @return True, если операция успешна, False в случае ошибки.
   */
  bool IsSuccess() const;

private:
  std::string errorMessage_; ///< Сообщение об ошибке.
  bool isSuccess_;           ///< Флаг успешного выполнения операции.
};

} // namespace s21

#endif // CPP4_3DVIEWER_V2_0_1_FACADEOPERATIONRESULT_H_
