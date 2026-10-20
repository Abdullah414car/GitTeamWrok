int main()
{
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    // Open the input file
    ifstream inputFile("tasks.txt");

    if (!inputFile)
    {
        cout << "Error: Could not open tasks.txt.\n";
    }
    else
    {
        // Read task name, priority, and deadline from each line
        while (taskCount < MAX_TASKS &&
            inputFile >> tasks[taskCount].taskName
            >> tasks[taskCount].priority
            >> tasks[taskCount].deadline)
        {
            // Every task starts as incomplete
            tasks[taskCount].isCompleted = false;
            taskCount++;
        }

        inputFile.close();
    }

    // Menu loop
    do
    {
        displayMenu();

        while (!(cin >> choice))
        {
            cout << "Please enter a number from 1 to 6: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (choice)
        {
        case 1:
            viewTasks(tasks, taskCount);
            break;

        case 2:
            addTask(tasks, taskCount);
            break;

        case 3:
            completeTask(tasks, taskCount);
            break;

        case 4:
            removeTask(tasks, taskCount);
            break;

        case 5:
            modifyTask(tasks, taskCount);
            break;

        case 6:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid menu choice.\n";
        }

    } while (choice != 6);

    return 0;
}
