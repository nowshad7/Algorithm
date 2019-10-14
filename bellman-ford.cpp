#include<bits/stdc++.h>
#define inf 999999
using namespace std;
struct edge{
    int u,v,w;
    edge(int _u,int _v,int _w){
        u=_u;
        v=_v;
        w=_w;
    }
};
vector<edge>edges;
int p[100],dis[100],E,V;
void Bellman_ford(int s){
    for(int i=0;i<V;i++){
        if(i==s)
            dis[i]=0;
        else dis[i]=inf;
        p[i]=i;
    }
    for(int j=0;j<V-1;j++){
        for(int i=0;i<E;i++){
            int u=edges[i].u;
            int v=edges[i].v;
            int w=edges[i].w;
            if((dis[u]+w)<dis[v]){
                dis[v]=dis[u]+w;
                p[v]=u;
            }

        }
    }
}

void printSolution()
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dis[i]);
}

int main(){
    cin >>V>>E;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(edge(u,v,w));
    }
    Bellman_ford(2);
    printSolution();

}

