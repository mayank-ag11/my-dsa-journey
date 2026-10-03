/***
 * For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. That is, you need to print in the order followed for every iteration:
 * 
 * a. First row(left to right)
   b. Last column(top to bottom)
   c. Last row(right to left)
   d. First column(bottom to top)

 * Similar Qs: https://www.geeksforgeeks.org/create-a-matrix-with-alternating-rectangles-of-0-and-x/
 ***/
// Solution discussed in class: Webinar 7
void spiralPrint(int **arr, int nRows, int mCols)
{
    if (nRows == 0 || mCols == 0) {
        return;
    }
    int minR = 0, minC = 0, maxR = nRows-1, maxC = mCols-1;
    
    while(minR <= maxR && minC <= maxC) {
        // printing first row
        for(int i=minC; i<=maxC; i++)
            cout << arr[minR][i] << ' ';
        minR++;
        
        // printing last col
        for(int i=minR; i<=maxR; i++)
            cout << arr[i][maxC] << ' ';
        maxC--;
        
        // printing last row reverse
        if(minR <= maxR) {
            for(int i=maxC; i>=minC; i--)
            	cout << arr[maxR][i] << ' ';
            maxR--;
        }
        
        // printing first col reverse
        if(minC <= maxC) {
            for(int i=maxR; i>=minR; i--)
            	cout << arr[i][minC] << ' ';
        	minC++;
        }
    }
}

// My Code from CodeQuotient(Sem 2)
void spiralPrint(int **a, int r, int c)
{
    int i,k=0,l=0;

    /*  k - starting row index
        r - ending row index
        l - starting column index
        c - ending column index
        i - iterator
    */

    while(k<r && l<c)
    {
        //first row
        for(i=l;i<c;i++)
            printf("%d ", a[k][i]);
        k++;

        //last column
        for(i=k;i<r;i++)
            printf("%d ", a[i][c-1]);
        c--;

        //last row
        if(k<r)
        {
            for(i=c-1;i>=l;i--)
                printf("%d ", a[r-1][i]);

            r--;
        }

        //first column
        if(l<c)
        {
            for(i=r-1;i>=k;i--)
                printf("%d ", a[i][l]);
            l++;
        }

    }
}

// Coding Ninjas Solution
void spiralPrint(int nRows, int mCols, int input[][mCols]) {
    if (nRows == 0 || mCols == 0) {
        return;
    }
    int i, rowStart = 0, colStart = 0;
    int numElements = nRows * mCols, count = 0;
    while (count < numElements) {
        for (i = colStart; count < numElements && i < mCols; ++i) {
            printf("%d ", input[rowStart][i]); count++;
        }
        rowStart++;
        for (i = rowStart; count < numElements && i < nRows; ++i) {
            printf("%d ", input[i][mCols - 1]); count++;
        }
        mCols--;
        for (i = mCols - 1; count < numElements && i >= colStart; --i) {
            printf("%d ", input[nRows - 1][i]); count++;
        }
        nRows--;
        for (i = nRows - 1; count < numElements && i >= rowStart; --i) {
            printf("%d ", input[i][colStart]); count++;
        }
        colStart++;
    }
}