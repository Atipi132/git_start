#pragma once

#include <opencv2/opencv.hpp>
#include "shape.h"

class CircleDrawer : public Shape {
public:
	CircleDrawer(const std::string& windowName, int radius, int centerX, int centerY, int thickness, int r, int g, int b)
		: Shape(windowName, thickness, r, g, b), radius_(radius), centerX_(centerX), centerY_(centerY) {}
	void draw(cv::Mat& image) override {
		cv::circle(image, cv::Point(centerX_, centerY_), radius_, color_, thickness_);
	}
private:
	int radius_;
	int centerX_;
	int centerY_;
};
