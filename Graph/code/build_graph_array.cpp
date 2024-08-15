tuple<int, int, int> E[MAXM]; // 如果沒有邊權則改為 pair<int, int>

void build() {
    cin >> n >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        E[i] = {a, b, c};
    }
}