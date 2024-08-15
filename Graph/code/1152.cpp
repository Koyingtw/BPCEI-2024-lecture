#define MAXN 10005

int n, ans = 0;
int d[MAXN];
vector<int> G[MAXN];

int dfs(int i, int dep) {
	d[i] = dep;
	
	pair<int, int> mx(dep, dep);
	
	for (int e: G[i]) {
		int tmp = dfs(e, dep + 1);
		
		if (tmp >= mx.first)
			mx = {tmp, mx.first};
		else if (tmp > mx.second)
			mx = {mx.first, tmp};
	}
	ans = max(ans, mx.first + mx.second - 2 * dep);
	
	return mx.first;
}

void sol() {
	cin >> n;
	
	for (int i = 0, a; i < n; i++) {
		while (cin >> a && a > 0)
			G[i].push_back(a);
	}
	dfs(0, 1);
	
	cout << ans << endl;
}