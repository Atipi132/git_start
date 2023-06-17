#include <iostream>
#include <opencv2/opencv.hpp>
#include "shape.h"
#include "RectangleDrawer.h"
#include "CircleDrawer.h"
#include <thread>
#include <chrono>

int main() {
    const std::string windowName = "Drawing Window";
    const int imageWidth = 800;
    const int imageHeight = 600;
    cv::Mat image(imageHeight, imageWidth, CV_8UC3, cv::Scalar(255, 255, 255));

    // Création des formes
    Shape* rectangle = new RectangleDrawer(windowName, 200, 150, 100, 100, 2, 255, 0, 0);
    Shape* circle = new CircleDrawer(windowName, 75, 400, 300, 3, 0, 0, 255);

    // Dessiner les formes sur l'image
    rectangle->draw(image);
    circle->draw(image);

    // Afficher l'image dans la fenêtre
    cv::namedWindow(windowName);
    cv::resizeWindow(windowName, imageWidth, imageHeight); // Redimensionner la fenêtre à la taille de l'image
    cv::imshow(windowName, image);
    cv::waitKey(1);
    std::this_thread::sleep_for(std::chrono::seconds(2)); //attendre 2 secondes avant de changer le position du cercle et du rectangle
    circle->update(100, 100, image);
    rectangle->update(-50, 50, image);
    cv::imshow(windowName, image);
    cv::waitKey(0); // attendre que l'utilisateur appuie sur une touche pour sortir detruire la fenetre

    // Nettoyage
    cv::destroyWindow(windowName);
    delete rectangle;
    delete circle;

	return 0;
}
