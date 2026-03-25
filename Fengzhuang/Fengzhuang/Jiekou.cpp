// 这个相机类对外提供的接口就是：连接、拍照、断开
class Camera {
public:
	// 这些都是接口 - 外部能调用的函数
	bool connect();           // 就像插座的插孔
	cv::Mat capture();        // 外部只知道能拍照，不知道如何拍
	void disconnect();

private:
	// 这些不是接口 - 内部实现细节
	void initializeSensor();  // 外部不知道传感器怎么初始化
	void readImageData();     // 外部不知道数据怎么读取
};
