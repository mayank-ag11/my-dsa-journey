/***
 * For a given two-dimensional integer array/list of size (N x M), you need to find out which row or column has the largest sum(sum of all the elements in a row/column) amongst all the rows and columns.
 * 
 * If there are more than one rows/columns with maximum sum, consider the row/column that comes first. And if ith row and jth column has the same largest sum, consider the ith row as answer.
 ***/
#include <climits>
void findLargest(int **arr, int m, int n)
{
    int max_sum = INT_MIN, max_index = 0;
    bool row_max = true;
    // Finding Row-wise-sum
    for(int i=0; i<m; i++) {
        int sum = 0;
        for(int j=0; j<n; j++) {
            sum += arr[i][j];
        }
        if(sum > max_sum) {
            max_sum = sum;
            max_index = i;
        }
    }
    
    // Finding Col-wise-sum
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=0; j<m; j++) {
            sum += arr[j][i];
        }
        if(sum > max_sum) {
            max_sum = sum;
            max_index = i;
            row_max = false;
        }
    }
    
    if(row_max) {
        cout << "row " << max_index << ' ' << max_sum << '\n';
    }
    else {
        cout << "column " << max_index << ' ' << max_sum << '\n';
    }
}