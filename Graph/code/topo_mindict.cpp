#define MAXN 200005

int n, m;
int in[MAXN];
vector<int> G[MAXN], topo;

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		in[b]++;
	}
	
	priority_queue<int, vector<int>, greater<int>> q;
	
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			q.push(i);
			in[i] = INF;
		}
	}
	
	while (q.size()) {
		int now = q.top();
		q.pop();
		
		topo.push_back(now);
		
		for (int e: G[now]) {
			in[e]--;
			if (!in[e]) {
				q.push(e);
				in[e] = INF;
			}
		}
	}
	
	if (topo.size() == n) {
		for (int it: topo)
			cout << it << " ";
		cout << endl;
	}
	else
		cout << "IMPOSSIBLE" << endl;
}