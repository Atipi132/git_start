#include "CircleDrawer.h"
#include "RectangleDrawer.h"
#include "Shape.h"
#include "TriangleDrawer.h"
#include "LineDrawer.h"

int main() {
    const std::string windowName = "Drawing Window";
    const int imageWidth = 800;
    const int imageHeight = 600;
    cv::Mat image(imageHeight, imageWidth, CV_8UC3, cv::Scalar(255, 255, 255));

    // Création des formes
    Shape* rectangle = new RectangleDrawer(windowName, 200, 150, 100, 100, 2, 255, 0, 0);
    Shape* circle = new CircleDrawer(windowName, 75, 400, 300, 3, 0, 0, 255);
    Shape* triangle = new TriangleDrawer(windowName, 200, 100, 300, 250, 400, 100, 2, 0, 255, 0);
    Shape* line = new LineDrawer(windowName, 100, 400, 600, 400, 2, 255, 255, 0);

    // Dessiner les formes sur l'image
    rectangle->draw(image);
    circle->draw(image);
    triangle->draw(image);
    line->draw(image);

    // Afficher l'image dans la fenêtre
    cv::imshow(windowName, image);
    cv::waitKey(0);

    // Nettoyage
    cv::destroyWindow(windowName);
    delete rectangle;
    delete circle;
    delete triangle;
    delete line;

    return 0;
}
