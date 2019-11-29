using namespace std;
#include<iostream>
int max(int a,int b)
{
    return a>b?a:b;
}
bool subsetSum(int set[],int n,int sum){
    bool L[n+1][sum+1];

    for(int i=0;i<=n;i++){
        L[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        L[i][0] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j<set[i-1])
                L[i][j] = L[i-1][j];
            else
                L[i][j] = L[i-1][j] || L[i-1][j-set[i-1]];
        }
    }
    return L[n][sum];

}
int main()
{
    int set[] = {3,24,4,12,5,2};
    int sum = 9;
    int n = sizeof(set)/sizeof(set[0]);

    cout<<subsetSum(set,n,sum);
    return 0;
}