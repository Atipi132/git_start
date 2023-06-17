#pragma once
#include <opencv2/opencv.hpp>
#include "shape.h"

// La classe CircleDrawer représente un dessinateur de cercle qui hérite de la classe Shape.
class CircleDrawer : public Shape {
public:
	 // Constructeur de la classe CircleDrawer.
    // - windowName : le nom de la fenêtre OpenCV dans laquelle le cercle sera dessiné.
    // - radius : le rayon du cercle.
    // - centerX, centerY : les coordonnées du centre du cercle.
    // - thickness : l'épaisseur du trait utilisé pour dessiner le cercle.
    // - r, g, b : les valeurs RGB qui définissent la couleur du cercle.
	CircleDrawer(const std::string& windowName, int radius, int centerX, int centerY, int thickness, int r, int g, int b);
    
    // Redéfinition de la fonction de dessin pour le cercle.
    // Dessine un cercle en utilisant les coordonnées du centre, le rayon, la couleur et l'épaisseur spécifiés.
	void draw(cv::Mat& image) override;
	void update(int x, int y, cv::Mat& image) override; // Mettre à jour les coordonnées du cercle en fonction des paramètres d'animation


private:
	int radius_;
	int centerX_;
	int centerY_;
};
