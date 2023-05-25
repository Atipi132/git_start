#pragma once
#include <opencv2/opencv.hpp>
#include "Drawable.h"

// La classe Shape représente une forme générique qui peut être dessinée dans une fenêtre OpenCV.
class Shape : public Drawable {
public:
    // Constructeur de la classe Shape.
    // - windowName : le nom de la fenêtre OpenCV dans laquelle la forme sera dessinée.
    // - thickness : l'épaisseur du trait utilisé pour dessiner la forme.
    // - r, g, b : les valeurs RGB qui définissent la couleur de la forme.
    Shape(const std::string& windowName, int thickness, int r, int g, int b);
    
    // Destructeur virtuel de la classe Shape.
    virtual ~Shape();

protected:
    std::string windowName_;  // Le nom de la fenêtre OpenCV.
    int thickness_;           // L'épaisseur du trait utilisé pour dessiner la forme.
    cv::Scalar color_;        // La couleur de la forme (en valeurs RGB).
};
