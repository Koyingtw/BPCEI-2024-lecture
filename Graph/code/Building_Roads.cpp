int n, m;
vector<int> G[MAXN];
bool vis[MAXN];

void dfs(int i) {
	vis[i] = true;
	
	for (int e: G[i]) {
		if (!vis[e])
			dfs(e);
	}
}

void sol() {
	cin >> n >> m;
	
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs(1);
	vector<pair<int, int>> ans;
	
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			ans.push_back({1, i});
			dfs(i);
		}
	}
	
	cout << ans.size() << endl;
	for (auto it: ans)
		cout << it.first << " " << it.second << endl;
}