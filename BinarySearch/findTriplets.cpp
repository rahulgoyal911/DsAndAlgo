using namespace std;
#include<iostream>
bool havePair(int a[],int i,int sum,int n){
    int j = n - 1;
    while(i<j){
        if(a[i]+a[j] > sum){
            j--;
        }else if(a[i]+a[j] < sum){
            i++;
        }
        else{
            return true;
        }
    }
}
int compa(const void *a,const void *b){
    return *(int *)a > *(int *)b;
}
bool haveTriplet(int a[],int sum,int n){
    qsort(a,n,sizeof(int),compa);
    for(int i=0;i<n-2;i++){
        if(havePair(a,i+1,sum+a[i],n))   
        return true;
        else
        {
            cout<<a[i]<<endl;
        }
        
    }
    return false;
}
int main(){
    int a[] = {2,7,1,-1,0,5};
    // int a[] = {-1,0,1,2,5,7};
    int n = sizeof(a)/sizeof(a[0]);
    int sum = 8;
    cout<<haveTriplet(a,sum,n);
    return 0;
}