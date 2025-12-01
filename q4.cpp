#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet, int n){
    int minVal = INT_MAX, idx = -1;
    for(int i=0;i<n;i++){
        if(!mstSet[i] && key[i] < minVal){
            minVal = key[i];
            idx = i;
        }
    }
    return idx;
}

int main(){
    int n = 5;

    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 0, 0},
        {0, 3, 0, 0, 7},
        {6, 0, 0, 0, 9},
        {0, 0, 7, 9, 0}
    };

    vector<int> parent(n);
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);

    key[0] = 0;
    parent[0] = -1;

    for(int i=0;i<n-1;i++){
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        for(int v=0;v<n;v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Prim's MST:\n";
    int total = 0;
    for(int i=1;i<n;i++){
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]];
    }

    cout << "Total Weight = " << total << endl;
}
