/**
 * @file main.cpp
 * @brief 程序的入口点，负责初始化 TodoManager 并启动程序。
 */

#include <iostream>
#include "TodoManager.h"

/**
 * @brief 程序入口函数。
 * 
 * 创建 TodoManager 实例并调用 run() 方法。
 * 包含异常处理以捕获程序运行中的重大错误。
 * 
 * @return 0 表示程序正常退出，1 表示捕获到异常。
 */
int main() {
    // 使用 try-catch 结构来包裹整个程序的运行过程
    // 这样如果程序内部发生了严重的错误（异常），我们能优雅地处理它，而不是让程序直接崩溃
    try {
        // 第一步：创建管理类（TodoManager）的实例对象
        // 这一步会初始化程序所需的资源（比如创建任务列表工具）
        TodoManager manager;
        
        // 第二步：调用 run 方法启动程序的主逻辑
        // 程序会在这里进入菜单循环，直到用户选择退出
        manager.run();
    }
    catch (const std::exception& e) {
        // 如果程序运行中抛出了标准 C++ 异常，会在这里被捕获
        // e.what() 会告诉我们具体的错误原因
        std::cerr << "捕获到致命异常: " << e.what() << std::endl;
        // 返回 1 表示程序是非正常退出的
        return 1;
    }
    catch (...) {
        // 这里捕获那些不属于标准异常类的其他所有错误
        std::cerr << "捕获到未知异常。" << std::endl;
        return 1;
    }

    // 如果程序一切顺利，最终返回 0
    return 0;
}
