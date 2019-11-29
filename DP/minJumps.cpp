using namespace std;
#include<iostream>
int min(int a,int b){
    return a<b?a:b;
}
int minJumps(int a[],int n){
    int T[n];
    T[0] = 0;
    for(int i=1;i<n;i++){
        T[i] = INT32_MAX;
        for(int j=0;j<i;j++){
            if(i<= j+a[j] && T[j]!= INT32_MAX){
                T[i] = min(T[i],T[j]+1);
                break;
            }
        }
    }

    return T[n-1];

}
int main()
{
    int a[] = {2,3,1,1,2,4,2,0,1,1};
    cout<<minJumps(a,sizeof(a)/sizeof(a[0]));
    return 0;
}