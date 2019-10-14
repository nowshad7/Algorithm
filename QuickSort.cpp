#include<bits/stdc++.h>

using namespace std;

int partion(int A[], int s, int e)
{
    int i=s-1;
    int j;
    int pivot= A[e];
    for(j=s; j <e ; j++)
    {
        if(A[j]<=pivot)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[e]);
    return i+1;

}

void QuickSort(int A[], int s, int e)
{
    if(s<e)
    {
         int p=partion(A, s, e);
         QuickSort(A,s,p-1);
         QuickSort(A,p+1, e);
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

    QuickSort(A, 0 , n-1);

    cout <<"Sorted Array : ";
    for(int i=0;i<n;i++)
        cout<< A[i]<<" ";


}
