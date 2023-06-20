#include  <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "exe.h"

#define ASCII_OFFSET 32

int main(){
	 
	srand(time(NULL)); //for seed
	char choice; 
	int flag = 1; //while flag
	
	do{
		//menu 
		printf("Please choose one of the following options: \n");
		printf("S/s - Biggest Matrix Sum\n");
		printf("C/c -  Color Game\n");
		printf("E/e -  Quit\n");
		//scan choice 
		scanf("%c", &choice);
		//buffer clean
		getchar(); 

		//turns the input char into Capital Letter
		if ( (choice >= 'a') && (choice <= 'z')) choice -= ASCII_OFFSET;
	 
	 	switch(choice){
	 		//Question 1 - Biggest Matrix Sum
			case 'S':
				q1();
				break;
			//Question 2 - Color game
			case 'C':
				q2();
				break;		
			//exit
			case 'E':
				flag = 0;
				printf("Thank you, bye bye!\n");
				break;
			//anything else
			default:
				printf("Wrong input, Please try again: \n");
				break;				
			}
	}while(flag);
	
	return 0;
}
