/**
 * @file TodoManager.cpp
 * @brief TodoManager 类的实现文件，包含程序的主循环和用户交互逻辑。
 */

#include "TodoManager.h"
#include <iostream>
#include <limits>
#include <fstream>

/**
 * @brief 构造函数。
 * 初始化 TodoList 实例，使用 unique_ptr 进行内存管理。
 */
TodoManager::TodoManager() : todoList(std::make_unique<TodoList>()) {
    // 构造时创建一个 TodoList 的实例，并由智能指针管理内存
}

/**
 * @brief 启动程序。
 * 显示欢迎界面并进入主菜单循环。
 */
void TodoManager::run() {
    // 打印程序启动时的欢迎信息
    std::cout << "=== 待办事项列表 ===" << std::endl;
    // 提示用户当前正在操作哪一个数据文件
    std::cout << "当前文件: " << todoList->getFilename() << std::endl;

    // 进入核心的主菜单处理函数
    handleMainMenu();
}

/**
 * @brief 打印主菜单。
 */
void TodoManager::printMainMenu() const {
    // 列出主菜单的所有可用选项
    std::cout << "\n--- 主菜单 ---" << std::endl;
    std::cout << "1. 添加任务" << std::endl;
    std::cout << "2. 查看任务" << std::endl;
    std::cout << "3. 删除任务" << std::endl;
    std::cout << "4. 文件操作" << std::endl;
    std::cout << "5. 统计信息" << std::endl;
    std::cout << "6. 清空所有任务" << std::endl;
    std::cout << "7. 退出程序" << std::endl;
    std::cout << "请选择操作 (1-7): ";
}

/**
 * @brief 打印文件操作子菜单。
 */
void TodoManager::printFileMenu() const {
    // 列出文件管理子菜单的所有可用选项
    std::cout << "\n--- 文件操作 ---" << std::endl;
    std::cout << "1. 保存到文件" << std::endl;
    std::cout << "2. 从文件加载" << std::endl;
    std::cout << "3. 查看文件内容" << std::endl;
    std::cout << "4. 更改文件名" << std::endl;
    std::cout << "5. 返回主菜单" << std::endl;
    std::cout << "请选择操作 (1-5): ";
}

/**
 * @brief 主菜单逻辑处理。
 * 使用 do-while 循环维持程序运行，直到用户选择退出。
 */
void TodoManager::handleMainMenu() {
    int choice = 0;

    do {
        // 先显示菜单
        printMainMenu();
        // 获取用户输入，并进行错误处理（比如用户输了字母而不是数字）
        if (!(std::cin >> choice)) {
            // 如果输入不是数字，清除错误标记
            std::cin.clear();
            // 扔掉输入缓冲区里剩下的非法字符
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效，请输入数字！" << std::endl;
            continue; // 重新开始循环
        }
        // 吃掉输入数字后剩下的回车符
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // 根据用户的选择执行相应的功能
        switch (choice) {
        case 1:
            handleAddTask(); // 添加任务
            break;
        case 2:
            todoList->viewTasks(); // 显示所有任务
            break;
        case 3:
            handleDeleteTask(); // 删除任务
            break;
        case 4:
            handleFileMenu(); // 进入文件操作子菜单
            break;
        case 5:
            todoList->displayStatistics(); // 显示统计信息
            break;
        case 6:
            todoList->clearAllTasks(); // 全部清空
            break;
        case 7:
            // 退出程序前的告别语
            std::cout << "感谢使用待办事项列表，再见！" << std::endl;
            break;
        default:
            // 处理不在 1-7 范围内的数字
            std::cout << "无效选项，请重试。" << std::endl;
        }
    } while (choice != 7); // 只要不是选 7，就一直循环
}

/**
 * @brief 文件操作菜单逻辑处理。
 */
