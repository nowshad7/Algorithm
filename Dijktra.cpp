#include <bits/stdc++.h>
using namespace std;
int graph[100][100], V , E;
int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
int printSolution(int dist[])
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
void dijkstra(int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = true;
       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
     printSolution(dist);
}
int main (){
    cin >>V>>E;
    int u,v,w;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        graph[u][v]=w;
    }
    dijkstra(0);
}
/*
6 10
0 1 10
0 2 2
1 3 30
1 4 4
2 1 3
2 4 15
2 3 20
4 3 5
4 5 40
3 5 2
*/
