vector<int> G[MAXN];
bool vis[MAXN];

void dfs(int i) {
    vis[i] = true;

    for (int e: G[i]) {
        if (!vis[e])
            dfs(e);
    }
}
