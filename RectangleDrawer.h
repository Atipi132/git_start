#pragma once

#include <opencv2/opencv.hpp>
#include "shape.h"

class RectangleDrawer : public Shape {
public:
    RectangleDrawer(const std::string& windowName, int width, int height, int x, int y,
        int thickness, int r, int g, int b);

    void draw(cv::Mat& image) override;

private:
    int width_;
    int height_;
    int x_;
    int y_;
};
