#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODES 200

bool isBicolorable(int start, int color, int *colors, int **graph, int *graphSizes);

int main() {
    int nods, edges, a, b;
    while (scanf("%d", &nods) && nods) {
        scanf("%d", &edges);
        int *graph[MAX_NODES];
        int graphSizes[MAX_NODES];
        int colors[MAX_NODES];
        memset(graphSizes, 0, sizeof(graphSizes));
        memset(colors, 0, sizeof(colors));

        for (int i = 0; i < nods; ++i) {
            graph[i] = (int *)malloc(MAX_NODES * sizeof(int));
        }

        for (int i = 0; i < edges; ++i) {
            scanf("%d %d", &a, &b);
            graph[a][graphSizes[a]++] = b;
            graph[b][graphSizes[b]++] = a;
        }

        if (isBicolorable(0, 1, colors, graph, graphSizes)) {
            printf("BICOLORABLE.\n");
        } else {
            printf("NOT BICOLORABLE.\n");
        }

        for (int i = 0; i < nods; ++i) {
            free(graph[i]);
        }
    }

    return 0;
}

bool isBicolorable(int start, int color, int *colors, int **graph, int *graphSizes) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = start;
    colors[start] = color;

    while (front < rear) {
        int node = queue[front++];
        int nextColor = (colors[node] == 1) ? 2 : 1;

        for (int i = 0; i < graphSizes[node]; ++i) {
            int neighbor = graph[node][i];
            if (colors[neighbor] == 0) {
                colors[neighbor] = nextColor;
                queue[rear++] = neighbor;
            } else if (colors[neighbor] != nextColor) {
                return false;
            }
        }
    }

    return true;
}
