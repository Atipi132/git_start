#include "CircleDrawer.h"
#include "RectangleDrawer.h"
#include "Shape.h"
#include "TriangleDrawer.h"
#include "LineDrawer.h"

int main() {
    const std::string windowName = "Drawing Window";
    const int imageWidth = 800;
    const int imageHeight = 600;
    cv::Mat image(imageHeight, imageWidth, CV_8UC3, cv::Scalar(255, 255, 255));

    std::vector<Drawable*> shapes;// Crée un vecteur pour stocker les formes dessinables
    
    // Ajoute différentes formes au vecteur
    shapes.push_back(new TriangleDrawer(windowName, 200, 100, 300, 250, 400, 100, 2, 0, 255, 0));
    shapes.push_back(new RectangleDrawer(windowName, 200, 150, 100, 100, 2, 255, 0, 0));
    shapes.push_back(new CircleDrawer(windowName, 75, 400, 300, 3, 0, 0, 255));
    shapes.push_back(new LineDrawer(windowName, 100, 400, 600, 400, 2, 255, 255, 0));

    bool isAnimating = true;
    
    // Boucle principale de l'animation
    while (isAnimating) {
        for (Drawable* shape : shapes) {
            shape->draw(image);
            shape->update();
        }
        
        // Affiche l'image dans une fenêtre OpenCV
        cv::imshow(windowName, image);
        
         // Vérifie si une touche est enfoncée pour arrêter l'animation
        if (cv::waitKey(10) != -1) {
            isAnimating = false;
        }
    }
    
    // Détruit la fenêtre OpenCV et libère la mémoire des formes
    cv::destroyWindow(windowName);
    for (Drawable* shape : shapes) {
        delete shape;
    }

    return 0;
}
