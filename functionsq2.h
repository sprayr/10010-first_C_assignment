#ifndef __FUNC2__
#define __FUNC2__


int expandColor(int* mat, int rows, int cols, int rowIndex, int colIndex, int color, int turn);
void colorTheBoard(int* mat, int rows, int cols, int colors, const int* startValues);
void randomInitStartValues(int* mat, int rows, int cols, int maxRows, int maxCols);
void colorGame();

#endif
