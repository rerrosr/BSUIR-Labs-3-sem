#include "funct.h"

int main() {
    std::vector<Task> tasks;

    int choice;
    do {
        std::cout << "Menu:\n" << std::endl
                  << "1. Add a task" << std::endl
                  << "2. Delete uncompleted tasks" << std::endl
                  << "3. Show tasks" << std::endl
                  << "4. Mark a task as completed" << std::endl
                  << "5. Remove a task" << std::endl
                  << "6. Edit a task" << std::endl
                  << "0. Exit" << std::endl
                  << "Choose: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                removeUncompleted(tasks);
                break;
            case 3:
                listTasks(tasks);
                break;
            case 4: {
                size_t index;
                std::cout << "Enter task number: ";
                std::cin >> index;
                markTaskCompleted(tasks, index);
                break;
            }
            case 5: {
                size_t index;
                std:: cout << "Enter task number to remove:";
                std::cin >> index;
                removeTask(tasks,index);
                break;
            }
            case 6: {
                size_t index;
                std::cout << "Enter task number to edit: ";
                std::cin >> index;
                if (index > 0 && index <=tasks.size()) {
                    editTask(tasks[index - 1]);
                }
                else {
                    std::cout << "Invalid task number" << std::endl;
                }
                break;
            }
            case 0:
                std::cout << "Program finished." << std::endl;
                break;
            default:
                std::cout << "Try again" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
