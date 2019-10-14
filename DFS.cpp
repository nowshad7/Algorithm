#include<iostream>
#include<vector>
#include<stack>

using namespace std;

const int INF= INT_MAX;
stack<int> S;
int V;
int E;
bool visited[100];
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
        visited[i]=false;
    int s=0;
    visited[s]=true;
    S.push(s);
    while(!S.empty())
    {
        int j=S.top();
        S.pop();

        cout<<j<<"  ";
        int n=adj[j].size();
        for(int i=0;i<n;i++)
        {
            int h=adj[j][i];
            if(visited[h]==false)
            {
                visited[h]=true;
                S.push(h);
               // cout<<h;
            }
        }
    }
    ///cout<<endl;
  //  for(int i=0;i<V;i++)
      //  cout<<d[i]<<" ";

}
