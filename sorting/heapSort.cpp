using namespace std;
#include<iostream>
void heapify(int arr[],int n,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }

}
void buildHeap(int arr[],int n){
    int startIdex = (n/2) - 1;
    for(int i=startIdex;i>=0;i--){
        heapify(arr,n,i);
    }
}

void printHeap(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void deleteRoot(int arr[],int &n){
    cout<<arr[0]<<endl;
    int lastElemet = arr[n-1];
    arr[0] = lastElemet;
    n= n-1;
    heapify(arr,n,0);
    // buildHeap(arr,n);
}

int main()
{
    // int arr[] = {12,11,13,5,6,7};
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 }; 
    int n = sizeof(arr)/sizeof(arr[0]);
    buildHeap(arr,n);
    printHeap(arr,n);
    while(n>0)
    deleteRoot(arr,n);
    
    return 0;
}