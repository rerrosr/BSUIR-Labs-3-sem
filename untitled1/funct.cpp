#include "funct.h"

void addTask(std::vector<Task>& tasks){
    std::string text;
    std::cin.ignore();
    std::cout << "Enter task text:";
    std::getline(std::cin, text);
    tasks.push_back(Task(text));
}

void removeUncompleted(std::vector<Task>& tasks) {
    std::time_t currentTime = std::time(nullptr);
    std::vector<Task>::iterator it = tasks.begin();

    while (it != tasks.end()) {
        const Task& task = *it;

        if (!task.isCompleted() && task.getData() < currentTime) {
            it = tasks.erase(it);
        } else {
            ++it;
        }
    }
    std::cout << "Uncompleted tasks deleted" << std::endl;
}

void listTasks(const std::vector<Task>& tasks) {
    for (const Task& task : tasks) {
        std::cout << "Task: " << task.getText() << std::endl;
        std::time_t taskTime = task.getData();
        std::cout << "Date and Time: " << std::asctime(std::localtime(&taskTime)) << std::endl;
        std::cout << "Completed: " << (task.isCompleted() ? "Yes" : "No") << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
}

void markTaskCompleted(std::vector<Task>& tasks, size_t index){
    if (index > 0 && index <= tasks.size()){
        tasks[index - 1].markCompleted();
    } else {
        std::cout << "Invalid task number" << std::endl;
    }
}