void TodoManager::handleFileMenu() {
    int fileChoice = 0;

    do {
        // 显示子菜单
        printFileMenu();
        // 同样进行输入有效性检查
        if (!(std::cin >> fileChoice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效，请输入数字！" << std::endl;
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (fileChoice) {
        case 1:
            handleSaveToFile(); // 保存
            break;
        case 2:
            handleLoadFromFile(); // 加载
            break;
        case 3:
            handleViewFileContent(); // 查看原始内容
            break;
        case 4:
        {
            // 修改文件名的交互逻辑
            std::string newFilename;
            std::cout << "请输入新的文件名: ";
            std::getline(std::cin, newFilename);
            todoList->setFilename(newFilename);
        }
        break;
        case 5:
            // 退出子菜单
            std::cout << "返回主菜单..." << std::endl;
            break;
        default:
            std::cout << "无效选项，请重试。" << std::endl;
        }
    } while (fileChoice != 5); // 只要不是选 5，就一直循环
}

/**
 * @brief 处理添加任务的交互。
 */
void TodoManager::handleAddTask() {
    std::string task;
    std::cout << "请输入任务: ";
    // 获取用户输入的整行文字（包含空格）
    std::getline(std::cin, task);
    // 指挥 todoList 把这个任务加进去
    todoList->addTask(task);

    // 贴心小功能：如果任务加成功了，问问要不要立即存到硬盘上
    if (!task.empty()) {
        char autoSave;
        std::cout << "是否立即保存到文件？(y/n): ";
        std::cin >> autoSave;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (autoSave == 'y' || autoSave == 'Y') {
            todoList->saveToFile(); // 执行保存
        }
    }
}

/**
 * @brief 处理删除任务的交互。
 */
void TodoManager::handleDeleteTask() {
    // 先把现有的任务列出来，方便用户看编号
    todoList->viewTasks();
    // 只有在列表不为空的时候才需要输入编号
    if (!todoList->isEmpty()) {
        int taskNumber;
        std::cout << "请输入要删除的任务编号: ";
        // 输入检查
        if (!(std::cin >> taskNumber)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效，请输入数字！" << std::endl;
            return;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // 执行删除指令
        todoList->deleteTask(taskNumber);
    }
}

/**
 * @brief 处理保存文件的交互。
 */
void TodoManager::handleSaveToFile() {
    char choice;
    // 询问用户是否存到默认的文件里
    std::cout << "保存到默认文件 " << todoList->getFilename() << "？(y/n): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 'y' || choice == 'Y') {
        // 使用默认文件名保存
        todoList->saveToFile();
    }
    else {
        // 如果用户想换个名字存，比如存成备份文件
        std::string customFilename;
        std::cout << "请输入自定义文件名: ";
        std::getline(std::cin, customFilename);
        todoList->saveToFile(customFilename);
    }
}

/**
 * @brief 处理加载文件的交互。
 */
void TodoManager::handleLoadFromFile() {
    char choice;
    // 询问用户是否从默认文件加载
    std::cout << "从默认文件 " << todoList->getFilename() << " 加载？(y/n): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 'y' || choice == 'Y') {
        // 从默认文件加载
        todoList->loadFromFile();
    }
    else {
        // 或者从用户指定的另一个文件加载
        std::string customFilename;
        std::cout << "请输入要加载的文件名: ";
        std::getline(std::cin, customFilename);
        todoList->loadFromFile(customFilename);
    }
}

/**
 * @brief 查看文件的原始文本内容。
 */
void TodoManager::handleViewFileContent() const {
    // 获取当前正在用的文件名
    std::string filename = todoList->getFilename();
    // 创建文件流读取文件
    std::ifstream file(filename);

    // 如果文件能打开
    if (file.is_open()) {
        std::cout << "\n--- 文件内容 (" << filename << ") ---" << std::endl;
        std::string line;
        int lineNum = 1;
        // 循环读取每一行并直接打印在屏幕上
        while (std::getline(file, line)) {
            std::cout << lineNum << ". " << line << std::endl;
            lineNum++;
        }
        file.close(); // 读完记得关掉
    }
    else {
        // 如果文件不存在或者被其他程序占用了
        std::cout << "文件不存在或无法打开！" << std::endl;
    }
}
