#include "funct.h"

void addTask(std::vector<Task>& tasks){
    std::string text;
    std::cin.ignore();
    std::cout << "Enter task text:";
    std::getline(std::cin, text);
    if (text.empty()){
        std::cout << "Try again" << std::endl;
        return;
    }
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

void removeTask(std::vector<Task>& tasks, size_t index){
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task removed successfully." << std::endl;
    } else {
        std::cout << "Invalid task number" << std::endl;
    }
}

void editTask(Task& task){
    std::cout << "Editing task: " << task.getText() << std::endl;
    std::cout << "Enter new task text: ";
    std::string newText;
    std::cin.ignore();
    std::getline(std::cin, newText);
    if (!newText.empty()) {
        task.setText(newText);
        task.setData(std::time(nullptr)); // Обновляем дату и время при изменении задачи
        std::cout << "Task updated successfully." << std::endl;
    } else {
        std::cout << "Task text cannot be empty. Task not updated." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Task& task){
    os << "Task text:" << task.text << std::endl;
    os << "Date and time:" << std::asctime(std::localtime(&task.data));
    os << "Completed:" << (task.isCompleted() ? "Yes" : "No");
    return os;
}
std::istream& operator>>(std::istream& is, Task& task){
    std::string text;
    std::cout<< "Enter task text: ";
    is.ignore();
    std::getline(is, text);
    if (text.empty()){
        std::cout << "Try again" << std::endl;
        return is;
    }
    task.text = text;
    task.data = std::time(nullptr);
    task.completed = false;
    return is;
}

