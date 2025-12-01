#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDist(vector<int>& dist, vector<bool>& visited, int n){
    int minVal = INT_MAX, index = -1;

    for(int i=0;i<n;i++){
        if(!visited[i] && dist[i] < minVal){
            minVal = dist[i];
            index = i;
        }
    }
    return index;
}

int main(){
    int n = 5;

    int graph[5][5] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int src = 0;

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for(int i=0;i<n-1;i++){
        int u = minDist(dist, visited, n);
        visited[u] = true;

        for(int v=0;v<n;v++){
            if(!visited[v] && graph[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Dijkstra shortest distances from source 0:\n";
    for(int i=0;i<n;i++)
        cout << i << " : " << dist[i] << endl;
}
