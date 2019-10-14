#include<bits/stdc++.h>
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
int p[100];

bool cmp(edge a,edge b){
    return a.w<b.w;
}

int root(int x){
    if(p[x]==x)
        return x;
    return root(p[x]);

}

void kruskal(int e){
    int mini_cost=0;
    cout<<"Minimum Spanning Tree: "<<endl;

    for(int i=0;i<e;i++){

        int u_root=root(edges[i].u);
        int v_root=root(edges[i].v);
        int cost=edges[i].w;

        if(u_root!=v_root){
            cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].w<<endl;
            mini_cost+=cost;
            p[u_root]=p[v_root];
        }
    }
    cout<<"Minimum Cost : "<<mini_cost<<endl;
}
int main(){
    int e;
    cin >>e;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(edge(u,v,w));
        p[u]=u;
        p[v]=v;
    }
    cout<<endl;

    sort(edges.begin(),edges.end(),cmp);

    cout<<endl;

    kruskal(e);
}
/*
7
0 1 10
0 2 70
1 2 50
1 3 40
1 4 30
2 4 60
3 4 20
*/
