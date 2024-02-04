#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() {
        cout << "Task List:" << endl;
        cout << setw(4) << "No." << setw(25) << "Description" << setw(15) << "Status" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << setw(4) << i + 1 << setw(25) << tasks[i].description;
            if (tasks[i].completed) {
                cout << setw(15) << "Completed" << endl;
            } else {
                cout << setw(15) << "Pending" << endl;
            }
        }
    }

    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].completed = true;
            cout << "Task marked as completed: " << tasks[taskIndex].description << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            cout << "Task removed: " << tasks[taskIndex].description << endl;
            tasks.erase(tasks.begin() + taskIndex);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    ToDoList todo;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                todo.addTask(taskDescription);
                break;
            }
            case 2:
                todo.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                todo.markTaskCompleted(taskIndex - 1); 
                break;
            }
            case 4: {
                size_t taskIndex;
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                todo.removeTask(taskIndex - 1);
                break;
            }
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
