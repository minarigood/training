#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 10000 /* 무한대 (연결이 없는 경우) */

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct GraphType {
    int n; // 정점의 개수
    Node* adj_list[MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES]; /* 시작 정점으로부터의 최단 경로 거리 */
int found[MAX_VERTICES]; /* 방문한 정점 표시 */

// 최단 경로 알고리즘의 진행 상황을 출력하는 함수
void print_status(GraphType* g) {

    printf("Distance: ");
    for (int i = 0; i < (g->n)-1; i++) {
        if (distance[i] == INF) {
            printf("* ");
        }
        else {
            printf("%d ", distance[i]);
        }
    }
    printf("\nFound: ");
    for (int i = 0; i < (g->n)-1; i++) {
        printf("%d ", found[i]);
    }
    printf("\n\n");
}

int choose(int distance[], int n, int found[]) {
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++)
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    return minpos;
}

// 최단 경로를 찾는 함수
void shortest_path(GraphType* g, int start) {
    int i, u, w;
    int list[10];
    for (i = 0; i < g->n; i++) {
        distance[i] = INF;
        found[i] = FALSE;
    }
    distance[start] = 0;
    for (i = 0; i < g->n - 1; i++) {
        if (i >= 1) {
            print_status(g);
        }
        u = choose(distance, g->n, found);
        list[i] = u + 1;
        found[u] = TRUE;
        Node* current = g->adj_list[u];
        while (current != NULL) {
            w = current->vertex;
            if (!found[w] && distance[u] + current->weight < distance[w]) {
                distance[w] = distance[u] + current->weight;
            }
            current = current->next;
        }
    }
    printf("정점 출력 : ");
    for (i = 0; i < 10; i++) {
        printf("%d ", list[i]);
    }
}

// 그래프에 정점과 가중치를 추가하는 함수
void add_edge(GraphType* g, int start, int end, int weight) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->vertex = end;
    new_node->weight = weight;
    new_node->next = g->adj_list[start];
    g->adj_list[start] = new_node;
}

int main(void) {
    GraphType g;
    g.n = 11;
    for (int i = 0; i < g.n; i++) {
        g.adj_list[i] = NULL;
    }

    // 간선 추가
    add_edge(&g, 0, 1, 3);
    add_edge(&g, 0, 5, 11);
    add_edge(&g, 0, 6, 12);
    add_edge(&g, 1, 2, 5);
    add_edge(&g, 1, 3, 4);
    add_edge(&g, 1, 4, 1);
    add_edge(&g, 1, 5, 7);
    add_edge(&g, 1, 6, 8);
    add_edge(&g, 2, 3, 2);
    add_edge(&g, 2, 6, 6);
    add_edge(&g, 2, 7, 5);
    add_edge(&g, 3, 4, 13);
    add_edge(&g, 3, 7, 14);
    add_edge(&g, 3, 9, 16);
    add_edge(&g, 4, 5, 9);
    add_edge(&g, 4, 8, 18);
    add_edge(&g, 4, 9, 17);
    add_edge(&g, 5, 8, 18);
    add_edge(&g, 6, 7, 13);
    add_edge(&g, 7, 9, 15);
    add_edge(&g, 8, 9, 10);

    printf("Dijkstra Algorithm(연결 리스트)\n");
    shortest_path(&g, 0);
    return 0;
}
