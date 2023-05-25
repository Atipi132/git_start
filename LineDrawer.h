#pragma once
#include <opencv2/opencv.hpp>
#include "shape.h"

// La classe LineDrawer représente un dessinateur de ligne qui hérite de la classe Shape.
class LineDrawer : public Shape {
public:
    
    // Constructeur de la classe LineDrawer.
    // - windowName : le nom de la fenêtre OpenCV dans laquelle la ligne sera dessinée.
    // - x1, y1, x2, y2 : les coordonnées des extrémités de la ligne.
    // - thickness : l'épaisseur du trait utilisé pour dessiner la ligne.
    // - r, g, b : les valeurs RGB qui définissent la couleur de la ligne.
    LineDrawer(const std::string& windowName, int x1, int y1, int x2, int y2,
        int thickness, int r, int g, int b)
        : Shape(windowName, thickness, r, g, b), x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}
    
    // Redéfinition de la fonction de dessin pour la ligne.
    // Dessine une ligne en utilisant les coordonnées des extrémités, la couleur et l'épaisseur spécifiées.
    void draw(cv::Mat& image) override {
        cv::line(image, cv::Point(x1_, y1_), cv::Point(x2_, y2_), color_, thickness_);
    }
    
    // Redéfinition de la fonction de mise à jour pour la ligne.
    // Met à jour les coordonnées de la ligne en fonction des paramètres d'animation.
    void update() override {
        // Mettre à jour les coordonnées de la ligne en fonction des paramètres d'animation
        x1_ += speedX_;
        y1_ += speedY_;
        x2_ += speedX_;
        y2_ += speedY_;
    }

private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;
    int speedX_ = 2;
    int speedY_ = 1;
};
