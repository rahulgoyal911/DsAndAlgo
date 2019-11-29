using namespace std;
#include<cstring>
#include<bits/stdc++.h>
#include<iostream>
void computeLPSArray(char *pat,int m,int *lps){
    int len = 0;
    lps[0] = 0;
    int i=1;
    while(i<m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(char text[],char pat[]){
    int m = strlen(pat);
    int n = strlen(text);
    int lps[m];
    computeLPSArray(pat,m,lps);
    int i=0,j=0;
    while(i<n){
        if(pat[j] == text[i]){
            i++;
            j++;
        }
        if(j == m){
            cout<<"found at index: "<<i-j<<endl;
        }
        else if(i < n && pat[j]!=text[i]){
            if(j!=0)
                j=lps[j-1];
            else
                ++i;
        }
    }
}

int main()
{
    char txt[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB";
    KMPSearch(pat,txt);
    return 0;
}