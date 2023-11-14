#include <stdio.h>
#include <stdlib.h>

struct node{
    int vertex;
    struct node *next;
};

struct node* createNode(int v){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
}

struct Graph{
    int numVertices;
    int *visited;
    struct node **adjLists; //Array of Linked lists with their heads as vertices 
};

struct Graph *createGraph(int vertices){
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->visited = malloc(vertices*sizeof(int));
    graph->adjLists = malloc(vertices*sizeof(struct node*));

    for(int i=0; i<vertices; i++){
        graph->adjLists = NULL;
        graph->visited = 0;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest){
    //First, we link source vertex to destination vertex:
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    //Now, we link the destination vertex to source vertex:
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph){
    int v;
    for(v=0; v<graph->numVertices; v++){
        struct node *temp = graph->adjLists[v];
        printf("\nAdjacency List for vertex %d: \n", v);
        while(temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
    }
}

void DFS(struct Graph *graph, int vertex){
    struct node *adjList = graph->adjLists[vertex];
    struct node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    if(temp!=NULL){
        int connectedVertex = temp->vertex;
        if(graph->visited[connectedVertex]==0)
            DFS(graph, connectedVertex);
        temp = temp->next;
    }
}