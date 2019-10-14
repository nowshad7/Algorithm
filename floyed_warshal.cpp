#include<bits/stdc++.h>
#define no 100
using namespace std;
int weight[no][no];
int node,edge;
void floyed_warshal()
{
    for(int k=1;k<=node;k++)
       for(int i=1;i<=node;i++)
          for(int j=1;j<=node;j++)
              weight[i][j] = min(weight[i][j],weight[i][k]+weight[k][j]);


}


int main()
{
    for(int i=0;i<no;i++)
        {
            for(int j=0;j<no;j++)
            {
                if(i==j) weight[i][j] = 0;
                else  weight[i][j] = 1000;
            }
        }

    cin>>node>>edge;

    for(int i=0;i<edge;i++)
    {

        int u,v,w;
        cin>>u>>v>>w;
        weight[u][v] = w;
    }


    floyed_warshal();

    for(int i= 1;i<=node;i++)
    {
       for(int j= 1;j<=node;j++)
         {
             cout<<weight[i][j]<<"\t";
         }
         cout<<endl;
    }


    return 0;
}
