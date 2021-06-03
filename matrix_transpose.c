/*****************************************************************************************************************/
/*												Matrix Transpose Calculator                                      */
/*****************************************************************************************************************/

/*
 * Author:	Aly Khan Nuruddin
 * Date:	June 3, 2021
 *
 * Purpose: This program computes the tranpose of a 2 x 3 matrix, and then prints the resulting '3 x 2' matrix
 *          on the screen, for the user.
 */

/*****************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS															// Prohibit the compiler from suggesting secure versions of library functions.

#include <stdio.h>																		// Include the standard input and output library in C.
#include <stdlib.h>																		// Include the standard library in C.

#define INPUT_ROW 2																		// Initialize the number of rows of the input matrix.
#define INPUT_COLUMN 3																	// Initialize the number of columns of the input matrix.

#define TRANSPOSE_ROW 3																	// Initialize the number of rows of the tranpose matrix.
#define TRANSPOSE_COLUMN 2																// Initialize the number of columns of the tranpose matrix.

void transpose(int inputMatrix[INPUT_ROW][INPUT_COLUMN], int transposeMatrix[TRANSPOSE_ROW][TRANSPOSE_COLUMN]);	 // Define the prototype for the function "transpose".

int main(void)																			// Define the function "main".
{
	int inputMatrix[INPUT_ROW][INPUT_COLUMN];											// Define the array that stores the entries of the input matrix.
	int transposeMatrix[TRANSPOSE_ROW][TRANSPOSE_COLUMN];								// Define the array that stores the entries of the transpose matrix.

	int numRow = 1;																		// Initialize the row number.

	for (int numColumn = 1; numColumn <= INPUT_COLUMN; numColumn++)						// Initialize the column number. Increment the column number by 1. Exit the loop when the column number exceeds the number of columns of the input matrix.
	{
		inputMatrix[numRow][numColumn] = numColumn;										// Assign the value of each entry in the first row to its corresponding column number. 
	}

	numRow = 2;																			// Re-initialize the row number.

	for (int numColumn = 1; numColumn <= INPUT_COLUMN; numColumn++)						// Initialize the column number. Increment the column number by 1. Exit the loop when the column number exceeds the number of columns of the input matrix.
	{
		inputMatrix[numRow][numColumn] = numColumn + inputMatrix[1][INPUT_COLUMN];		// Assign the value of each entry in the second row to its corresponding column number plus the value of the third entry in the first row.
	}

	printf("The %d x %d input matrix is ", INPUT_ROW, INPUT_COLUMN);					// Print the following statement for the input matrix.

	for (int numRow = 1; numRow <= INPUT_ROW; numRow++)									// Initialize the row number. Increment the row number by 1. Exit the loop when the row number exceeds the number of rows of the input matrix.
	{
		printf("{%d", inputMatrix[numRow][1]);											// Print an 'opening bracket' and the first entry of the first row.

		for (int numColumn = 2; numColumn <= INPUT_COLUMN; numColumn++)					// Initialize the column number. Increment the column number by 1. Exit the loop when the column number exceeds the number of columns of the input matrix.
		{
			printf(" ");																// Print a 'space'.
			printf("%d", inputMatrix[numRow][numColumn]);								// Print the values of the remaining entries of the first row.
		}

		printf("}");																	// Print a 'closing bracket'

		if (numRow < INPUT_ROW)															// Define the condition where the row number is less than the number of rows of the input matrix.
		{
			printf("\n%*c", 26, ' ');													// Print a 'newline' and a width of 26 spaces.
		}
	}

	printf(".");																		// Print a 'full stop'.		

	transpose(inputMatrix, transposeMatrix);											// Call the function "tranpose".

	printf("\n\n");																		// Print two 'newlines' before suspending the program.

	system("PAUSE");																	// Suspend the execution of the program.
	return 0;																			// Terminate the execution of the program.
}

void transpose(int inputMatrix[INPUT_ROW][INPUT_COLUMN], int transposeMatrix[TRANSPOSE_ROW][TRANSPOSE_COLUMN])  // Define the function "transpose".
{
	for (int numRow = 1; numRow <= TRANSPOSE_ROW; numRow++)								// Initialize the row number. Increment the row number by 1. Exit the loop when the row number exceeds the number of rows of the transpose matrix.
	{
		for (int numColumn = 1; numColumn <= TRANSPOSE_COLUMN; numColumn++)				// Initialize the column number. Increment the column number by 1. Exit the loop when the column number exceeds the number of columns of the transpose matrix.
		{
			transposeMatrix[numRow][numColumn] = inputMatrix[numColumn][numRow];		// Assign the value of the 'm x n' entry of the input matrix to the 'n x m' entry of the transpose matrix.
		}
	}

	printf("\n\nThe %d x %d transpose matrix is ", TRANSPOSE_ROW, TRANSPOSE_COLUMN);	// Print the following statement for the transpose matrix.

	for (int numRow = 1; numRow <= TRANSPOSE_ROW; numRow++)								// Initialize the row number. Increment the row number by 1. Exit the loop when the row number exceeds the number of rows of the transpose matrix.
	{
		printf("{%d", transposeMatrix[numRow][1]);										// Print an 'opening bracket' and the first entry of the first row.

		for (int numColumn = 2; numColumn <= TRANSPOSE_COLUMN; numColumn++)				// Initialize the column number. Increment the column number by 1. Exit the loop when the column number exceeds the number of columns of the transpose matrix.
		{
			printf(" ");																// Print a 'space'.
			printf("%d", transposeMatrix[numRow][numColumn]);							// Print the values of the remaining entries of the first row.
		}

		printf("}");																	// Print a 'closing bracket'

		if (numRow < TRANSPOSE_ROW)														// Define the condition where the row number is less than the number of rows of the transpose matrix.
		{
			printf("\n%*c", 30, ' ');													// Print a 'newline' and a width of 30 spaces.
		}
	}

	printf(".");																		// Print a 'full stop'.	

	return;																				// Return 'void' to the "main" function.
}