#include <stdio.h>
#define INF 9999;
#define MAX 10;

void Dijkstra(int Graph[10][10], int n, int start){
    int cost[10][10], distance[10], pred[10];
    int visited[10], count=0, mindistance, nextnode, i, j;

    //Step 1: Create a cost matrix
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(Graph[i][j]==0)
                cost[i][j] = 9999;
            else
                cost[i][j] = Graph[i][j];
    
    //Step 2: Initialize the predetermined array and the visited array, as well as the vertex cost from the start vertex
    for(i=0; i<n; i++){
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i]=0;
    }

    //Step 3: Mark the first vertex as visited and update the arrays.
    distance[start]=0;
    visited[start]=1;
    count=1;

    //Step 4: 
    //4.1: Visit every edge (0 to n-1):
    while(count<n-1){
        mindistance=9999;
        //4.2: Find the minimum distance from the current vertex to every one of the connected vertices, and store its index address:
        for(i=0; i<n; i++)
            if(mindistance>distance[i] && !visited[i]){
                mindistance=distance[i];
                nextnode = i;
            }
        //4.3: Mark the nextnode found from Step 4.2 as visited:
        visited[nextnode]=1;
        //4.4: Now, we fire up another for loop to update the overall edge cost for comparision:
        for(i=0; i<n; i++)
            if(!visited[i]) //4.5: If the updated edge cost is less than the original edge cost, then we update it.
                if((mindistance+cost[nextnode][i])<distance[i]){
                    distance[i] = mindistance+cost[nextnode][i];
                    pred[i] = nextnode;
                }
        //4.6: Finally, we raise the counter to confirm the successful processing of a vertex:
        count++;
    }

    //Step 5: Finally, we display the distance of the calculated shortest path:
    for(i=0; i<n; i++)
        if(i!=start)
            printf("\nDistance from source to %d: %d", i, distance[i]);
    
}

int main() {
  int Graph[10][10], i, j, n, u;
  n = 7;

  Graph[0][0] = 0;
  Graph[0][1] = 0;
  Graph[0][2] = 1;
  Graph[0][3] = 2;
  Graph[0][4] = 0;
  Graph[0][5] = 0;
  Graph[0][6] = 0;

  Graph[1][0] = 0;
  Graph[1][1] = 0;
  Graph[1][2] = 2;
  Graph[1][3] = 0;
  Graph[1][4] = 0;
  Graph[1][5] = 3;
  Graph[1][6] = 0;

  Graph[2][0] = 1;
  Graph[2][1] = 2;
  Graph[2][2] = 0;
  Graph[2][3] = 1;
  Graph[2][4] = 3;
  Graph[2][5] = 0;
  Graph[2][6] = 0;

  Graph[3][0] = 2;
  Graph[3][1] = 0;
  Graph[3][2] = 1;
  Graph[3][3] = 0;
  Graph[3][4] = 0;
  Graph[3][5] = 0;
  Graph[3][6] = 1;

  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 3;
  Graph[4][3] = 0;
  Graph[4][4] = 0;
  Graph[4][5] = 2;
  Graph[4][6] = 0;

  Graph[5][0] = 0;
  Graph[5][1] = 3;
  Graph[5][2] = 0;
  Graph[5][3] = 0;
  Graph[5][4] = 2;
  Graph[5][5] = 0;
  Graph[5][6] = 1;

  Graph[6][0] = 0;
  Graph[6][1] = 0;
  Graph[6][2] = 0;
  Graph[6][3] = 1;
  Graph[6][4] = 0;
  Graph[6][5] = 1;
  Graph[6][6] = 0;

  u = 0;
  Dijkstra(Graph, n, u);

  return 0;
}