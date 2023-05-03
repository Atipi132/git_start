

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