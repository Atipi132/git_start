class LineDrawer : public Shape {
public:
    LineDrawer(const std::string& windowName, int x1, int y1, int x2, int y2,
        int thickness, int r, int g, int b)
        : Shape(windowName, thickness, r, g, b), x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}

    void draw(cv::Mat& image) override {
        cv::line(image, cv::Point(x1_, y1_), cv::Point(x2_, y2_), color_, thickness_);
    }

    void update() override {
        // Mettre à jour les coordonnées de la ligne en fonction des paramètres d'animation
        x1_ += speedX_;
        y1_ += speedY_;
        x2_ += speedX_;
        y2_ += speedY_;
    }

private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;
    int speedX_ = 2;
    int speedY_ = 1;
};
