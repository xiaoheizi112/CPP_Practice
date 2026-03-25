// 基础相机类 - 定义所有相机的共性
class BaseCamera {
protected:
    std::string name_;
    bool connected_;

public:
    BaseCamera(const std::string& name) : name_(name), connected_(false) {}

    virtual bool connect() {
        std::cout << "Base camera connecting..." << std::endl;
        connected_ = true;
        return true;
    }

    virtual cv::Mat capture() {
        if (!connected_) throw std::runtime_error("Not connected");
        return cv::Mat();
    }

    virtual ~BaseCamera() = default;
};

// USB相机 - 继承基础功能，添加特有功能
class USBCamera : public BaseCamera {
private:
    int device_id_;

public:
    USBCamera(const std::string& name, int id)
        : BaseCamera(name), device_id_(id) {
    }

    // 重写连接方法，提供USB相机的具体实现
    bool connect() override {
        std::cout << "USB camera " << device_id_ << " connecting..." << std::endl;
        // USB特有的连接逻辑
        connected_ = true;
        return true;
    }

    // 添加USB相机特有功能
    void setUSBSpeed(int speed) {
        std::cout << "Setting USB speed to " << speed << std::endl;
    }
};

// 网络相机 - 同样的接口，不同的实现
class NetworkCamera : public BaseCamera {
private:
    std::string ip_address_;

public:
    NetworkCamera(const std::string& name, const std::string& ip)
        : BaseCamera(name), ip_address_(ip) {
    }

    bool connect() override {
        std::cout << "Network camera " << ip_address_ << " connecting..." << std::endl;
        // 网络连接逻辑
        connected_ = true;
        return true;
    }
};