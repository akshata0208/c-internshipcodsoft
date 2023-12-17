#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function prototypes
void addTask(vector<Task> &tasks, const string &description);
void viewTasks(const vector<Task> &tasks);
void markCompleted(vector<Task> &tasks, int index);
void removeTask(vector<Task> &tasks, int index);

int main() {
    vector<Task> tasks;

    cout << "Simple To-Do List Manager\n";

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter the task description: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markCompleted(tasks, index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}

void addTask(vector<Task> &tasks, const string &description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
    } else {
        cout << setw(5) << "Index" << setw(25) << "Description" << setw(15) << "Status" << endl;
        cout << "------------------------------------------\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << setw(5) << i << setw(25) << tasks[i].description << setw(15)
                 << (tasks[i].completed ? "Completed" : "Pending") << endl;
        }
    }
}

void markCompleted(vector<Task> &tasks, int index) {
    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        tasks[index].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

void removeTask(vector<Task> &tasks, int index) {
    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid index.\n";
    }
}





