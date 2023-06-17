#pragma once

#include <opencv2/opencv.hpp>
#include "shape.h"

class RectangleDrawer : public Shape {
public:
    RectangleDrawer(const std::string& windowName, int width, int height, int x, int y,
        int thickness, int r, int g, int b);

    void draw(cv::Mat& image) override;
    void update(int x, int y, cv::Mat& image) override; // Mettre à jour les coordonnées du cercle en fonction des paramètres d'animation

private:
    int width_;
    int height_;
    int x_;
    int y_;
};
