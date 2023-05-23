#include "cercle.h"
#include "rectangle.h"
#include "shape.h"

int main() {
    const std::string windowName = "Drawing Window";
    const int imageWidth = 800;
    const int imageHeight = 600;
    cv::Mat image(imageHeight, imageWidth, CV_8UC3, cv::Scalar(255, 255, 255));

    // Création des formes
    Shape* rectangle = new RectangleDrawer(windowName, 200, 150, 100, 100, 2, 255, 0, 0);
    Shape* circle = new CircleDrawer(windowName, 75, 400, 300, 3, 0, 0, 255);

    // Dessiner les formes sur l'image
    rectangle->draw(image);
    circle->draw(image);

    // Afficher l'image dans la fenêtre
    cv::imshow(windowName, image);
    cv::waitKey(0);

    // Nettoyage
    cv::destroyWindow(windowName);
    delete rectangle;
    delete circle;

    return 0;
}
