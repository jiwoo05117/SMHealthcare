//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    loadExercises(EXERCISEFILEPATH);
    loadDiets(DIETFILEPATH);

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	// Check if the user has reached their daily calorie goal (sum of calories burned + intake)
    	if (health_data.total_calories_burned + health_data.total_calories_intake >= DAILY_CALORIE_GOAL){
    		 // If the calorie goal has been reached, print a message and prevent further actions
            printf("You have consumed all your calories for today \n");
		} 
		else{
			// Otherwise, show the system menu options
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice); // Take user input for the menu choice
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	// If user chooses "1", input exercise data (calories burned) into the health data
            	inputExercise(&health_data);
                break;
                
            case 2:// If user chooses "2", input diet data (calories intake) into the health data
            	inputDiet(&health_data);
                break;
                
            case 3: // If user chooses "3", print the logged health data (exercise, diet, calories)
            	printHealthData(&health_data);
                break;
            
            case 4:
            	// If user chooses "4", exit the system
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while (choice != 4);// Keep looping until the user chooses option 4 (Exit)

    return 0;// Program ends, returning 0 to indicate successful execution
}
