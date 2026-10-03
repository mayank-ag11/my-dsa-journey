/***
 * For a given two-dimensional integer array/list of size (N x M), print the array/list in a sine wave order, i.e, print the first column top to bottom, next column bottom to top and so on.
 ***/
void wavePrint(int **arr, int m, int n)
{
    bool top_bottom = true;
   	for(int i=0; i<n; i++) {
        if(top_bottom) {
        	for(int j=0; j<m; j++)
                cout << arr[j][i] << ' ';
        }
        else {
            for(int j=m-1; j>=0; j--)
                cout << arr[j][i] << ' ';
        }
        top_bottom = !top_bottom;
    }
}