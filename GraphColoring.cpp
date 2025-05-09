#include <iostream>
using namespace std;

const int V = 4; // Number of vertices

// Check if it's safe to assign color `c` to vertex `v`
bool isSafe(int v, int color[], int c, int graph[V][V]) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && color[i] == c)
            return false; // Adjacent vertex has the same color
    return true;
}

// Recursive function to solve the coloring problem
bool solve(int v, int color[], int m, int graph[V][V]) {
    if (v == V) return true; // All vertices are colored

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, color, c, graph)) {
            color[v] = c; // Assign color

            if (solve(v + 1, color, m, graph)) return true; // Recur

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

void graphColoring(int graph[V][V], int m) {
    int color[V] = {0};

    if (!solve(0, color, m, graph)) {
        cout << "No solution\n";
        return;
    }

    cout << "Color assignment: ";
    for (int i = 0; i < V; i++) cout << color[i] << " ";
    cout << endl;
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0}
    };

    int m = 3; // Number of colors
    graphColoring(graph, m);
    return 0;
}
