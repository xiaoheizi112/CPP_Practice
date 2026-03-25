/**
 * @file todoList.cpp
 * @brief TodoList 类的实现文件。
 */

#include "TodoList.h"
#include <iostream>
#include <limits>
#include <algorithm>

/**
 * @brief 默认构造函数。
 * 默认使用 "todo_list.txt" 作为文件名，并自动加载已有任务。
 */
TodoList::TodoList() : filename("todo_list.txt") {
    // 构造对象时，尝试从默认文件加载之前保存的任务
    loadFromFile(); 
}

/**
 * @brief 带参数的构造函数。
 * @param file 初始化的文件名。
 */
TodoList::TodoList(const std::string& file) : filename(file) {
    // 使用用户指定的文件名，并尝试从中加载任务
    loadFromFile(); 
}

/**
 * @brief 添加新任务。
 * 如果任务字符串非空，则将其添加到任务向量中。
 * @param task 任务描述内容。
 */
void TodoList::addTask(const std::string& task) {
    // 检查输入的字符串是否为空（用户可能直接按了回车）
    if (!task.empty()) {
        // 如果不为空，就把它放到任务列表（tasks 向量）的末尾
        tasks.push_back(task);
        std::cout << "任务添加成功！" << std::endl;
    }
    else {
        // 如果为空，给出友情提示
        std::cout << "任务内容不能为空！" << std::endl;
    }
}

/**
 * @brief 查看所有任务。
 * 如果列表为空则提示，否则调用内部方法打印所有任务。
 */
void TodoList::viewTasks() const {
    // 先看看现在盒子里有没有任务
    if (tasks.empty()) {
        std::cout << "当前没有待办任务。" << std::endl;
        return;
    }

    // 打印一个漂亮的分隔线
    std::cout << "\n--- 当前待办任务 ---" << std::endl;
    // 调用私有的打印函数，把任务一个一个列出来
    displayTasksInternal();
    // 最后总结一下任务的总数量
    std::cout << "总计: " << tasks.size() << " 个任务" << std::endl;
}

/**
 * @brief 删除指定编号的任务。
 * @param taskNumber 用户看到的任务编号（从1开始）。
 */
void TodoList::deleteTask(int taskNumber) {
    // 没任务的时候，提示用户无法删除
    if (tasks.empty()) {
        std::cout << "当前没有可删除的任务。" << std::endl;
        return;
    }

    // 检查用户输入的编号是否在范围内（比如总共3个任务，输4就是无效的）
    if (isValidIndex(taskNumber)) {
        // 记录一下要删除的内容，方便一会儿告诉用户删掉了哪个
        std::string removedTask = tasks[taskNumber - 1];
        // 关键操作：使用 erase 函数从向量中移除该元素
        // 注意：用户输入的是从1开始的编号，而 C++ 索引是从0开始的，所以要减1
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "任务 \"" << removedTask << "\" 已删除。" << std::endl;
    }
    else {
        // 编号不对时，报错提示
        std::cout << "无效的任务编号！" << std::endl;
    }
}

/**
 * @brief 清空内存中的所有任务。
 */
void TodoList::clearAllTasks() {
    // 直接清空 tasks 向量，释放所有存储的任务
    tasks.clear();
    std::cout << "所有任务已清空。" << std::endl;
}

/**
 * @brief 保存到默认文件。
 * @return 成功返回 true。
 */
bool TodoList::saveToFile() const {
    // 调用带参数的保存函数，传入默认记录的文件名
    return saveToFile(filename);
}

/**
 * @brief 将任务持久化到指定文件。
 * @param customFilename 目标文件名。
 * @return 成功返回 true。
 */
bool TodoList::saveToFile(const std::string& customFilename) const {
    // 创建一个文件输出流对象，准备向文件写数据
    std::ofstream outputFile(customFilename);

    // 检查文件是否成功打开（可能是磁盘满了或者权限不足）
    if (!outputFile.is_open()) {
        std::cout << "错误：无法打开或创建文件 " << customFilename << "！" << std::endl;
        return false;
    }

    // 遍历任务列表，把每一个任务都写进文件里，每个占一行
    for (const auto& task : tasks) {
        outputFile << task << std::endl;
    }

    // 写完之后关闭文件，确保数据真正写入磁盘
    outputFile.close();
    std::cout << "成功保存 " << tasks.size() << " 个任务到文件: " << customFilename << std::endl;
    return true;
}

