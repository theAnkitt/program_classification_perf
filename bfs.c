#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, i, j, *visited, *queue, front = -1, rear = -1;
int **adj;

void bfs(int v) {
    for (i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            queue[++rear] = i;
            visited[i] = 1;
        }
    }
    if (front <= rear) {
        bfs(queue[++front]);
    }
}

int main() {
    int v;
    FILE *file;
    file = fopen("bfsinput.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    fscanf(file, "%d", &n);

    // Allocate memory for visited array
    visited = (int *)malloc((n + 1) * sizeof(int));
    if (visited == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    // Allocate memory for queue
    queue = (int *)malloc((n + 1) * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed.\n");
        free(visited);
        fclose(file);
        return 1;
    }

    // Allocate memory for the adjacency matrix
    adj = (int **)malloc((n + 1) * sizeof(int *));
    if (adj == NULL) {
        printf("Memory allocation failed.\n");
        free(visited);
        free(queue);
        fclose(file);
        return 1;
    }
    for (i = 0; i <= n; i++) {
        adj[i] = (int *)malloc((n + 1) * sizeof(int));
        if (adj[i] == NULL) {
            printf("Memory allocation failed.\n");
            for (int j = 0; j < i; j++) {
                free(adj[j]);
            }
            free(adj);
            free(visited);
            free(queue);
            fclose(file);
            return 1;
        }
    }

    for (i = 1; i <= n; i++) {
        queue[i] = 0;
        visited[i] = 0;
    }

    printf("Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            fscanf(file, "%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    fscanf(file, "%d", &v);
    fclose(file);

    visited[v] = 1;
    bfs(v);

    printf("The nodes which are reachable are:\n");
    int allNodesReachable = 1;
    for (i = 1; i <= n; i++) {
        if (visited[i]) {
            printf("%d\t", i);
        } else {
            allNodesReachable = 0;
        }
    }

    if (!allNodesReachable) {
        printf("BFS is not possible. Not all nodes are reachable.\n");
    }

    // Free allocated memory
    for (i = 0; i <= n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(visited);
    free(queue);

    return 0;
}
