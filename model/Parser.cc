#ifndef CPP4_3DVIEWER_V2_0_1_PARSER_CC_
#define CPP4_3DVIEWER_V2_0_1_PARSER_CC_

#include "Parser.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "FacadeOperationResult.h"

namespace s21 {

Parser::Parser(const std::string &filePath) : filePath_(filePath) {}

void Parser::ParseFile(NormalizationParametrs &parametrs) {
  std::fstream file(filePath_, std::ios::in);
  if (!file) {
    throw FacadeOperationResult("Can't open file", false);
  }
  vertices_.clear();
  polygons_.clear();

  std::string line;
  while (std::getline(file, line)) {
    if (line.substr(0, 2) == "v ") {
      std::istringstream stream(line.substr(2));
      double x, y, z;
      stream >> x >> y >> z;
      parametrs.CheckPoint(x, y, z);
      vertices_.push_back(x);
      vertices_.push_back(y);
      vertices_.push_back(z);
    } else if (line.substr(0, 2) == "f ") {
      std::istringstream stream(line.substr(2));
      std::string trash;
      std::vector<size_t> polygons;
      while (stream) {
        size_t number;
        stream >> number >> trash;
        polygons.push_back(number);
      }
      polygons.pop_back();
      polygons_.push_back(polygons);
    }
  }
}

std::vector<double> Parser::GetVertices() const { return vertices_; }

std::vector<std::vector<size_t>> Parser::GetPolygons() const {
  return polygons_;
}

void Parser::setFilePath(const std::string &filePath) { filePath_ = filePath; }
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_PARSER_CC_
