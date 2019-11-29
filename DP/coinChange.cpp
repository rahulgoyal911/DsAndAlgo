using namespace std;
#include<iostream>
int min(int a,int b){
    return a<b?a:b;
}
int getMinCoins(int arr[],int m,int val){
    int table[m+1][val+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=val;j++){
            if(j==0){
                table[i][j] = 0;
            }
            else if(i==0){
                table[i][j] = INT16_MAX;
            }
            // else if(j == arr[i]){
            //     table[i][j] = 1;
            // }
            else if(j>=arr[i-1]){
                table[i][j] = min(table[i-1][j],1+table[i][j-arr[i-1]]);
            }
            else{
                table[i][j] = table[i-1][j];
            }
            
        }
    }
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=val;j++){
    //         cout<<table[i][j]<<" ";
    //     }cout<<endl;
    // }
    return table[m-1][val];


}
int main(){
    int arr[] = {1,5,6,8};
    int m = sizeof(arr)/sizeof(arr[0]);
    int val = 11;
    cout<<getMinCoins(arr,m,val);
    return 0;
}