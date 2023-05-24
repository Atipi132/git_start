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

    // Création des formes
    Shape* rectangle = new RectangleDrawer(windowName, 200, 150, 100, 100, 2, 255, 0, 0);
    Shape* circle = new CircleDrawer(windowName, 75, 400, 300, 3, 0, 0, 255);
    Shape* triangle = new TriangleDrawer(windowName, 200, 100, 300, 250, 400, 100, 2, 0, 255, 0);
    Shape* line = new LineDrawer(windowName, 100, 400, 600, 400, 2, 255, 255, 0);

    // Variables pour l'animation
    bool isAnimating = true;

    // Boucle principale de l'animation
    while (isAnimating) {
        // Dessiner les formes sur l'image avec les coordonnées actuelles
        rectangle->draw(image);
        circle->draw(image);
        triangle->draw(image);
        line->draw(image);

        // Mettre à jour les coordonnées des formes avec les nouvelles valeurs
        rectangle->update();
        circle->update();
        triangle->update();
        line->update();

        // Afficher l'image dans la fenêtre
        cv::imshow(windowName, image);

        // Attendre 10 millisecondes et vérifier si l'utilisateur appuie sur une touche pour quitter
        if (cv::waitKey(10) != -1) {
            isAnimating = false;
        }
    }

    // Nettoyage
    cv::destroyWindow(windowName);
    delete rectangle;
    delete circle;
    delete triangle;
    delete line;

    return 0;
}
