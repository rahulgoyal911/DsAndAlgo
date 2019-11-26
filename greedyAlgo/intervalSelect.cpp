using namespace std;
#include<iostream>
void printMaxActivities(int s[],int f[],int n){
    int i,j;
    i = 0;
    // first activity always gets selected
    cout<<i<<" ";
    for(int j=1;j<n;j++){
        if(s[j] >= f[i]){
            cout<<j<<" ";
            i=j;
        }
    }
}
int main()
{
    int s[] = {1,3,0,5,8,5};
    int f[] = {2,4,6,7,9,9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s,f,n);
    return 0;
    }