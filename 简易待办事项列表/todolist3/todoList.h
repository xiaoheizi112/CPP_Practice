/**
 * @file TodoList.h
 * @brief 待办事项管理核心类，负责任务的增删改查及文件持久化。
 */

#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include <string>
#include <fstream>

/**
 * @class TodoList
 * @brief 管理待办事项列表的类。
 * 
 * 该类封装了一个字符串向量来存储任务，并提供了与文件交互的功能。
 */
class TodoList {
private:
    std::vector<std::string> tasks; ///< 存储任务列表的容器
    std::string filename;           ///< 默认的保存/加载文件名

    /**
     * @brief 检查给定的任务索引是否有效。
     * @param index 任务索引（从1开始计数）。
     * @return 如果有效返回 true，否则返回 false。
     */
    bool isValidIndex(int index) const;

    /**
     * @brief 内部辅助函数，用于在控制台打印所有任务。
     */
    void displayTasksInternal() const;

public:
    /**
     * @brief 默认构造函数，初始化并尝试从默认文件加载任务。
     */
    TodoList();

    /**
     * @brief 带文件名的构造函数。
     * @param file 指定的默认文件名。
     */
    explicit TodoList(const std::string& file);

    // --- 核心功能函数 ---

    /**
     * @brief 向列表中添加一个新任务。
     * @param task 任务描述字符串。
     */
    void addTask(const std::string& task);

    /**
     * @brief 在控制台查看所有任务。
     */
    void viewTasks() const;

    /**
     * @brief 根据编号删除一个任务。
     * @param taskNumber 任务编号（从1开始）。
     */
    void deleteTask(int taskNumber);

    /**
     * @brief 清空当前列表中的所有任务。
     */
    void clearAllTasks();

    // --- 文件操作函数 ---

    /**
     * @brief 将当前任务列表保存到默认文件。
     * @return 保存成功返回 true。
     */
    bool saveToFile() const;

    /**
     * @brief 从默认文件加载任务列表。
     * @return 加载成功返回 true。
     */
    bool loadFromFile();

    /**
     * @brief 将任务列表保存到指定文件。
     * @param customFilename 目标文件名。
     * @return 保存成功返回 true。
     */
    bool saveToFile(const std::string& customFilename) const;

    /**
     * @brief 从指定文件加载任务列表。
     * @param customFilename 源文件名。
     * @return 加载成功返回 true。
     */
    bool loadFromFile(const std::string& customFilename);

    // --- 查询函数 ---

    /**
     * @brief 获取当前任务总数。
     * @return 任务数量。
     */
    int getTaskCount() const;

    /**
     * @brief 检查列表是否为空。
     * @return 如果为空返回 true。
     */
    bool isEmpty() const;

    /**
     * @brief 获取指定索引的任务描述。
     * @param index 任务索引（从1开始）。
     * @return 任务描述字符串。
     */
    std::string getTask(int index) const;

    // --- 状态信息 ---

    /**
     * @brief 获取当前关联的文件名。
     * @return 文件名字符串。
     */
    std::string getFilename() const;

    /**
     * @brief 设置关联的文件名。
     * @param newFilename 新的文件名。
     */
    void setFilename(const std::string& newFilename);

    // --- 高级功能 ---

    /**
     * @brief 显示当前任务列表的统计信息（总数、文件、预览等）。
     */
    void displayStatistics() const;
};

#endif // TODOLIST_H
