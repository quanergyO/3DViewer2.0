#ifndef CPP4_3DVIEWER_V2_0_1_FACADEOPERATIONRESULT_CC_
#define CPP4_3DVIEWER_V2_0_1_FACADEOPERATIONRESULT_CC_

#include "FacadeOperationResult.h"

namespace s21 {
FacadeOperationResult::FacadeOperationResult(const std::string &errorMessage,
                                             bool isSuccess)
    : errorMessage_(errorMessage), isSuccess_(isSuccess) {}

std::string FacadeOperationResult::GetErrorMessage() const {
  return errorMessage_;
}

bool FacadeOperationResult::IsSuccess() const { return isSuccess_; }

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_FACADEOPERATIONRESULT_CC_