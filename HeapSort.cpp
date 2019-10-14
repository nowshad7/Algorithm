#include<bits/stdc++.h>
using namespace std;

maxHeapify(int A[],int i, int heapSize)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<heapSize && A[l]>A[largest])
        largest=l;
    if(r<heapSize && A[r]>A[largest])
        largest=r;
    if(largest!=i)
    {
        swap(A[largest],A[i]);
        maxHeapify(A,largest,heapSize);
    }
}
BuildMaxHeap(int A[],int heapSize)
{
    for(int i=(heapSize/2)-1;i>=0;i--)
        maxHeapify(A,i,heapSize);
}
HeapSort(int A[],int heapSize)
{
    BuildMaxHeap(A,heapSize);
    for(int i=heapSize-1;i>=0;i--)
    {
        swap(A[0],A[i]);
        heapSize--;
        maxHeapify(A,0,heapSize);
    }
}
int main()
{
    int n;
    cout<<"Enter the no of nodes : "<<endl;
    cin>>n;
    int A[n];
    int heapSize=sizeof(A)/sizeof(A[0]);
    cout<<"Enter the nodes"<<endl;
    for(int i=0;i<n;i++)
        cin>>A[i];
    HeapSort(A, heapSize);
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
}
