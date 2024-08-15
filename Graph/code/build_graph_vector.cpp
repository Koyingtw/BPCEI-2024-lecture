vector<pair<int, int>> G[MAXN]; // 沒有邊權則改為 vector<int>

void build() {
    cin >> n >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c}); // 如果是無向圖
    }
}