#include<bits/stdc++.h>
using namespace std;

vector <int> adj[10];
bool visited[10];
stack<int>st;
int nodes, edges, x, y, connectedComponents = 0;

void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i){
        if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
    }
    st.push(s);
}
void dfs_util(){
    for(int i = 1;i <= nodes;++i) {
         if(visited[i] == false)     {
             dfs(i);
         }
        }
}

void initialize() {
    for(int i = 0;i < 10;++i)
        visited[i] = false;
}

int main() {
    cin >> nodes;
    cin >> edges;
    for(int i = 0;i < edges;++i){
        cin >> x >> y;
        adj[x].push_back(y);
    }

    initialize();
    dfs_util();
    while(!st.empty()){
        cout << st.top() << "\t";
        st.pop();
    }

    }
