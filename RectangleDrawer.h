#pragma once
#include <opencv2/opencv.hpp>
#include "shape.h"

// La classe RectangleDrawer représente un dessinateur de rectangle qui hérite de la classe Shape.
class RectangleDrawer : public Shape {
public:
    // Constructeur de la classe RectangleDrawer.
    // - windowName : le nom de la fenêtre OpenCV dans laquelle le rectangle sera dessiné.
    // - width : la largeur du rectangle.
    // - height : la hauteur du rectangle.
    // - x, y : les coordonnées du coin supérieur gauche du rectangle.
    // - thickness : l'épaisseur du trait utilisé pour dessiner le rectangle.
    // - r, g, b : les valeurs RGB qui définissent la couleur du rectangle.
    RectangleDrawer(const std::string& windowName, int width, int height, int x, int y,
        int thickness, int r, int g, int b)
        : Shape(windowName, thickness, r, g, b), width_(width), height_(height), x_(x), y_(y) {}

    // Redéfinition de la fonction de dessin pour le rectangle.
    // Dessine un rectangle en utilisant les coordonnées du coin supérieur gauche, la largeur, la hauteur, la couleur et l'épaisseur spécifiées.
    void draw(cv::Mat& image) override {
        cv::rectangle(image, cv::Point(x_, y_), cv::Point(x_ + width_, y_ + height_), color_, thickness_);
    }

    // Redéfinition de la fonction de mise à jour pour le rectangle.
    // Met à jour les coordonnées du rectangle en fonction des paramètres d'animation.
    void update() override {
        // Mettre à jour les coordonnées du rectangle en fonction des paramètres d'animation
        x_ += speedX_;
        y_ += speedY_;
    }

private:
    int width_;
    int height_;
    int x_;
    int y_;
    int speedX_ = 2;
    int speedY_ = 1;
};
