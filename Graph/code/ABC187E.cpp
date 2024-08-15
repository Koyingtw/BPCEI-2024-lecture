#define MAXN 200005

int n, q, timestamp = 1;
int intime[MAXN], outtime[MAXN];
int cnt[MAXN * 2], c[MAXN];
pair<int, int> E[MAXN], ett[MAXN * 2];
vector<int> G[MAXN];

void dfs(int i, int dep) {
	intime[i] = timestamp;
	ett[timestamp] = {i, dep};
	timestamp++;
	
	for (int e: G[i]) {
		if (!intime[e])
			dfs(e, dep + 1);
	}
	
	outtime[i] = timestamp;
	ett[timestamp] = {i, dep};
	timestamp++;
}

void sol() {
	cin >> n;
	
	for (int i = 1; i < n; i++) {
		cin >> E[i].first >> E[i].second;
		G[E[i].first].push_back(E[i].second);
		G[E[i].second].push_back(E[i].first);
	}
	
	dfs(1, 1);
	
	cin >> q;
	int t, e, x;
	while (q--) {
		cin >> t >> e >> x;
		
		int a = E[e].first, b = E[e].second;
		int depa = ett[intime[a]].second, depb = ett[intime[b]].second;
			
		if (t == 1) {
			if (depa < depb) {
				cnt[1] += x;
				cnt[intime[b]] -= x;
				
				cnt[outtime[b] + 1] += x;
				cnt[timestamp] -= x;
			}
			else {
				cnt[intime[a]] += x;
				cnt[outtime[a] + 1] -= x;
			}
		}
		else {
			if (depb < depa) {
				cnt[1] += x;
				cnt[intime[a]] -= x;
				
				cnt[outtime[a] + 1] += x;
				cnt[timestamp] -= x;
			}
			else {
				cnt[intime[b]] += x;
				cnt[outtime[b] + 1] -= x;
			}
		}
	}
	
	for (int i = 1; i < timestamp; i++) {
		cnt[i] = cnt[i - 1] + cnt[i];
		c[ett[i].first] = cnt[i];
	}
	for (int i = 1; i <= n; i++)
		cout << c[i] << endl;
}