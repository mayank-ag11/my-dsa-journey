/***
 * Qs discussed in class (webinar 7)
 * https://www.geeksforgeeks.org/a-boolean-matrix-question/
 * https://drive.google.com/file/d/18vq17s9DIavVaVTfcr4lg9b-mF2ngeWk/view
 ***/
#include <bits/stdc++.h>
using namespace std;
#define R 3
#define C 4

void modifyMatrix(int mat[R][C])
{
	// variables to check if there are any 1
	// in first row and column
	bool row_flag = false;
	bool col_flag = false;

	// updating the first row and col if 1
	// is encountered
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i == 0 && mat[i][j] == 1)
				row_flag = true;

			if (j == 0 && mat[i][j] == 1)
				col_flag = true;

			if (mat[i][j] == 1) {

				mat[0][j] = 1;
				mat[i][0] = 1;
			}
		}
	}

	// Modify the input matrix mat[] using the
	// first row and first column of Matrix mat
	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++) {

			if (mat[0][j] == 1 || mat[i][0] == 1) {
				mat[i][j] = 1;
			}
		}
	}

	// modify first row if there was any 1
	if (row_flag == true) {
		for (int i = 0; i < C; i++) {
			mat[0][i] = 1;
		}
	}

	// modify first col if there was any 1
	if (col_flag == true) {
		for (int i = 0; i < R; i++) {
			mat[i][0] = 1;
		}
	}
}

/* A utility function to print a 2D matrix */
void printMatrix(int mat[R][C])
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << mat[i][j];
		}
		cout << "\n";
	}
}

// Driver function to test the above function
int main()
{

	int mat[R][C] = { { 1, 0, 0, 1 },
					{ 0, 0, 1, 0 },
					{ 0, 0, 0, 0 } };

	cout << "Input Matrix :\n";
	printMatrix(mat);

	modifyMatrix(mat);

	cout << "Matrix After Modification :\n";
	printMatrix(mat);
	return 0;
}