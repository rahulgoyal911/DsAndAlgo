using namespace std;
#include<iostream>
int min(int a,int b,int c){
    if(a<b && a<c)
    return a;
    else if(b<a && b<c)
    return b;
    else return c;
}

int minEditDist(string s1,string s2,int m,int n){
    int T[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0)
                T[i][j] = j;
            else if(j==0)
                T[i][j] = i;
            else if(s1[i-1] == s2[j-1]){
                T[i][j] = T[i-1][j-1];
            }
            else{
                T[i][j] = 1+min(T[i-1][j],T[i-1][j-1],T[i][j-1]);
            }
        }
    }
    return T[m][n];
}
int main(){
    string s1 = "sunday";
    string s2 = "monday";
    cout<<minEditDist(s1,s2,s1.length(),s2.length());
    return 0;
}