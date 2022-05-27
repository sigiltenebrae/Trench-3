#include "main.h"

using namespace cv;
using namespace std;

int main() {
    std::string image_path = "C:\\Users\\chris\\CLionProjects\\Trench-3\\firefox-logo.png";
    Mat img = imread(image_path, IMREAD_COLOR);

    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }

    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window

    Mat out_image = neon_glow(img, 131);

    imshow("Display window", out_image);
    k = waitKey(0); // Wait for a keystroke in the window
    return 0;
}
