#pragma once
#include <opencv2/opencv.hpp>
class Drawable {
public:
    virtual void draw(cv::Mat& image) = 0;
    virtual void update() = 0;
    virtual ~Drawable() {}
};
