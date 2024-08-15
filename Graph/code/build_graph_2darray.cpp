pair<bool, int> G[MAXN][MAXN]; // 沒有邊權則改為 bool

void build() {
    cin >> n >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        G[a][b] = {1, c};
        G[b][a] = {1, c}; // 如果是無向圖
    }
}