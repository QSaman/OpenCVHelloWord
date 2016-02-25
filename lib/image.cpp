#include "image.hpp"
#include <algorithm>

double Image::findMaxValue() const
{
    return findMaxValue(data());
}

Image::Image(const std::string& path, const std::string& tile)
{
    setTitle(tile);
    setPath(path);
    setData(cv::imread(path, CV_LOAD_IMAGE_UNCHANGED));
}

double Image::findMinValue() const
{
    return findMinValue(data());
}

cv::Mat Image::normalizeRange(const cv::Mat& image)
{
    cv::Mat ret;
    ret = image.clone();
    double min = findMinValue(ret);
    double max = findMaxValue(ret);
    //I first translate (max + min) / 2 to 0 because scaling is in respect to 0 (T1),
    //then scale to size 1 ([-0.5, 0.5]) (S), then translate to [0, 1] (T2):
    //((x + T1) * S) + T2 = (S * x) + (T1 * S + T2)
    double t1 = -(max + min) / 2.0;
    double scale = (max == min ? 1 : 1.0 / (max - min));
    double alpha = scale;
    double beta = scale * t1 + 0.5;
    ret.convertTo(ret, ret.type(), scale, beta);
    return ret;
}

double Image::findMinValue(const cv::Mat& image)
{
    std::vector<cv::Mat> v;
    cv::split(image, v);
    double ret = INFINITY;
    for (auto img : v)
    {
        double min;
        cv::minMaxLoc(img, &min, nullptr);
        ret = std::min(min, ret);
    }
    return ret;
}

double Image::findMaxValue(const cv::Mat& image)
{
    std::vector<cv::Mat> v;
    cv::split(image, v);
    double ret = 0;
    for (auto img : v)
    {
        double max;
        cv::minMaxLoc(img, nullptr, &max);
        ret = std::max(max, ret);
    }
    return ret;
}

cv::Mat Image::changeBrightness(const cv::Mat &image, cv::Scalar delta)
{
    return image + delta;
}

cv::Mat Image::discreteRange(const cv::Mat &image, int type)
{
    auto ret = normalizeRange(image);
    ret.convertTo(ret, type, 255);
    return ret;
}
