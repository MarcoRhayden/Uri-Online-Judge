#include <bits/stdc++.h>
using namespace std;

vector<int> subset;

struct Graph {
    int x, y, z;
};

bool compare(Graph A, Graph B) {
    return (A.z < B.z);
}

void make(int vertexes) {
    for (int x = 0; x < vertexes; x++)
        subset[x] = x;
}

int find(int v) {
    return ((subset[v] == v) ? v : subset[v] = find(subset[v]));
}

void unionSet(int p, int q) {
    subset[find(p)] = find(q);
}

bool isSameSet(int i, int j) {
    return find(i) == find(j);
}

int main(int argc, char *argv[]) {
    int m, n, minimum;
    vector<Graph> edges;
    while (cin >> m && cin >> n) {
        if (m == 0 && n == 0)
            break;
        minimum = 0;
        edges.resize(n);
        subset.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> edges[i].x;
            cin >> edges[i].y;
            cin >> edges[i].z;
        }
        sort(edges.begin(), edges.end(), compare);
        make(m);
        for (int nx = 0; nx < n; nx++) {
            if (!isSameSet(edges[nx].x, edges[nx].y))
                unionSet(edges[nx].x, edges[nx].y);
            else
                minimum += edges[nx].z;
        }
        subset.clear();
        edges.clear();
        cout << minimum << endl;
    }
    return(0);
}
