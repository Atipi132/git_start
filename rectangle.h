class RectangleDrawer {
public:
    RectangleDrawer(const std::string& windowName, int width, int height)
        : windowName_(windowName), width_(width), height_(height)
    {
        cv::namedWindow(windowName_, cv::WINDOW_NORMAL);
        cv::resizeWindow(windowName_, width_, height_);
        cv::waitKey(1);
    }

    void drawRectangle(int x, int y, int width, int height, int thickness, const cv::Scalar& color)
    {
        cv::Rect rect(x, y, width, height);
        cv::rectangle(image_, rect, color, thickness);
    }

    void showImage()
    {
        cv::imshow(windowName_, image_);
        cv::waitKey(0);
    }

private:
    std::string windowName_;
    int width_;
    int height_;
    cv::Mat image_ = cv::Mat::zeros(height_, width_, CV_8UC3);
};