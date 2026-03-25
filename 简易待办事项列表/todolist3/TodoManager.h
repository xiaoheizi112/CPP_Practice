/**
 * @file TodoManager.h
 * @brief 待办事项管理逻辑类，负责用户交互和流程控制。
 */

#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include "TodoList.h"
#include <memory>

/**
 * @class TodoManager
 * @brief 负责驱动整个待办事项程序的类。
 * 
 * 该类通过组合 TodoList 类来实现具体的功能，并负责处理所有的控制台输入和输出。
 */
class TodoManager {
private:
    std::unique_ptr<TodoList> todoList; ///< 指向 TodoList 实例的智能指针

    // --- 界面打印函数 ---
    void printMainMenu() const; ///< 打印主菜单选项
    void printFileMenu() const; ///< 打印文件操作子菜单选项

    // --- 流程控制函数 ---
    void handleMainMenu();      ///< 处理主菜单的逻辑循环
    void handleFileMenu();      ///< 处理文件操作菜单的逻辑循环

    // --- 具体功能处理函数 ---
    void handleAddTask();           ///< 处理添加任务的交互逻辑
    void handleDeleteTask();        ///< 处理删除任务的交互逻辑
    void handleSaveToFile();        ///< 处理保存文件的交互逻辑
    void handleLoadFromFile();      ///< 处理加载文件的交互逻辑
    void handleViewFileContent() const; ///< 处理查看原始文件内容的交互逻辑

public:
    /**
     * @brief 构造函数，初始化 todoList 实例。
     */
    TodoManager();

    /**
     * @brief 启动程序的主运行入口。
     */
    void run();
};

#endif // TODOMANAGER_H
