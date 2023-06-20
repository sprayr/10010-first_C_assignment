#include <stdio.h>
#include <stdlib.h>
#include "matfunctions.h" 


#define ROWS 10
#define COLS 10
#define MAT_INIT 0
#define COLOR 4
#define COLOR_MAT_COLS 2




//######################## Tries to expand the color for the current turn and returns the amount of the colored cells at this turn ########################// 
//mat - matrix
//rows, cols - matrix dimentions
//rowIndex, colIndex - the startValues color 
//color - the color expanding
//turn - the current turn

int expandColor(int* mat, int rows, int cols, int rowIndex, int colIndex, int color, int turn){
	int counter=0;
	for(int i = rowIndex - turn ; i <= rowIndex + turn ; i++){
		for(int j = colIndex - turn ; j <= colIndex + turn ; j++){
			if( i >= 0 && j >= 0 && i < rows && j < cols) {
				if(*(mat+i*cols+j)==0){
					*(mat+i*cols+j)=color;
					counter++;
				}
			}
		} 
	}
	return counter;

}

//######################## coloring the board ########################// 
//mat - matrix
//rows, cols - matrix dimentions
//colorsNumber - the number of colors in game
//startValues - matrix that holds the start point of each color

void colorTheBoard(int* mat, int rows, int cols, int colorsNumber, const int* startValues){
	int turn = 0;
	int counter;  //counts how many cells have been colored each turn
	
	//runs while the board is not full
	do{
		counter=0;
		//calls expandColor() functions for each color
		for(int i=1 ; i <= colorsNumber ; i++){
			counter += expandColor(mat, rows, cols, *(startValues+(i-1)*2), *(startValues+(i-1)*2+1), i, turn);	
		}
		turn++;
		
		if(counter){
			printf("Turn number - %d", turn);
			printMatrix(mat, rows, cols);
		}else{
			printf("The end, thank you :)\n\n");
		}
	}while(counter);
}


//######################## initalizing matrix with random numbers <MY_RAND_MIN - MY_RAND_MAX> ##########################//
//mat - matrix
//rows, cols - matrix dimentions

void randomInitStartValues(int* mat, int rows, int cols, int maxRows, int maxCols){
	for ( int i = 0 ; i < rows ; i++){
			//random number generation
			*(mat+i*cols) = (rand()%(maxRows - 1)); //rows generator
			*(mat+i*cols+1) = (rand()%(maxCols - 1));//cols generator
			for(int j = 0 ; j < i ; j++){
				//checks if there is the same start point for a different color
				if(*(mat+i*cols) == *(mat+j*cols) && *(mat+i*cols+1) == *(mat+j*cols+1)){
					i--; //do it again
				}
			}
	}
}


//######################## question 1 - excersize's main function ############################//
// mat - matrix
// rows, cols - matrix dimentions
// startValues - matrix that holds the start point of each color

void colorGame(){
	printf("Board rows number is: %d\nBoard cols number is: %d \n",ROWS, COLS);
	int mat[ROWS][COLS];
	zeroInitMatrix((int*)  mat, ROWS, COLS);
	printf("There are %d Colors", COLOR);
	printMatrix((int*)  mat, ROWS, COLS);
	
	int startValues[COLOR][COLOR_MAT_COLS];
	randomInitStartValues((int*) startValues, COLOR, COLOR_MAT_COLS, ROWS, COLS);
	
	colorTheBoard((int*) mat, ROWS, COLS, COLOR, (int*) startValues);

}
