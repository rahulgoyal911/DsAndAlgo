#include<bits/stdc++.h>
using namespace std;
#include<iostream>
int max(int a,int b){
    return a>b?a:b;
}
int lis(int arr[],int n){
    int lis[n];
    lis[0] = 1;
    for(int i=1;i<n;i++){
        lis[i] = 1;
        for(int j=0;j<i;j++){
            if(arr[i] >arr[j] && lis[i] <lis[j] +1){
                lis[i] = lis[j]+1;
            }
        }
       
    } return *max_element(lis,lis+n);

}
int main()
{
    int seq[] = {10,22,9,33,21,50,41,60};
    int n = sizeof(seq)/sizeof(seq[0]);
    cout<<lis(seq,n);
    return 0;
}