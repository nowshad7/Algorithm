/*
Name : Robiul Hasan Nowshad
ID   : 16-01-04-061
Group: B1
*/
#include<bits/stdc++.h>
using namespace std;

int s,d,n,e[100],p[100],last=0,temp;

vector <int> v[100] ;
int level[100];
bool vis[100];
void bfs(int s) {
    queue <int> q;
    q.push(s);
    level[ s ] = 0 ;
    vis[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0;i < v[ p ].size() ; i++)
        {
            if(vis[ v[ p ][ i ] ] == false)
            {
                level[ v[ p ][ i ] ] = level[ p ]+1;
                q.push(v[ p ][ i ]);
                vis[ v[ p ][ i ] ] = true;
            }
        }
    }

    }

int main(){
    cin>>s>>n>>d;
    for(int i=0;i<n;i++){
        cin>>e[i];
    }
    temp=s;
    int i=0,j=0,k=0,trk=0;
    p[k]=s;
    while(last!=d){
        for(int l=0;l<n;l++){
            last=temp+e[l];
            v[temp].push_back(last);
            v[last].push_back(temp);
            if(last==!d)
                break;
        }
        if(j<n){
            temp=p[k]+e[j++];
            p[++trk]=temp;
        }
        else{
            j=0;
            temp=p[++k]+e[j];
        }
    }
    bfs(s);
    int steps=level[d];
    cout<<"steps :"<<steps;
}
