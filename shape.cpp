#include "shape.h"

Shape::Shape(const std::string& windowName, int thickness, int r, int g, int b)
    : windowName_(windowName), thickness_(thickness), color_(cv::Scalar(b, g, r)) {
    cv::namedWindow(windowName_);
}
