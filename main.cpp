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

        printf("Enter task title: \n");
        scanf("%s", newTask.title);

        printf("Enter task description: \n");
        scanf("%s", newTask.description);

        printf("Enter task due date (YYYY-MM-DD): \n");
        scanf("%s", newTask.date);

        printf("Enter task priority (High/Low): \n");
        scanf("%s", newTask.priority);

        tasks[taskCount] = newTask;  
        taskCount++;  
        printf("Task added successfully!\n");
    } else {
        printf("Task limit reached.\n");
    }
}

void displayTasks() {
    printf("\n--- Task List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Title: %s, Description: %s, Date: %s, Priority: %s\n",
               tasks[i].title, tasks[i].description, tasks[i].date, tasks[i].priority);
    }
}

void editTask() {
    int taskIndex;
    printf("Enter the task number to edit (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);
    taskIndex--;  

    if (taskIndex >= 0 && taskIndex < taskCount) {
        printf("Enter new description: ");
        scanf("%s", tasks[taskIndex].description);

        printf("Enter new due date (YYYY-MM-DD): ");
        scanf("%s", tasks[taskIndex].date);

        printf("Enter new priority (High/Low): ");
        scanf("%s", tasks[taskIndex].priority);

        printf("Task updated successfully!\n");
    } else {
        printf("Task not found.\n");
    }
}

void deleteTask() {
    int taskIndex;
    printf("Enter the task number to delete (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);
    taskIndex--;  // Adjust for zero-based index

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
    printf("\n--- Main Menu ---\n");
    printf("1. Add Task\n");
    printf("2. Display Tasks\n");
    printf("3. Edit Task\n");
    printf("4. Delete Task\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
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
                editTask();
                break;
            case 4:
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










    	
    	
    	
    	
    	
    	
    	

    
    
    
    
    
    
    










