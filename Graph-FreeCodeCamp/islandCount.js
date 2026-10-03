/***
 * Write a function, islandCount, that takes in a grid containing Ws and Ls.
 * W represents water and L represents Land.
 * The function should return the number of islands on the grid.
 * An island is a vertically or horizontally connected region of land.
 ***/

/*
// Javascript Sets
const s = new Set();
s.add([1, 3]);
console.log(s.has([1, 2])); // false

s.add('1,3');
console.log(s.has('1,3')); // true
*/

// T: O(rc), S: O(rc)
// where, r: # rows, c: # cols
const islandCount = (grid) => {
    const visited = new Set();
    let count = 0;

    for(let r = 0; r < grid.length; r++) {
        for(let c = 0; c < grid[0].length; c++) {
            if(explore(grid, r, c, visited) === true) {
                count++;
            }
        }
    }

    return count;
};

const explore = (grid, r, c, visited) => {
    const rowInbounds = 0 <= r && r < grid.length;
    const colInbounds = 0 <= c && c < grid[0].length;
    if(!rowInbounds || !colInbounds) return false;

    if(grid[r][c] === 'W') return false;

    const pos = r + ',' + c;
    if(visited.has(pos)) return false;
    visited.add(pos);

    explore(grid, r - 1, c, visited);
    explore(grid, r + 1, c, visited);
    explore(grid, r, c - 1, visited);
    explore(grid, r, c + 1, visited);

    return true;
};

const grid = [
    ['W', 'L', 'W', 'W', 'W'],
    ['W', 'L', 'W', 'W', 'W'],
    ['W', 'W', 'W', 'L', 'W'],
    ['L', 'W', 'W', 'L', 'L'],
    ['L', 'L', 'W', 'W', 'W']
];

console.log(islandCount(grid)); // -> 3
