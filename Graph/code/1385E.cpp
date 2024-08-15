#define MAXN 200005

int n, m;
int in[MAXN];
vector<int> G[MAXN];
vector<pair<int, int>> dir;
set<int> undir[MAXN];

void init() {
	for (int i = 1; i <= n; i++) {
		G[i].clear();
	 	undir[i].clear();
		in[i] = 0;
	}
	dir.clear();
}

void sol() {
	cin >> n >> m;
	init();
	
	for (int i = 0, t, a, b; i < m; i++) {
		cin >> t >> a >> b;
		if (t == 0) {
			undir[a].insert(b);
			undir[b].insert(a);
		}
		else {
			G[a].push_back(b);
			in[b]++;
			dir.push_back({a, b});
		}
	}
	
	queue<int> q;
	int viscnt = 0;
	
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			q.push(i);
			in[i] = INF;
		}
	}
	
	while (q.size()) {
		int now = q.front();
		q.pop();
		viscnt++;
		
		for (int e: G[now]) {
			in[e]--;
			
			if (!in[e]) {
				q.push(e);
				in[e] = INF;
			}
		}
		
		for (int it: undir[now]) {
			dir.push_back({now, it});
			undir[it].erase(now);
		}
	}
	
	if (viscnt == n) {
		cout << "YES" << endl;
		for (auto it: dir)
			cout << it.first << " " << it.second << endl;
	}
	else
		cout << "NO" << endl;
}