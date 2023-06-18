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

    std::vector<Drawable*> shapes;
    shapes.push_back(new TriangleDrawer(windowName, 200, 100, 300, 250, 400, 100, 2, 0, 255, 0));
    shapes.push_back(new RectangleDrawer(windowName, 200, 150, 100, 100, 2, 255, 0, 0));
    shapes.push_back(new CircleDrawer(windowName, 75, 400, 300, 3, 0, 0, 255));
    shapes.push_back(new LineDrawer(windowName, 100, 400, 600, 400, 2, 255, 255, 0));

    bool isAnimating = true;

    while (isAnimating) {
        for (Drawable* shape : shapes) {
            shape->draw(image);
            shape->update();
        }

        cv::imshow(windowName, image);

        if (cv::waitKey(10) != -1) {
            isAnimating = false;
        }
    }

    cv::destroyWindow(windowName);
    for (Drawable* shape : shapes) {
        delete shape;
    }

    return 0;
}