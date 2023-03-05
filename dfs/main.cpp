#include <bits/stdc++.h>

using namespace std;

// 0 based graph
struct graph {
    int n;
    vector<vector<int>> g;
    vector<bool> used;
    vector<int> d;
    graph(int n) {
        this->g = vector<vector<int> > (n, vector<int>(0));
        this->n = n;
        this->used = vector<bool> (n, false);
        this->d = vector<int>(n, -1);
    }

    void dfs(int v, int p = -1) {
        used[v] = true;
        for(int to : g[v]) {
            if(!used[to]) dfs(to, v);
        }
    }

    inline void bfs(int start) {
        queue<int> q;
        q.push(start);
        d[start] = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to : g[v]) {
                if(d[to] == -1) {
                    d[to] = d[v] + 1;
                    q.push(to);
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    return 0;
}

