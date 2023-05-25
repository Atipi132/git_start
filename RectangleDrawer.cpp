#include "RectangleDrawer.h"

void RectangleDrawer::draw(cv::Mat& image) {
    cv::rectangle(image, cv::Point(x_, y_), cv::Point(x_ + width_, y_ + height_), color_, thickness_);
}

void RectangleDrawer::update() {
    // Mettre à jour les coordonnées du rectangle en fonction des paramètres d'animation
    x_ += speedX_;
    y_ += speedY_;
}
