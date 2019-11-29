using namespace std;
#include<iostream>
#define N 4
int board[50][50];
int is_attack(int i,int j)
{
    for(int k=0;k<N;k++)
    {
        if(board[i][k] == 1 || board[k][j] == 1)
            return 1;
    }
    for(int k=0;k<N;k++)
    {
        for(int l=0;l<N;l++)
        {
            if( ((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(board[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int N_queen(int n){
    if(n == 0)   
        return 1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!is_attack(i,j) && board[i][j] != 1)
            {
                board[i][j] = 1;
                if(N_queen(n-1) == 1)
                {
                    return 1;
                }
                board[i][j] = 0;

            }
        }
    }
    return 0;
}

int main()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            board[i][j] = 0;
        }
    }
    N_queen(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

}