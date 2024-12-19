//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;



//description : read the information in "diets.txt"
void loadDiets(const char* DIETFILEPATH) {
	FILE*file;
	
	file = fopen(DIETFILEPATH, "r"); //open file
	//Print an error message if the file cannot be opened
	if (file == NULL) {
		printf("Unable to open the file\n");
		return; 
	}

    
     // ToCode: to read a list of the diets from the given file 
	 while (fscanf(file, "%s %d", diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) == 2) {// Reads the food name and calorie value from each line using fscanf
        // Check if the diet list is full
        if (diet_list_size >= MAX_DIETS){
        	break;
		}
		diet_list_size++; // Increases the size of the diet list
    }

    fclose(file); //close file
} 

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    for (i = 0; i < diet_list_size; i++) {
    	// Prints the number, food name, and calorie of each diet item
        printf("%d. %s - %d kcal\n", i + 1, diet_list[i].food_name, diet_list[i].calories_intake);
    }
    
	// ToCode: to enter the diet to be chosen with exit option
   printf("Enter the number of the diet you want to choose: ");
   scanf("%d", &choice);
    
    // Exit condition
    // If the choice is 0, exit
    if (choice == 0) {
        printf("Exiting the diet selection.\n");
        return;
    }
    // Print an error message if an invalid choice is entered
    if (choice < 1 || choice > diet_list_size) {
        printf("Invalid choice. Please try again.\n");
        return;
    }

    // ToCode: to enter the selected diet in the health data
    health_data->diet[health_data->diet_count] = diet_list[choice - 1];
    health_data->diet_count++; // Increase the count of the number of diets


    // ToCode: to enter the total calories intake in the health data
    health_data->total_calories_intake += diet_list[choice - 1].calories_intake;
}
