using namespace std;
#include<iostream>
#include <bits/stdc++.h> 
struct Item{
    int value,weight;
    Item(int value,int weight){
        this->value = value;
        this->weight = weight;
    }
};
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 
double fractionalKnapsack(int w,Item arr[],int n){
    sort(arr,arr+n,cmp);
    int currWeight = 0;
    double finalvalue = 0.0;
    for(int i=0;i<n;i++){
        if(currWeight + arr[i].weight <= w){
            currWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
        else{
            int remain = w - currWeight;
            finalvalue +=  arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
int main(){
    int W = 50;
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, arr, n); 
    return 0; 

}