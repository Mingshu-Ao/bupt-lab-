#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 30

typedef struct Edge {
    int dest;
    struct Edge* next;
} Edge;

typedef struct {
    int numVertices;
    Edge** adjLists;
} Graph;

typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

// ����һ���µı�
Edge* createEdge(int dest) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->dest = dest;
    newEdge->next = NULL;
    return newEdge;
}

// ����һ��ͼ
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // �����ڽӱ�����
    graph->adjLists = (Edge**)malloc(vertices * sizeof(Edge*));

    // ��ʼ���ڽӱ�Ϊ��
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// ��ӱߵ�����ͼ
void addEdge(Graph* graph, int src, int dest) {
    // ��Ӵ�src��dest�ı�
    Edge* newEdge = createEdge(dest);
    newEdge->next = graph->adjLists[src];
    graph->adjLists[src] = newEdge;

    // ��Ϊ������ͼ����Ӵ�dest��src�ı�
    newEdge = createEdge(src);
    newEdge->next = graph->adjLists[dest];
    graph->adjLists[dest] = newEdge;
}

// ������������ӡ��������
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ��������������ݹ飩
void DFSUtil(Graph* graph, int v, int visited[], int* stack, int* index) {
    visited[v] = 1;
    stack[(*index)++] = v;

    Edge* adjList = graph->adjLists[v];
    while (adjList != NULL) {
        int connectedVertex = adjList->dest;
        if (!visited[connectedVertex]) {
            DFSUtil(graph, connectedVertex, visited, stack, index);
        }
        adjList = adjList->next;
    }
}

// �����������
void DFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = { 0 };
    int stack[MAX_VERTICES];
    int index = 0;

    DFSUtil(graph, startVertex, visited, stack, &index);

    printArray(stack, index);
}

// �����������
void BFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = { 0 };
    int queue[MAX_VERTICES], front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Edge* adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) {
            int connectedVertex = adjList->dest;
            if (!visited[connectedVertex]) {
                visited[connectedVertex] = 1;
                queue[rear++] = connectedVertex;
            }
            adjList = adjList->next;
        }
    }
    printf("\n");
}

// ջ����
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->array[stack->top--];
}

// �ǵݹ������������
void iterativeDFS(Graph* graph, int startVertex) {
    int visited[MAX_VERTICES] = { 0 };
    Stack* stack = createStack(graph->numVertices);

    push(stack, startVertex);

    while (!isEmpty(stack)) {
        int currentVertex = pop(stack);

        if (!visited[currentVertex]) {
            visited[currentVertex] = 1;
            printf("%d ", currentVertex);
        }

        Edge* adjList = graph->adjLists[currentVertex];
        while (adjList != NULL) {
            int connectedVertex = adjList->dest;
            if (!visited[connectedVertex]) {
                push(stack, connectedVertex);
            }
            adjList = adjList->next;
        }
    }

    printf("\n");
    free(stack->array);
    free(stack);
}

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    printf("DFS (recursive) starting from vertex 2:\n");
    DFS(graph, 2);

    printf("BFS starting from vertex 2:\n");
    BFS(graph, 2);

    printf("DFS (iterative) starting from vertex 2:\n");
    iterativeDFS(graph, 2);

    // �ͷ��ڴ�
    for (int i = 0; i < graph->numVertices; i++) {
        Edge* adjList = graph->adjLists[i];
        Edge* temp;
        while (adjList != NULL) {
            temp = adjList;
            adjList = adjList->next;
            free(temp);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}