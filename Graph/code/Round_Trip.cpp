#define MAXN 200005

int n, m;
int vis[MAXN];
vector<int> G[MAXN], ans;
stack<int> path;

void dfs(int i, int pre) {
	vis[i] = 2;
	path.push(i);
	
	for (int e: G[i]) {
		if (!vis[e])
			dfs(e, i);
			
		if (vis[e] == 2 && e != pre && ans.empty()) {
			ans.push_back(e);
			while (path.size()) {
				ans.push_back(path.top());
				if (path.top() == e)
					break;
				path.pop();
			}
			reverse(ans.begin(), ans.end());
			return;
		}
	}
	
	vis[i] = 1;
	
	if (path.size())
		path.pop();
}

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i, i);
	
	if (ans.size()) {
		cout << ans.size() << endl;
		for (int it: ans)
			cout << it << " ";
		cout << endl;
	}
	else
		cout << "IMPOSSIBLE" << endl;
}