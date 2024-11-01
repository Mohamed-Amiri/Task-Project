#include <stdio.h> 
#include <string.h>

#define MAX_TASKS 100

struct Task {
    char title[50];
    char description[100];
    char date[11];
    char priority[10];
    char isCompleted;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void addTask() { 
    if (taskCount < MAX_TASKS) { 
        struct Task newTask;
        printf("\n--- Adding a New Task ---\n");

        printf("Enter task title: \n");
        getchar(); 
        scanf("%[^\n]s", newTask.title);

        printf("Enter task description: \n");
        getchar(); 
        scanf("%[^\n]s", newTask.description);

        int day, month, year;
        while (1) {
            printf("Enter task due date (DD-MM-YYYY): \n");
            scanf("%s", newTask.date);

            if (sscanf(newTask.date, "%d-%d-%d", &day, &month, &year) == 3) {
                if (day >= 1 && day <= 31 && month <= 12 && day >= 1 && day <= 31) {
                    break; 
                } else {
                    printf("Invalid date. Please enter a valid date (DD-MM-YYYY).\n");
                }
            } else {
                printf("Invalid date format. Please enter date in format (DD-MM-YYYY).\n");
            }

            while (getchar() != '\n');
        }

        while (1) {
            printf("Enter task priority (High/Low): \n");
            scanf("%s", newTask.priority);
            if (strcmp(newTask.priority, "High") == 0 || strcmp(newTask.priority, "Low") == 0) {
                break; 
            } else {
                printf("Invalid priority. Please enter either 'High' or 'Low'.\n");
                while (getchar() != '\n'); 
            }
        }

        tasks[taskCount] = newTask;  
        taskCount++;  
        printf("Task added successfully!\n");
    } else {
        printf("Task limit reached.\n");
    }
}

void displayTasks() {
    printf("\n----- Task List -----\n");
    if (taskCount == 0) {
        printf("No tasks available.\n");
    } else {
        for (int i = 0; i < taskCount; i++) {
            printf("\n- - - - - - - - - - - - - - -\n");
            printf("Task %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Date: %s\n", tasks[i].date);
            printf("Priority: %s\n", tasks[i].priority);
        }
        printf("\n- - - - - - - - - - - - - - -\n");
    }
}

void filterTasks() {
    char filterPriority[10];
    printf("\n--- Filtering Tasks by Priority ---\n");
    printf("Enter priority to filter by (High/Low): ");
    getchar(); 
    scanf("%[^\n]s", filterPriority); 

    printf("\n------- Filtered Task List (Priority: %s) -------\n", filterPriority);
    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].priority, filterPriority) == 0) {
            printf("\n- - - - - - - - - - - - - - -\n");
            printf("Task %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Date: %s\n", tasks[i].date);
            printf("Priority: %s\n", tasks[i].priority);
            found = 1;
        }
    }

    if (!found) {
        printf("No tasks found with priority: %s\n", filterPriority);
    }
    printf("\n- - - - - - - - - - - - - - -\n");
}

void editTask() {
    int taskIndex;
    printf("\n--- Editing a Task ---\n");
    printf("Enter the task number to edit (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);
    taskIndex--;  

    if (taskIndex >= 0 && taskIndex < taskCount) {
        getchar(); 

        printf("Enter new Title: ");
        scanf("%[^\n]s", tasks[taskIndex].title);
        getchar(); 

        printf("Enter new description: ");
        scanf("%[^\n]s", tasks[taskIndex].description);
        getchar(); 

        printf("Enter new due date (DD-MM-YYYY): ");
        scanf("%s", tasks[taskIndex].date);
        getchar(); 

        printf("Enter new priority (High/Low): ");
        scanf("%s", tasks[taskIndex].priority);
        getchar(); 

        printf("Task updated successfully!\n");
    } else {
        printf("Task not found.\n");
    }
}


void deleteTask() {
    int taskIndex;
    printf("\n--- Deleting a Task ---\n");
    printf("Enter the task number to delete (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);
    taskIndex--;  

    if (taskIndex >= 0 && taskIndex < taskCount) {
        for (int i = taskIndex; i < taskCount - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        printf("Task deleted successfully.\n");
    } else {
        printf("Task not found.\n");
    }
}

void displayMenu() {
    printf("\n_______ Main Menu _______\n");
    printf("\n");
    printf("1. Add Task\n");
    printf("2. Display Tasks\n");
    printf("3. Filter Tasks\n"); 
    printf("4. Edit Task\n");
    printf("5. Delete Task\n");
    printf("0. Exit\n");
    printf("\n");
    printf("---- Choose an option: ----\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                filterTasks(); 
                break;
            case 4:
                editTask();
                break;
            case 5:
                deleteTask();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

