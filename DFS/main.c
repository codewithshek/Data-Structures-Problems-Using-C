#include<stdio.h>
#define MAX 10

int n;
int visited[MAX];
int adj[MAX][MAX];

void create_graph();
void dfs(int);

int main() {  // Correct return type
    int v;
    create_graph();
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    dfs(v);
    return 0;  // Return statement for main
}

void create_graph() {
    int origin, destin, c, max_edge;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    max_edge = n * (n - 1);

    // Initialize adjacency matrix to zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (c = 1; c <= max_edge; c++) {
        printf("Enter edge %d (1 1 to quit): ", c);
        scanf("%d %d", &origin, &destin);
        if ((origin == 1) && (destin == 1)) {
            break;  // Correctly placed inside the loop
        } else if (origin > n || destin > n || origin < 1 || destin < 1) {
            printf("Invalid edge!\n");
        } else {
            adj[origin - 1][destin - 1] = 1;  // Adjust for zero-based index
        }
    }
}

void dfs(int i) {
    int j;
    printf("%d ", i + 1);  // Adjust for zero-based index
    visited[i] = 1;
    for (j = 0; j < n; j++) {
        if (!visited[j] && adj[i][j] == 1) {
            dfs(j);
        }
    }
}