/**
 * @brief 从默认文件加载任务。
 * @return 成功返回 true。
 */
bool TodoList::loadFromFile() {
    // 调用带参数的加载函数，传入默认记录的文件名
    return loadFromFile(filename);
}

/**
 * @brief 从指定文件读取任务到内存。
 * 如果文件不存在，会提示并返回 false。
 * @param customFilename 源文件名。
 * @return 成功加载任务返回 true。
 */
bool TodoList::loadFromFile(const std::string& customFilename) {
    // 创建一个文件输入流对象，准备从文件读数据
    std::ifstream inputFile(customFilename);

    // 检查文件是否存在且能打开
    if (!inputFile.is_open()) {
        std::cout << "文件 " << customFilename << " 不存在或无法打开，将创建新文件。" << std::endl;
        return false;
    }

    // 准备一个临时的列表，防止加载失败导致原本的任务丢了
    std::vector<std::string> loadedTasks;
    std::string line;
    int loadedCount = 0;

    // 逐行读取文件内容，直到读完整个文件
    while (std::getline(inputFile, line)) {
        // 忽略空行
        if (!line.empty()) {
            loadedTasks.push_back(line);
            loadedCount++;
        }
    }

    // 读完后及时关闭文件
    inputFile.close();

    // 如果确实读到了任务，就用新加载的任务替换掉现在的任务列表
    if (loadedCount > 0) {
        tasks = loadedTasks; 
        filename = customFilename; // 更新一下当前使用的文件名
        std::cout << "从文件加载了 " << loadedCount << " 个任务。" << std::endl;
        return true;
    }

    return false;
}

/**
 * @brief 返回任务总数。
 */
int TodoList::getTaskCount() const {
    // 返回向量的大小，即任务的个数
    return static_cast<int>(tasks.size());
}

/**
 * @brief 检查任务列表是否为空。
 */
bool TodoList::isEmpty() const {
    // 使用向量自带的 empty 函数判断是否一个任务都没有
    return tasks.empty();
}

/**
 * @brief 获取指定索引的任务字符串。
 * @param index 任务编号（1-based）。
 * @return 任务内容或错误提示。
 */
std::string TodoList::getTask(int index) const {
    // 先验证编号是否合法
    if (isValidIndex(index)) {
        // 合法就返回对应索引的任务内容（注意索引要减1）
        return tasks[index - 1];
    }
    return "无效的任务索引";
}

/**
 * @brief 返回当前操作的文件名。
 */
std::string TodoList::getFilename() const {
    // 返回存储在成员变量中的文件名
    return filename;
}

/**
 * @brief 更新操作的文件名。
 */
void TodoList::setFilename(const std::string& newFilename) {
    // 修改成员变量的值，并通知用户
    filename = newFilename;
    std::cout << "文件名已更新为: " << filename << std::endl;
}

/**
 * @brief 打印任务统计信息。
 */
void TodoList::displayStatistics() const {
    // 打印一个精简的统计报表
    std::cout << "\n--- 统计信息 ---" << std::endl;
    std::cout << "任务总数: " << getTaskCount() << std::endl;
    std::cout << "存储文件: " << getFilename() << std::endl;
    std::cout << "是否为空: " << (isEmpty() ? "是" : "否") << std::endl;

    // 如果有任务，额外展示前几个，让用户心里有个数
    if (!isEmpty()) {
        std::cout << "前3个任务预览:" << std::endl;
        // 计算展示的数量，最多展示3个
        int displayCount = std::min(3, getTaskCount());
        for (int i = 1; i <= displayCount; ++i) {
            std::cout << "  " << i << ". " << getTask(i) << std::endl;
        }
    }
}

/**
 * @brief 检查用户输入的编号是否在有效范围内。
 * @param index 1-based 编号。
 */
bool TodoList::isValidIndex(int index) const {
    // 编号必须大于等于1，且小于等于当前任务的总数
    return (index >= 1 && index <= static_cast<int>(tasks.size()));
}

/**
 * @brief 遍历并打印所有任务。
 */
void TodoList::displayTasksInternal() const {
    // 使用普通的 for 循环遍历向量中的每一个字符串并打印
    for (size_t i = 0; i < tasks.size(); ++i) {
        // 打印格式为：编号. 任务内容
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}
