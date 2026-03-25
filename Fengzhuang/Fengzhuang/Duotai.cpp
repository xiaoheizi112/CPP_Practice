class Algorithm {
public:
    // 虚函数：可以被重写
    virtual void run() {
        std::cout << "Base algorithm running" << std::endl;
    }

    // 纯虚函数：必须被重写（定义接口）
    virtual void initialize() = 0;

    // 虚析构函数：确保正确清理
    virtual ~Algorithm() = default;
};

class EdgeDetector : public Algorithm {
public:
    void run() override {  // override确保正确重写
        std::cout << "Detecting edges..." << std::endl;
    }

    void initialize() override {
        std::cout << "Initializing edge detector" << std::endl;
    }
};