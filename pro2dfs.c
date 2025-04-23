#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100  

int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

void dfs(int grid[MAX][MAX], int visited[MAX][MAX], int m, int n, int x, int y) {
    if (x < 0 || x>=m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y])
        return;

    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int newX = x + rowDir[i];
        int newY = y + colDir[i];
        dfs(grid, visited, m, n, newX, newY);
    }
}

int countIslands(int grid[MAX][MAX], int m, int n) {
    int visited[MAX][MAX] = {0};
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(grid, visited, m, n, i, j);
                count++;
            }
        }
    }
    return count;
}

void dfsGraph(int graph[MAX][MAX], int visited[MAX], int n, int start) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[start][i] && !visited[i]) {
            dfsGraph(graph, visited, n, i);
        }
    }
}

int main() {
    int n;
    printf("Enter the grid size (n x n): ");
    scanf("%d", &n);

    int grid[MAX][MAX];
    srand(time(0));

    printf("Generated Grid:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = rand() % 2;
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    clock_t start, end;
    start = clock();
    int islandCount = countIslands(grid, n, n);
    end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Number of Islands: %d\n", islandCount);
    printf("Time taken: %lf seconds\n", timeTaken);

    int graph[MAX][MAX];
    printf("\nEnter adjacency matrix for directed graph (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int startNode;
    printf("Enter starting node for DFS in the directed graph: ");
    scanf("%d", &startNode);

    int visited[MAX] = {0};
    printf("Nodes reachable from %d: ", startNode);
    dfsGraph(graph, visited, n, startNode);
    printf("\n");

    return 0;
}
