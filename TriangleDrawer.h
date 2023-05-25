#pragma once
#include <opencv2/opencv.hpp>
#include "shape.h"

// La classe TriangleDrawer représente un dessinateur de triangle qui hérite de la classe Shape.
class TriangleDrawer : public Shape {
public:
    // Constructeur de la classe TriangleDrawer.
    // - windowName : le nom de la fenêtre OpenCV dans laquelle le triangle sera dessiné.
    // - x1, y1, x2, y2, x3, y3 : les coordonnées des sommets du triangle.
    // - thickness : l'épaisseur du trait utilisé pour dessiner le triangle.
    // - r, g, b : les valeurs RGB qui définissent la couleur du triangle.
    TriangleDrawer(const std::string& windowName, int x1, int y1, int x2, int y2, int x3, int y3,
        int thickness, int r, int g, int b)
        : Shape(windowName, thickness, r, g, b), x1_(x1), y1_(y1), x2_(x2), y2_(y2), x3_(x3), y3_(y3) {}
    
    // Redéfinition de la fonction de dessin pour le triangle.
    // Dessine les trois côtés du triangle en utilisant les coordonnées des sommets, la couleur et l'épaisseur spécifiées.
    void draw(cv::Mat& image) override {
        cv::line(image, cv::Point(x1_, y1_), cv::Point(x2_, y2_), color_, thickness_);
        cv::line(image, cv::Point(x2_, y2_), cv::Point(x3_, y3_), color_, thickness_);
        cv::line(image, cv::Point(x3_, y3_), cv::Point(x1_, y1_), color_, thickness_);
    }
    // Redéfinition de la fonction de mise à jour pour le triangle.
    // Met à jour les coordonnées du triangle en fonction des paramètres d'animation.
    void update() override {
        // Mettre à jour les coordonnées du triangle en fonction des paramètres d'animation
        x1_ += speedX_;
        y1_ += speedY_;
        x2_ += speedX_;
        y2_ += speedY_;
        x3_ += speedX_;
        y3_ += speedY_;
    }

private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;
    int x3_;
    int y3_;
    int speedX_ = 2;
    int speedY_ = 1;
};
