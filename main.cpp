#include <opencv2/opencv.hpp>
#include "rectangle.h"
#include "Cercle.h"
int main()
{
    RectangleDrawer drawer("Rectangles", 800, 600);
    drawer.drawRectangle(100, 100, 200, 150, 2, cv::Scalar(0, 255, 0));
    drawer.drawRectangle(400, 300, 100, 100, -1, cv::Scalar(0, 0, 255));
    drawer.showImage();
    circle = Circle(20);
    circle.draw();
    return 0;
}
