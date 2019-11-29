using namespace std;
#include<iostream>
int max(int a,int b){
    return a>b?a:b;
}
int getMaxProfit(int len[],int val[],int n,int length){
    int T[n+1][length+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=length;j++){
            if(i==0 || j==0){
                T[i][j] = 0;
            }
            
            else if(j>=i){
                T[i][j] = max(T[i-1][j] , val[i-1]+T[i][j-i]);
            }
            
            else{
                T[i][j] = T[i-1][j];
            }
        }
    }

    return T[n][length];
}
int main()
{
    int len[] =  {1,2,3,4};
    int val[] = {2,5,7,8};
    int length = 5;
    cout<<getMaxProfit(len,val,sizeof(len)/sizeof(len[0]),length);
    return 0;
}