#ifndef __MATRIX__
#define __MATRIX__


void getDimention(int* ptr, int maxValue);
void scanMatrixDimentions(int* rowsPtr, int* colsPtr, int maxRows, int maxCols);
void printMatrix(const int* mat, int rows,int cols);
void zeroInitMatrix(int* mat, int rows, int cols);
void randomInitMatrix(int* mat, int rows, int cols, int maxValue, int minValue);


#endif
