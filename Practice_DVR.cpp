#include <bits/stdc++.h>
using namespace std;

struct Node{
    int distance[20];
    int pi[20];
}rt[10];

int main(){
    int i, j, k, nodes, count=0;
    int cost[20][20];
    cout << "Enter the total nodes in the network: ";
    cin >> nodes;
    cout << "Enter the cost matrix ";
    for(i=0; i<nodes; i++)
        for(j=0; j<nodes; j++){
            cin >> cost[i][j];
            cost[i][i] = 0;
            rt[i].distance[j] = cost[i][j];
            rt[i].pi[j] = j;
        }
    do{
        count = 0;
        for(i=0; i<nodes; i++)
            for(j=0; j<nodes; j++)
                for(k=0; k<nodes; k++)
                    if(rt[i].distance[j] > cost[i][k] + rt[k].distance[j]){
                        rt[i].distance[j] = cost[i][k] + rt[k].distance[j];
                        rt[i].pi[j] = k;
                    }
    }while(count!=0);
    for(i=0;i<nodes;i++)
    {
        printf("\n\nFor router %d\n",i+1);
        for(j=0;j<nodes;j++)
            printf("\t\nnode %d via %d Distance %d ",j+1,rt[i].pi[j]+1,rt[i].distance[j]);
    }
    return 0;
}