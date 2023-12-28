<<<<<<< HEAD
#include "Parser.h"
#include <iostream>

int main() {
    std::string fileName = "coub.obj";
    s21::Parser* parser = s21::ParserSingleton::GetInstance();
    parser->setFilePath(fileName);
    parser->ParseFile();

    auto vec = parser->GetVertices();
    auto polygons = parser->GetPolygons();

    for (auto item : vec)
        std::cout << item << ' ';
    std::cout << std::endl;

    for (auto item : polygons)
        std::cout << item << ' ';
    

=======
#include <iostream>
#include "Facade.h"

int main() {
    std::string fileName = "/Users/pagemois/school21/CPP4_3DViewer_v2.0-1/src/coub.obj";
    s21::Facade facade;
    facade.LoadScene(fileName);

    auto scene = facade.getScene();

    for (auto figure : scene) {
        for (auto vertex : figure) {
            for (auto point : vertex) {
                std::cout << point << ' ';
            }
            std::cout << '\n';
        }
    }

    scene.ScaleScene(2);
    for (auto figure : scene) {
        for (auto vertex : figure) {
            for (auto point : vertex) {
                std::cout << point << ' ';
            }
            std::cout << '\n';
        }
    }
>>>>>>> pagemois

    return 0;
}
