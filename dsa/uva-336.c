#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1;
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return value;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

int main() {
    int NC, Case = 1;
    while (scanf("%d", &NC) == 1 && NC != 0) {
        struct Node* adjList[MAX_NODES];
        memset(adjList, 0, sizeof(adjList));

        for (int i = 0; i < NC; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);

            // Add edge from u to v
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = v;
            newNode->next = adjList[u];
            adjList[u] = newNode;

            // Add edge from v to u
            newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = u;
            newNode->next = adjList[v];
            adjList[v] = newNode;
        }

        int s, ttl;
        while (scanf("%d %d", &s, &ttl) == 2 && !(s == 0 && ttl == 0)) {
            // Use BFS to solve the SSSP problem.
            struct Queue* q = createQueue();
            int dist[MAX_NODES] = {0};
            int reachableNodes = 1;

            dist[s] = 1;
            enqueue(q, s);
            while (!isEmpty(q)) {
                int u = dequeue(q);
                struct Node* temp = adjList[u];
                while (temp) {
                    int v = temp->data;
                    if (!dist[v]) {
                        dist[v] = dist[u] + 1;
                        if (dist[v] <= ttl) {
                            enqueue(q, v);
                            ++reachableNodes;
                        }
                    }
                    temp = temp->next;
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", Case++, NC - reachableNodes, s, ttl);
        }
    }
    return 0;
}
