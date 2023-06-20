#include <stdio.h>
#include <stdlib.h>

#define ZERO 0



//######################## scans a dimention (cols/rows) from the user ########################//
//value - input value
//flag - while loop flag
//ptr - pointer to the original dimention variable 

void getDimention(int* ptr, int maxValue){ 
	int value, flag = 1;

	//checks if value is in bounds
	do{
		scanf("%d", &value);
		if (value <= 0 || value > maxValue){
			printf("wrong input, please try again <1-%d> : \n",maxValue);
		}
		else{
			flag=0;
		}
	}while(flag);
	
	*ptr = value;
}


//######################## scan matrix dimentions using sub function  getDimention #####################//
// rowsPtr, colsPtr - pointers to the rows and cols of the matrix
// maxRows,  maxCols - the largest values of rows and cols in range

void scanMatrixDimentions(int* rowsPtr, int* colsPtr, int maxRows, int maxCols){
	
	//scanning number of rows
	printf("Please choose the number of rows in matrix <1-%d> :\n", maxRows);
	getDimention(rowsPtr, maxRows); 
	
	//scanning number of cols
	printf("Please choose the number of cols in matrix <1-%d> :\n", maxCols);
	getDimention(colsPtr, maxCols); 
}


//######################## prints matrix ##############################################################//
//mat - matrix
//rows, cols - matrix dimentions

void printMatrix(const int* mat, int rows,int cols){
	printf("\n"); //cosmetic
	for(int i=0; i<rows ; i++){
		for(int j=0; j<cols ; j++){
			printf("%5d", *(mat+i*cols+j));
		}	
		printf("\n"); 
	}
	printf("\n\n"); //cosmetic
}

//######################## initalizing matrix with 0 ##########################//
//mat - matrix
//rows, cols - matrix dimentions

void zeroInitMatrix(int* mat, int rows, int cols){
	for ( int i = 0 ; i < rows ; i++){
		for (int j = 0 ; j < cols ; j++){
			
			*(mat+i*cols + j) = ZERO;
		}
	}
	printf("The matrix is initialized with %d\n",ZERO);
}


//######################## initalizing matrix with random numbers <MY_RAND_MIN - MY_RAND_MAX> ##########################//
//mat - matrix
//rows, cols - matrix dimentions

void randomInitMatrix(int* mat, int rows, int cols, int maxValue, int minValue){
	for ( int i = 0 ; i < rows ; i++){
		for (int j = 0 ; j < cols ; j++){
			//random number generation
			*(mat+i*cols + j) = minValue + (rand()%(maxValue - minValue - 1));
		}
	}
	printf("The matrix is initialized with numbers between %d and %d\n",minValue,maxValue);
}

