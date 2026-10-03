// On directed, connected and acyclic graph
const depthFirstPrint = (graph, source) => {
    const stack = [ source ];

    while(stack.length > 0) {
        const current = stack.pop();
        console.log(current);

        for(let neighbor of graph[current]) {
            stack.push(neighbor);
        }
    }
};

const depthFirstPrintRecursive = (graph, source) => {
    console.log(source);
    for(let neighbor of graph[source]) {
        depthFirstPrintRecursive(graph, neighbor);
    }
};

const graph = {
    a: ['c', 'b'],
    b: ['d'],
    c: ['e'],
    d: ['f'],
    e: [],
    f: []
};

depthFirstPrint(graph, 'a'); // abdfce
console.log();
depthFirstPrintRecursive(graph, 'a'); // acebdf
