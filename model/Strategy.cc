#ifndef CPP4_3DVIEWER_V2_0_1_MODEL_STRATEGY_CC_
#define CPP4_3DVIEWER_V2_0_1_MODEL_STRATEGY_CC_

#include "Strategy.h"

namespace s21 {
void RotateSceneByX::Rotate(double angle, Scene &scene) {
  scene.RotateSceneByX(angle);
}

void RotateSceneByY::Rotate(double angle, Scene &scene) {
  scene.RotateSceneByY(angle);
}

void RotateSceneByZ::Rotate(double angle, Scene &scene) {
  scene.RotateSceneByZ(angle);
}

RotateProcessor::RotateProcessor() : compressionStrategy_(nullptr) {}

RotateProcessor::RotateProcessor(CompressionStrategy *strategy)
    : compressionStrategy_(strategy) {}

void RotateProcessor::processRotate(double angle, Scene &scene) {
  compressionStrategy_->Rotate(angle, scene);
}

void RotateProcessor::setCompressionStrategy(CompressionStrategy *strategy) {
  compressionStrategy_ = strategy;
}

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_MODEL_STRATEGY_CC_