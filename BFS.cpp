#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF= INT_MAX;
queue<int> Q;
int V;
int E;
int d[100];
vector<int>adj[100];

int main()
{
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<V;i++)
        d[i]=INF;
    int s=0;
    d[0]=0;
    Q.push(s);
    while(!Q.empty())
    {
        int j=Q.front();
        Q.pop();
        cout<<j<<"  ";
        int n=adj[j].size();
        for(int i=0;i<n;i++)
        {
            int h=adj[j][i];
            if(d[h]==INF)
            {
                d[h]=d[j]+1;
                Q.push(h);
            }
        }
    }
    cout<<endl;
    for(int i=0;i<V;i++)
        cout<<d[i]<<" ";

}
