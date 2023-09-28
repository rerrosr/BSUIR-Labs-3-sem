#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

#ifndef UNTITLED1_FUNCT_H
#define UNTITLED1_FUNCT_H

class Task{
public:
    Task operator+(const Task& other) const{
        Task result(*this);
        result.text += other.text;
        return result;
    }

    Task& operator+=(const Task& other) {
        text += other.text;
        return *this;
    }

    Task operator-(const Task& other) const {
        Task result(*this);
        size_t pos = result.text.find(other.text);
        if (pos != std::string::npos) {
            result.text.erase(pos, other.text.length());
        }
        return result;
}
    Task& operator-=(const Task& other) {
        size_t pos = text.find(other.text);
        if (pos != std::string::npos) {
            text.erase(pos, other.text.length());
        }
        return *this;
    }

    // Overload the equality operator to compare tasks
    bool operator==(const Task& other) const {
        return (text == other.text) && (completed == other.completed) && (data == other.data);
    }

    // Overload the inequality operator to compare tasks
    bool operator!=(const Task& other) const {
        return !(*this == other);
    }

    // Overload the less-than operator to compare tasks lexicographically by text
    bool operator<(const Task& other) const {
        return text < other.text;
    }

    // Overload the greater-than operator to compare tasks lexicographically by text
    bool operator>(const Task& other) const {
        return text > other.text;
    }

    // Overload the less-than-or-equal-to operator to compare tasks lexicographically by text
    bool operator<=(const Task& other) const {
        return text <= other.text;
    }

    // Overload the greater-than-or-equal-to operator to compare tasks lexicographically by text
    bool operator>=(const Task& other) const {
        return text >= other.text;
    }

    // Overload the equality operator to compare a Task with a time_t
    bool operator==(const std::time_t& otherTime) const {
        return data == otherTime;
    }

    // Overload the inequality operator to compare a Task with a time_t
    bool operator!=(const std::time_t& otherTime) const {
        return data != otherTime;
    }

    // Overload the less-than operator to compare a Task with a time_t
    bool operator<(const std::time_t& otherTime) const {
        return data < otherTime;
    }

    // Overload the greater-than operator to compare a Task with a time_t
    bool operator>(const std::time_t& otherTime) const {
        return data > otherTime;
    }

    // Overload the less-than-or-equal-to operator to compare a Task with a time_t
    bool operator<=(const std::time_t& otherTime) const {
        return data <= otherTime;
    }

    // Overload the greater-than-or-equal-to operator to compare a Task with a time_t
    bool operator>=(const std::time_t& otherTime) const {
        return data >= otherTime;
    }


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

    void setData(std::time_t newData){
        data = newData;
    }

    void setText(const std::string& newText){
        text = newText;
    }

    friend std::ostream& operator<<(std::ostream& os, const Task& task);
    friend std::istream& operator>>(std::istream& is, Task& task);

private:
    bool completed;
    std::string text;
    std::time_t data;
};

void addTask(std::vector<Task>& tasks);
void removeUncompleted(std::vector<Task>& tasks);
void listTasks(const std::vector<Task>& tasks);
void markTaskCompleted(std::vector<Task>& tasks, size_t index);
void removeTask(std::vector<Task>& tasks, size_t index);
void editTask(Task& task);
void autoTask();
std::ostream& operator<<(std::ostream& os, const Task& task);
std::istream& operator>>(std::istream& is, Task& task);


#endif //UNTITLED1_FUNCT_H
