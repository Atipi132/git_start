#pragma once
#include <opencv2/opencv.hpp>
#include "shape.h"

class RectangleDrawer : public Shape {
public:
    RectangleDrawer(const std::string& windowName, int width, int height, int x, int y,
        int thickness, int r, int g, int b)
        : Shape(windowName, thickness, r, g, b), width_(width), height_(height), x_(x), y_(y) {}

    void draw(cv::Mat& image) override {
        cv::rectangle(image, cv::Point(x_, y_), cv::Point(x_ + width_, y_ + height_), color_, thickness_);
    }

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