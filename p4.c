 #include <stdio.h>
int cost[10][10], n, dist[10], parent[10];
void printPath(int v) {
    if (parent[v] == -1) {
        printf("%d", v);
        return;
    }
    printPath(parent[v]);
    printf(" -> %d", v);
}

void dijkstra(int source) {
    int s[10] = {0};
    int min, w = 0;
    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = 999;
        parent[i] = -1;
    }
    dist[source] = 0;

    for (int i = 0; i < n; i++) {  // Pick unvisited vertex with minimum distance
        min = 999;
        w = -1;
        for (int j = 0; j < n; j++) {
            if (s[j] == 0 && dist[j] < min) {
                min = dist[j];
                w = j;
            }
        }
        if (w == -1) break; // All remaining vertices are unreachable
        s[w] = 1;

        // Relax neighbors
        for (int j = 0; j < n; j++) {
            if (s[j] == 0 && cost[w][j] != 999) {
                if (dist[w] + cost[w][j] < dist[j]) {
                    dist[j] = dist[w] + cost[w][j];
                    parent[j] = w;  // Track path
                }
            }
        }
    }
}

int main() {
    int source;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(source);
    printf("\nShortest distances from source vertex %d:\n\n", source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == 999)
            printf("To vertex %d: unreachable\n", i);
        else {
            printf("To vertex %d: cost = %d  |  Path: ", i, dist[i]);
            printPath(i);
            printf("\n");
        }
    }
    return 0;
}
