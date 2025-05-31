#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

std::vector<double> image_to_vector(const std::string& image_path) {
    cv::Mat img = cv::imread(image_path, cv::IMREAD_GRAYSCALE);  // or IMREAD_COLOR
    img = img.reshape(1, 1); // Flatten to single row
    img.convertTo(img, CV_64F); // Convert to double

    std::vector<double> img_vector;
    img_vector.assign((double*)img.datastart, (double*)img.dataend);

    for (auto i : img_vector)
        cout << i << " ";
    return img_vector;
}

int main() {
    auto img = "C:/Users/Sachi/OneDrive/Pictures/Screenshots/Screenshot 2024-08-22 202911.png";
    vector<double> a = image_to_vector(img);
}
