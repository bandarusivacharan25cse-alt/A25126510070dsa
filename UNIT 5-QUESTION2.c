#include <stdio.h>

#define MAX 20
#define INF 9999

int main() {
    int n, g[MAX][MAX], dist[MAX], visited[MAX] = {0};
    int src, i, j, count;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter weighted adjacency matrix (0 = no road):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    if (src < 0 || src >= n) {
        printf("Invalid source vertex!\n");
        return 1;
    }

    for (i = 0; i < n; i++) dist[i] = INF;
    dist[src] = 0;

    for (count = 0; count < n - 1; count++) {
        int u = -1;
        for (i = 0; i < n; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) u = i;
        if (dist[u] == INF) break;       /* remaining vertices unreachable */
        visited[u] = 1;

        for (j = 0; j < n; j++)
            if (g[u][j] && !visited[j] && dist[u] + g[u][j] < dist[j])
                dist[j] = dist[u] + g[u][j];
    }

    printf("\nShortest distances from vertex %d:\n", src);
    printf("Destination\tDistance\n");
    for (i = 0; i < n; i++) {
        if (i == src) continue;
        if (dist[i] == INF) printf("%d\t\tUnreachable\n", i);
        else                printf("%d\t\t%d\n", i, dist[i]);
    }
    return 0;
}
