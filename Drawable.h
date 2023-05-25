#pragma once
#include <opencv2/opencv.hpp>

// La classe Drawable est une classe abstraite qui définit une interface commune pour les objets dessinables.
class Drawable {
public:  
    
    // Fonction virtuelle pure pour dessiner l'objet.
    // Prend en paramètre une référence à une image OpenCV sur laquelle l'objet sera dessiné.
    virtual void draw(cv::Mat& image) = 0;
    
    // Fonction virtuelle pure pour mettre à jour l'objet.
    // Cette fonction est utilisée pour effectuer des modifications sur l'objet, par exemple changer ses coordonnées.
    virtual void update() = 0;
    
    // Destructeur virtuel pour permettre la destruction polymorphique des objets dérivés.
    virtual ~Drawable() {}
};
