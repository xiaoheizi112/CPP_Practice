// 1. 封装为函数：把复杂算法包起来
double calculateDistance(const Point& p1, const Point& p2) {
    // 内部可能是复杂的欧几里得距离计算
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// 2. 封装为类：把相关数据和操作包起来
class ImageProcessor {
private:
    cv::Mat current_image_;  // 内部状态，对外隐藏

public:
    // 只暴露简单的处理接口
    void loadImage(const std::string& path);
    void applyFilter(FilterType type);
    cv::Mat getResult();
};

// 3. 封装为模块：把整套功能包起来
namespace VisionAlgorithms {
    class Detector { /*...*/ };
    class Tracker { /*...*/ };
    class Classifier { /*...*/ };
}

// 4. 封装为dll：把实现完全隐藏
// vision_lib.h - 只提供接口声明
class IVisionAlgorithm {
public:
    virtual cv::Mat process(const cv::Mat& input) = 0;
    virtual ~IVisionAlgorithm() = default;
};

// 工厂函数 - 唯一的创建接口
DLL_EXPORT IVisionAlgorithm* createDetector();