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
