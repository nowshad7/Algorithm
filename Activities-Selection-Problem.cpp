#include<bits/stdc++.h>
using namespace std;

struct act{
    int start;
    int finish;
};

bool actCompare (act s1,act s2)
{
    return(s1.finish<s2.finish);
}

void mostNumberOfActPossible(act ar[],int n)
{
    sort(ar,ar+n,actCompare);
    int i=0;
    cout<<ar[i].start<<" "<<ar[i].finish<<endl;
    for(int j=1; j<n; j++){
        if(ar[j].start>ar[i].finish){
            cout<<ar[j].start<<" "<<ar[j].finish<<endl;
            i=j;
        }
    }
}

int main()
{
    act ar[100];
    int n;
    cout<<"Enter number of act : ";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ar[i].start>>ar[i].finish;
    }
    mostNumberOfActPossible(ar,n);
    return 0;
}

