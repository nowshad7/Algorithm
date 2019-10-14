#include<bits/stdc++.h>
using namespace std;

vector <int> adj[100];
vector <int> rev_adj[100];
bool visited[100];
stack<int>st;
int nodes, edges, x, y,l=1;

void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i){
        if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
    }
    st.push(s);
}
void rev_dfs(int s) {
    visited[s] = true;
    cout<<s;
    for(int i = 0;i < rev_adj[s].size();++i){
        if(visited[rev_adj[s][i]] == false)
             rev_dfs(rev_adj[s][i]);
    }
}
void dfs_util(){
    for(int i = 0;i < nodes;++i) {
         if(visited[i] == false)     {
             dfs(i);
         }
        }
}

void initialize() {
    for(int i = 0;i <nodes;++i)
        visited[i] = false;
}
void SCC(){
    dfs_util();
    initialize();
    cout<<"Strongly Connected Components: "<<endl;
    while(!st.empty()){
        int h=st.top();
        st.pop();
        if(visited[h] == false){
            cout<<l++<<". ";
            rev_dfs(h);
            cout<<endl;
        }
    }
}

int main() {
    cin >> nodes;
    cin >> edges;
    for(int i = 0;i < edges;++i){
        cin >> x >> y;
        adj[x].push_back(y);
        rev_adj[y].push_back(x);
    }

    initialize();
    SCC();
    }
