#include <opencv2/opencv.hpp>

class RectangleDrawer {
public:
    RectangleDrawer(int x, int y, int width, int height, int thickness, cv::Scalar color)
        : m_x(x), m_y(y), m_width(width), m_height(height), m_thickness(thickness), m_color(color) {}

    void dessiner(cv::Mat& image) const {
        cv::rectangle(image, cv::Rect(m_x, m_y, m_width, m_height), m_color, m_thickness);
    }

private:
    int m_x, m_y, m_width, m_height, m_thickness;
    cv::Scalar m_color;
};

int main() {
    cv::Mat image(400, 400, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::namedWindow("Rectangles");

    RectangleDrawer rect1(50, 50, 100, 150, 5, cv::Scalar(255, 0, 0));
    rect1.dessiner(image);

    RectangleDrawer rect2(200, 100, 80, 120, 3, cv::Scalar(0, 255, 0));
    rect2.dessiner(image);

    cv::imshow("Rectangles", image);
    cv::waitKey(0);

    return 0;
}