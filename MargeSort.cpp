#include<bits/stdc++.h>

using namespace std;

void Marge(int A[],int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1] , R[n2+1];
    for(int i = 0 ; i < n1 ; i++)
    {
        L[i] = A[p+i];
    }
    for(int j = 0 ; j < n2 ; j++)
    {
        R[j] = A[q+1+j];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    for(int i = 0 , j = 0 , k = p ; k <= r ; k++)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}
void MargeSort(int A[], int p, int r)
{
    if(p<r)
    {
         int q=(p+r)/2;
         MargeSort(A,p,q);
         MargeSort(A,q+1,r);
         Marge(A,p,q,r);
    }
}

int main ()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
       A[i]=rand()%100;

    cout <<"Unsorted Array : ";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    MargeSort (A,0,n-1);

    cout <<"Sorted Array : ";
    for(int i=0;i<n;i++)
        cout<< A[i]<<" ";


}

