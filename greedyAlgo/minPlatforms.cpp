using namespace std;
#include<iostream>
#include<algorithm>
int findPlatforms(int arr[],int dep[],int n){
    sort(arr,arr+n);
    sort(dep,dep+n);

    int plat_meeded = 1;
    int result = 1;
    int i=1,j=0;

    while(i<n && j<n){
        if(arr[i] <= dep[j]){
            plat_meeded++;
            i++;

            if(plat_meeded > result){
                result = plat_meeded;
            }
        }
        else{
            plat_meeded--;
            j++;
        }
    }
    return result;

}
int main(){
    int arr[] = {900,940,950,1100,1500,1800};
    int dep[] = {910,1200,1120,1130,1900,2000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findPlatforms(arr,dep,n);
    return 0;
}