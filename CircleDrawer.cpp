
#include "CircleDrawer.hpp"


CircleDrawer::CircleDrawer(const std::string& windowName, int radius, int centerX, int centerY,
    int thickness, int r, int g, int b)
    : Shape(windowName, thickness, r, g, b), radius_(radius), centerX_(centerX), centerY_(centerY) {}

    
// Redéfinition de la fonction de dessin pour le cercle.
// Dessine un cercle en utilisant les coordonnées du centre, le rayon, la couleur et l'épaisseur spécifiés.
void CircleDrawer::draw(cv::Mat& image) {
    cv::circle(image, cv::Point(centerX_, centerY_), radius_, color_, thickness_);
}

// Redéfinition de la fonction de mise à jour pour le cercle.
// Met à jour les coordonnées du cercle en fonction des paramètres d'animation.
void CircleDrawer::update() {
    // Mettre à jour les coordonnées du cercle en fonction des paramètres d'animation
    centerX_ += speedX_;
    centerY_ += speedY_;
}

