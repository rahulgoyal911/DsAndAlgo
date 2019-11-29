// to find shortest path between every pair
using namespace std;
#include<iostream>
#define INF 99999
#define V 4
void printSolution(int dist[][V]){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
        {
            if(dist[i][j] == INF)
            cout<<"%"<<" ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}
void floydWarshall(int graph[][V]){
    int dist[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++){
            dist[i][j] = graph[i][j];
        }
    }
        for(int k=0;k<V;k++){
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
            
        }printSolution(dist);

}
int main()
{
    int graph[V][V] = { {0, 5, INF, 10},  
                            {INF, 0, 3, INF},  
                            {INF, INF, 0, 1},  
                            {INF, INF, INF, 0}  
                        }; 
    floydWarshall(graph);
    return 0;
}