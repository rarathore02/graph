#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void BFS(int start, vector<vector<int>>& adj, int n){
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int x : adj[node]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main(){
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,3};
    adj[3] = {1,2,4};
    adj[4] = {3};

    cout << "BFS starting from node 0: ";
    BFS(0, adj, n);
}
