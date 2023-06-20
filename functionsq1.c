#include <stdio.h>
#include "matfunctions.h" 

#define ROWS 10
#define COLS 10
#define MY_RAND_MAX 50
#define MY_RAND_MIN -50

//######################## returns the sum of a sub matrix of a matrix ########################//
//mat- matrix
//subMatRows, subMatCols - dimentions of the sub matrix
//startRow, startCol - the start index of sub matrix
//matCols - main matrix number of cols
    
 int subSum(const int* mat, int subMatRows, int subMatCols, int startRow, int startCol,int matCols){
    int sum = 0;
    for (int i = startRow ; i < startRow + subMatRows; i++){
        for(int j = startCol ; j < startCol + subMatCols; j++){
            sum += *(mat+i*matCols+j);
        }
    }
    return sum;
 }  


//######################## finds and returns the largest sum of a sub matrix from a matrix and it's start index ########################//
// mat - matrix
// rows, cols - matrix cols and rows
// subRows,subCols - the sub matrix cols and rows
// rowPtr,colPtr - the index of the start of the sub matrix starts that has the largest sum

int doFindMaxSubMatrix(const int* mat, int rows, int cols, int subRows, int subCols, int* rowPtr, int* colPtr){
	int largestSum = 0;
	int tempSum = 0;
	for (int i = 0; i < rows; i++){  
		for(int j =0; j < cols; j++){		        
        		
        		//checks if the current index is a valid starting point for the sub matrix
        		if(i + subRows <= rows && j + subCols <= cols){  
				tempSum = subSum(mat,subRows,subCols,i,j,cols); //sum of the sub matrix starting at the current cell 
 				
 				//at the start the largest sum is the sub matrix starting at [0][0]
 				if(i == 0 && j == 0){ 
 					largestSum = tempSum;
 				}
              			else if(tempSum > largestSum){
                			largestSum = tempSum;
                			*rowPtr = i;
                			*colPtr = j;
              			}
			}	
		}
	}
	return largestSum;
}



//######################## question 1 - excersize's main function ############################//
// mat - matrix
// rows, cols - main matrix dimentions
//subRows, subCols - sub matrix dimentions
//rowPtr, colsPtr - pointers to mat dimentions 
//subMatStartRow, subMatStartCol - largest sum sub matrix start index;

void biggestMatrixSum(){
	printf("\n\n");
	printf("Max matrix rows number is: %d\nMax matrix cols number is: %d \n",ROWS, COLS);
	int mat[ROWS][COLS];
	int rows,cols; //main matrix dimentions
	int subRows, subCols; //submatrix dimentions
	
	//matrix
	int *rowsPtr = &rows; //pointers in order to use scanMatrixDimentions for matrix
	int *colsPtr = &cols;
	scanMatrixDimentions(rowsPtr, colsPtr, ROWS, COLS);
 	printf("\nyou chose a matrix with %d rows and %d cols\n\n", rows, cols);
	randomInitMatrix((int*)  mat, rows, cols, MY_RAND_MAX, MY_RAND_MIN);
	printMatrix((int*) mat, rows, cols);
	
	//sub matrix
	rowsPtr = &subRows; //in order to use scanMatrixDimentions for sub matrix
	colsPtr = &subCols;
	printf("Now for the sub matrix:\n");
	scanMatrixDimentions(rowsPtr, colsPtr, rows-1, cols-1);
 	printf("\nyou chose a sub-matrix with %d rows and %d cols\n\n", subRows, subCols);
	
	int subMatStartRow ,subMatStartCol; 
	int sum = doFindMaxSubMatrix((int*) mat, rows, cols, subRows, subCols, &subMatStartRow, &subMatStartCol);
	printf("the sub matrix with the largest sum starts at mat[%d][%d] and its sum is: %d\n\n\n", subMatStartRow, subMatStartCol, sum);
	
	
	
}

