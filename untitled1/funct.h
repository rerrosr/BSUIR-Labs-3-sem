#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

#ifndef UNTITLED1_FUNCT_H
#define UNTITLED1_FUNCT_H

class Task{
public:
    Task(std::string& text) : text(text), completed(false){
        data = std::time(nullptr);
    }

    void markCompleted(){
        completed = true;
    };

    bool isCompleted() const {
        return completed;
    }

    std::string getText() const {
        return text;
    }

    std::time_t getData() const {
        return data;
    }

private:
    bool completed;
    std::string text;
    std::time_t data;
};

void addTask(std::vector<Task>& tasks);
void removeUncompleted(std::vector<Task>& tasks);
void listTasks(const std::vector<Task>& tasks);
void markTaskCompleted(std::vector<Task>& tasks, size_t index);

#endif //UNTITLED1_FUNCT_H
