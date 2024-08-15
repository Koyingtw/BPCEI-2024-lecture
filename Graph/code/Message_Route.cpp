int n, m;
int from[MAXN];
vector<int> G[MAXN];

void sol() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    
    while (q.size()) {
        auto now = q.front();
        q.pop();

        for (int e: G[now]) {
            if (from[e] == 0) {
                from[e] = now;
                q.push(e);
            }
        }
    }

    if (from[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> ans;
    int now = n;
    while (now != 1) {
        ans.push_back(now);
        now = from[now];
    }
    ans.push_back(now);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int e: ans) {
        cout << e << " ";
    }
    cout << endl;
}