using namespace std;
#include<iostream>
int max(int a,int b){
    return (a>b)?a:b;
}
int knapsack(int W,int wt[],int val[],int n){
    int T[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                T[i][j] = 0;
            }
            else if(j>wt[i-1]){
                T[i][j] = max(T[i-1][j], T[i-1][j-wt[i-1]]+val[i-1]);
            }
            else{
                T[i][j] = T[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<T[i][j]<<" ";
        }cout<<endl;
    }
    return T[n][W];
}
int main()
{
    int val[] = {1,2,5,6};
    int wt[] = {2,3,4,5};
    int w = 8;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(w,wt,val,n);
    return 0;
}