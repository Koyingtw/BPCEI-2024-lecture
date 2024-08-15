#define MAXN 200005

int n, m, cnt, diff;
int color[2][MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis;

bool dfs(int i) {
	vis[i] = true;
	cnt++;
	diff += color[0][i] != color[1][i];
	
	bool legal = true;
	for (int e: G[i]) {
		if (color[1][i] == color[1][e])
			return false;
			
		if (!vis[e]) {
			color[1][e] = 1 + (color[1][i] == 1);
			legal &= dfs(e);
		}
	}
	return legal;
}

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> color[0][i];
		color[0][i]++;
	}
	for (int i, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	int ans = 0;
	bool legal = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			color[1][i] = 1;
			cnt = diff = 0;
			
			legal &= dfs(i);
			
			ans += min(diff, cnt - diff);
		}
	}
	
	cout << (legal == true ? ans : -1) << endl;
}