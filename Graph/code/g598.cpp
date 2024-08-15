#define MAXN 200005
#define MAXM 1000005 
int n, m, p, k;
int color[MAXN];
vector<pair<int, int>> G[MAXN];
bitset<MAXN> vis, illegal;

bool dfs(int i, int mid) {
	vis[i] = true;
	
	bool legal = true;
	for (auto e: G[i]) {
		if (e.second > mid || illegal[e.second])
			continue;
            
		if (vis[e.first] && color[e.first] == color[i]) {
			return false;
		}
		
		if (!vis[e.first]) {
			color[e.first] = 1 + (color[i] == 1);
			legal &= dfs(e.first, mid);
		}
	}
	return legal;
}

bool check(int mid) { // 判斷 1~mid 的調查員所提供的資料是否合法
	vis.reset();
	memset(color, 0, sizeof(color));
			
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			color[i] = 1;
			if (!dfs(i, mid))
				return false;
		}
	}
	return true;
}

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back({b, 0});
		G[b].push_back({a, 0});
	}
	
	cin >> p >> k;
	for (int i = 1; i <= p; i++) {
		for (int j = 0, a, b; j < k; j++) {
			cin >> a >> b;
			G[a].push_back({b, i});
			G[b].push_back({a, i});
		}
	}
	
	vector<int> ans;
	for (int i = 0; i < 3 && !check(p); i++) {
		int l = 0, r = p;
		while (l < r) {
			int mid = (l + r) / 2;
			
			if (check(mid))
				l = mid + 1;
			else
				r = mid;
		}
		
		if (r > 0) {
			illegal[r] = true;
			ans.push_back(r);
		}
	}
	
	for (int it: ans)
		cout << it << endl;
}