
// Displays the menu
void displayMenu()
{
    cout << "\n===== To-Do List Menu =====\n";
    cout << "1. View Tasks\n";
    cout << "2. Add Task\n";
    cout << "3. Complete Task\n";
    cout << "4. Remove Task\n";
    cout << "5. Modify Task\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Displays all tasks
void viewTasks(const Task tasks[], int taskCount)
{
    if (taskCount == 0)
    {
        cout << "\nThere are no tasks.\n";
        return;
    }

    cout << "\n===== Tasks =====\n";

    for (int i = 0; i < taskCount; i++)
    {
        cout << i + 1 << ". ";
        cout << tasks[i].taskName;
        cout << " | Priority: " << tasks[i].priority;
        cout << " | Deadline: " << tasks[i].deadline;
        cout << " | Status: ";

        if (tasks[i].isCompleted)
        {
            cout << "Complete";
        }
        else
        {
            cout << "Incomplete";
        }

        cout << endl;
    }
}

// Adds a new task
void addTask(Task tasks[], int& taskCount)
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "The task list is full.\n";
        return;
    }

    cout << "\nEnter task name: ";
    cin >> tasks[taskCount].taskName;

    cout << "Enter priority: ";
    cin >> tasks[taskCount].priority;

    cout << "Enter deadline: ";
    cin >> tasks[taskCount].deadline;

    tasks[taskCount].isCompleted = false;
    taskCount++;

    cout << "Task added successfully.\n";
}

// Marks a task as complete
void completeTask(Task tasks[], int taskCount)
{
    if (taskCount == 0)
    {
        cout << "There are no tasks to complete.\n";
        return;
    }

    viewTasks(tasks, taskCount);

    int taskNumber = getTaskNumber(taskCount);

    if (taskNumber == -1)
    {
        return;
    }

    tasks[taskNumber - 1].isCompleted = true;

    cout << "Task marked as complete.\n";
}

// Removes a task
void removeTask(Task tasks[], int& taskCount)
{
    if (taskCount == 0)
    {
        cout << "There are no tasks to remove.\n";
        return;
    }

    viewTasks(tasks, taskCount);

    int taskNumber = getTaskNumber(taskCount);

    if (taskNumber == -1)
    {
        return;
    }

    int index = taskNumber - 1;

    // Shift tasks to the left
    for (int i = index; i < taskCount - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    taskCount--;

    cout << "Task removed successfully.\n";
}

// Modifies an existing task
void modifyTask(Task tasks[], int taskCount)
{
    if (taskCount == 0)
    {
        cout << "There are no tasks to modify.\n";
        return;
    }

    viewTasks(tasks, taskCount);

    int taskNumber = getTaskNumber(taskCount);

    if (taskNumber == -1)
    {
        return;
    }

    int index = taskNumber - 1;

    cout << "\nEnter the new task name: ";
    cin >> tasks[index].taskName;

    cout << "Enter the new priority: ";
    cin >> tasks[index].priority;

    cout << "Enter the new deadline: ";
    cin >> tasks[index].deadline;

    cout << "Task modified successfully.\n";
}

// Gets and validates a task number
int getTaskNumber(int taskCount)
{
    int taskNumber;

    cout << "Enter the task number: ";

    while (!(cin >> taskNumber))
    {
        cout << "Please enter a valid number: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    if (taskNumber < 1 || taskNumber > taskCount)
    {
        cout << "Invalid task number.\n";
        return -1;
    }

    return taskNumber;
}
