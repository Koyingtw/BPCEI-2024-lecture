vector<int> G[MAXN];
bitset<MAXN> vis;

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (q.size()) {
        int now = q.front();
        q.pop();

        for (int e: G[now]) {
            if (!vis[e]) {
                vis[e] = true;
                q.push(e);
            }
        }
    }
}