#include <stdio.h>

#define MAX 20

int n, adj[MAX][MAX];
int visited[MAX];

void dfs(int v) {
    visited[v] = 1;                      /* mark so it is never processed again */
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i);
}

void bfs(int start) {
    int queue[MAX], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++)
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;          /* mark when enqueued */
                queue[rear++] = i;
            }
    }
}

void reset() {
    for (int i = 0; i < n; i++) visited[i] = 0;
}

void report() {
    int all = 1;
    for (int i = 0; i < n; i++)
        if (!visited[i]) {
            if (all) printf("\nNot reachable from start: ");
            printf("%d ", i);
            all = 0;
        }
    if (all) printf("\nAll vertices visited -> graph is connected.");
    else     printf("\n-> graph is partially connected (disconnected).");
    printf("\n");
}

int main() {
    int start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    reset();
    printf("\nDFS visit order: ");
    dfs(start);
    report();

    reset();
    printf("\nBFS visit order: ");
    bfs(start);
    report();
    return 0;
}
