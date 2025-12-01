#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
};

bool cmp(Edge a, Edge b){
    return a.wt < b.wt;
}

int findParent(int v, vector<int>& parent){
    if(parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank){
    a = findParent(a, parent);
    b = findParent(b, parent);

    if(rank[a] < rank[b]) parent[a] = b;
    else if(rank[a] > rank[b]) parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main(){
    int n = 4; 
    vector<Edge> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n), rank(n,0);
    for(int i=0;i<n;i++) parent[i]=i;

    vector<Edge> mst;
    int totalWeight = 0;

    for(auto &e : edges){
        int uP = findParent(e.u, parent);
        int vP = findParent(e.v, parent);

        if(uP != vP){
            mst.push_back(e);
            totalWeight += e.wt;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    cout << "Kruskal MST edges:\n";
    for(auto &e : mst)
        cout << e.u << " - " << e.v << " : " << e.wt << endl;

    cout << "Total Weight = " << totalWeight << endl;
}
