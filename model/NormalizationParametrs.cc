#ifndef CPP4_3DVIEWER_V2_0_1_NORMALIZATION_PARAMETRS_CC_
#define CPP4_3DVIEWER_V2_0_1_NORMALIZATION_PARAMETRS_CC_

#include "NormalizationParametrs.h"

namespace s21 {
NormalizationParametrs::NormalizationParametrs()
    : minX_(std::numeric_limits<double>::max()),
      maxX_(std::numeric_limits<double>::min()),
      minY_(std::numeric_limits<double>::max()),
      maxY_(std::numeric_limits<double>::min()),
      minZ_(std::numeric_limits<double>::max()),
      maxZ_(std::numeric_limits<double>::min()),
      scale_(0.0) {}

void NormalizationParametrs::CheckPoint(double x, double y, double z) {
  minX_ = std::min(minX_, x);
  maxX_ = std::max(maxX_, x);
  minY_ = std::min(minY_, y);
  maxY_ = std::max(maxY_, y);
  minZ_ = std::min(minZ_, z);
  maxZ_ = std::max(maxZ_, z);
}

void NormalizationParametrs::CalculateScale() {
  const double SCALE_VALUE = 0.5;
  double x = maxX_ - minX_;
  double y = maxY_ - minY_;
  double z = maxZ_ - minZ_;
  double max = std::max(std::max(x, y), z);
  scale_ = SCALE_VALUE / max;
}

double NormalizationParametrs::GetScale() const { return scale_; }

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_NORMALIZATION_PARAMETRS_CC_
