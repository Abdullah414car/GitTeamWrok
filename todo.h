#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Maximum number of tasks the program can store
const int MAX_TASKS = 100;

// Struct definition
struct Task
{
    string taskName;
    string priority;
    string deadline;
    bool isCompleted;
};

// Function prototypes
void displayMenu();
void viewTasks(const Task tasks[], int taskCount);
void addTask(Task tasks[], int& taskCount);
void completeTask(Task tasks[], int taskCount);
void removeTask(Task tasks[], int& taskCount);
void modifyTask(Task tasks[], int taskCount);
int getTaskNumber(int taskCount);
