#include "CircleDrawer.h"

CircleDrawer::CircleDrawer(const std::string& windowName, int radius, int centerX, int centerY, int thickness, int r, int g, int b)
    : Shape(windowName, thickness, r, g, b), radius_(radius), centerX_(centerX), centerY_(centerY)
{
}

void CircleDrawer::draw(cv::Mat& image)
{
    cv::circle(image, cv::Point(centerX_, centerY_), radius_, color_, thickness_);
}

void CircleDrawer::update(){     // Mettre à jour les coordonnées du cercle en fonction des paramètres d'animation
    centerX_ += 2;
    centerY_ += 1;
}
