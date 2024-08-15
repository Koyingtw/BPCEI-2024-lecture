#define MAXN 200005

int n, m;
int vis[MAXN];
vector<int> G[MAXN], topo;

bool dfs(int i) {
	vis[i] = 2;
	
	bool legal = true;
	for (int e: G[i]) {
		if (vis[e] == vis[i]) 
			return false;
		else if (!vis[e])
			legal &= dfs(e);
	}
	
	vis[i] = 1;
	topo.push_back(i);
	return legal;
}

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
	}
	
	bool legal = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			legal &= dfs(i);
		}
	}		
	
	if (legal) {
		reverse(topo.begin(), topo.end());
		for (int it: topo)
			cout << it << " ";
		cout << endl;
	}
	else
		cout << "IMPOSSIBLE" << endl;
}