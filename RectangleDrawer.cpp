#include "RectangleDrawer.h"

RectangleDrawer::RectangleDrawer(const std::string& windowName, int width, int height, int x, int y,
    int thickness, int r, int g, int b)
    : Shape(windowName, thickness, r, g, b), width_(width), height_(height), x_(x), y_(y) {}

void RectangleDrawer::draw(cv::Mat& image) {
    cv::rectangle(image, cv::Point(x_, y_), cv::Point(x_ + width_, y_ + height_), color_, thickness_);
}

void RectangleDrawer::update(int x, int y, cv::Mat& image) {     // Mettre à jour les coordonnées du cercle en fonction des paramètres d'animation
    cv::rectangle(image, cv::Point(x_, y_), cv::Point(x_ + width_, y_ + height_), cv::Scalar(255, 255, 255), thickness_);
    x_ += x;
    y_ += y;
    draw(image);
}
