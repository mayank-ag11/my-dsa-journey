/*
Time complexity: O(V + E)
Space complexity: O(V^2)
where V is the number of vertices in the input graph and
E is the number of edges in the input graph
*/
import java.util.LinkedList;
import java.util.Queue;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class PrintBFS {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void printBFSHelper(int edges[][], int sv, boolean visited[]) {
        Queue < Integer > queue = new LinkedList < > ();
        visited[sv] = true;
        queue.add(sv);
        while (!queue.isEmpty()) {
            int front = queue.remove();
            System.out.print(front + " ");
            for (int i = 0; i < edges.length; i++) {
                if (edges[front][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue.add(i);
                }
            }
        }
    }
    public static void printBFS(int edges[][]) {
        boolean visited[] = new boolean[edges.length];
        for (int i = 0; i < visited.length; i++) {
            if (!visited[i]) {
                printBFSHelper(edges, i, visited);
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        String[] strNums;
        strNums = br.readLine().split("\\s");
        int n = Integer.parseInt(strNums[0]);
        int e = Integer.parseInt(strNums[1]);
        if (n == 0) {
            return;
        }
        int edges[][] = new int[n][n];
        for (int i = 0; i < e; i++) {
            String[] strNums1;
            strNums1 = br.readLine().split("\\s");
            int fv = Integer.parseInt(strNums1[0]);
            int sv = Integer.parseInt(strNums1[1]);
            edges[fv][sv] = 1;
            edges[sv][fv] = 1;
        }
        printBFS(edges);
    }
}