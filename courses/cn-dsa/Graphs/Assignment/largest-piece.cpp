/***
 * It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's.
 * But Gary wants the biggest piece of '1's and no '0's.
 * A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake.
 * Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?
 * 
 * Test Case:
    N = 2
    1 1
    0 1

    => 3
 ***/

// T: O(n * n), S: O(n * n)
bool validPoint(int x, int y, int n) {
    return (0 <= x and x < n and 0 <= y and y < n);
}

int exploreSize(vector<vector<int>> &cake, int n, int x, int y, vector<vector<bool>> &visited) {
    if(visited[x][y]) return 0;
    visited[x][y] = true;

    int size = 1;
    int dXdY[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

    for(int i = 0; i < 4; i++) {
        int nx = x + dXdY[i][0];
        int ny = y + dXdY[i][1];

        if(validPoint(nx, ny, n) and cake[nx][ny] == 1)
            size += exploreSize(cake, n, nx, ny, visited);
    }

    return size;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    vector<vector<bool>> visited(n, vector<bool> (n, false));

    int largest = 0;

    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n; y++) {
            int size = 0;
            if(cake[x][y] == 1 and !visited[x][y]) {
                size = exploreSize(cake, n, x, y, visited);
            }

            if(size > largest)
                largest = size;
        }
    }

    return largest;
}