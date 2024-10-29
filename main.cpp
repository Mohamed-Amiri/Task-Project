#include <stdio.h>
#include <stdlib.h>
#include <string.h>yi

#define MAX_TASKS 100

struct Task {
	char title [50];
	char description[100];
	char duedate[11];
	char priotity[10];
	char isCompleted;
};
void displayMenu(){
	printf("1. Add Task \n");
	printf("2. Dissplay Task \n");
	printf("3. Edit Task \n");
	printf("4. Delet Task \n");
	printf("5. Filter Task \n");
	
}
 
void addTask(struct Task Tasks [] , int *taskCount ) {
	if (*taskCount >= MAX_TASKS){
		printf("Task limit reached. \n");
		return;
	}
	  printf("Enter task title : ");
	fgets(Tasks[*taskCount].title, sizeof(Tasks[*taskCount].title), stdin);
	  printf("Enter task description : ");
	fgets(Tasks[*taskCount].description, sizeof(Tasks[*taskCount].description), stdin);
	  printf("Enter due date (YY_MM_DD) : ");
	fgets(Tasks[*taskCount].duedate, sizeof(Tasks[*taskCount].duedate), stdin);
	  printf("Enter priotity (High/Low) : ");
	fgets(Tasks[*taskCount].priotity, sizeof(Tasks[*taskCount].priotity), stdin);
	
	Tasks[*taskCount].isCompleted = 0 ;
	(*taskCount)++;
	printf("Task added successfully ! \n");
}








int main() {
   
   struct Task  tasks[MAX_TASKS];
          int taskCount = 0;
    
     while (1) {
    	displayMenu();
    	
    	int choice ;
    	scanf("%d", &choice);
    	 
    	 
    	 
    	switch (choice){
    		case 1 : 
    		addTask(tasks, &taskCount);
    		break;
    		case 2 : 
    		displayTasks(tasks, &taskCount);
    		break;
    		case 3;
    	    EdittingTask(tasks, &taskCount);
    	    break;
    	    case 4;
    	    DeletingTask(tasks, &taskCount);
    	    break;
    	    case 5;
    	    FeltringTask(tasks, &taskCount);
    	     
    	     return 0;
    	 default : 
    	 printf("Invalid choice Please try again \n");
    		
   
    		
    		
    	}
    }
    		
		
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	
    	

    
    
    
    
    
    
    
    return 0;
}








