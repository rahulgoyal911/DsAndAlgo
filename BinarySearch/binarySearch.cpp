using namespace std;
#include<iostream>
int binarySearch(int a[],int l,int r,int number){
    if(l<=r)
    {
        int mid = l + (r-l)/2;
        if(a[mid] == number)
            return mid;
        else if(a[mid] > number)
            binarySearch(a,l,mid-1,number);
        else
            binarySearch(a,mid+1,r,number);

    }
    else 
        return -1;
    
    
}
int main()
{
    int a[] = {1,3,5,7,11,14,15,17,99,111};
    int number = 15;
    int n = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
        cout<<binarySearch(a,0,n-1,a[i])<<endl;
    return 0;
}