#include <opencv2/opencv.hpp>
#include <string>

#include "image.hpp"
#include "global.hpp"

Image img;

void parseInput(int argc, char* argv[])
{
    std::string path;
    if (argc == 1)
        path = "img/Lenna.png";
    else
        path = argv[1];
    img = Image(path);
    img.showMe();
}

int main(int argc, char* argv[])
{
    parseInput(argc, argv);
    cv::waitKey(0);
}
