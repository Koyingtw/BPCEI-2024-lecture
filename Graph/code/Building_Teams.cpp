#define MAXN 200005

int n, m;
int color[MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis;

bool dfs(int i) {
	vis[i] = true;
	
	bool legal = true;
	for (int e: G[i]) {
		if (color[e] == color[i])
			return false;
			
		if (!vis[e]) {
			color[e] = 1 + (1 == color[i]);
			legal &= dfs(e);
		}
	}
	return legal;
}

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	bool legal = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			color[i] = 1;
			legal &= dfs(i);
		}
		if (!legal) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << color[i] << " ";
	cout << endl;
}