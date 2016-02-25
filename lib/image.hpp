#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <opencv2/opencv.hpp>
#include <string>

class Image
{
public:
    //Convert pixel value range to [0, 1]
    static cv::Mat normalizeRange(const cv::Mat& image);
    //First normalizing range ([0, 1]) then changing range to [0, 255]
    static cv::Mat discreteRange(const cv::Mat& image, int type);
    static double findMinValue(const cv::Mat& image);
    static double findMaxValue(const cv::Mat& image);
    //For a 3 channels image you must use cv::Scalar(B, G, R)
    static cv::Mat changeBrightness(const cv::Mat& image, cv::Scalar delta);
public:
    inline void showMe()
    {
        //cv::namedWindow(title(), cv::WINDOW_NORMAL);
        cv::imshow(title(), data());
    }

    double findMaxValue() const;
    double findMinValue() const;

    Image() {}
    explicit Image(const std::string& path, const std::string& tile = std::string());
    Image(const cv::Mat& data, const std::string& path)
    {
        setData(data);
        setPath(path);
    }

    Image(const std::string& title, const cv::Mat& data, const std::string& path = "")
    {
        setData(data);
        setTitle(title);
        setPath(path);
    }

    Image& operator=(const cv::Mat& right)
    {
        setData(right.clone());
        return *this;
    }

    inline void convertTo(int type = -1, double alpha = 1, double beta = 0)
    {
        _data.convertTo(_data, type, alpha, beta);
    }

    inline void setPath(const std::string& path)
    {        
        _path = path;
        if (title().empty())
            setTitle(path);
    }
    inline std::string path() const
    {
        return _path;
    }
    inline void setData(const cv::Mat& data)
    {
        _data = data;
    }
    inline cv::Mat data() const
    {
        return _data;
    }
    inline void setTitle(const std::string& title)
    {
        _title = title;
    }
    inline std::string title()
    {
        return _title;
    }

private:
    std::string _path, _title;
    cv::Mat _data;
};

#endif
