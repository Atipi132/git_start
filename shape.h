#pragma once

#include <opencv2/opencv.hpp>

class Shape {
public:
    Shape(const std::string& windowName, int thickness, int r, int g, int b)
        : windowName_(windowName), thickness_(thickness), color_(cv::Scalar(b, g, r)) {
        cv::namedWindow(windowName_);
    }

    virtual ~Shape() {} // Ajout d'un destructeur virtuel

    virtual void draw(cv::Mat& image) = 0;

protected:
    std::string windowName_;
    int thickness_;
    cv::Scalar color_;
};
