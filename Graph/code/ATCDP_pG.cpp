#define MAXN 200005

int n, m;
int in[MAXN], dp[MAXN];
vector<int> G[MAXN];

void sol() {
	cin >> n >> m;
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		in[b]++;
	}
	
	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			q.push(i);
			in[i] = INF;
		}
	}
	
	while (q.size()) {
		int now = q.front();
		q.pop();
		
		for (int e: G[now]) {
			in[e]--;
			dp[e] = max(dp[e], dp[now] + 1);
			
			if (!in[e]) {
				q.push(e);
				in[e] = INF;
			}
		}
	}
	
	cout << *max_element(dp + 1, dp + n + 1) << endl;
}