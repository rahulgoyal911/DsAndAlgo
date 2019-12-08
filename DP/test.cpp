#include<stdio.h>
int compa(const void *a,const void *b){
    return *(int *)a > *(int *)b;
}
int main()
{
    int a[] = {3,4,1,2,7};
    int n = 5;
    qsort(a,5,sizeof(int),compa);
    for(int i=0;i<5;i++)
    cout<<a[i];

}